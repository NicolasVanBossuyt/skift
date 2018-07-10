#pragma once
#include "types.h"

#define cli() asm volatile("cli");
#define sti() asm volatile("sti");
#define hlt() asm volatile("hlt");

u8   inb (u16 port);
void outb(u16 port, u8 data);

void cpu_setup();
void gdt_setup();

void gdt_dump();
void set_kernel_stack(u32 stack);

typedef struct __attribute__ ((packed))
{
	u32	prev_tss;
	u32	esp0;
	u32	ss0;
	u32	esp1;
	u32	ss1;
	u32	esp2;
	u32	ss2;
	u32	cr3;
	u32	eip;
	u32	eflags;
	u32	eax;
	u32	ecx;
	u32	edx;
	u32	ebx;
	u32	esp;
	u32	ebp;
	u32	esi;
	u32	edi;
	u32	es;
	u32	cs;
	u32	ss;
	u32	ds;
	u32	fs;
	u32	gs;
	u32	ldt;
	u16	trap;
	u16	iomap_base;
} tss_t;
