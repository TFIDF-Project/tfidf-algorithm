#include "list.hpp"
using namespace std;

void Swap(Block *a, Block *b){
	Item aux;
	aux = a -> data;
	a -> data = b -> data;
	b -> data = aux;
	
}

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

/////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////

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

// MUDANDO AQUI

void LInsertContWordSeen(List *l, ContWordSeen d){
	l -> last -> prox = new Block;
	l -> last = l -> last -> prox;
	l -> last -> cont_all_documents = d;
	l -> last -> prox = NULL;
}

void check_if_stopword_final_cont(List *main_doc, List *sw, ContWordSeen aux) {
	Block *aux_block;

	aux_block = sw->first->prox;

	while (aux_block != NULL) {
		if (aux.word == aux_block -> data.word) {
			return;
		}

		aux_block = aux_block -> prox;
	}

	// aux.contador = 0;
	LInsertContWordSeen(main_doc, aux);
}

// FINALIZADO AS MUDANÇAS

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

//////////////////////////////////////// LEITURA DE TEXTO ////////////////////////////////////////

void read_phrase(List *doc, string doc_name, List *sw1, List *sw2, List *sw3, List *sw4, List *sw5, List *sw6, List *sw7, List *sw8, List *sw9, 
List *sw10, List *sw11, List *sw12, List *sw13) {
	ifstream myfile;
	string line, auxiliar, auxiliar_2, delimiter = " ";
	ContWordSeen aux;
	size_t pos = 0;
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
					check_if_stopword_final_cont(doc, sw1, aux);
				} else if (aux.word.size() == 2) {
					check_if_stopword_final_cont(doc, sw2, aux);
				} else if (aux.word.size() == 3) {
					check_if_stopword_final_cont(doc, sw3, aux);
				} else if (aux.word.size() == 4) {
					check_if_stopword_final_cont(doc, sw4, aux);
				} else if (aux.word.size() == 5) {
					check_if_stopword_final_cont(doc, sw5, aux);
				} else if (aux.word.size() == 6) {
					check_if_stopword_final_cont(doc, sw6, aux);
				} else if (aux.word.size() == 7) {
					check_if_stopword_final_cont(doc, sw7, aux);
				} else if (aux.word.size() == 8) {
					check_if_stopword_final_cont(doc, sw8, aux);
				} else if (aux.word.size() == 9) {
					check_if_stopword_final_cont(doc, sw9, aux);
				} else if (aux.word.size() == 10) {
					check_if_stopword_final_cont(doc, sw10, aux);
				} else if (aux.word.size() == 11) {
					check_if_stopword_final_cont(doc, sw11, aux);
				} else if (aux.word.size() == 12) {
					check_if_stopword_final_cont(doc, sw12, aux);
				} else if (aux.word.size() == 13) {
					check_if_stopword_final_cont(doc, sw13, aux);
				}
			}
		}
	} else {
		cout << "nao abriu";
	}

}

//////////////////////////////////////// LEITURA DE TEXTO ////////////////////////////////////////

void verify_how_many_times_seen(List *input, List *document) {
	Block *aux_input, *aux_document;

	aux_input = input->first->prox;
	
	while (aux_input != NULL) {
		aux_document = document->first->prox;
		while (aux_document != NULL) {
			if (aux_document->data.word == aux_input->cont_all_documents.word) {
				aux_input->cont_all_documents.contador++;
				aux_document = document -> last;
			}

			aux_document = aux_document -> prox;
		}

		aux_input = aux_input -> prox;
	}
}

void print(List *input) {
	Block *aux;

	aux = input->first->prox;

	while (aux != NULL) {
		cout << "PALAVRA: " << aux->cont_all_documents.word << "\t\tCONTADOR: " << aux->cont_all_documents.contador << endl << endl;
		aux = aux -> prox;
	}
}

// SE DER MERDA, COMECOU A DAR AQUI

// void tf_calc() {

// }

// void tf_idf_calc(List *input/*, List *wordcounter, List *document*/) {
// 	Block *aux_input;
// 	aux_input = input -> first -> prox;
// 	// float idf;
// 	// int i;
// 	// int final_tf_idf[6];

// 	while (aux_input != NULL) {
// 		if (aux_input->cont_all_documents.contador != 0) {
// 			// idf = log10(6 / aux_input->cont_all_documents.contador);
// 			// cout << idf << endl;

// 			for (int j = 0; j < 6; j++) {
				
// 			}


// 		} else {
// 			// idf = 0;
// 		}

// 		//final_tf_idf[i] = idf*tf;

// 		aux_input = aux_input -> prox;
// 		// i++;
// 	}
// }

int find_word_cont(List *wordcounter, string to_find) {
	Block *aux;
	aux = wordcounter->first->prox;

	while (aux != NULL) {
		// cout << "STRING: " << to_find << "\tNA LISTA: " << aux->cont_all_documents.word << "\tCONTADOR: " << aux->cont_all_documents.contador << endl; 
		
		if (aux->single_cont.word == to_find) {
			// cout << "\n\n\nihdfisdhgfosdghsopdighbsdiugbsduigbsdgbsdg" << endl << endl << endl;
			return aux->single_cont.contador;
		}
		
		aux = aux -> prox;
	}

	return 0;
}

