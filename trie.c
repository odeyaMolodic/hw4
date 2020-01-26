#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "trie.h"


struct _node* newTrie() {
    _node* root = node();
    char keys[NUM_LETTERS];
    int length_key=0;
   
    do {
     length_key=get_word(keys);
     if(length_key!=0)
     insert_node(root ,keys,length_key);
    }while(length_key!=0);
   
    return root;
}

struct _node* node() {
    _node* tmp=(_node*)malloc(sizeof(_node));
    for(int i=0;i<NUM_LETTERS;i++)
        tmp->next[i]=NULL;
   
    tmp->_EndOfWord=false;
    tmp->count=0;
   
    return tmp;
}

int get_word(char str[]) {
    char letter;
    char* word=str;
     int len = 0;
    do {
        if(scanf("%c",&letter)==EOF) {
            	return 0;
	}
	if(letter>='A'&&letter<='Z') {
		letter+=32;
	}
	if(letter>='a'&&letter<='z') {
		*(word++)=letter;
		len++;
        }
    }while(letter!='\n'&&letter!='\t'&&letter!=' ');

    return len;
}

void insert_node(_node* root,char* word,int len) {
    int height;
    struct _node* tmp=root;
   
    for(height=0;height<len;height++) {
        int i=word[height]-'a';

        if(tmp->next[i]==NULL) {
            tmp->next[i]=node();
        }
        tmp=tmp->next[i];      
    }
    if(tmp->_EndOfWord)
        tmp->count++;
    else {
        tmp->_EndOfWord=true;
        tmp->count=1;
    }
}

bool EndOfWord(_node* root) {
    return root->_EndOfWord;
}


void printFromUp(_node* root,char str[],int level) {
    if(EndOfWord(root)) {
        str[level]='\0';
        print(str,root->count);
    }
    int i;
    for(i=0;i<NUM_LETTERS;i++) {
        if(root->next[i]) {
            str[level]=i+'a';
            printFromUp(root->next[i],str,level+1);
        }
    }
}

void printFromDown(_node* root,char str[],int level) {
    if(EndOfWord(root)) {
        str[level]='\0';
        print(str,root->count);
    }
    int i;
    for(i=NUM_LETTERS-1;i>=0;i--) {
        if(root->next[i]) {
            str[level]=i+'a';
            printFromDown(root->next[i],str,level+1);
        }
    }
}

void freeMemory(_node* root) {
    _node* tmp=root;
    int i;

    for(i=NUM_LETTERS-1;i>=0;i--) {
        if(root->next[i]) {
            freeMemory(tmp->next[i]); 
        }      
    }
    free(root);
}

void print(char word[],int count) {
    printf("%s\t%d\n",word,count);
}
