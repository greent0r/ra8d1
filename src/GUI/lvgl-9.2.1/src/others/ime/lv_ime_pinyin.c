/**
 * @file lv_ime_pinyin.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_ime_pinyin_private.h"
#include "../../core/lv_obj_class_private.h"
#if LV_USE_IME_PINYIN != 0

#include "../../lvgl.h"
#include "../../core/lv_global.h"

/*********************
 *      DEFINES
 *********************/
#define MY_CLASS (&lv_ime_pinyin_class)
#define cand_len LV_GLOBAL_DEFAULT()->ime_cand_len

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void lv_ime_pinyin_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void lv_ime_pinyin_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void lv_ime_pinyin_style_change_event(lv_event_t * e);
static void lv_ime_pinyin_kb_event(lv_event_t * e);
static void lv_ime_pinyin_cand_panel_event(lv_event_t * e);

static void init_pinyin_dict(lv_obj_t * obj, const lv_pinyin_dict_t * dict);
static void pinyin_input_proc(lv_obj_t * obj);
static void pinyin_page_proc(lv_obj_t * obj, uint16_t btn);
static char * pinyin_search_matching(lv_obj_t * obj, char * py_str, uint16_t * cand_num);
static void pinyin_ime_clear_data(lv_obj_t * obj);

#if LV_IME_PINYIN_USE_K9_MODE
    static void pinyin_k9_init_data(lv_obj_t * obj);
    static void pinyin_k9_get_legal_py(lv_obj_t * obj, char * k9_input, const char * py9_map[]);
    static bool pinyin_k9_is_valid_py(lv_obj_t * obj, char * py_str);
    static void pinyin_k9_fill_cand(lv_obj_t * obj);
    static void pinyin_k9_cand_page_proc(lv_obj_t * obj, uint16_t dir);
#endif

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t lv_ime_pinyin_class = {
    .constructor_cb = lv_ime_pinyin_constructor,
    .destructor_cb  = lv_ime_pinyin_destructor,
    .width_def      = LV_SIZE_CONTENT,
    .height_def     = LV_SIZE_CONTENT,
    .group_def      = LV_OBJ_CLASS_GROUP_DEF_TRUE,
    .instance_size  = sizeof(lv_ime_pinyin_t),
    .base_class     = &lv_obj_class,
    .name = "ime-pinyin",
};

#if LV_IME_PINYIN_USE_K9_MODE
static const char * lv_btnm_def_pinyin_k9_map[LV_IME_PINYIN_K9_CAND_TEXT_NUM + 21] = {\
                                                                                      ",\0", "123\0",  "abc \0", "def\0",  LV_SYMBOL_BACKSPACE"\0", "\n\0",
                                                                                      ".\0", "ghi\0", "jkl\0", "mno\0",  LV_SYMBOL_KEYBOARD"\0", "\n\0",
                                                                                      "?\0", "pqrs\0", "tuv\0", "wxyz\0",  LV_SYMBOL_NEW_LINE"\0", "\n\0",
                                                                                      LV_SYMBOL_LEFT"\0", "\0"
                                                                                     };

static lv_buttonmatrix_ctrl_t default_kb_ctrl_k9_map[LV_IME_PINYIN_K9_CAND_TEXT_NUM + 17] = { 1 };
static char   lv_pinyin_k9_cand_str[LV_IME_PINYIN_K9_CAND_TEXT_NUM + 2][LV_IME_PINYIN_K9_MAX_INPUT] = {0};
#endif

static char   lv_pinyin_cand_str[LV_IME_PINYIN_CAND_TEXT_NUM][4];
static char * lv_btnm_def_pinyin_sel_map[LV_IME_PINYIN_CAND_TEXT_NUM + 3];