void tf_idf_calc(List *input, List *wordcounter_doc1, List *wordcounter_doc2, List *wordcounter_doc3, List *wordcounter_doc4, List *wordcounter_doc5, List *wordcounter_doc6,
List *document_1, List *document_2, List *document_3, List *document_4, List *document_5, List *document_6) {
	Block *aux_input;
	float idf, tf, final_tfidf[6];
	int i, occurrences, total;
	aux_input = input->first->prox;
	vector <string> ranking;

	ranking.push_back("1st Document");
	ranking.push_back("2nd Document");
	ranking.push_back("3rd Document");
	ranking.push_back("4th Document");
	ranking.push_back("5th Document");
	ranking.push_back("6th Document");


	for (i = 0; i < 6; i++) {
		final_tfidf[i] = 0;
	}

	while (aux_input != NULL) {
		i = 0;
		// cout << aux_input->cont_all_documents.word; // para encontrar a palavra cont_all_documents.word
		// cout << aux_input->cont_all_documents.contador; // para encontrar o contador da determinada palavra em todos os documentos cont_all_documents.contador

		// pegar a palavra atual e realizar o idf PARA A PALAVRA
		if (aux_input -> cont_all_documents.contador != 0) {
			idf = log10(6 / aux_input->cont_all_documents.contador);
		} else {
			idf = 0;
		}
	
		// cout << "\t\tIDF: " << idf << endl;
			
		// agora que calculei o IDF para uma palavra especifica, vou calcular o tf para essa palavra e logo em seguida o tfidf da palavra no documento, salvando em um vetor 

		occurrences = find_word_cont(wordcounter_doc1, aux_input->cont_all_documents.word);
		total = document_1 ->first->prox->cont.total_words;
		if (occurrences == 0) {
			tf = 0;
		} else {
			tf = (float)occurrences / (float)total;
		}
		final_tfidf[i] += (tf*idf);
		i++;

		// cout << "Palavra: " << aux_input->cont_all_documents.word << "\t\t\t\tAparições: " << aux_input->cont_all_documents.contador;
		// cout << "\t\t\t\tTF palavra: " << tf << "\t\t\t\tIDF palavra: " << idf << endl;; 

		occurrences = find_word_cont(wordcounter_doc2, aux_input->cont_all_documents.word);
		total = document_2 ->first->prox->cont.total_words;
		if (occurrences == 0) {
			tf = 0;
		} else {
			tf = (float)occurrences / (float)total;
		}
		final_tfidf[i] += (tf*idf);
		i++;

		occurrences = find_word_cont(wordcounter_doc3, aux_input->cont_all_documents.word);
		total = document_3 ->first->prox->cont.total_words;
		if (occurrences == 0) {
			tf = 0;
		} else {
			tf = (float)occurrences / (float)total;
		}
		final_tfidf[i] += (tf*idf);
		i++;

		occurrences = find_word_cont(wordcounter_doc4, aux_input->cont_all_documents.word);
		total = document_4 ->first->prox->cont.total_words;
		if (occurrences == 0) {
			tf = 0;
		} else {
			tf = (float)occurrences / (float)total;
		}
		final_tfidf[i] += (tf*idf);
		i++;

		occurrences = find_word_cont(wordcounter_doc5, aux_input->cont_all_documents.word);
		total = document_5 ->first->prox->cont.total_words;
		if (occurrences == 0) {
			tf = 0;
		} else {
			tf = (float)occurrences / (float)total;
		}
		final_tfidf[i] += (tf*idf);
		i++;

		occurrences = find_word_cont(wordcounter_doc6, aux_input->cont_all_documents.word);
		total = document_6 ->first->prox->cont.total_words;
		if (occurrences == 0) {
			tf = 0;
		} else {
			tf = (float)occurrences / (float)total;
		}
		final_tfidf[i] += (tf*idf);
		i++;

		aux_input = aux_input -> prox;
	}

	string aux;
	float auxiliar;

	for (i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (final_tfidf[i] < final_tfidf[j]) {
				auxiliar = final_tfidf[i]; aux = ranking[i];
				final_tfidf[i] = final_tfidf[j]; ranking[i] = ranking[j];
				final_tfidf[j] = auxiliar; ranking[j] = aux;
			}
		}
	}

	cout << endl << endl;
	for (i = 0; i < 6; i++) {
		// cout << "TF/IDF documento " << i + 1 << ": " << final_tfidf[i] << endl;
		cout << ranking[i] << endl; 
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

	List input;
	FLVazia(&input);
	read_phrase(&input, "phrasetosearch.txt", &sw1, &sw2, &sw3, &sw4, &sw5, &sw6, &sw7, &sw8, &sw9, &sw10, &sw11, &sw12, &sw13);

	LImprime(&input);

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
	// LImprimeWordCounter(&wordcounter_doc1);
	// cout << endl << endl;

	fill_list_with_cont(&document_2, &wordcounter_doc2);
	sorting_alphabetically(&wordcounter_doc2);

	fill_list_with_cont(&document_3, &wordcounter_doc3);
	sorting_alphabetically(&wordcounter_doc3);

	fill_list_with_cont(&document_4, &wordcounter_doc4);
	sorting_alphabetically(&wordcounter_doc4);

	fill_list_with_cont(&document_5, &wordcounter_doc5);
	sorting_alphabetically(&wordcounter_doc5);

	fill_list_with_cont(&document_6, &wordcounter_doc6);
	sorting_alphabetically(&wordcounter_doc6);

	/////////////////////////////////////
	//  				   			   //
	//  REALIZANDO TESTES - QUICKSORT  //
	//                     			   //
	/////////////////////////////////////

	// Block *aux_input, *aux_document;

	// aux_input = input.first->prox;
	// aux_document = document_1.first->prox;

	// string word;

	// while (aux_input != NULL) {
	// 	aux_document = document_1.first->prox;
	// 	while (aux_document != NULL) {
	// 		if (aux_document->data.word == aux_input->cont_all_documents.word) {
	// 			aux_input->cont_all_documents.contador++;
	// 			break;
	// 		}

	// 		aux_document = aux_document -> prox;
	// 	}
	// 	cout << "PALAVRA: " << aux_input->cont_all_documents.word << endl;
	// 	cout << "CONTADOR DA PALAVRA DIGITADA NO DOCUMENTO 1: " << aux_input->cont_all_documents.contador << endl << endl;

	// 	aux_input = aux_input -> prox;
	// }

	verify_how_many_times_seen(&input, &document_1);
	print(&input);

	cout << endl << endl;
	verify_how_many_times_seen(&input, &document_2);
	print(&input);

	cout << endl << endl;
	verify_how_many_times_seen(&input, &document_3);
	print(&input);

	cout << endl << endl;
	verify_how_many_times_seen(&input, &document_4);
	print(&input);

	cout << endl << endl;
	verify_how_many_times_seen(&input, &document_5);
	print(&input);

	cout << endl << endl;
	verify_how_many_times_seen(&input, &document_6);
	print(&input);

	// SE DER MERDA, COMECOU A DAR AQUI

		// idf - tf

			// número total de documentos - 6
			// total de documentos em que o termo apareceu

				// para visualizar o total de documentos em que a palavra apareceu:
					// abrir a lista input, procurar a palavra desejada, visualizar o .contador (ContWordSeen)
					// realizar o cálculo para a palavra desejada
					// log(6 / .contador)
					// finalizado o calculo do idf.

				// para visualizar o total de vezes que a palavra apareceu
					// abrir a lista wordcounter, procurar a palavra desejada, visualizar o .contador (ContWordSeen) -> número de aparições de X palavra
					// abrir a lista document, visualizar a posição first->prox.total_words -> total de palavras no documento.
					// total_de_aparições / total_de_palavras
					// finalizado o cáculo do tf.

			// multiplicar tf x idf;
			// aumentar no somatório total do documento.
			// jogar em um vetor ao finalizar todo o somatório.

	tf_idf_calc(&input, &wordcounter_doc1, &wordcounter_doc2, &wordcounter_doc3, &wordcounter_doc4, &wordcounter_doc5, &wordcounter_doc6,
	&document_1, &document_2, &document_3, &document_4, &document_5, &document_6);
}

