#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "trie.h"

int main(int argc, char* argv[]) {
    _node* root = newTrie();
    int level = 0;
    char str[NUM_LETTERS];

    if(argc == 2 && *(argv[1]) == 'r') {
        printFromDown(root,str,level);
    } else if (argc == 1) {
        printFromUp(root,str,level);
    } else {
        printf("Err\n");
    }

    freeMemory(root);
    return 0;
}
