#ifndef TRIE_H
#define TRIE_H
#define NUM_LETTERS ((int)26)

typedef struct _node {
 char _letter;
 long count;
 struct _node* next[NUM_LETTERS];
 bool _EndOfWord;
}_node;

struct _node* newTrie();

struct _node* node();

void printFromUp(_node* root,char str[],int level);

void printFromDown(_node* root,char str[],int level);

void insert_node(_node* root,char* key,int length);

bool is_word(_node* root);

int get_word(char str[]);

void print(char str[],int count);

void freeMemory(_node* root);
#endif
