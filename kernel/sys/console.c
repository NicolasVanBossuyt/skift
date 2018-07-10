#include "kernel/system.h"
#include "device/uart.h"
#include "device/vga.h"
#include "ascii.h"
#include "libc.h"

#define TAB_SIZE 8

console_t console;

void console_setup()
{
    console.cursor.x = 0;
    console.cursor.y = 0;
    console.bg = console_defaul_bg;
    console.fg = console_defaul_fg;

    vga_setup();
    uart_setup();
}

void console_color(console_color_t fg, console_color_t bg)
{
    console.fg = fg;
    console.bg = bg;
}

void console_put(char c)
{
    vga_cell(console.cursor.x, console.cursor.y, vga_entry(c, console.bg, console.fg));
    uart_put(COM1, c);
    console.cursor.x++;

    if (console.cursor.x >= vga_screen_width)
    {
        console.cursor.x = 0;
        console.cursor.y++;
    }

    if (console.cursor.y >= vga_screen_height)
    {
        console.cursor.x = 0;
        console.cursor.y--;
        vga_scroll(console.bg);
    }

    vga_cursor(console.cursor.x, console.cursor.y);
}

void console_print(string message)
{
    bool wait_for_color_id = false;
    
    for(u32 i = 0; message[i]; i++)
    {
        char c = message[i];

        if (wait_for_color_id == true)
        {
            if (c == ASCII_AND)
            {
                vga_cell(console.cursor.x, console.cursor.y, vga_entry(c, console.fg, console.bg));
                uart_put(COM1, c);
                console.cursor.x++;
            }
            else
            {
                char buffer[2] = " ";
                buffer[0] = c;
                console.fg = stoi(buffer, 16);
            }

            wait_for_color_id = false;
        }
        else
        {
            switch (c)
            {
                case ASCII_LF:
                    console.cursor.y++;
                    console.cursor.x = 0;
                    break;
                
                case ASCII_AND:
                    wait_for_color_id = true;
                    break;

                case ASCII_HT:
                    console.cursor.x = console.cursor.x + TAB_SIZE - (console.cursor.x % TAB_SIZE);
                    break;
                
                case ASCII_CR:
                    console.cursor.x = 0;
                    break;
                
                default:
                    vga_cell(console.cursor.x, console.cursor.y, vga_entry(c, console.fg, console.bg));
                    console.cursor.x++;
                    break;
            }

            if (c != ASCII_AND)
                uart_put(COM1, c);
        }

        if (console.cursor.x >= vga_screen_width)
        {
            console.cursor.x = 0;
            console.cursor.y++;
        }

        if (console.cursor.y >= vga_screen_height)
        {
            console.cursor.x = 0;
            console.cursor.y--;
            vga_scroll(console.bg);
        }

    }

    vga_cursor(console.cursor.x, console.cursor.y);
}

void console_read(string buffer, int size)
{
    UNUSED(buffer + size);
}