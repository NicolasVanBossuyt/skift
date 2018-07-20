#pragma once
#include "types.h"

#define PAGE_SIZE 0x1000
#define PAGE_TABLE_ENTRY_COUNT 1024
#define PAGE_DIRECTORIE_ENTRY_COUNT 1024

typedef PACKED(union) // page table entry
{
    PACKED(struct) 
    {
        bool Present               : 1;
        bool Write                 : 1;
        bool Supervisor            : 1;
        bool PageLevelWriteThrough : 1;
        bool PageLevelCacheDisable : 1;
        bool Accessed              : 1;
        bool Dirty                 : 1;
        bool Pat                   : 1;
        u32  Ignored               : 4;
        u32  PageFrameNumber       : 20;
    };

    u32 as_uint;
} page_t;

typedef PACKED(struct) // page table 
{
    page_t pages[PAGE_TABLE_ENTRY_COUNT];
} page_table_t;

typedef PACKED(union) // page directorie entry
{
    PACKED(struct)
    {
        bool Present                : 1;
        bool Write                  : 1;
        bool Supervisor             : 1;
        bool PageLevelWriteThrough  : 1;
        bool PageLevelCacheDisable  : 1;
        bool Accessed               : 1;
        bool Ignored1               : 1;
        bool LargePage              : 1;
        u32 Ignored2                : 4;
        u32 PageFrameNumber         : 20;
    };
    u32 as_uint;
} page_directorie_entry_t;

typedef PACKED(struct) // page directorie
{
    page_directorie_entry_t entries[PAGE_DIRECTORIE_ENTRY_COUNT];
} page_directorie_t;


extern void paging_enable(void);
extern void paging_load_directorie(page_directorie_t * directorie);

void mm_setup();
