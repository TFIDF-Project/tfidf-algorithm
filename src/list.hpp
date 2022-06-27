#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

typedef struct Item Item;
typedef struct Block Block;
typedef struct List List;
typedef struct Contador Contador;
typedef struct WordCounter WordCounter;
typedef struct ContWordSeen ContWordSeen;

struct Item{
	std::string word;
};

struct Contador {
	int total_words;
};

struct WordCounter {
	std::string word;
	int contador;
};

struct ContWordSeen {
	std::string word;
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
void LInsertCont(List *l, Contador d);
void LInsertWordCounter(List *l, WordCounter d);
std::string string_treatment(std::string s);
void filter_stop_words(List *sw1, List *sw2, List *sw3, List *sw4, List *sw5, List *sw6, List *sw7, List *sw8, List *sw9, List *sw10, List *sw11,
List *sw12, List *sw13);
void check_if_stopword(List *main_doc, List *sw, Item aux);
void LInsertContWordSeen(List *l, ContWordSeen d);
// void check_if_stopword_final_cont(List *main_doc, List *sw, ContWordSeen aux);
void filter_documents(List *doc, std::string doc_name, List *sw1, List *sw2, List *sw3, List *sw4, List *sw5, List *sw6, List *sw7, List *sw8, List *sw9, 
List *sw10, List *sw11, List *sw12, List *sw13);
bool verify_if_word_exist(List *wordcount, std::string word);
void fill_list_with_cont(List *document, List *wordcount);
void read_phrase(List *doc, std::string doc_name, List *sw1, List *sw2, List *sw3, List *sw4, List *sw5, List *sw6, List *sw7, List *sw8, List *sw9, 
List *sw10, List *sw11, List *sw12, List *sw13);
void verify_how_many_times_seen(List *input, List *document);
int find_word_cont(List *wordcounter, std::string to_find);
void tf_idf_calc(List *input, List *wordcounter_doc1, List *wordcounter_doc2, List *wordcounter_doc3, List *wordcounter_doc4, List *wordcounter_doc5, List *wordcounter_doc6,
List *document_1, List *document_2, List *document_3, List *document_4, List *document_5, List *document_6);
void tf_idf();

#endif