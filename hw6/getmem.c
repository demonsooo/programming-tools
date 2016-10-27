    // getmem.c
    // CSE374 HW6
    // This is the implimentation of the method getmem.

    #include "mem.h"
    #include "mem_impl.h"

    // Return a pointer to a new block of storage with
    // at least size bytes of memory.

    void* getmem(uintptr_t size) {
        check_heap();

         if (size <= 0) {
            check_heap();
              return NULL;
         }
         // if the size is not mutiple of 16, round it up to nearest multiple
         if (size % 16 != 0) {
              size = (size/16 + 1) * 16;
         }

         // freelist is empty
         if (freeList == NULL) {
            check_heap();
              return (void*) getNewBlock(size) + PTR_SIZE*2;
         }

         struct memNode* temp = freeList;
         struct memNode* chosen = NULL;

         // if the first block is large enough for memory
         if (freeList->size >= size + PTR_SIZE*2) {
              if (freeList->size >= (size + PTR_SIZE*2)*SPLIT_PROPORTION) {
                check_heap();
                return (void*) splitBlock(freeList, size) + PTR_SIZE*2;
              } else {
                   chosen = freeList;
                   freeList = freeList->next;
              }
              check_heap();
              return (void*)chosen + PTR_SIZE*2;
         }

         // iterate through the list to find a size large enough
         while (temp->next != NULL && temp->next->size < size + PTR_SIZE*2) {
              temp = temp->next;
         }

         // no block large enough
         if (temp->next == NULL) {
            check_heap();
            return (void*)getNewBlock(size) + PTR_SIZE*2;
         }

         // block large enough to be splited
         if (temp->next->size > (size + PTR_SIZE*2) * SPLIT_PROPORTION) {
              chosen = splitBlock(temp->next, size);
         } else {  // block is directly used to return
              chosen =  temp->next;
              temp->next = temp->next->next;
         }
        check_heap();
         return (void*)chosen + PTR_SIZE*2;
    }

    // malloc a new block
    // if size greater than required size * SPLIT_PROPORTION,
    // free and split the new block and take the requied size
    // leave the rest on the free list
    // otherwise return the new block without adding to free list
    struct memNode* getNewBlock(uintptr_t size) {
         uintptr_t allocSize = size;
         if (size < DEFAULT_BLOCK) allocSize = DEFAULT_BLOCK;
         struct memNode* newBlock =
             (struct memNode*) malloc(allocSize + PTR_SIZE*2);
         TOTAL_MEMORY += allocSize;
         newBlock->size = allocSize;
         newBlock->next = NULL;
         if (allocSize > size * SPLIT_PROPORTION) {
              freemem((void*) newBlock + PTR_SIZE*2);
              return splitBlock(newBlock, size);
         } else {
              return newBlock;
         }
    }

    // linking is handled
    struct memNode* splitBlock(struct memNode* root, uintptr_t size) {
         // find the address of the block to be created
         struct memNode* newNode =
             (struct memNode*) ((uintptr_t)root + root->size - size);
         newNode->size = size;
         newNode->next = NULL;

         // subtract the size been cut off from the original size
         root->size = root->size - size - 2*PTR_SIZE;
         // root->next = newNode;
         return newNode;
    }