#if LV_IME_PINYIN_USE_DEFAULT_DICT
static const lv_pinyin_dict_t lv_ime_pinyin_def_dict[] = {
      { "a", "啊阿" },
      { "ai", "哀哎唉埃挨爱癌矮碍艾蔼隘" },
      { "an", "俺安岸庵按暗案氨鞍" },
      { "ang", "昂肮" },
      { "ao", "傲凹奥懊拗澳熬袄" },
      { "ba", "八叭吧坝巴扒把拔捌爸疤笆罢耙芭跋霸靶" },
      { "bai", "拜掰摆柏白百败" },
      { "ban", "伴办半扮扳拌搬斑板版班瓣绊般颁" },
      { "bang", "傍帮梆棒榜磅绑膀蚌谤邦" },
      { "bao", "保包堡宝报抱暴爆胞苞薄褒豹雹饱" },
      { "bei", "倍北卑备悲惫杯焙狈碑背被贝辈" },
      { "ben", "奔本笨" },
      { "beng", "崩泵绷蹦" },
      { "bi", "匕壁币庇弊彼必比毕毙璧痹碧秕笔臂荸蓖蔽逼避鄙闭鼻" },
      { "bian", "便匾变扁编蝙贬辨辩辫边遍鞭" },
      { "biao", "彪标膘表" },
      { "bie", "别憋瘪鳖" },
      { "bin", "宾彬滨濒缤鬓" },
      { "bing", "丙兵冰并柄病禀秉饼" },
      { "bo", "伯剥勃博卜拨搏播波渤玻簸脖膊舶菠跛驳" },
      { "bu", "不哺埠布怖捕步簿补部" },
      { "ca", "擦" },
      { "cai", "彩才材猜睬菜裁财踩采" },
      { "can", "参惨惭掺残灿蚕餐" },
      { "cang", "仓沧舱苍藏" },
      { "cao", "操曹槽糙草" },
      { "ce", "侧册厕测策" },
      { "ceng", "层曾蹭" },
      { "cha", "叉察岔差插杈查碴茬茶衩" },
      { "chai", "拆柴豺" },
      { "chan", "产搀缠蝉铲阐颤馋" },
      { "chang", "倡偿厂唱场尝常敞昌猖畅肠" },
      { "chao", "吵嘲巢抄朝潮炒超钞" },
      { "che", "彻扯撤澈车" },
      { "chen", "尘忱晨沉臣衬趁辰陈" },
      { "cheng", "乘呈城惩成承撑橙澄秤称程诚逞" },
      { "chi", "侈吃嗤尺弛持斥池痴翅耻赤迟驰齿" },
      { "chong", "充冲宠崇虫" },
      { "chou", "丑仇愁抽畴稠筹绸臭酬" },
      { "chu", "储出初厨处楚橱畜矗础触锄除雏" },
      { "chuai", "揣" },
      { "chuan", "串传喘川穿船" },
      { "chuang", "创幢床疮窗闯" },
      { "chui", "吹垂捶椎炊锤" },
      { "chun", "唇春椿淳纯蠢醇" },
      { "chuo", "戳绰" },
      { "ci", "伺刺慈次此瓷磁祠词赐辞雌" },
      { "cong", "丛从匆囱聪葱" },
      { "cou", "凑" },
      { "cu", "促簇粗醋" },
      { "cuan", "窜篡" },
      { "cui", "催崔悴摧粹翠脆" },
      { "cun", "存寸村" },
      { "cuo", "挫措搓撮锉错" },
      { "da", "大打搭瘩答达" },
      { "dai", "代呆带待怠戴歹袋贷逮" },
      { "dan", "丹但单弹担掸旦氮淡耽胆蛋诞" },
      { "dang", "党当挡档荡裆铛" },
      { "dao", "倒刀到叨导岛悼捣盗祷稻蹈道" },
      { "de", "得德的" },
      { "deng", "凳灯登瞪等蹬邓" },
      { "di", "低嘀地堤嫡帝底弟抵敌涤滴笛第缔蒂递" },
      { "dian", "佃典垫奠店惦掂殿淀点玷电甸碘颠" },
      { "diao", "刁叼吊掉碉调钓雕" },
      { "die", "叠爹碟蝶谍跌" },
      { "ding", "丁叮定盯订钉锭顶鼎" },
      { "diu", "丢" },
      { "dong", "东冬冻动懂栋洞董" },
      { "dou", "兜抖斗痘蚪豆逗都陡" },
      { "du", "堵妒度杜毒渡牍独督睹肚读赌镀" },
      { "duan", "断段短端缎锻" },
      { "dui", "兑堆对队" },
      { "dun", "吨囤墩敦盹盾蹲钝顿" },
      { "duo", "哆垛堕多夺惰朵舵跺踱躲" },
      { "e", "俄噩恶愕扼蛾讹遏额饿鳄鹅" },
      { "en", "恩" },
      { "er", "二儿尔而耳贰饵" },
      { "fa", "乏伐发法筏罚阀" },
      { "fan", "凡反帆樊泛烦犯番矾繁翻范贩返饭" },
      { "fang", "仿坊妨房放方纺肪芳访防" },
      { "fei", "匪吠啡废沸肥肺菲诽费非飞" },
      { "fen", "份分吩坟奋忿愤氛焚粉粪纷芬" },
      { "feng", "丰冯凤奉封峰枫疯缝蜂讽逢锋风" },
      { "fou", "否" },
      { "fu", "付伏佛俘俯傅凫副咐复夫妇孵富幅府扶抚拂敷斧服浮父甫福符缚肤腐腹芙蝠袱覆负赋赴辅辐附麸" },
      { "gai", "丐改概溉盖该钙" },
      { "gan", "干感敢杆柑橄甘秆竿肝赶" },
      { "gang", "冈刚岗杠港纲缸肛钢" },
      { "gao", "告搞稿篙糕羔膏镐高" },
      { "ge", "个割各哥戈搁格歌疙胳葛阁隔革鸽" },
      { "gei", "给" },
      { "gen", "根跟" },
      { "geng", "埂更梗羹耕耿" },
      { "gong", "供公共功宫工巩弓恭拱攻汞蚣贡躬" },
      { "gou", "勾垢够构沟狗苟购钩" },
      { "gu", "估古咕固姑孤故沽箍股菇谷辜雇顾骨鼓" },
      { "gua", "刮卦寡挂瓜褂" },
      { "guai", "乖怪拐" },
      { "guan", "关冠官惯棺灌管罐观贯馆" },
      { "guang", "光广逛" },
      { "gui", "傀刽归柜桂瑰硅规诡贵跪轨闺鬼龟" },
      { "gun", "棍滚" },
      { "guo", "国果裹过郭锅" },
      { "ha", "哈蛤" },
      { "hai", "亥孩害海还骇" },
      { "han", "函含喊寒悍憨憾捍撼旱汉汗涵焊罕翰酣韩" },
      { "hang", "夯杭航" },
      { "hao", "号嚎壕好毫浩耗蒿豪" },
      { "he", "何合呵和喝核河盒禾荷褐贺赫鹤" },
      { "hei", "嘿黑" },
      { "hen", "很恨狠痕" },
      { "heng", "哼恒横衡" },
      { "hong", "哄宏洪烘红虹轰鸿" },
      { "hou", "侯候厚后吼喉猴" },
      { "hu", "乎互呼唬壶弧忽户护沪湖狐糊胡葫虎蝴" },
      { "hua", "划化华哗桦滑猾画花话" },
      { "huai", "坏徊怀槐淮" },
      { "huan", "唤宦幻患换欢涣焕环痪缓" },
      { "huang", "凰幌恍惶慌晃煌皇荒蝗蟥谎黄" },
      { "hui", "会回徽恢悔惠慧挥晦毁汇灰秽绘茴蛔讳诲贿辉" },
      { "hun", "婚昏浑混荤魂" },
      { "huo", "伙惑或活火祸获豁货霍" },
      { "ji", "冀几击剂即及叽吉唧圾基妓嫉季寂寄己忌急技挤既机极棘济激畸疾祭积稽箕籍级纪继绩肌脊荠计讥记辑迹际集饥鲫鸡" },
      { "jia", "价佳假加嘉夹嫁家架枷甲稼茄荚贾钾颊驾" },
      { "jian", "件俭健兼减剑剪坚奸尖建拣捡柬检歼涧渐溅煎监碱简箭肩舰艰茧荐见贱践鉴键间" },
      { "jiang", "僵匠奖姜将桨江浆疆缰蒋讲酱降" },
      { "jiao", "交侥剿叫娇搅教椒浇焦狡矫礁窖绞缴胶脚蕉角轿较郊酵饺骄" },
      { "jie", "介借劫姐届戒截捷接揭杰洁界皆秸竭结节芥街解诫阶" },
      { "jin", "仅今劲尽巾斤晋津浸禁筋紧襟谨近进金锦" },
      { "jing", "井京兢净境径惊敬景晶睛竞竟精经茎荆警镜阱靖静颈鲸" },
      { "jiong", "窘" },
      { "jiu", "久九就揪救旧灸玖疚究纠臼舅酒韭鸠" },
      { "ju", "举俱具剧句局居巨惧拒拘据橘沮炬矩聚菊距锯鞠驹" },
      { "juan", "倦卷捐眷绢鹃" },
      { "jue", "倔决嚼掘爵绝觉诀" },
      { "jun", "俊军君均峻竣菌钧骏" },
      { "ka", "卡咖" },
      { "kai", "凯开慨揩楷" },
      { "kan", "刊勘坎堪看砍" },
      { "kang", "康慷扛抗炕糠" },
      { "kao", "拷烤考铐靠" },
      { "ke", "克刻可咳坷壳客棵渴磕科苛蝌课颗" },
      { "ken", "啃垦恳肯" },
      { "keng", "吭坑" },
      { "kong", "孔恐控空" },
      { "kou", "口寇扣抠" },
      { "ku", "哭库枯窟苦裤酷" },
      { "kua", "垮夸挎胯跨" },
      { "kuai", "块快筷" },
      { "kuan", "宽款" },
      { "kuang", "况旷框狂眶矿筐" },
      { "kui", "亏愧溃盔窥葵魁" },
      { "kun", "困坤捆昆" },
      { "kuo", "廓扩括阔" },
      { "la", "啦喇垃拉腊蜡辣" },
      { "lai", "来癞莱赖" },
      { "lan", "兰懒拦揽栏榄滥澜烂篮缆蓝览" },
      { "lang", "廊朗榔浪狼琅郎" },
      { "lao", "劳唠姥捞涝潦烙牢老酪" },
      { "le", "乐了肋" },
      { "lei", "儡勒垒擂泪类累蕾雷" },
      { "leng", "冷棱楞" },
      { "li", "丽例俐利力励历厉厘吏哩李栗梨沥漓犁狸理璃痢砾礼离立篱粒荔莉里隶雳鲤黎" },
      { "lia", "俩" },
      { "lian", "帘廉怜恋敛炼练联脸莲连链镰" },
      { "liang", "两亮凉晾梁粮粱良谅辆量" },
      { "liao", "僚嘹寥撩料燎疗瞭缭聊辽镣" },
      { "lie", "列劣咧烈猎裂" },
      { "lin", "临凛吝林檩淋琳磷赁躏邻鳞" },
      { "ling", "令伶凌另岭灵玲翎菱蛉铃陵零领龄" },
      { "liu", "六刘柳榴流溜琉留瘤硫馏" },
      { "long", "咙垄拢窿笼聋胧隆龙" },
      { "lou", "娄搂楼漏篓陋" },
      { "lu", "卢卤庐录炉碌芦虏赂路陆露颅鲁鹿" },
      { "luan", "乱卵峦" },
      { "lun", "仑伦抡沦论轮" },
      { "luo", "啰洛箩络罗萝落螺裸逻锣骆骡" },
      { "lv", "侣吕屡履律旅氯滤率绿缕虑铝驴" },
      { "lve", "掠略" },
      { "ma", "吗妈玛码蚂蟆马骂麻" },
      { "mai", "买卖埋脉迈麦" },
      { "man", "幔慢曼满漫瞒蔓蛮馒" },
      { "mang", "忙氓盲芒茫莽" },
      { "mao", "冒帽毛猫矛茂茅貌贸铆锚" },
      { "me", "么" },
      { "mei", "妹媒媚昧枚梅楣每没煤玫眉美霉" },
      { "men", "们门闷" },
      { "meng", "孟朦梦檬猛盟萌蒙锰" },
      { "mi", "咪密弥泌眯秘米糜蜜觅谜迷靡" },
      { "mian", "免冕勉娩棉眠绵缅面" },
      { "miao", "妙庙描渺瞄秒苗藐" },
      { "mie", "灭蔑" },
      { "min", "悯敏民皿闽" },
      { "ming", "名命明螟铭鸣" },
      { "miu", "谬" },
      { "mo", "墨寞抹摩摸摹末模沫漠磨膜茉莫蘑陌馍魔默" },
      { "mou", "某谋" },
      { "mu", "亩募墓姆幕慕拇暮木母沐牡牧目睦穆" },
      { "na", "呐哪娜拿捺纳那钠" },
      { "nai", "乃奈奶耐" },
      { "nan", "南男难" },
      { "nang", "囊" },
      { "nao", "恼挠脑闹" },
      { "ne", "呢" },
      { "nei", "内馁" },
      { "nen", "嫩" },
      { "neng", "能" },
      { "ni", "你匿尼拟昵泥溺腻逆" },
      { "nian", "年念捻撵碾蔫" },
      { "niang", "娘酿" },
      { "niao", "尿鸟" },
      { "nie", "孽捏聂镊" },
      { "nin", "您" },
      { "ning", "凝宁拧柠泞狞" },
      { "niu", "扭牛纽钮" },
      { "nong", "农弄浓脓" },
      { "nu", "努奴怒" },
      { "nuan", "暖" },
      { "nuo", "懦挪糯诺" },
      { "nv", "女" },
      { "nve", "疟虐" },
      { "ou", "偶呕欧殴藕鸥" },
      { "pa", "帕怕爬趴" },
      { "pai", "徘拍排派湃牌" },
      { "pan", "判叛攀潘畔盘盼" },
      { "pang", "乓庞旁胖螃" },
      { "pao", "刨咆抛泡炮袍跑" },
      { "pei", "佩培沛胚赔配陪" },
      { "pen", "喷盆" },
      { "peng", "彭捧朋棚澎烹砰硼碰篷膨蓬鹏" },
      { "pi", "僻劈匹啤坯屁批披疲皮脾譬辟霹" },
      { "pian", "偏片篇翩骗" },
      { "piao", "漂瓢票飘" },
      { "pie", "撇" },
      { "pin", "品拼聘贫频" },
      { "ping", "乒凭坪屏平瓶苹萍评" },
      { "po", "坡婆泊泼破迫颇魄" },
      { "pou", "剖" },
      { "pu", "仆圃扑普朴浦瀑脯菩葡蒲谱铺" },
      { "qi", "七乞企其凄启嘁器奇契妻岂崎弃戚旗期柒栖棋欺歧气汽泣漆畦砌祈脐起迄骑鳍齐" },
      { "qia", "恰掐洽" },
      { "qian", "乾前千嵌欠歉浅潜牵签谦谴迁遣钱钳铅黔" },
      { "qiang", "呛墙强抢枪腔" },
      { "qiao", "乔侨俏峭巧悄憔撬敲桥瞧窍翘荞跷锹" },
      { "qie", "且切怯窃" },
      { "qin", "亲侵勤寝擒琴禽秦芹钦" },
      { "qing", "倾卿庆情擎晴氢清蜻请轻青顷" },
      { "qiong", "琼穷" },
      { "qiu", "丘囚求球秋蚯" },
      { "qu", "区去取娶屈岖曲渠蛆趋趣躯驱" },
      { "quan", "全券劝圈拳权泉犬痊" },
      { "que", "却瘸确缺雀鹊" },
      { "qun", "群裙" },
      { "ran", "染然燃" },
      { "rang", "嚷壤攘瓤让" },
      { "rao", "扰绕饶" },
      { "re", "惹热" },
      { "ren", "人仁任刃忍纫认韧" },
      { "reng", "仍扔" },
      { "ri", "日" },
      { "rong", "冗容榕溶熔绒茸荣蓉融" },
      { "rou", "揉柔肉蹂" },
      { "ru", "乳儒入如蠕褥辱" },
      { "ruan", "软" },
      { "rui", "瑞蕊锐" },
      { "run", "润闰" },
      { "ruo", "弱若" },
      { "sa", "撒洒萨飒" },
      { "sai", "塞腮赛" },
      { "san", "三伞叁散" },
      { "sang", "丧嗓桑" },
      { "sao", "嫂扫搔臊骚" },
      { "se", "涩瑟色" },
      { "sen", "森" },
      { "seng", "僧" },
      { "sha", "傻刹厦啥杀沙煞砂纱霎" },
      { "shai", "晒筛" },
      { "shan", "删善山扇擅杉珊膳苫衫赡闪陕" },
      { "shang", "上伤商尚晌裳赏" },
      { "shao", "勺哨少捎梢烧稍绍芍" },
      { "she", "奢射摄涉社舌舍蛇设赊赦" },
      { "shen", "什伸呻婶审慎沈深渗甚申神绅肾身" },
      { "sheng", "剩升圣声牲生甥盛省笙绳胜" },
      { "shi", "世事似使侍势匙十史嗜士失始实室尸屎市师式恃拭拾施时是柿氏湿狮矢石示虱蚀视誓识试诗适逝释食饰驶" },
      { "shou", "兽受售守寿手授收瘦首" },
      { "shu", "书叔墅属庶恕抒数暑曙术束枢树梳殊淑漱熟疏秫竖署舒蔬薯蜀赎输述黍鼠" },
      { "shua", "刷耍" },
      { "shuai", "帅摔甩蟀衰" },
      { "shuan", "拴栓涮" },
      { "shuang", "双爽霜" },
      { "shui", "水睡税谁" },
      { "shun", "吮瞬顺" },
      { "shuo", "烁硕说" },
      { "si", "丝司嘶四寺思撕斯死私肆饲" },
      { "song", "宋松耸讼诵送颂" },
      { "sou", "嗽搜艘" },
      { "su", "俗塑宿溯粟素肃苏诉速酥" },
      { "suan", "算蒜酸" },
      { "sui", "岁碎祟穗虽遂随隧髓" },
      { "sun", "孙损笋" },
      { "suo", "唆嗦所梭琐索缩锁" },
      { "ta", "他塌塔她它踏蹋" },
      { "tai", "台太态抬汰泰胎苔" },
      { "tan", "叹坛坦探摊昙檀毯滩潭炭痰瘫碳袒谈谭贪" },
      { "tang", "倘唐堂塘搪棠汤淌烫糖膛趟躺" },
      { "tao", "套掏桃涛淘滔萄讨逃陶" },
      { "te", "特" },
      { "teng", "疼腾藤誊" },
      { "ti", "体剃剔啼屉惕提替梯涕踢蹄题" },
      { "tian", "填天恬添甜田舔" },
      { "tiao", "挑条笤跳" },
      { "tie", "帖贴铁" },
      { "ting", "亭停厅听庭廷挺艇蜓" },
      { "tong", "同彤捅桐桶痛瞳童筒统通铜" },
      { "tou", "偷头投透" },
      { "tu", "兔凸吐图土屠徒涂秃突途" },
      { "tuan", "团" },
      { "tui", "推腿蜕褪退颓" },
      { "tun", "吞屯臀" },
      { "tuo", "唾妥托拓拖椭脱驮驼鸵" },
      { "wa", "娃挖洼瓦蛙袜" },
      { "wai", "外歪" },
      { "wan", "万丸婉完宛弯惋挽晚湾玩碗腕豌顽" },
      { "wang", "亡妄往忘旺望枉汪王网" },
      { "wei", "为伟伪位偎卫危味唯喂围委威尉尾巍微慰未桅猬畏纬维胃苇萎蔚薇谓违魏" },
      { "wen", "吻文温瘟稳紊纹蚊问闻" },
      { "weng", "嗡瓮翁" },
      { "wo", "卧我握沃涡窝蜗" },
      { "wu", "乌五伍侮务勿午吴呜坞屋巫悟捂无晤梧武污物舞芜蜈诬误雾鹉" },
      { "xi", "习吸喜夕媳嬉希席徙息悉惜戏昔晰析洗溪熄熙牺犀稀系细膝蟋袭西铣锡隙" },
      { "xia", "下侠匣吓夏峡暇狭瞎虾辖霞" },
      { "xian", "仙先县咸嫌宪弦掀显涎献现纤线羡腺舷衔贤锨闲限险陷馅鲜" },
      { "xiang", "乡享像厢向响巷想橡湘相祥箱翔详象镶项香" },
      { "xiao", "哮啸嚣孝宵小效晓校消淆硝笑箫肖萧销" },
      { "xie", "些写协卸屑懈挟携斜械楔歇泄泻胁蝎蟹谐谢邪鞋" },
      { "xin", "信心新欣芯薪衅辛锌" },
      { "xing", "兴刑型姓幸形性星杏猩腥行邢醒" },
      { "xiong", "兄凶汹熊胸雄" },
      { "xiu", "休修嗅朽秀绣羞袖锈" },
      { "xu", "叙吁婿序徐恤旭絮绪续蓄虚许酗需须" },
      { "xuan", "喧宣悬旋漩炫玄匈癣轩选" },
      { "xue", "削学穴薛血雪靴" },
      { "xun", "勋寻巡循旬殉汛熏训讯询迅逊驯" },
      { "ya", "亚压呀哑崖押涯牙芽蚜衙讶轧雅鸦鸭" },
      { "yan", "严厌咽唁堰奄宴岩延掩檐沿淹演炎烟焰燕盐眼研砚腌艳蜒衍言谚阎雁颜验" },
      { "yang", "仰养央扬杨样殃氧洋漾痒秧羊阳鸯" },
      { "yao", "吆咬夭妖姚摇窑耀肴腰舀药要谣遥邀钥" },
      { "ye", "业也冶叶夜掖椰液爷腋谒野页" },
      { "yi", "一义乙亦亿以仪伊依倚医壹夷奕姨宜屹已异役忆意抑揖易椅毅溢疑疫益移绎翼肄胰艺蚁衣议译谊逸遗邑" },
      { "yin", "印吟因姻引殷淫瘾茵蚓银阴隐音饮" },
      { "ying", "婴应影映樱盈硬缨英荧莹莺萤营蝇赢迎颖鹦鹰" },
      { "yo", "哟" },
      { "yong", "佣勇咏庸拥永泳涌用蛹踊" },
      { "you", "优佑又友右尤幼幽忧悠有油游犹由诱邮" },
      { "yu", "与予于余喻域娱宇寓屿御愈愉愚榆欲浴淤渔狱玉羽育舆芋裕誉语豫迂逾遇郁隅雨预鱼" },
      { "yuan", "元冤原员园圆怨愿援渊源猿缘袁辕远院鸳" },
      { "yue", "岳悦月粤约越跃阅" },
      { "yun", "云允匀孕晕耘蕴运酝陨韵" },
      { "za", "杂砸" },
      { "zai", "仔再在宰栽灾载" },
      { "zan", "咱攒暂赞" },
      { "zang", "脏葬赃" },
      { "zao", "凿噪早枣澡灶燥皂糟藻蚤躁造遭" },
      { "ze", "则择泽责" },
      { "zei", "贼" },
      { "zen", "怎" },
      { "zeng", "增憎赠" },
      { "zha", "乍喳扎栅榨渣炸眨诈铡闸" },
      { "zhai", "债宅寨摘斋窄" },
      { "zhan", "占展崭战斩栈毡沾盏瞻站粘绽蘸" },
      { "zhang", "丈仗帐张彰掌杖樟涨章胀账长障" },
      { "zhao", "兆召找招昭沼照爪罩赵" },
      { "zhe", "哲折浙着者蔗辙这遮" },
      { "zhen", "侦振斟枕榛珍疹真诊贞针镇阵震" },
      { "zheng", "争征怔拯挣政整正狰症睁筝蒸证郑" },
      { "zhi", "之侄值制只吱址帜志执指挚掷支旨智枝植止殖汁治滞直知秩稚窒纸织置职肢脂至致芝蜘质趾" },
      { "zhong", "中仲众忠盅种终肿衷重钟" },
      { "zhou", "周咒宙州帚昼洲皱粥肘舟轴骤" },
      { "zhu", "主住助嘱拄朱柱株注烛煮猪珠祝竹筑著蛀蛛诸贮逐铸驻" },
      { "zhua", "抓" },
      { "zhuan", "专撰砖赚转" },
      { "zhuang", "壮妆庄撞桩状装" },
      { "zhui", "坠缀赘追锥" },
      { "zhun", "准谆" },
      { "zhuo", "卓啄拙捉桌浊灼茁酌" },
      { "zi", "咨姊姿子字滋滓籽紫自资" },
      { "zong", "宗总棕纵综踪" },
      { "zou", "奏揍走" },
      { "zu", "卒族祖租组诅足阻" },
      { "zuan", "钻" },
      { "zui", "嘴最罪醉" },
      { "zun", "尊遵" },
      { "zuo", "作做坐左座昨琢" },
    {NULL,NULL}
};


