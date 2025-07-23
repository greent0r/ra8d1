#include "recipe.h"
#include "cJSON.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ff.h"
#include "FreeRTOS.h"
#include "task.h"
#include "platform.h"
#include "mymalloc.h"
#include "lvgl.h"

recipe_t myrecipe BSP_ALIGN_VARIABLE(64) BSP_PLACE_IN_SECTION(".sdram");
recipe_t recipe_rx BSP_ALIGN_VARIABLE(64) BSP_PLACE_IN_SECTION(".sdram");
char recipe_list[13][64] BSP_ALIGN_VARIABLE(64) BSP_PLACE_IN_SECTION(".sdram");
result_t result[6];

cJSON* recipe_to_json(recipe_t *recipe)
{
    if (!recipe) {
        return NULL;
    }

    cJSON *root = cJSON_CreateObject();
    if (!root) {
        // 内存分配失败
        printf("Failed to create root JSON object\n");
        return NULL;
    }

    // 添加基础字段（添加空指针保护）
    if (recipe->name[0] != '\0') {
        cJSON_AddItemToObject(root, "name", cJSON_CreateString(recipe->name));
    } else {
        cJSON_AddItemToObject(root, "name", cJSON_CreateString(""));
    }

    if (recipe->description[0] != '\0') {
        cJSON_AddItemToObject(root, "description", cJSON_CreateString(recipe->description));
    } else {
        cJSON_AddItemToObject(root, "description", cJSON_CreateString(""));
    }

    if (recipe->category[0] != '\0') {
        cJSON_AddItemToObject(root, "category", cJSON_CreateString(recipe->category));
    } else {
        cJSON_AddItemToObject(root, "category", cJSON_CreateString(""));
    }

    cJSON_AddItemToObject(root, "difficulty", cJSON_CreateNumber(recipe->difficulty));
    cJSON_AddItemToObject(root, "prep_time", cJSON_CreateNumber(recipe->prep_time));
    cJSON_AddItemToObject(root, "cook_time", cJSON_CreateNumber(recipe->cook_time));

    // 食材 ingredients
    cJSON *ingredients = cJSON_CreateArray();
    for (int i = 0; i < recipe->ingredient_count && i < MAX_INGREDIENTS; i++) {
        cJSON *item = cJSON_CreateObject();
        if (!item) continue;

        if (recipe->ingredients[i].name[0] != '\0') {
            cJSON_AddItemToObject(item, "name1", cJSON_CreateString(recipe->ingredients[i].name));
        } else {
            cJSON_AddItemToObject(item, "name1", cJSON_CreateString(""));
        }

        cJSON_AddItemToObject(item, "quantity", cJSON_CreateNumber(recipe->ingredients[i].quantity));

        if (recipe->ingredients[i].unit[0] != '\0') {
            cJSON_AddItemToObject(item, "unit", cJSON_CreateString(recipe->ingredients[i].unit));
        } else {
            cJSON_AddItemToObject(item, "unit", cJSON_CreateString(""));
        }

        cJSON_AddItemToArray(ingredients, item);
    }
    cJSON_AddItemToObject(root, "ingredients", ingredients);

    // 步骤 steps
    cJSON *steps = cJSON_CreateArray();
    for (int i = 0; i < recipe->step_count && i < MAX_STEPS; i++) {
        cJSON *item = cJSON_CreateObject();
        if (!item) continue;

        cJSON_AddItemToObject(item, "step_number", cJSON_CreateNumber(recipe->steps[i].step_number));

        if (recipe->steps[i].instruction[0] != '\0') {
            cJSON_AddItemToObject(item, "instruction", cJSON_CreateString(recipe->steps[i].instruction));
        } else {
            cJSON_AddItemToObject(item, "instruction", cJSON_CreateString(""));
        }

        if (recipe->steps[i].note[0] != '\0') {
            cJSON_AddItemToObject(item, "note", cJSON_CreateString(recipe->steps[i].note));
        } else {
            cJSON_AddItemToObject(item, "note", cJSON_CreateString(""));
        }

        cJSON_AddItemToArray(steps, item);
    }
    cJSON_AddItemToObject(root, "steps", steps);

    return root;
}

