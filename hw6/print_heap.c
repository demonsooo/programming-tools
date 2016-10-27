// print_heap.c
// CSE374 HW6
// This is the implimentation of the method print_heap.

#include "mem.h"
#include "mem_impl.h"

// Print a formatted listing on file f showing the blocks on the free list.
void print_heap(FILE * f) {
    struct memNode* temp = freeList;
    while (temp != NULL) {
        fprintf(f, "%p %lu\n", temp, temp->size);
        temp = temp->next;
    }
    fclose(f);
}

// debug draft
void printHeap() {
    struct memNode* temp = freeList;
    printf("Print heap \n");
    while (temp != NULL) {
        printf("%p %lu\n", temp, temp->size);
        temp = temp->next;
    }
    printf("end of heap \n");
}