#endif

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
lv_obj_t * lv_ime_pinyin_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(MY_CLASS, parent);
    lv_obj_class_init_obj(obj);
    return obj;
}

/*=====================
 * Setter functions
 *====================*/

void lv_ime_pinyin_set_keyboard(lv_obj_t * obj, lv_obj_t * kb)
{
    if(kb) {
        LV_ASSERT_OBJ(kb, &lv_keyboard_class);
    }

    LV_ASSERT_OBJ(obj, MY_CLASS);
    lv_ime_pinyin_t * pinyin_ime = (lv_ime_pinyin_t *)obj;

    pinyin_ime->kb = kb;
    lv_obj_set_parent(obj, lv_obj_get_parent(kb));
    lv_obj_set_parent(pinyin_ime->cand_panel, lv_obj_get_parent(kb));
    lv_obj_add_event_cb(pinyin_ime->kb, lv_ime_pinyin_kb_event, LV_EVENT_VALUE_CHANGED, obj);
    lv_obj_align_to(pinyin_ime->cand_panel, pinyin_ime->kb, LV_ALIGN_OUT_TOP_MID, 0, 0);
}

void lv_ime_pinyin_set_dict(lv_obj_t * obj, lv_pinyin_dict_t * dict)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);

    init_pinyin_dict(obj, dict);
}