// int find_word_cont(List *wordcounter, string to_find) {
// 	Block *aux;
// 	aux = wordcounter->first->prox;

// 	while (aux != NULL) {
// 		if (aux->cont_all_documents.word == to_find) {
// 			return aux->cont_all_documents.contador;
// 		}

// 		aux = aux -> prox;
// 	}

// 	return 0;
// }




// para visualizar o total de vezes que a palavra apareceu
		// abrir a lista wordcounter, procurar a palavra desejada, visualizar o .contador (ContWordSeen) -> número de aparições de X palavra
		// abrir a lista document, visualizar a posição first->prox.total_words -> total de palavras no documento.
		// total_de_aparições / total_de_palavras
		// finalizado o cáculo do tf.


/*
	PARA O CÁLCULO
		W = numero de vezes que o termo aparece no documento - FEITO
			O número total de palavras no documento está na primeira posição das listas nomeadas de "document"
				Para verificar: cout << document_x.first->prox->cont.total_words;
		X = numero de palavras no documento - FEITO
		Y = numero de documentos que o termo apareceu 
			Criar função para encontrar o termo, se ele aparecer, return true, se não, return false.
		Z = numero total de documentos - 6

	6 DOCUMENTOS - 
	PALAVRA X
	DOC 1 - 6
	DOC 2 - 4
	DOC 3 - 0
	.
	.
	.

	VETOR -> PALAVRA
		VETOR (6 POSIÇÕES) -> QUANTAS VEZES CADA PALAVRA APARECEU
*/






