// get_mem_stats.c
// CSE374 HW6
// This is the implimentation of the method check_heap.

#include "mem_impl.h"

// Check for possible problems with the free list data structure
void check_heap() {
    struct memNode* temp = freeList;
    while (temp != NULL) {
        // check if the size of any block is positive
        assert(temp->size > 0);
        if (temp->next != NULL) {
            // check if the heap is strictly increasing
            assert(temp < temp->next);
            // check if there's any overlap or touching
            assert((void*)temp->next > (void*)temp + PTR_SIZE*2 + temp->size);
        }
        temp = temp->next;
    }
}
