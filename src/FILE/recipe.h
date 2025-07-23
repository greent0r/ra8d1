/*
 * recipe.h
 *
 *  Created on: 2025年6月19日
 *      Author: greentor
 */

#ifndef FILE_RECIPE_H_
#define FILE_RECIPE_H_

#include "hal_data.h"
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "cJSON.h"
#include "platform.h"

// 识别结果结构体
typedef struct {
    char name[64];
    float score;
} result_t;

extern result_t result[6];

// 最大食材数量
#define MAX_INGREDIENTS 30
// 最大步骤数量
#define MAX_STEPS       20

// 食材结构体
typedef struct {
    char name[64];
    float quantity;
    char unit[16];
} ingredient_t;

// 步骤结构体
typedef struct {
    int step_number;
    char instruction[256];
    char note[256];  // 可选备注
} step_t;

// 菜谱结构体
typedef struct {
    char name[64];
    char description[256];
    char category[64];
    int tag_count;
    int difficulty;       // 初级=1, 中级=2, 高级=3
    int prep_time;        // 准备时间（分钟）
    int cook_time;        // 烹饪时间（分钟）
    ingredient_t ingredients[MAX_INGREDIENTS];
    int ingredient_count;
    step_t steps[MAX_STEPS];
    int step_count;
} recipe_t;

#define safe_strcpy(dest, size, src) \
    do { \
        strncpy((dest), (src), (size) - 1); \
        (dest)[(size) - 1] = '\0'; \
    } while (0)

extern recipe_t myrecipe BSP_ALIGN_VARIABLE(64) BSP_PLACE_IN_SECTION(".sdram");
extern recipe_t recipe_rx BSP_ALIGN_VARIABLE(64) BSP_PLACE_IN_SECTION(".sdram");
extern char recipe_list[13][64] BSP_ALIGN_VARIABLE(64) BSP_PLACE_IN_SECTION(".sdram");


cJSON* recipe_to_json(recipe_t *recipe);
bool json_to_recipe(const char *json_str, recipe_t *recipe);

// 将菜谱写入 SD 卡（JSON 格式）
bool save_recipe(recipe_t *recipe);
// 从 SD 卡读取菜谱文件并解析为 recipe_t 结构体
bool load_recipe(recipe_t *recipe);
// 删除 SD 卡上的菜谱文件
bool delete_recipe_file(recipe_t *recipe);
// 打印字段以便调试
void print_recipe(recipe_t *recipe);
size_t list_recipe_files(char (*names)[64], size_t max_count, size_t start_index);
int get_recipe_count(void);
bool find_recipe(const char *partial_name);
bool get_random_recipe_name(char* buffer, size_t buffer_size);

#endif /* FILE_RECIPE_H_ */
