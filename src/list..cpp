#include "list.hpp"
using namespace std;

void Swap(Block *a, Block *b){
	Item aux;
	aux = a -> data;
	a -> data = b -> data;
	b -> data = aux;
	
}

// aux = i ->single_cont;
// i -> single_cont = j->single_cont;
// j -> single_cont = aux;

void swap(Block *a, Block *b) {
	WordCounter aux;
	aux = a -> single_cont;
	a -> single_cont = b -> single_cont;
	b -> single_cont = aux;
}

void FLVazia(List *l){
	l -> first = new Block;
	l -> last  = l -> first;
	l -> first -> prox = NULL;
}

void LInsert(List *l, Item d){
	l -> last -> prox = new Block;
	l -> last = l -> last -> prox;
	l -> last -> data = d;
	l -> last -> prox = NULL;
}

void LInsertCont(List *l, Contador d){
	l -> last -> prox = new Block;
	l -> last = l -> last -> prox;
	l -> last -> cont = d;
	l -> last -> prox = NULL;
}

void LInsertWordCounter(List *l, WordCounter d){
	l -> last -> prox = new Block;
	l -> last = l -> last -> prox;
	l -> last-> single_cont = d;
	l -> last -> prox = NULL;
}

void LImprimeWordCounter(List *l){
	Block *aux;

	aux = l -> first -> prox;
	while(aux != NULL){
		cout << "PALAVRA: " << aux -> single_cont.word;
		cout << "\t\t\t\tVALOR: " << aux -> single_cont.contador << endl; 
		aux = aux->prox;
	}
}

void LRemove(List *l, Item d){
	Block *aux, *tmp;

	if(l -> first == l -> last || l == NULL || l -> first -> prox == NULL){
		cout << "LISTA VAZIA!\n";
		return;
	}
	
	aux = l -> first;
	while(aux -> prox != NULL){
		if (aux -> prox -> data.word == d.word){
			tmp = aux;
			aux = aux->prox;
			tmp -> prox = aux -> prox;
			if (aux == l -> last)
				l -> last = tmp;
			free(aux);
			aux -> prox = NULL;
		}
		else {
			aux = aux -> prox;
		}
	}
}

void LImprime(List *l){
	Block *aux;

	aux = l -> first -> prox;
	while(aux != NULL){
		cout << "\t\t\t\t      " << aux -> data.word << endl;
		aux = aux->prox;
	}
}

bool list_is_empty(List *l) {
	if (l -> first == l -> last || l == NULL || l -> first -> prox == NULL){
		return true;
	} else {
		return false;
	}
}

string string_treatment(string s) {
	int size = s.size();
	string aux;

	for (int i = 0; i < size; i++) {
		if (s[i] != '.' && s[i]!= ',' && s[i] != ':' && s[i] != ';' && s[i] != '?' && s[i] != '!' && s[i] != '(' && s[i] != ')' && s[i] != '[' && s[i] != ']' && s[i] != '{'
			&& s[i] != '}' && s[i] != '+'&& s[i] != '=' && s[i] != '-' && s[i] != '*' && s[i] != '/' && s[i] != '%' && !isdigit(s[i])) {
			s[i] = tolower(s[i]);
            aux += s[i];
		}
	}
 
	return aux;
}

void filter_stop_words(List *sw1, List *sw2, List *sw3, List *sw4, List *sw5, List *sw6, List *sw7, List *sw8, List *sw9, List *sw10, List *sw11,
List *sw12, List *sw13) {
	ifstream myfile;
	string line;
	Item aux;

	myfile.open("stopwords.txt");

	if (myfile.is_open()) {
		while(!myfile.eof()) {
			getline(myfile, line);
            aux.word = line;
            if (line.size() == 1) {
                LInsert(sw1, aux);
            } else if (line.size() == 2) {
                LInsert(sw2, aux);
            } else if (line.size() == 3) {
                LInsert(sw3, aux);
            } else if (line.size() == 4) {
                LInsert(sw4, aux);
            } else if (line.size() == 5) {
                LInsert(sw5, aux);
            } else if (line.size() == 6) {
                LInsert(sw6, aux);
            } else if (line.size() == 7) {
                LInsert(sw7, aux);
            } else if (line.size() == 8) {
                LInsert(sw8, aux);
            } else if (line.size() == 9) {
                LInsert(sw9, aux);
            } else if (line.size() == 10) {
                LInsert(sw10, aux);
            } else if (line.size() == 11) {
                LInsert(sw11, aux);
            } else if (line.size() == 12) {
                LInsert(sw12, aux);
            } else {
                LInsert(sw13, aux);
            }
		}

		myfile.close();
	}
}

void check_if_stopword(List *main_doc, List *sw, Item aux) {
	Block *aux_block;

	aux_block = sw->first->prox;

	while (aux_block != NULL) {
		if (aux.word == aux_block -> data.word) {
			return;
		}

		aux_block = aux_block -> prox;
	}

	LInsert(main_doc, aux);
}

