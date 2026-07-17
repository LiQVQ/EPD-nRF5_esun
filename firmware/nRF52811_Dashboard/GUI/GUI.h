#ifndef __GUI_H
#define __GUI_H

#include "Adafruit_GFX.h"

typedef enum {
    MODE_PICTURE = 0,
    MODE_CALENDAR = 1,
    MODE_CLOCK = 2,
    MODE_DASHBOARD = 3,  // 控台模式
} display_mode_t;

// 倒计时配置 (2条)
typedef struct {
    char event_name[20];   // 事件名称
    uint32_t target_ts;    // 截止时间戳
} dash_countdown_t;

// 消息配置 (5条轮播)
typedef struct {
    char text[20];         // 文字内容
} dash_message_t;

// 大学目标配置 (5条轮播)
typedef struct {
    char univ_name[20];    // 大学名称
    uint16_t score;        // 分数
    uint8_t rank;          // 名次 (0-9对应一到十)
} dash_goal_t;

// 控台数据配置
typedef struct {
    dash_countdown_t countdowns[2];  // 2条倒计时
    dash_message_t messages[5];      // 5条消息轮播
    dash_goal_t goals[5];            // 5条目标轮播
    uint8_t msg_index;               // 当前消息索引 (用于轮播)
    uint8_t goal_index;              // 当前目标索引 (用于轮播)
} dashboard_data_t;

typedef struct {
    display_mode_t mode;
    uint16_t color;
    uint16_t width;
    uint16_t height;
    uint32_t timestamp;
    uint8_t week_start;  // 0: Sunday, 1: Monday
    int8_t temperature;
    float voltage;
    char ssid[20];
    dashboard_data_t dashboard;  // 控台数据
} gui_data_t;

void DrawGUI(gui_data_t* data, buffer_callback callback, void* callback_data);

#endif
