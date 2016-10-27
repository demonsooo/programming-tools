// CSE 374 hw5
// Yijia Liu 1238339

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "node.h"

// construct a Trie node
struct node* createNode() {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    if (node == NULL) {
        fprintf(stderr, "Error: unable to allocate storage. \n");
        exit(0);
    }
    for (int i = 0; i < 10; i++) {
        node->list[i] = NULL;
        node->word = NULL;
    }
    return node;
}

// construct a word object
struct word* createWord(char* word) {
    char* copy = (char*)malloc(sizeof(char)*strlen(word));
    strncpy(copy, word, strlen(word));
    struct word* temp = (struct word*)malloc(sizeof(struct word));
    temp->string = copy;
    temp->next = NULL;
    return temp;
}

// convert letter into t9 code
int convert(int c) {
    if (c == 'a' || c == 'b' || c == 'c') {
        return 2;
    }
    if (c == 'd' || c == 'e' || c == 'f') {
        return 3;
    }
    if (c == 'g' || c == 'h' || c == 'i') {
        return 4;
    }
    if (c == 'j' || c == 'k' || c == 'l') {
        return 5;
    }
    if (c == 'm' || c == 'n' || c == 'o') {
        return 6;
    }
    if (c == 'p' || c == 'q' || c == 'r' || c == 's') {
        return 7;
    }
    if (c == 't' || c == 'u' || c == 'v') {
        return 8;
    }
    return 9;
}

// construct the Trie by adding word to it
void addWord(struct node* root, char* word, char* rem) {
    if (rem[0] != '\0') {
        int i;
        i = convert(tolower(rem[0]));
        if (root->list[i] == NULL) {
            root->list[i] = createNode();
        }
        addWord(root->list[i], word, rem+1);
    } else {
        if (root->word == NULL) {
            root->word = createWord(word);
        } else {
            struct word* temp = root->word;
            // shift the pointer to the last word
            while (temp->next != NULL) {
                temp = temp->next;
            }
            struct word* newWord = createWord(word);
            temp->next = newWord;
        }
    }
}

// find the word of a given code
void findWord(struct node* INIT_ROOT, struct node* root, struct word* temp, char* code) {
    int i = 0;
    int n;
    while (code[i] != '\0' && i < strlen(code) && code[i] != '#') {
        n = code[i] - '0';
        if (root->list[n] != NULL) {
            root = root->list[n];
            temp = root->word;
        } else {
            printf("%s\n", "Not found in current dictionary.");
            getCode(INIT_ROOT, temp);
        }
        i++;
    }
    if (i == strlen(code) && root->word == NULL) {
        printf("%s\n", "Not found in current dictionary.");
        getCode();
    }
    while (code[i] == '#' && i < strlen(code)) {
        if (temp!= NULL && temp->next != NULL) {
            temp = temp->next;
        } else {
            printf("%s\n", "There are no more T9onyms");
            getCode(INIT_ROOT, temp);
        }
        i++;
    }
    printf("\'%s\'\n", temp->string);
    getCode(INIT_ROOT, temp);
}

// free the Trie recursively
void freeTrie(struct node* root) {
    if (root != NULL) {
        for (int i = 0; i < 10; i++) {
            if (root->list[i] != NULL) {
                freeTrie(root->list[i]);
            }
        }
        if (root->word != NULL) {
            freeWords(root->word);
        }
        free(root);
    }
}

// free the word list recursively
void freeWords(struct word* word) {
    if (word->next != NULL) {
        freeWords(word->next);
    }
    free(word->string);
    free(word);
}