void lv_ime_pinyin_set_mode(lv_obj_t * obj, lv_ime_pinyin_mode_t mode)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);
    lv_ime_pinyin_t * pinyin_ime = (lv_ime_pinyin_t *)obj;

    LV_ASSERT_OBJ(pinyin_ime->kb, &lv_keyboard_class);

    pinyin_ime->mode = mode;

#if LV_IME_PINYIN_USE_K9_MODE
    if(pinyin_ime->mode == LV_IME_PINYIN_MODE_K9) {
        pinyin_k9_init_data(obj);
        lv_keyboard_set_map(pinyin_ime->kb, LV_KEYBOARD_MODE_USER_1, (const char **)lv_btnm_def_pinyin_k9_map,
                            default_kb_ctrl_k9_map);
        lv_keyboard_set_mode(pinyin_ime->kb, LV_KEYBOARD_MODE_USER_1);
    }
#endif
}

/*=====================
 * Getter functions
 *====================*/

lv_obj_t * lv_ime_pinyin_get_kb(lv_obj_t * obj)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);

    lv_ime_pinyin_t * pinyin_ime = (lv_ime_pinyin_t *)obj;

    return pinyin_ime->kb;
}

lv_obj_t * lv_ime_pinyin_get_cand_panel(lv_obj_t * obj)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);

    lv_ime_pinyin_t * pinyin_ime = (lv_ime_pinyin_t *)obj;

    return pinyin_ime->cand_panel;
}

const lv_pinyin_dict_t * lv_ime_pinyin_get_dict(lv_obj_t * obj)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);

    lv_ime_pinyin_t * pinyin_ime = (lv_ime_pinyin_t *)obj;

    return pinyin_ime->dict;
}

