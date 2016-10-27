// bench.c
// CSE374 HW6
// This is the benchmark file for testing

#include "mem.h"

#include <time.h>
#include <unistd.h>

struct list {
    void* p;
    struct list* next;
};


int main(int argc, char *argv[]) {
    // get options
    int opts[6] = {10000, 50, 10, 200, 20000, clock()};
    for (int i = 1; i < argc; i++) {
        opts[i - 1] = atoi(argv[i]);
    }
    int n = opts[0];
    int pctget = opts[1];
    int pctlarge = opts[2];
    int small_limit = opts[3];
    int large_limit = opts[4];
    int random_seed = opts[5];

    // initialize the array
    void** list = (void**) malloc(n * sizeof(void*));
    for (int i = 0; i < n; i++) {
        list[i] = NULL;
    }

    int func;
    int large;
    int size;
    int nmem = 0;
    int pos = 0;
    int timeEnd;
    uintptr_t total_size = 0;
    uintptr_t total_free = 0;
    uintptr_t n_free_blocks = 0;
    srand(random_seed);

    // simulate n times
    for (int i = 0; i < n; i++) {
        func = rand() % 100;
        // get memory
        if (func < pctget) {
            //
            large  = rand() % 100;
            // get size of block
            if (large < pctlarge) {
                size = (rand() % (large_limit - small_limit)) + small_limit + 1;
            } else {
                size = (rand() % small_limit) + 1;
            }
            void* p = getmem(size);
            list[nmem] = p;
            nmem++;
        // free memory
        } else {
            if (nmem > 0) {
                pos = rand() % nmem;
                freemem(list[pos]);
                list[pos] = list[nmem - 1];
               // list[nmem - 1] = NULL;
                nmem--;
            }
        }
        if ((i + 1) % (n/10) == 0) {
            printf("%d percentage has been processed. \n",
                    (i + 1) / (n / 10) * 10);
            timeEnd = clock();
            // works, but get warning from here
            get_mem_stats(&total_size, &total_free, &n_free_blocks);
            printf("Total CPU time: %f\n",
                    (double)(timeEnd - random_seed)/CLOCKS_PER_SEC);
            printf("Total amount of storage:  %d\n", (int) total_size);
            printf("Total number of free blocks: %d\n", (int)n_free_blocks);
            if (n_free_blocks == 0) {
                      printf("Average size of free blocks: 0\n\n");
            } else {
                      printf("Average size of free blocks:  %lu\n\n",
                          (total_free / n_free_blocks));
            }
        }
    }
    // free all the memory to the freeList
    for (int i = 0; i < nmem; i++) {
        freemem(list[i]);
    }
    freeMemList();

    return 0;
}
