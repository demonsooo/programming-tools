// CSE 374 hw5
// Yijia Liu 1238339

#ifndef TRIE_NODE
#define TRIE_NODE

struct node {
    struct node* list[10];
    struct word* word;
};

struct word {
    char* string;
    struct word* next;
};

struct node* createNode();
struct word* createWord(char* word);
int convert(int c);
void addWord(struct node* root, char* word, char* rem);
void findWord(struct node* INIT_ROOT, struct node* root, struct word* temp, char* code);
void getCode();
void freeTrie(struct node* root);
void freeWords(struct word* word);

#endif
