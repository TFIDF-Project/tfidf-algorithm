#ifndef LIST_HPP
#define LIST_HPP

#include <string>
#include <iostream>
#include <fstream>

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

void readStopWords(List *l, Item d); //Função que lê o arquivo .txt contendo as stopwords e às tokeniza inserindo-as cada uma em uma posição da lista dinâmica.

#endif