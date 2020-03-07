#include "paging.h"

extern uint8_t __end;

// The size of this array should be determined by the amount of memory the hardware actually has. (total_mem/page_size)
///@todo declare somewhere else?
page_flags_t page_table[PAGE_NUM_TMP];

void init_pages(){
    int i;
    uint32_t kernel_pages;


    kernel_pages = ((uint32_t)&__end) / PAGE_SIZE;
    for(i = 0; i < kernel_pages; i++){
        page_table[i].allocated = 1;
        page_table[i].kernel = 1;
	page_table[i].mapped_addr = 4096 * i;
    }
    for(; i < PAGE_NUM_TMP; i++){
        page_table[i].allocated = 0;
        page_table[i].kernel = 0;
	page_table[i].mapped_addr = 4096 * i;
    }

    return;
}

void *alloc_page() {
	for (int i = 0; i < PAGE_NUM_TMP; i++) {
		if (page_table[i].allocated == 0) {
			return (void *) page_table[i].mapped_addr;
		}
	}
	return (void *) ERR_NO_PAGE;
}

void free_page(void *ptr) {
	int mapped_page = (int)ptr / PAGE_SIZE;
	page_table[mapped_page].allocated = 0;
}
