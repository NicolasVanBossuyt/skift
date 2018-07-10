#include "kernel/cpu.h"
#include "kernel/system.h"

void cpu_setup()
{
    setup(gdt);
}

u8 inb(u16 port)
{
    u8 data;
    asm volatile("in %1,%0" : "=a" (data) : "d" (port));
    return data;
}

void outb(u16 port, u8 data)
{
    asm volatile("out %0,%1" : : "a" (data), "d" (port));
}