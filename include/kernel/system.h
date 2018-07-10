#pragma once
#include "types.h"



void system_setup();

/* --- Logging -------------------------------------------------------------- */

typedef enum 
{
    LOG_MAJOR,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_PANIC
} log_level_t;

#define major(x...) __log(LOG_MAJOR, x)
#define info(x...) __log(LOG_INFO, x)
#define warn(x...) __log(LOG_INFO, x)
#define error(x...) __log(LOG_INFO, x)
#define panic(x...) __panic(__FILE__, (string)__FUNCTION__, __LINE__, x) 

#define setup(x) { info("Setting up " #x "..."); x##_setup(); }

void __log(log_level_t level, string message, ...);
void __panic(const string file, const string function, const int line, string message, ...);

/* --- time ----------------------------------------------------------------- */

#define TIME_SECOND 0x00
#define TIME_MINUTE 0x02
#define TIME_HOUR   0x04
#define TIME_DAY    0x07
#define TIME_MONTH  0x08
#define TIME_YEAR   0x09

typedef struct {
    u8 second;
    u8 minute;
    u8 hour;
    u8 day;
    u8 month;
    u32 year;
} time_t;

time_t time();
u32 time_get(u32 selector);

/* --- console -------------------------------------------------------------- */

#define console_black         0x0
#define console_blue          0x1
#define console_green         0x2
#define console_cyan          0x3
#define console_red           0x4
#define console_magenta       0x5
#define console_brown         0x6
#define console_light_gray    0x7
#define console_gray          0x8
#define console_light_blue    0x9
#define console_light_green   0xA
#define console_light_cyan    0xB
#define console_light_red     0xC
#define console_light_magenta 0xD
#define console_light_yellow  0xE
#define console_white         0xF

#define console_defaul_fg 0x7;
#define console_defaul_bg 0x0;

typedef uchar console_color_t;

typedef struct 
{
    console_color_t fg;
    console_color_t bg;
    upoint_t cursor;
} console_t;

void console_setup(void);
void console_color(console_color_t fg, console_color_t bg);
void console_put(char c);
void console_print(string message);
void console_read(string buffer, int size);