bool json_to_recipe(const char *json_str, recipe_t *recipe)
{
    if (!json_str || !recipe) return false;

    cJSON *root = cJSON_Parse(json_str);
    if (!root) {
        printf("Error: Failed to parse JSON\n");
        return false;
    }
    // 初始化结构体为 0
    memset(recipe, 0, sizeof(recipe_t));
    // 基本字段
    cJSON *name = cJSON_GetObjectItemCaseSensitive(root, "name");
    if (name && cJSON_IsString(name)) strcpy(recipe->name, name->valuestring);
    cJSON *desc = cJSON_GetObjectItemCaseSensitive(root, "description");
    if (desc && cJSON_IsString(desc)) strcpy(recipe->description, desc->valuestring);
    cJSON *category = cJSON_GetObjectItemCaseSensitive(root, "category");
    if (category && cJSON_IsString(category)) strcpy(recipe->category, category->valuestring);
    cJSON *difficulty = cJSON_GetObjectItemCaseSensitive(root, "difficulty");
    if (difficulty && cJSON_IsNumber(difficulty)) recipe->difficulty = difficulty->valueint;
    cJSON *prep_time = cJSON_GetObjectItemCaseSensitive(root, "prep_time");
    if (prep_time && cJSON_IsNumber(prep_time)) recipe->prep_time = prep_time->valueint;
    cJSON *cook_time = cJSON_GetObjectItemCaseSensitive(root, "cook_time");
    if (cook_time && cJSON_IsNumber(cook_time)) recipe->cook_time = cook_time->valueint;

    // 食材
    cJSON *ingredients = cJSON_GetObjectItemCaseSensitive(root, "ingredients");
    if (ingredients && cJSON_IsArray(ingredients)) {
        recipe->ingredient_count = cJSON_GetArraySize(ingredients);
        for (int i = 0; i < recipe->ingredient_count && i < MAX_INGREDIENTS; i++) {
            cJSON *item = cJSON_GetArrayItem(ingredients, i);
            cJSON *ingredients_name = cJSON_GetObjectItemCaseSensitive(item, "name1");
            cJSON *quantity = cJSON_GetObjectItemCaseSensitive(item, "quantity");
            cJSON *unit = cJSON_GetObjectItemCaseSensitive(item, "unit");

            if (ingredients_name && cJSON_IsString(name)) strcpy(recipe->ingredients[i].name, ingredients_name->valuestring);
            if (quantity && cJSON_IsNumber(quantity)) recipe->ingredients[i].quantity = (float)quantity->valuedouble;
            if (unit && cJSON_IsString(unit)) strcpy(recipe->ingredients[i].unit, unit->valuestring);
        }
    }

    // 步骤
    cJSON *steps = cJSON_GetObjectItemCaseSensitive(root, "steps");
    if (steps && cJSON_IsArray(steps)) {
        recipe->step_count = cJSON_GetArraySize(steps);
        for (int i = 0; i < recipe->step_count && i < MAX_STEPS; i++) {
            cJSON *item = cJSON_GetArrayItem(steps, i);
            cJSON *step_num = cJSON_GetObjectItemCaseSensitive(item, "step_number");
            cJSON *instr = cJSON_GetObjectItemCaseSensitive(item, "instruction");
            cJSON *note = cJSON_GetObjectItemCaseSensitive(item, "note");

            if (step_num && cJSON_IsNumber(step_num)) recipe->steps[i].step_number = step_num->valueint;
            if (instr && cJSON_IsString(instr)) strcpy(recipe->steps[i].instruction, instr->valuestring);
            if (note && cJSON_IsString(note)) strcpy(recipe->steps[i].note, note->valuestring);
        }
    }

    cJSON_Delete(root);
    return true;
}

