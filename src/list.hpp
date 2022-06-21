#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <cmath>
#include <fstream>
#include <string>
#include <locale>
#include <vector>
using namespace std;

typedef struct Item Item;
typedef struct Block Block;
typedef struct List List;
typedef struct Contador Contador;
typedef struct WordCounter WordCounter;
typedef struct ContWordSeen ContWordSeen;

struct Item{
	string word;
};

struct Contador {
	int total_words;
};

struct WordCounter {
	string word;
	int contador;
};

struct ContWordSeen {
	string word;
	int contador = 0;
};

struct Block{
	Item data;
	Contador cont;
	WordCounter single_cont;
	ContWordSeen cont_all_documents;
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

// Função para tratar caractesres especias de uma string e torná-la inteira minúscula
string string_treatment(string s);

// Função para ler o arquivo de stop words e organizá-lo de acordo com a quantidade de caracteres
void filter_stop_words(List *sw1, List *sw2, List *sw3, List *sw4, List *sw5, List *sw6, List *sw7, List *sw8, List *sw9, List *sw10, List *sw11,
List *sw12, List *sw13);

// Função que checará se a palavra do documento é uma stop word, caso não seja, irá inseri-la
void check_if_stopword(List *main_doc, List *sw, Item aux);

// Função a qual tokenizará qualquer um dos documentos dados
void filter_documents(List *doc, string doc_name, List *sw1, List *sw2, List *sw3, List *sw4, List *sw5, List *sw6, List *sw7, List *sw8, List *sw9, 
List *sw10, List *sw11, List *sw12, List *sw13);

// Função na qual se encontrará toda a resolução do TF/IDF
void tf_idf();

#endif