/*=====================
 * Other functions
 *====================*/

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void lv_ime_pinyin_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    lv_ime_pinyin_t * pinyin_ime = (lv_ime_pinyin_t *)obj;

    uint16_t py_str_i = 0;
    uint16_t btnm_i = 0;
    for(btnm_i = 0; btnm_i < (LV_IME_PINYIN_CAND_TEXT_NUM + 3); btnm_i++) {
        if(btnm_i == 0) {
            lv_btnm_def_pinyin_sel_map[btnm_i] = "<";
        }
        else if(btnm_i == (LV_IME_PINYIN_CAND_TEXT_NUM + 1)) {
            lv_btnm_def_pinyin_sel_map[btnm_i] = ">";
        }
        else if(btnm_i == (LV_IME_PINYIN_CAND_TEXT_NUM + 2)) {
            lv_btnm_def_pinyin_sel_map[btnm_i] = "";
        }
        else {
            lv_pinyin_cand_str[py_str_i][0] = ' ';
            lv_btnm_def_pinyin_sel_map[btnm_i] = lv_pinyin_cand_str[py_str_i];
            py_str_i++;
        }
    }

    pinyin_ime->mode = LV_IME_PINYIN_MODE_K26;
    pinyin_ime->py_page = 0;
    pinyin_ime->ta_count = 0;
    pinyin_ime->cand_num = 0;
    lv_memzero(pinyin_ime->input_char, sizeof(pinyin_ime->input_char));
    lv_memzero(pinyin_ime->py_num, sizeof(pinyin_ime->py_num));
    lv_memzero(pinyin_ime->py_pos, sizeof(pinyin_ime->py_pos));

    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);

#if LV_IME_PINYIN_USE_DEFAULT_DICT
    init_pinyin_dict(obj, lv_ime_pinyin_def_dict);
#endif

    /* Init pinyin_ime->cand_panel */
    pinyin_ime->cand_panel = lv_buttonmatrix_create(lv_obj_get_parent(obj));
    lv_buttonmatrix_set_map(pinyin_ime->cand_panel, (const char **)lv_btnm_def_pinyin_sel_map);
    lv_obj_set_size(pinyin_ime->cand_panel, LV_PCT(100), LV_PCT(5));
    lv_obj_add_flag(pinyin_ime->cand_panel, LV_OBJ_FLAG_HIDDEN);

    lv_buttonmatrix_set_one_checked(pinyin_ime->cand_panel, true);
    lv_obj_remove_flag(pinyin_ime->cand_panel, LV_OBJ_FLAG_CLICK_FOCUSABLE);

    /* Set cand_panel style*/
    // Default style
    lv_obj_set_style_bg_opa(pinyin_ime->cand_panel, LV_OPA_0, 0);
    lv_obj_set_style_border_width(pinyin_ime->cand_panel, 0, 0);
    lv_obj_set_style_pad_all(pinyin_ime->cand_panel, 8, 0);
    lv_obj_set_style_pad_gap(pinyin_ime->cand_panel, 0, 0);
    lv_obj_set_style_radius(pinyin_ime->cand_panel, 0, 0);
    lv_obj_set_style_pad_gap(pinyin_ime->cand_panel, 0, 0);
    lv_obj_set_style_base_dir(pinyin_ime->cand_panel, LV_BASE_DIR_LTR, 0);

    // LV_PART_ITEMS style
    lv_obj_set_style_radius(pinyin_ime->cand_panel, 12, LV_PART_ITEMS);
    lv_obj_set_style_bg_color(pinyin_ime->cand_panel, lv_color_white(), LV_PART_ITEMS);
    lv_obj_set_style_bg_opa(pinyin_ime->cand_panel, LV_OPA_0, LV_PART_ITEMS);
    lv_obj_set_style_shadow_opa(pinyin_ime->cand_panel, LV_OPA_0, LV_PART_ITEMS);

    // LV_PART_ITEMS | LV_STATE_PRESSED style
    lv_obj_set_style_bg_opa(pinyin_ime->cand_panel, LV_OPA_COVER, LV_PART_ITEMS | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(pinyin_ime->cand_panel, lv_color_white(), LV_PART_ITEMS | LV_STATE_PRESSED);

    /* event handler */
    lv_obj_add_event_cb(pinyin_ime->cand_panel, lv_ime_pinyin_cand_panel_event, LV_EVENT_VALUE_CHANGED, obj);
    lv_obj_add_event_cb(obj, lv_ime_pinyin_style_change_event, LV_EVENT_STYLE_CHANGED, NULL);

#if LV_IME_PINYIN_USE_K9_MODE
    pinyin_ime->k9_input_str_len = 0;
    pinyin_ime->k9_py_ll_pos = 0;
    pinyin_ime->k9_legal_py_count = 0;
    lv_memzero(pinyin_ime->k9_input_str, LV_IME_PINYIN_K9_MAX_INPUT);

    pinyin_k9_init_data(obj);

    lv_ll_init(&(pinyin_ime->k9_legal_py_ll), sizeof(ime_pinyin_k9_py_str_t));
#endif
}

static void lv_ime_pinyin_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    lv_ime_pinyin_t * pinyin_ime = (lv_ime_pinyin_t *)obj;

    if(lv_obj_is_valid(pinyin_ime->kb))
        lv_obj_delete(pinyin_ime->kb);

    if(lv_obj_is_valid(pinyin_ime->cand_panel))
        lv_obj_delete(pinyin_ime->cand_panel);
}

