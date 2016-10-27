// mem.h
// CSE374 HW6
// This is the header file header containing the public
// declarations of the functions for client usage.

#ifndef MEM_H
#define MEM_H

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// assert library
#include <assert.h>

// Return a pointer to a new block of storage
// with at least size bytes of memory.
void* getmem(uintptr_t size);

// Return the block of storage at location p
// to the pool of available free storage.
void freemem(void* p);

// Store statistics about the current state of
// the memory manager in the three integer variables
// whose addresses are given as arguments.
void get_mem_stats(uintptr_t* total_size,
    uintptr_t* total_free, uintptr_t* n_free_blocks);

// Print a formatted listing on file f showing
// the blocks on the free list.
void print_heap(FILE * f);

void freeMemList();


#endif
