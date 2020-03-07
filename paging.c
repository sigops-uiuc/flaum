#include "paging.h"

extern uint8_t __end;

// The size of this array should be determined by the amount of memory the hardware actually has. (total_mem/page_size)
///@todo declare somewhere else?
page_flags_t page_table[1024];

void init_pages(){
    int i;
    uint32_t kernel_pages;


    kernel_pages = ((uint32_t)&__end) / PAGE_SIZE;
    for(i = 0; i < kernel_pages; i++){
        page_table[i].allocated = 1;
        page_table[i].kernel = 1;
    }
    for(; i < PAGE_NUM_TMP; i++){
        page_table[i].allocated = 0;
        page_table[i].kernel = 0;
    }

    return;
}