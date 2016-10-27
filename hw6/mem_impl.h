// mem_impl.h
// CSE374 HW6
// This is the header file including the implementaion details

#ifndef MEM_IMPL_H
#define MEM_IMPL_H

#include "mem.h"

#define TRUE 1
#define FALSE 0

// default size of a required block 1k
#define DEFAULT_BLOCK 8000

// the size of a pointer
#define PTR_SIZE sizeof(uintptr_t)

// if the block is twice the size of the user request
// the block is splited
#define SPLIT_PROPORTION 2

struct memNode {
      uintptr_t size;
      struct memNode* next;
};

// A global linked list of memNodes
struct memNode* freeList;

// an int record total memory mallocated
uintptr_t TOTAL_MEMORY;

// Check for possible problems with the free list data structure.
void check_heap();

// split the given block in to one block with the required size
// and the other with the rest of the size
struct memNode* splitBlock(struct memNode* root, uintptr_t size);

// create a new block with proper size and free it into the freeList
struct memNode* getNewBlock(uintptr_t size);

// combine the two blocks if they are touching
void combine(struct memNode* temp, struct memNode* mem);

// debug draft
void printHeap();

// free memNodes
void freeNodes(struct memNode* node);

#endif
