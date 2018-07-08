#pragma once

#include "types.h"

#define COM1 0x3F8
#define COM2 0x2F8
#define COM3 0x3E8
#define COM4 0x2E8

typedef unsigned short uart_port_t;

bool install_uart();
void uart_open_port(uart_port_t port);
void uart_put(uart_port_t port, char a);
void uart_print(uart_port_t port, string str);