void filter_documents(List *doc, string doc_name, List *sw1, List *sw2, List *sw3, List *sw4, List *sw5, List *sw6, List *sw7, List *sw8, List *sw9, 
List *sw10, List *sw11, List *sw12, List *sw13) {
	ifstream myfile;
	string line, auxiliar, auxiliar_2, delimiter = " ";
	Item aux;
	size_t pos = 0;
	int cont = 0;
	myfile.open(doc_name);

	if (myfile.is_open()) {
		while(!myfile.eof()) {
			getline(myfile, line);
			aux.word = line;
			while ((pos = line.find(delimiter)) != string::npos) {
				aux.word = (line.substr(0, pos));
				line.erase(0, pos + delimiter.size());
				auxiliar = aux.word;
				auxiliar_2 = string_treatment(auxiliar);
				aux.word = auxiliar_2;

				if (aux.word.size() == 1) {
					check_if_stopword(doc, sw1, aux);
				} else if (aux.word.size() == 2) {
					check_if_stopword(doc, sw2, aux);
				} else if (aux.word.size() == 3) {
					check_if_stopword(doc, sw3, aux);
				} else if (aux.word.size() == 4) {
					check_if_stopword(doc, sw4, aux);
				} else if (aux.word.size() == 5) {
					check_if_stopword(doc, sw5, aux);
				} else if (aux.word.size() == 6) {
					check_if_stopword(doc, sw6, aux);
				} else if (aux.word.size() == 7) {
					check_if_stopword(doc, sw7, aux);
				} else if (aux.word.size() == 8) {
					check_if_stopword(doc, sw8, aux);
				} else if (aux.word.size() == 9) {
					check_if_stopword(doc, sw9, aux);
				} else if (aux.word.size() == 10) {
					check_if_stopword(doc, sw10, aux);
				} else if (aux.word.size() == 11) {
					check_if_stopword(doc, sw11, aux);
				} else if (aux.word.size() == 12) {
					check_if_stopword(doc, sw12, aux);
				} else if (aux.word.size() == 13) {
					check_if_stopword(doc, sw13, aux);
				}
				cont++;
			}
		}
	} else {
		cout << "nao abriu";
	}

	Block *tmp;
	tmp = doc -> first -> prox;
	tmp -> cont.total_words = cont;
	// LImprime(doc);
}

//////////////////////////////////////////////////////////////////////////////////////

bool verify_if_word_exist(List *wordcount, string word) {
	Block *aux;

	aux = wordcount -> first -> prox;

	while (aux != NULL) {
		if (aux -> single_cont.word == word) {
			return true;
		}

		aux = aux -> prox;
	}

	return false;
}

void fill_list_with_cont(List *document, List *wordcount) {
	Block *aux_main_document;
	string aux_str;
	Block *tmp;
	WordCounter aux_insert;

	aux_main_document = document -> first -> prox;

	while (aux_main_document != NULL) {
		aux_str = aux_main_document -> data.word;	
		if (verify_if_word_exist(wordcount, aux_str)) {
			tmp = wordcount -> first -> prox;
			while (tmp != NULL) {
				if (tmp -> single_cont.word == aux_main_document -> data.word) {
					tmp->single_cont.contador++;
				}

				tmp = tmp -> prox;
			}
		} else {
			aux_insert.word = aux_main_document -> data.word;
			aux_insert.contador = 1;
			LInsertWordCounter(wordcount, aux_insert);
		}
	
		aux_main_document = aux_main_document -> prox;
	}
}

void sorting_alphabetically(List *doc) {
	Block *i, *j;

	i = doc -> first -> prox;

	while (i != NULL) {
		j = i-> prox;
		while (j != NULL) {
			if (j -> single_cont.word < i -> single_cont.word) {
				swap (i, j);
			}

			j = j -> prox;
		}

		i = i -> prox;
	}
}

