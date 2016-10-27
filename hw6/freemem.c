// freemem.c
// CSE374 HW6
// This is the implimentation of the method freemem.

#include "mem.h"
#include "mem_impl.h"

// Return the block of storage at location p to the pool of available
// free storage
void freemem(void* p) {
    check_heap();
    if (p == NULL) {
        return;
    }
    struct memNode* mem = (struct memNode*) (p - PTR_SIZE*2);
    struct memNode* temp = freeList;
    // if freeList is NULL
    if (temp == NULL) {
        freeList = mem;
    // combine the newnode and the first block
    } else if (mem != NULL) {
        struct memNode* endOfMem = (struct memNode*)
            ((void*)mem + PTR_SIZE * 2 + mem->size);
        if (endOfMem < freeList) {
            mem->next = temp;
            freeList = mem;
        } else if (endOfMem == freeList) {
            mem->size += freeList->size + PTR_SIZE*2;
            mem->next = freeList->next;
            freeList = mem;
        } else {
            while (temp->next != NULL && temp->next < mem) {
                temp = temp->next;
            }
            // mem is the last one on the freeList
            if (temp->next == NULL) {
                struct memNode* endOfTemp = (struct memNode*)
                    ((void*)temp + PTR_SIZE * 2 + temp->size);
                if (endOfTemp == mem) {
                    temp->size += mem->size + 2 * PTR_SIZE;
                } else {
                    temp->next = mem;
                }
                check_heap();
                return;
            }
            combine(temp, mem);
        }
    }
    check_heap();
}


void combine(struct memNode* temp, struct memNode* mem) {
     int touchFront = FALSE;
     int touchBack = FALSE;

     if ((void*)temp + PTR_SIZE * 2 + temp->size == mem) touchFront = TRUE;

     if (temp->next != NULL &&
         (void*)mem + PTR_SIZE * 2 + mem->size == (void*)temp->next)
         touchBack = TRUE;

     if (touchFront && touchBack) {
              temp->size += mem->size + temp->next->size + PTR_SIZE * 4;
              temp->next = temp->next->next;
     } else if (touchFront && !touchBack) {
              temp->size += mem->size + PTR_SIZE * 2;

     } else if (!touchFront && touchBack) {
              mem->size += temp->next->size + PTR_SIZE * 2;
              mem->next = temp->next->next;
              temp->next = mem;
     } else if (temp->next != mem) {
              mem->next = temp->next;
              temp->next = mem;
     }
}

void freeMemList() {
         freeNodes(freeList);
}

void freeNodes(struct memNode* node) {
         if (node->next !=  NULL) {
              freeNodes(node->next);
         }
         free(node);
}




