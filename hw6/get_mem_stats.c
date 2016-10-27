// get_mem_stats.c
// CSE374 HW6
// This is the implimentation of the method get_mem_stats.

#include "mem_impl.h"

// Store statistics about the current state of the memory manager in the three
// integer variables whose addresses are given as arguments.
void get_mem_stats(uintptr_t* total_size, uintptr_t* total_free,
    uintptr_t* n_free_blocks) {
    *total_free = 0;
    *n_free_blocks = 0;
    *total_size = TOTAL_MEMORY;
    struct memNode* temp = freeList;
        while (temp != NULL) {
        *total_free += temp->size;
        *n_free_blocks += 1;
        temp = temp->next;
    }
}