// 辅助函数：检查并创建目录
FRESULT create_directory_if_not_exists(const char* path)
{
    FRESULT res;
    FILINFO fno;

    // 检查目录是否存在
    res = f_stat(path, &fno);
    if (res == FR_OK && (fno.fattrib & AM_DIR)) {
        return FR_OK; // 目录已存在
    }

    if (res == FR_NO_FILE) {
        // 目录不存在，尝试创建
        res = f_mkdir(path);
        if (res == FR_OK) {
            printf("Created directory: %s\n", path);
        } else {
            printf("Failed to create directory: %s, error: %d\n", path, res);
        }
        return res;
    }

    return res;
}

// 写入菜谱
bool save_recipe(recipe_t *recipe)
{
    FRESULT res;
    FIL file;
    UINT bw;    // 实际写入的字节数

//    // 挂载文件系统（使用标准卷号 "1:"）
//    res = f_mount(&fs, "1:", 1);
//    if (res != FR_OK) {
//        printf("Error mounting SD card: %d\n", res);
//        return false;
//    }
    // 构建完整文件路径：recipe/<name>.json
    char file_path[128];
    snprintf(file_path, sizeof(file_path), "1:/recipe/%s.json", recipe->name);

    // 1. 创建父目录（如果不存在）
    res = f_mkdir("1:/recipe");
    if (res != FR_OK && res != FR_EXIST) { // 忽略已存在错误
        printf("Failed to create base 'recipe' directory: %d\n", res);
        return false;
    }

    // 3. 将 recipe 转换为 JSON 字符串
    cJSON *json = recipe_to_json(recipe);
    if (!json) {
        printf("Failed to convert recipe to JSON.\n");
        return false;
    }

    char *json_str = cJSON_Print(json);
    cJSON_Delete(json);
    if (!json_str) {
        printf("Failed to generate JSON string.\n");
        return false;
    }

    // 4. 打开/创建文件
    res = f_open(&file, file_path, FA_WRITE | FA_CREATE_ALWAYS);
    if (res != FR_OK) {
        printf("Failed to open file: %s\n", file_path);
        free(json_str);
        return false;
    }

    // 5. 写入数据
    res = f_write(&file, json_str, strlen(json_str), &bw);
    f_close(&file);
    free(json_str);

    if (res != FR_OK) {
        printf("Failed to write file: %s, error code: %d\n", file_path, res);
        return false;
    }

    if (bw != strlen(json_str)) {
        printf("Only %u bytes written out of %u\n", bw, (unsigned int)strlen(json_str));
        return false;
    }
    return true;
}

// 读取菜谱
bool load_recipe(recipe_t *recipe)
{
    if (!recipe || !recipe->name[0]) {
        printf("Invalid recipe data: name or category is missing.\n");
        return false;
    }

    FRESULT res;
    FIL file;
    UINT br;    // 实际读取的字节数

//    // 1.挂载文件系统（使用标准卷号 "1:"）
//    res = f_mount(&fs, "1:", 1);
//    if (res != FR_OK) {
//        printf("Error mounting SD card: %d\n", res);
//        return false;
//    }

    // 3.构建完整文件路径：recipe/<name>.json
    char file_path[128];
    snprintf(file_path, sizeof(file_path), "1:/recipe/%s.json", recipe->name);

    // 4.打开文件
    res = f_open(&file, file_path, FA_READ);
    if (res != FR_OK) {
        printf("Error: Failed to open file %s\n", file_path);
        return false;
    }

    // 5.读取字符串
    size_t fsize = f_size(&file);
    char *json_str = malloc(fsize + 1);  // 使用标准内存分配（也可替换为 pvPortMalloc）
    if (!json_str) {
        printf("Error: Memory allocation failed\n");
        f_close(&file);
        return false;
    }

    res = f_read(&file, json_str, fsize, &br);
    f_close(&file);

    if (res != FR_OK || br != fsize) {
        printf("Error: Failed to read file %s\n", file_path);
        free(json_str);
        return false;
    }

    json_str[fsize] = '\0';  // 添加字符串结尾

    // 6.使用 cJSON 解析 JSON 字符串为菜谱结构体
    bool success = json_to_recipe(json_str, recipe);
    free(json_str);

    if (!success) {
        printf("Failed to parse JSON into recipe structure.\n");
        return false;
    }
    return true;
}