static void lv_ime_pinyin_kb_event(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * kb = lv_event_get_current_target(e);
    lv_obj_t * obj = lv_event_get_user_data(e);

    lv_ime_pinyin_t * pinyin_ime = (lv_ime_pinyin_t *)obj;

#if LV_IME_PINYIN_USE_K9_MODE
    static const char * k9_py_map[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
#endif

    if(code == LV_EVENT_VALUE_CHANGED) {
        uint16_t btn_id  = lv_buttonmatrix_get_selected_button(kb);
        if(btn_id == LV_BUTTONMATRIX_BUTTON_NONE) return;

        const char * txt = lv_buttonmatrix_get_button_text(kb, lv_buttonmatrix_get_selected_button(kb));
        if(txt == NULL) return;

        lv_obj_t * ta = lv_keyboard_get_textarea(pinyin_ime->kb);

#if LV_IME_PINYIN_USE_K9_MODE
        if(pinyin_ime->mode == LV_IME_PINYIN_MODE_K9) {

            uint16_t tmp_button_str_len = lv_strlen(pinyin_ime->input_char);
            if((btn_id >= 16) && (tmp_button_str_len > 0) && (btn_id < (16 + LV_IME_PINYIN_K9_CAND_TEXT_NUM))) {
                lv_memzero(pinyin_ime->input_char, sizeof(pinyin_ime->input_char));
                lv_strcat(pinyin_ime->input_char, txt);
                pinyin_input_proc(obj);

                for(int index = 0; index < (pinyin_ime->ta_count + tmp_button_str_len); index++) {
                    lv_textarea_delete_char(ta);
                }

                pinyin_ime->ta_count = tmp_button_str_len;
                pinyin_ime->k9_input_str_len = tmp_button_str_len;
                lv_textarea_add_text(ta, pinyin_ime->input_char);

                return;
            }
        }
#endif

        if(lv_strcmp(txt, "Enter") == 0 || lv_strcmp(txt, LV_SYMBOL_NEW_LINE) == 0) {
            pinyin_ime_clear_data(obj);
            lv_obj_add_flag(pinyin_ime->cand_panel, LV_OBJ_FLAG_HIDDEN);
        }
        else if(lv_strcmp(txt, LV_SYMBOL_BACKSPACE) == 0) {
            // del input char
            if(pinyin_ime->ta_count > 0) {
                if(pinyin_ime->mode == LV_IME_PINYIN_MODE_K26)
                    pinyin_ime->input_char[pinyin_ime->ta_count - 1] = '\0';
#if LV_IME_PINYIN_USE_K9_MODE
                else
                    pinyin_ime->k9_input_str[pinyin_ime->ta_count - 1] = '\0';
#endif

                pinyin_ime->ta_count--;
                if(pinyin_ime->ta_count <= 0) {
                    pinyin_ime_clear_data(obj);
                    lv_obj_add_flag(pinyin_ime->cand_panel, LV_OBJ_FLAG_HIDDEN);
                }
                else if(pinyin_ime->mode == LV_IME_PINYIN_MODE_K26) {
                    pinyin_input_proc(obj);
                }
#if LV_IME_PINYIN_USE_K9_MODE
                else if(pinyin_ime->mode == LV_IME_PINYIN_MODE_K9) {
                    pinyin_ime->k9_input_str_len = lv_strlen(pinyin_ime->input_char) - 1;
                    pinyin_k9_get_legal_py(obj, pinyin_ime->k9_input_str, k9_py_map);
                    pinyin_k9_fill_cand(obj);
                    pinyin_input_proc(obj);
                    pinyin_ime->ta_count--;
                }
#endif
            }
        }
        else if((lv_strcmp(txt, "ABC") == 0) || (lv_strcmp(txt, "abc") == 0) || (lv_strcmp(txt, "1#") == 0) ||
                (lv_strcmp(txt, LV_SYMBOL_OK) == 0)) {
            pinyin_ime_clear_data(obj);
            return;
        }
        else if(lv_strcmp(txt, "123") == 0) {
            for(uint16_t i = 0; i < lv_strlen(txt); i++)
                lv_textarea_delete_char(ta);

            pinyin_ime_clear_data(obj);
            lv_textarea_set_cursor_pos(ta, LV_TEXTAREA_CURSOR_LAST);
            lv_ime_pinyin_set_mode(obj, LV_IME_PINYIN_MODE_K9_NUMBER);
            lv_keyboard_set_mode(kb, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_flag(pinyin_ime->cand_panel, LV_OBJ_FLAG_HIDDEN);
        }
        else if(lv_strcmp(txt, LV_SYMBOL_KEYBOARD) == 0) {
            if(pinyin_ime->mode == LV_IME_PINYIN_MODE_K26) {
                lv_ime_pinyin_set_mode(obj, LV_IME_PINYIN_MODE_K9);
            }
            else if(pinyin_ime->mode == LV_IME_PINYIN_MODE_K9) {
                lv_ime_pinyin_set_mode(obj, LV_IME_PINYIN_MODE_K26);
                lv_keyboard_set_mode(pinyin_ime->kb, LV_KEYBOARD_MODE_TEXT_LOWER);
            }
            else if(pinyin_ime->mode == LV_IME_PINYIN_MODE_K9_NUMBER) {
                lv_ime_pinyin_set_mode(obj, LV_IME_PINYIN_MODE_K9);
            }
            pinyin_ime_clear_data(obj);
        }
        else if((pinyin_ime->mode == LV_IME_PINYIN_MODE_K26) && ((txt[0] >= 'a' && txt[0] <= 'z') || (txt[0] >= 'A' &&
                                                                                                      txt[0] <= 'Z'))) {
            uint16_t len = lv_strlen(pinyin_ime->input_char);
            lv_snprintf(pinyin_ime->input_char + len, sizeof(pinyin_ime->input_char) - len, "%s", txt);
            pinyin_input_proc(obj);
            pinyin_ime->ta_count++;
        }
#if LV_IME_PINYIN_USE_K9_MODE
        else if((pinyin_ime->mode == LV_IME_PINYIN_MODE_K9) && (txt[0] >= 'a' && txt[0] <= 'z')) {
            for(uint16_t i = 0; i < 8; i++) {
                if((lv_strcmp(txt, k9_py_map[i]) == 0) || (lv_strcmp(txt, "abc ") == 0)) {
                    if(lv_strcmp(txt, "abc ") == 0)    pinyin_ime->k9_input_str_len += lv_strlen(k9_py_map[i]) + 1;
                    else                            pinyin_ime->k9_input_str_len += lv_strlen(k9_py_map[i]);
                    pinyin_ime->k9_input_str[pinyin_ime->ta_count] = 50 + i;
                    pinyin_ime->k9_input_str[pinyin_ime->ta_count + 1] = '\0';

                    break;
                }
            }
            pinyin_k9_get_legal_py(obj, pinyin_ime->k9_input_str, k9_py_map);
            pinyin_k9_fill_cand(obj);
            pinyin_input_proc(obj);
        }
        else if(lv_strcmp(txt, LV_SYMBOL_LEFT) == 0) {
            pinyin_k9_cand_page_proc(obj, 0);
        }
        else if(lv_strcmp(txt, LV_SYMBOL_RIGHT) == 0) {
            pinyin_k9_cand_page_proc(obj, 1);
        }
#endif
    }
}

static void lv_ime_pinyin_cand_panel_event(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * cand_panel = lv_event_get_current_target(e);
    lv_obj_t * obj = (lv_obj_t *)lv_event_get_user_data(e);

    lv_ime_pinyin_t * pinyin_ime = (lv_ime_pinyin_t *)obj;

    if(code == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t * ta = lv_keyboard_get_textarea(pinyin_ime->kb);
        if(ta == NULL) return;

        uint32_t id = lv_buttonmatrix_get_selected_button(cand_panel);
        if(id == LV_BUTTONMATRIX_BUTTON_NONE) {
            return;
        }
        else if(id == 0) {
            pinyin_page_proc(obj, 0);
            return;
        }
        else if(id == (LV_IME_PINYIN_CAND_TEXT_NUM + 1)) {
            pinyin_page_proc(obj, 1);
            return;
        }

        const char * txt = lv_buttonmatrix_get_button_text(cand_panel, id);
        uint16_t index = 0;
        for(index = 0; index < pinyin_ime->ta_count; index++)
            lv_textarea_delete_char(ta);

        lv_textarea_add_text(ta, txt);

        pinyin_ime_clear_data(obj);
    }
}

static void pinyin_input_proc(lv_obj_t * obj)
{
    lv_ime_pinyin_t * pinyin_ime = (lv_ime_pinyin_t *)obj;

    pinyin_ime->cand_str = pinyin_search_matching(obj, pinyin_ime->input_char, &pinyin_ime->cand_num);
    if(pinyin_ime->cand_str == NULL) {
        return;
    }

    pinyin_ime->py_page = 0;

    for(uint8_t i = 0; i < LV_IME_PINYIN_CAND_TEXT_NUM; i++) {
        lv_memset(lv_pinyin_cand_str[i], 0x00, sizeof(lv_pinyin_cand_str[i]));
        lv_pinyin_cand_str[i][0] = ' ';
    }

    // fill buf
    for(uint8_t i = 0; (i < pinyin_ime->cand_num && i < LV_IME_PINYIN_CAND_TEXT_NUM); i++) {
        for(uint8_t j = 0; j < 3; j++) {
            lv_pinyin_cand_str[i][j] = pinyin_ime->cand_str[i * 3 + j];
        }
    }

    lv_obj_remove_flag(pinyin_ime->cand_panel, LV_OBJ_FLAG_HIDDEN);
}

static void pinyin_page_proc(lv_obj_t * obj, uint16_t dir)
{
    lv_ime_pinyin_t * pinyin_ime = (lv_ime_pinyin_t *)obj;
    uint16_t page_num = pinyin_ime->cand_num / LV_IME_PINYIN_CAND_TEXT_NUM;
    uint16_t remainder = pinyin_ime->cand_num % LV_IME_PINYIN_CAND_TEXT_NUM;

    if(!pinyin_ime->cand_str) return;

    if(dir == 0) {
        if(pinyin_ime->py_page) {
            pinyin_ime->py_page--;
        }
    }
    else {
        if(remainder == 0) {
            page_num -= 1;
        }
        if(pinyin_ime->py_page < page_num) {
            pinyin_ime->py_page++;
        }
        else return;
    }

    for(uint8_t i = 0; i < LV_IME_PINYIN_CAND_TEXT_NUM; i++) {
        lv_memset(lv_pinyin_cand_str[i], 0x00, sizeof(lv_pinyin_cand_str[i]));
        lv_pinyin_cand_str[i][0] = ' ';
    }

    // fill buf
    uint16_t offset = pinyin_ime->py_page * (3 * LV_IME_PINYIN_CAND_TEXT_NUM);
    for(uint8_t i = 0; (i < pinyin_ime->cand_num && i < LV_IME_PINYIN_CAND_TEXT_NUM); i++) {
        if((remainder > 0) && (pinyin_ime->py_page == page_num)) {
            if(i >= remainder)
                break;
        }
        for(uint8_t j = 0; j < 3; j++) {
            lv_pinyin_cand_str[i][j] = pinyin_ime->cand_str[offset + (i * 3) + j];
        }
    }
}

static void lv_ime_pinyin_style_change_event(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_current_target(e);

    lv_ime_pinyin_t * pinyin_ime = (lv_ime_pinyin_t *)obj;

    if(code == LV_EVENT_STYLE_CHANGED) {
        const lv_font_t * font = lv_obj_get_style_text_font(obj, LV_PART_MAIN);
        lv_obj_set_style_text_font(pinyin_ime->cand_panel, font, 0);
    }
}

static void init_pinyin_dict(lv_obj_t * obj, const lv_pinyin_dict_t * dict)
{
    lv_ime_pinyin_t * pinyin_ime = (lv_ime_pinyin_t *)obj;

    char headletter = 'a';
    uint16_t offset_sum = 0;
    uint16_t offset_count = 0;
    uint16_t letter_calc = 0;

    pinyin_ime->dict = dict;

    for(uint16_t i = 0; ; i++) {
        if((NULL == (dict[i].py)) || (NULL == (dict[i].py_mb))) {
            headletter = dict[i - 1].py[0];
            letter_calc = headletter - 'a';
            pinyin_ime->py_num[letter_calc] = offset_count;
            break;
        }

        if(headletter == (dict[i].py[0])) {
            offset_count++;
        }
        else {
            headletter = dict[i].py[0];
            pinyin_ime->py_num[letter_calc] = offset_count;
            letter_calc = headletter - 'a';
            offset_sum += offset_count;
            pinyin_ime->py_pos[letter_calc] = offset_sum;

            offset_count = 1;
        }
    }
}

static char * pinyin_search_matching(lv_obj_t * obj, char * py_str, uint16_t * cand_num)
{
    lv_ime_pinyin_t * pinyin_ime = (lv_ime_pinyin_t *)obj;

    const lv_pinyin_dict_t * cpHZ;
    uint8_t index, len = 0, offset;
    volatile uint8_t count = 0;

    if(*py_str == '\0')    return NULL;
    if(*py_str == 'i')     return NULL;
    if(*py_str == 'u')     return NULL;
    if(*py_str == 'v')     return NULL;
    if(*py_str == ' ')     return NULL;

    offset = py_str[0] - 'a';
    len = lv_strlen(py_str);

    cpHZ  = &pinyin_ime->dict[pinyin_ime->py_pos[offset]];
    count = pinyin_ime->py_num[offset];

    while(count--) {
        for(index = 0; index < len; index++) {
            if(*(py_str + index) != *((cpHZ->py) + index)) {
                break;
            }
        }

        // perfect match
        if(len == 1 || index == len) {
            // The Chinese character in UTF-8 encoding format is 3 bytes
            * cand_num = lv_strlen((const char *)(cpHZ->py_mb)) / 3;
            return (char *)(cpHZ->py_mb);
        }
        cpHZ++;
    }
    return NULL;
}

static void pinyin_ime_clear_data(lv_obj_t * obj)
{
    lv_ime_pinyin_t * pinyin_ime = (lv_ime_pinyin_t *)obj;

#if LV_IME_PINYIN_USE_K9_MODE
    if(pinyin_ime->mode == LV_IME_PINYIN_MODE_K9) {
        pinyin_ime->k9_input_str_len = 0;
        pinyin_ime->k9_py_ll_pos = 0;
        pinyin_ime->k9_legal_py_count = 0;
        lv_memzero(pinyin_ime->k9_input_str,  LV_IME_PINYIN_K9_MAX_INPUT);
        lv_memzero(lv_pinyin_k9_cand_str, sizeof(lv_pinyin_k9_cand_str));
        for(uint8_t i = 0; i < LV_IME_PINYIN_CAND_TEXT_NUM; i++) {
            lv_strcpy(lv_pinyin_k9_cand_str[i], " ");
        }
        lv_strcpy(lv_pinyin_k9_cand_str[LV_IME_PINYIN_K9_CAND_TEXT_NUM], LV_SYMBOL_RIGHT"\0");
        lv_strcpy(lv_pinyin_k9_cand_str[LV_IME_PINYIN_K9_CAND_TEXT_NUM + 1], "\0");
        lv_buttonmatrix_set_map(pinyin_ime->kb, (const char **)lv_btnm_def_pinyin_k9_map);
    }
#endif

    pinyin_ime->ta_count = 0;
    for(uint8_t i = 0; i < LV_IME_PINYIN_CAND_TEXT_NUM; i++) {
        lv_memset(lv_pinyin_cand_str[i], 0x00, sizeof(lv_pinyin_cand_str[i]));
        lv_pinyin_cand_str[i][0] = ' ';
    }
    lv_memzero(pinyin_ime->input_char, sizeof(pinyin_ime->input_char));

    lv_obj_add_flag(pinyin_ime->cand_panel, LV_OBJ_FLAG_HIDDEN);
}

#if LV_IME_PINYIN_USE_K9_MODE
static void pinyin_k9_init_data(lv_obj_t * obj)
{
    LV_UNUSED(obj);

    uint16_t py_str_i = 0;
    uint16_t btnm_i = 0;
    for(btnm_i = 19; btnm_i < (LV_IME_PINYIN_K9_CAND_TEXT_NUM + 21); btnm_i++) {
        if(py_str_i == LV_IME_PINYIN_K9_CAND_TEXT_NUM) {
            lv_strcpy(lv_pinyin_k9_cand_str[py_str_i], LV_SYMBOL_RIGHT"\0");
        }
        else if(py_str_i == LV_IME_PINYIN_K9_CAND_TEXT_NUM + 1) {
            lv_strcpy(lv_pinyin_k9_cand_str[py_str_i], "\0");
        }
        else {
            lv_strcpy(lv_pinyin_k9_cand_str[py_str_i], " \0");
        }

        lv_btnm_def_pinyin_k9_map[btnm_i] = lv_pinyin_k9_cand_str[py_str_i];
        py_str_i++;
    }

    default_kb_ctrl_k9_map[0]  = LV_BUTTONMATRIX_CTRL_CHECKED | 1;
    default_kb_ctrl_k9_map[1]  = LV_BUTTONMATRIX_CTRL_NO_REPEAT | LV_BUTTONMATRIX_CTRL_CLICK_TRIG | 1;
    default_kb_ctrl_k9_map[4]  = LV_BUTTONMATRIX_CTRL_CHECKED | 1;
    default_kb_ctrl_k9_map[5]  = LV_BUTTONMATRIX_CTRL_CHECKED | 1;
    default_kb_ctrl_k9_map[9]  = LV_KEYBOARD_CTRL_BUTTON_FLAGS | 1;
    default_kb_ctrl_k9_map[10] = LV_BUTTONMATRIX_CTRL_CHECKED | 1;
    default_kb_ctrl_k9_map[14] = LV_BUTTONMATRIX_CTRL_CHECKED | 1;
    default_kb_ctrl_k9_map[15] = LV_BUTTONMATRIX_CTRL_CHECKED | 1;
    default_kb_ctrl_k9_map[LV_IME_PINYIN_K9_CAND_TEXT_NUM + 16] = LV_BUTTONMATRIX_CTRL_CHECKED | 1;
}

static void pinyin_k9_get_legal_py(lv_obj_t * obj, char * k9_input, const char * py9_map[])
{
    lv_ime_pinyin_t * pinyin_ime = (lv_ime_pinyin_t *)obj;

    uint16_t len = lv_strlen(k9_input);

    if((len == 0) || (len >= LV_IME_PINYIN_K9_MAX_INPUT)) {
        return;
    }

    char py_comp[LV_IME_PINYIN_K9_MAX_INPUT] = {0};
    int mark[LV_IME_PINYIN_K9_MAX_INPUT] = {0};
    int index = 0;
    int flag = 0;
    uint16_t count = 0;

    uint32_t ll_len = 0;
    ime_pinyin_k9_py_str_t * ll_index = NULL;

    ll_len = lv_ll_get_len(&pinyin_ime->k9_legal_py_ll);
    ll_index = lv_ll_get_head(&pinyin_ime->k9_legal_py_ll);

    while(index != -1) {
        if(index == len) {
            if(pinyin_k9_is_valid_py(obj, py_comp)) {
                if((count >= ll_len) || (ll_len == 0)) {
                    ll_index = lv_ll_ins_tail(&pinyin_ime->k9_legal_py_ll);
                    lv_strcpy(ll_index->py_str, py_comp);
                }
                else if((count < ll_len)) {
                    lv_strcpy(ll_index->py_str, py_comp);
                    ll_index = lv_ll_get_next(&pinyin_ime->k9_legal_py_ll, ll_index);
                }
                count++;
            }
            index--;
        }
        else {
            flag = mark[index];
            if((size_t)flag < lv_strlen(py9_map[k9_input[index] - '2'])) {
                py_comp[index] = py9_map[k9_input[index] - '2'][flag];
                mark[index] = mark[index] + 1;
                index++;
            }
            else {
                mark[index] = 0;
                index--;
            }
        }
    }

    if(count > 0) {
        pinyin_ime->ta_count++;
        pinyin_ime->k9_legal_py_count = count;
    }
}

/*true: visible; false: not visible*/
static bool pinyin_k9_is_valid_py(lv_obj_t * obj, char * py_str)
{
    lv_ime_pinyin_t * pinyin_ime = (lv_ime_pinyin_t *)obj;

    const lv_pinyin_dict_t * cpHZ = NULL;
    uint8_t index = 0, len = 0, offset = 0;
    volatile uint8_t count = 0;

    if(*py_str == '\0')    return false;
    if(*py_str == 'i')     return false;
    if(*py_str == 'u')     return false;
    if(*py_str == 'v')     return false;

    offset = py_str[0] - 'a';
    len = lv_strlen(py_str);

    cpHZ  = &pinyin_ime->dict[pinyin_ime->py_pos[offset]];
    count = pinyin_ime->py_num[offset];

    while(count--) {
        for(index = 0; index < len; index++) {
            if(*(py_str + index) != *((cpHZ->py) + index)) {
                break;
            }
        }

        // perfect match
        if(len == 1 || index == len) {
            return true;
        }
        cpHZ++;
    }
    return false;
}

static void pinyin_k9_fill_cand(lv_obj_t * obj)
{
    uint16_t index = 0, tmp_len = 0;
    ime_pinyin_k9_py_str_t * ll_index = NULL;

    lv_ime_pinyin_t * pinyin_ime = (lv_ime_pinyin_t *)obj;

    tmp_len = pinyin_ime->k9_legal_py_count;

    if(tmp_len != cand_len) {
        lv_memzero(lv_pinyin_k9_cand_str, sizeof(lv_pinyin_k9_cand_str));
        lv_strcpy(lv_pinyin_k9_cand_str[LV_IME_PINYIN_K9_CAND_TEXT_NUM], LV_SYMBOL_RIGHT"\0");
        lv_strcpy(lv_pinyin_k9_cand_str[LV_IME_PINYIN_K9_CAND_TEXT_NUM + 1], "\0");
        cand_len = tmp_len;
    }

    ll_index = lv_ll_get_head(&pinyin_ime->k9_legal_py_ll);
    lv_strcpy(pinyin_ime->input_char, ll_index->py_str);

    for(uint8_t i = 0; i < LV_IME_PINYIN_K9_CAND_TEXT_NUM; i++) {
        lv_strcpy(lv_pinyin_k9_cand_str[i], " ");
    }

    while(ll_index) {
        if(index >= LV_IME_PINYIN_K9_CAND_TEXT_NUM)
            break;

        if(index < pinyin_ime->k9_legal_py_count) {
            lv_strcpy(lv_pinyin_k9_cand_str[index], ll_index->py_str);
        }

        ll_index = lv_ll_get_next(&pinyin_ime->k9_legal_py_ll, ll_index); /*Find the next list*/
        index++;
    }
    pinyin_ime->k9_py_ll_pos = index;

    lv_obj_t * ta = lv_keyboard_get_textarea(pinyin_ime->kb);
    for(index = 0; index < pinyin_ime->k9_input_str_len; index++) {
        lv_textarea_delete_char(ta);
    }
    pinyin_ime->k9_input_str_len = lv_strlen(pinyin_ime->input_char);
    lv_textarea_add_text(ta, pinyin_ime->input_char);
}

static void pinyin_k9_cand_page_proc(lv_obj_t * obj, uint16_t dir)
{
    lv_ime_pinyin_t * pinyin_ime = (lv_ime_pinyin_t *)obj;

    lv_obj_t * ta = lv_keyboard_get_textarea(pinyin_ime->kb);
    uint16_t ll_len =  lv_ll_get_len(&pinyin_ime->k9_legal_py_ll);

    if((ll_len > LV_IME_PINYIN_K9_CAND_TEXT_NUM) && (pinyin_ime->k9_legal_py_count > LV_IME_PINYIN_K9_CAND_TEXT_NUM)) {
        ime_pinyin_k9_py_str_t * ll_index = NULL;
        int count = 0;

        ll_index = lv_ll_get_head(&pinyin_ime->k9_legal_py_ll);
        while(ll_index) {
            if(count >= pinyin_ime->k9_py_ll_pos)   break;

            ll_index = lv_ll_get_next(&pinyin_ime->k9_legal_py_ll, ll_index); /*Find the next list*/
            count++;
        }

        if((NULL == ll_index) && (dir == 1))   return;

        lv_memzero(lv_pinyin_k9_cand_str, sizeof(lv_pinyin_k9_cand_str));
        lv_strcpy(lv_pinyin_k9_cand_str[LV_IME_PINYIN_K9_CAND_TEXT_NUM], LV_SYMBOL_RIGHT"\0");
        lv_strcpy(lv_pinyin_k9_cand_str[LV_IME_PINYIN_K9_CAND_TEXT_NUM + 1], "\0");

        // next page
        if(dir == 1) {
            for(uint8_t i = 0; i < LV_IME_PINYIN_K9_CAND_TEXT_NUM; i++) {
                lv_strcpy(lv_pinyin_k9_cand_str[i], " ");
            }

            count = 0;
            while(ll_index) {
                if(count >= (LV_IME_PINYIN_K9_CAND_TEXT_NUM - 1))
                    break;

                lv_strcpy(lv_pinyin_k9_cand_str[count], ll_index->py_str);
                ll_index = lv_ll_get_next(&pinyin_ime->k9_legal_py_ll, ll_index); /*Find the next list*/
                count++;
            }
            pinyin_ime->k9_py_ll_pos += count - 1;

        }
        // previous page
        else {
            for(uint8_t i = 0; i < LV_IME_PINYIN_K9_CAND_TEXT_NUM; i++) {
                lv_strcpy(lv_pinyin_k9_cand_str[i], " ");
            }
            count = LV_IME_PINYIN_K9_CAND_TEXT_NUM - 1;
            ll_index = lv_ll_get_prev(&pinyin_ime->k9_legal_py_ll, ll_index);
            while(ll_index) {
                if(count < 0)  break;

                lv_strcpy(lv_pinyin_k9_cand_str[count], ll_index->py_str);
                ll_index = lv_ll_get_prev(&pinyin_ime->k9_legal_py_ll, ll_index); /*Find the previous list*/
                count--;
            }

            if(pinyin_ime->k9_py_ll_pos > LV_IME_PINYIN_K9_CAND_TEXT_NUM)
                pinyin_ime->k9_py_ll_pos -= 1;
        }

        lv_textarea_set_cursor_pos(ta, LV_TEXTAREA_CURSOR_LAST);
    }
}

#endif  /*LV_IME_PINYIN_USE_K9_MODE*/

#endif  /*LV_USE_IME_PINYIN*/
