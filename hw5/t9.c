// CSE 374 hw5
// Yijia Liu 1238339

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "node.h"

#define MaxSize 100

// get words from a given file and construct the Trie accordingly
void readFile(struct node* root, char* file) {
    FILE *f;
    f = fopen(file, "r");
    char word[MaxSize];
    if (f == NULL) {
        fprintf(stderr, "Error: file does not exist: %s\n", file);
        exit(0);
    } else {
        while (fgets(word, MaxSize, f) != NULL) {
            word[strlen(word) - 1] = '\0';
            addWord(root, word, word);
        }
    }
}

// get code from stdin and find word from the Trie
void getCode(struct node* INIT_ROOT, struct word* list) {
    printf("%s\n", "Enter Key Sequence (or \"#\" for next word):");
    char code[256];
    scanf("%s", code);
    if (strstr(code, "exit") != NULL) {
        freeTrie(INIT_ROOT);
        exit(0);
    }
    findWord(INIT_ROOT, INIT_ROOT, list, code);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Error: this program needs 2 arguments.\n");
        return -1;
    }
    struct node* INIT_ROOT = createNode();
    readFile(INIT_ROOT, argv[1]);
    printf("%s\n", "Enter \"exit\" to quit.");
    getCode(INIT_ROOT, NULL);
}
