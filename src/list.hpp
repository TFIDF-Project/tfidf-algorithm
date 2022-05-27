#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

typedef struct Item Item;
typedef struct Block Block;
typedef struct List List;

struct Item{
	string word;
};

struct Block{
	Item data;
	Block *prox;
};

struct List{
	Block *first;
	Block *last;
};


void FLVazia(List *l);
void LInsert(List *l, Item d);
void LRemove(List *l, Item d);
void Swap(Block *a, Block *b);
void LImprime(List *l);

//Função que lê o arquivo .txt contendo as stopwords e às tokeniza inserindo-as cada uma em uma posição da lista dinâmica.
void readStopWords(List *lw1, List *lw2, List *lw3, List *lw4, List *lw5, List *lw6, List *lw7, List *lw8, List *lw9, List *lw10, List *lw11, List *lw12, List *lw13, Item d); 

#endif