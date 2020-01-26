
all: trielib.so frequency

frequency: main.o trielib.so
	gcc -Wall -o frequency main.o ./trielib.so
trielib: trielib.so

trielib.so: trie.o
	gcc -shared -o trielib.so trie.o

main.o: main.c trie.h
	gcc -Wall -fPIC -g -c main.c
.PHONY: clean all trielib

trie.o: trie.c trie.h
	gcc -Wall -fPIC -g -c trie.c

clean: 
	rm -f *.o *.so frequency