void tf_idf() {
	List sw1, sw2, sw3, sw4, sw5, sw6, sw7, sw8, sw9, sw10, sw11, sw12, sw13;
    FLVazia(&sw1);
    FLVazia(&sw2);
    FLVazia(&sw3);
    FLVazia(&sw4);
    FLVazia(&sw5);
    FLVazia(&sw6);
    FLVazia(&sw7);
    FLVazia(&sw8);
    FLVazia(&sw9);
    FLVazia(&sw10);
    FLVazia(&sw11);
    FLVazia(&sw12);
    FLVazia(&sw13);
	
	filter_stop_words(&sw1, &sw2, &sw3, &sw4, &sw5, &sw6, &sw7, &sw8, &sw9, &sw10, &sw11, &sw12, &sw13);

	List document_1, document_2, document_3, document_4, document_5, document_6;
	string doc_name;
	FLVazia(&document_1);
	FLVazia(&document_2);
	FLVazia(&document_3);
	FLVazia(&document_4);
	FLVazia(&document_5);
	FLVazia(&document_6);

	// Função para tokenizar todo um documento, também excluindo essas stop words do texto
	// cout << endl << endl << "\t\t\t\tDOCUMENTO 1" << endl << endl;
	doc_name = "doc1.txt";
	filter_documents(&document_1, doc_name, &sw1, &sw2, &sw3, &sw4, &sw5, &sw6, &sw7, &sw8, &sw9, &sw10, &sw11, &sw12, &sw13);

	// cout << endl << endl << "primeira palavra: " << document_1.first->prox->data.word << endl;
	// cout << "total de palavras: " << document_1.first->prox->cont.total_words;

	// cout << endl << endl << "\t\t\t\tDOCUMENTO 2" << endl << endl;
	doc_name = "doc2.txt";
	filter_documents(&document_2, doc_name, &sw1, &sw2, &sw3, &sw4, &sw5, &sw6, &sw7, &sw8, &sw9, &sw10, &sw11, &sw12, &sw13);

	// cout << endl << endl << "primeira palavra: " << document_2.first->prox->data.word << endl;
	// cout << "total de palavras: " << document_2.first->prox->cont.total_words;

	// cout << endl << endl << "\t\t\t\tDOCUMENTO 3" << endl << endl;
	doc_name = "doc3.txt";
	filter_documents(&document_3, doc_name, &sw1, &sw2, &sw3, &sw4, &sw5, &sw6, &sw7, &sw8, &sw9, &sw10, &sw11, &sw12, &sw13);

	// cout << endl << endl << "primeira palavra: " << document_3.first->prox->data.word << endl;
	// cout << "total de palavras: " << document_3.first->prox->cont.total_words;

	// cout << endl << endl << "\t\t\t\tDOCUMENTO 4" << endl << endl;
	doc_name = "doc4.txt";
	filter_documents(&document_4, doc_name, &sw1, &sw2, &sw3, &sw4, &sw5, &sw6, &sw7, &sw8, &sw9, &sw10, &sw11, &sw12, &sw13);
	
	// cout << endl << endl << "primeira palavra: " << document_4.first->prox->data.word << endl;
	// cout << "total de palavras: " << document_4.first->prox->cont.total_words;

	// cout << endl << endl << "\t\t\t\tDOCUMENTO 5" << endl << endl;
	doc_name = "doc5.txt";
	filter_documents(&document_5, doc_name, &sw1, &sw2, &sw3, &sw4, &sw5, &sw6, &sw7, &sw8, &sw9, &sw10, &sw11, &sw12, &sw13);

	// cout << endl << endl << "primeira palavra: " << document_5.first->prox->data.word << endl;
	// cout << "total de palavras: " << document_5.first->prox->cont.total_words;

	// cout << endl << endl << "\t\t\t\tDOCUMENTO 6" << endl << endl;
	doc_name = "doc6.txt";
	filter_documents(&document_6, doc_name, &sw1, &sw2, &sw3, &sw4, &sw5, &sw6, &sw7, &sw8, &sw9, &sw10, &sw11, &sw12, &sw13);

	// cout << endl << endl << "primeira palavra: " << document_6.first->prox->data.word << endl;
	// cout << "total de palavras: " << document_6.first->prox->cont.total_words;

	List wordcounter_doc1, wordcounter_doc2, wordcounter_doc3, wordcounter_doc4, wordcounter_doc5, wordcounter_doc6;
	FLVazia(&wordcounter_doc1);
	FLVazia(&wordcounter_doc2);
	FLVazia(&wordcounter_doc3);
	FLVazia(&wordcounter_doc4);
	FLVazia(&wordcounter_doc5);
	FLVazia(&wordcounter_doc6);

	fill_list_with_cont(&document_1, &wordcounter_doc1);
	sorting_alphabetically(&wordcounter_doc1);

	fill_list_with_cont(&document_2, &wordcounter_doc2);
	sorting_alphabetically(&wordcounter_doc2);

	fill_list_with_cont(&document_3, &wordcounter_doc3);
	sorting_alphabetically(&wordcounter_doc3);

	fill_list_with_cont(&document_4, &wordcounter_doc4);
	sorting_alphabetically(&wordcounter_doc4);

	LImprimeWordCounter(&wordcounter_doc4);

	fill_list_with_cont(&document_5, &wordcounter_doc5);
	sorting_alphabetically(&wordcounter_doc5);

	fill_list_with_cont(&document_6, &wordcounter_doc6);
	sorting_alphabetically(&wordcounter_doc6);

	/////////////////////////
	//  				   //
	//  REALIZANDO TESTES  //
	//                     //
	/////////////////////////
}