// 删除菜谱
bool delete_recipe_file(recipe_t *recipe)
{
    FRESULT res;

    // 1.构建路径：1:/recipe/<category>/<name>.json
    char file_path[128];
    snprintf(file_path, sizeof(file_path), "1:/recipe/%s.json", recipe->name);

    // 3.删除文件
    res = f_unlink(file_path);

    if (res == FR_OK) {
        printf("Successfully deleted file: %s\n", file_path);
        return true;
    } else {
        printf("Failed to delete file: %s, error code: %d\n", file_path, res);
        return false;
    }
}

// 打印字段以便调试
void print_recipe(recipe_t *recipe)
{
    if (!recipe) {
        printf("Error: Invalid recipe pointer.\n");
        return;
    }

    // 基本信息
    if (recipe->name[0] != '\0') {
        printf("Name: %s\n", recipe->name);
    }
    if (recipe->description[0] != '\0') {
        printf("Description: %s\n", recipe->description);
    }
    if (recipe->category[0] != '\0') {
        printf("Category: %s\n", recipe->category);
    }

    printf("Difficulty: %d\n", recipe->difficulty);
    printf("Preparation Time: %d minutes\n", recipe->prep_time);
    printf("Cooking Time: %d minutes\n", recipe->cook_time);

    // 食材 ingredients
    if (recipe->ingredient_count > 0) {
        printf("Ingredients:\n");
        for (int i = 0; i < recipe->ingredient_count && i < MAX_INGREDIENTS; i++) {
            if (recipe->ingredients[i].name[0] != '\0') {
                printf("  [%d] Name: %s, Quantity: %.2f %s\n",
                       i + 1,
                       recipe->ingredients[i].name,
                       recipe->ingredients[i].quantity,
                       recipe->ingredients[i].unit);
            }
        }
    }

    // 步骤 steps
    if (recipe->step_count > 0) {
        printf("Steps:\n");
        for (int i = 0; i < recipe->step_count && i < MAX_STEPS; i++) {
            if (recipe->steps[i].instruction[0] != '\0') {
                printf("  Step %d: %s\n", recipe->steps[i].step_number, recipe->steps[i].instruction);
                if (recipe->steps[i].note[0] != '\0') {
                    printf("         Note: %s\n", recipe->steps[i].note);
                }
            }
        }
    }
}

/**
 * @brief 从 SD 卡中读取菜谱文件名，支持起始索引（分页）
 *
 * @param names 存放菜谱名称的二维数组
 * @param max_count 最多读取多少个
 * @param start_index 从第几个开始读取
 * @return size_t 实际读取到的数量
 */
size_t list_recipe_files(char (*names)[64], size_t max_count, size_t start_index)
{
    DIR dir;
    FILINFO fno;
    FRESULT res;

    // 打开 recipe 目录
    res = f_opendir(&dir, "1:/recipe/");
    if (res != FR_OK) {
        printf("Failed to open directory /recipe/ res:%d\n",res);
        return 0;
    }

    size_t count = 0;           // 已找到的总数
    size_t added = 0;           // 实际添加进 names 的数量

    // 读取目录内容
    while (f_readdir(&dir, &fno) == FR_OK && fno.fname[0] != '\0') {
        if (fno.fattrib & AM_DIR) continue; // 忽略子目录

        // 只处理 .json 文件
        if (strstr(fno.fname, ".json") != NULL) {
            char name[64];
            strncpy(name, fno.fname, sizeof(name) - 1);
            name[strlen(name) - 5] = '\0'; // 去掉 ".json"

            // 如果当前 count < start_index，则跳过（未到达起始位置）
            if (count >= start_index && added < max_count) {
                strncpy(names[added], name, 63);
                names[added][63] = '\0';
                added++;
            }
            count++;
        }
    }

    f_closedir(&dir);
    return added;
}

