Mingyu Zhang: getmem.c mem_impl.h mem.h
Yijia Liu: freemem.c bench.c get_mem_stats.c check_heap.c print_heap.c

The initial freeList is empty. When the user first request 
for a memory with size s, if s is larger than default block size,
the program mallocs a memNode structure with size s, otherwise
it mallocs a memNode structure with default size and free it
on to the freeList first and split a smaller size with size s and 
return its usable part to the user. That is how the freeList is build.
If the user frees a memory block, it is put back to the freeList and 
the program checks for if it is physically touching with the front
and back memNode, if so it is merged.

sample results:

500 trials
Total CPU time: 0.000252
Total amount of storage:  61168
Total number of free blocks: 4
Average size of free blocks:  15268

10,000 trials
Total CPU time: 0.003891
Total amount of storage:  173776
Total number of free blocks: 15
Average size of free blocks:  11506

100,000 trials
Total CPU time: 0.076042
Total amount of storage:  1166896
Total number of free blocks: 56
Average size of free blocks:  7116

500,000 trials
Total CPU time: 0.550916
Total amount of storage:  1683584
Total number of free blocks: 112
Average size of free blocks:  14497

generally speaking, the program is pretty efficient