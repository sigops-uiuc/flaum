#ifndef PAGING_H_
#define PAGING_H_

#include <stdint.h>

#define PAGE_SIZE 4096
#define MEM_SIZE_TMP 1024*1024*1024 // Temporary for usage for when we don't know size of memory
#define PAGE_NUM_TMP (MEM_SIZE_TMP/PAGE_SIZE)
#define ERR_NO_PAGE -1

typedef struct {
    uint8_t allocated;
    uint8_t kernel;
    uint32_t reserved;
    uint64_t mapped_addr;
} page_flags_t;

//extern page_flags_t* page_table;

void init_pages();
void *alloc_page();
void free_page(void *ptr);


#endif /* PAGING_H_ */