/**
 * @brief 获取 recipe 目录下的 .json 菜谱文件总数
 *
 * @return size_t 返回找到的菜谱文件数量（不包含子目录）
 */
int get_recipe_count(void)
{
    DIR dir;
    FILINFO fno;
    FRESULT res;
    int count = 0;

    // 打开 recipe 目录
    res = f_opendir(&dir, "1:/recipe/");
    if (res != FR_OK) {
        printf("Failed to open directory /recipe/\n");
        return 0;
    }

    // 读取目录内容
    while (f_readdir(&dir, &fno) == FR_OK && fno.fname[0] != '\0') {
        if (fno.fattrib & AM_DIR) continue; // 忽略子目录
        // 只统计 .json 文件
        if (strstr(fno.fname, ".json") != NULL) {
            count++;
        }
    }

    f_closedir(&dir);
    return count;
}

bool find_recipe(const char *partial_name)
{
    DIR dir;
    FILINFO fno;
    FRESULT res;

    res = f_opendir(&dir, "1:/recipe/");
    if (res != FR_OK) {
        printf("Failed to open directory /recipe/");
        return false;
    }

    while (f_readdir(&dir, &fno) == FR_OK && fno.fname[0] != '\0') {
        if (fno.fattrib & AM_DIR) continue;

        if (strstr(fno.fname, ".json") != NULL) {
            char name[64];
            strncpy(name, fno.fname, sizeof(name));
            name[strlen(name) - 5] = '\0'; // 去掉 ".json"

            if (strcasestr(name, partial_name)) { // 忽略大小写部分匹配
                f_closedir(&dir);
                return true;
            }
        }
    }

    f_closedir(&dir);
    return false;
}

/**
 * @brief 获取一个随机菜谱的名称（不带 .json 后缀）
 *
 * @param buffer 输出缓冲区，用于保存结果
 * @return bool 成功返回 true，失败返回 false
 */
bool get_random_recipe_name(char* buffer, size_t buffer_size)
{
    if (!buffer || buffer_size < 64) {
        printf("Invalid buffer or buffer size too small.\n");
        return false;
    }

    // Step 1: 获取总菜谱数
    int total_recipes = get_recipe_count();
    if (total_recipes <= 0) {
        printf("No recipes found.\n");
        return false;
    }

    // Step 2: 初始化随机种子
    srand(lv_tick_get());

    // Step 3: 生成随机索引
    int random_index = rand() % total_recipes;

    // Step 4: 打开目录并遍历文件
    DIR dir;
    FILINFO fno;
    FRESULT res = f_opendir(&dir, "1:/recipe/");
    if (res != FR_OK) {
        printf("Failed to open directory.\n");
        return false;
    }

    int current_index = 0;
    bool found = false;

    while (1) {
        res = f_readdir(&dir, &fno);
        if (res != FR_OK || fno.fname[0] == '\0') {
            break;
        }

        if (fno.fattrib & AM_DIR) continue; // 忽略子目录

        char *dot = strstr(fno.fname, ".json");
        if (dot != NULL) {
            if (current_index == random_index) {
                // 计算文件名长度（不包括.json）
                size_t name_len = dot - fno.fname;

                // 确保不超过缓冲区大小
                if (name_len >= buffer_size) {
                    name_len = buffer_size - 1;
                }

                // 复制文件名
                strncpy(buffer, fno.fname, name_len);
                buffer[name_len] = '\0';

                found = true;
                break;
            }
            current_index++;
        }
    }

    f_closedir(&dir);

    if (!found) {
        printf("Failed to find the %d-th recipe.\n", random_index);
        return false;
    }

    return true;
}


