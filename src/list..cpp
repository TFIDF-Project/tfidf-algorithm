#include "list.hpp"

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

std::string string_treatment(std::string s) {
	int size = s.size();
	std::string aux;

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
	std::ifstream myfile;
	std::string line;
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

	LInsertContWordSeen(main_doc, aux);
}

void filter_documents(List *doc, std::string doc_name, List *sw1, List *sw2, List *sw3, List *sw4, List *sw5, List *sw6, List *sw7, List *sw8, List *sw9, 
List *sw10, List *sw11, List *sw12, List *sw13) {
	std::ifstream myfile;
	std::string line, auxiliar, auxiliar_2, delimiter = " ";
	Item aux;
	size_t pos = 0;
	int cont = 0;
	myfile.open(doc_name);

	if (myfile.is_open()) {
		while(!myfile.eof()) {
			getline(myfile, line);
			aux.word = line;
			while ((pos = line.find(delimiter)) != std::string::npos) {
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
				} else {
					LInsert(doc, aux);
				}
				cont++;
			}
		}
	} else {
		std::cout << "nao abriu";
	}
}

bool verify_if_word_exist(List *wordcount, std::string word) {
	Block *aux;

	aux = wordcount -> first -> prox;

	while (aux != NULL) {
		if (aux -> single_cont.word == word) {
			aux -> single_cont.contador++;
			return true;
		}

		aux = aux -> prox;
	}

	return false;
}

void fill_list_with_cont(List *document, List *wordcount) {
	Block *aux_main_document;
	std::string aux_str;
	Block *tmp;
	WordCounter aux_insert;
	int cont = 0;

	aux_main_document = document -> first -> prox;

	while (aux_main_document != NULL) {
		aux_str = aux_main_document -> data.word;	
		if (!verify_if_word_exist(wordcount, aux_str)) {
			aux_insert.word = aux_main_document -> data.word;
			aux_insert.contador = 1;
			LInsertWordCounter(wordcount, aux_insert);
		}

		cont++;
		aux_main_document = aux_main_document -> prox;
	}

	tmp = document -> first->prox;
	tmp->cont.total_words = cont;
}

void read_phrase(List *doc, std::string doc_name, List *sw1, List *sw2, List *sw3, List *sw4, List *sw5, List *sw6, List *sw7, List *sw8, List *sw9, 
List *sw10, List *sw11, List *sw12, List *sw13) {
	std::ifstream myfile;
	std::string line, auxiliar, auxiliar_2, delimiter = " ";
	ContWordSeen aux;
	size_t pos = 0;
	myfile.open(doc_name);

	if (myfile.is_open()) {
		while(!myfile.eof()) {
			getline(myfile, line);
			aux.word = line;
			while ((pos = line.find(delimiter)) != std::string::npos) {
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
		std::cout << "nao abriu";
	}

}

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

int find_word_cont(List *wordcounter, std::string to_find) {
	Block *aux;
	aux = wordcounter->first->prox;

	while (aux != NULL) {
		if (aux->single_cont.word == to_find) {
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
	std::vector <std::string> ranking;

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

		if (aux_input -> cont_all_documents.contador != 0) {
			idf = log10(6 / aux_input->cont_all_documents.contador);
		} else {
			idf = 0;
		}

		occurrences = find_word_cont(wordcounter_doc1, aux_input->cont_all_documents.word);
		total = document_1 ->first->prox->cont.total_words;
		if (occurrences == 0) {
			tf = 0;
		} else {
			tf = (float)occurrences / (float)total;
		}
		final_tfidf[i] += (tf*idf);
		i++;

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

	std::string aux;
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

	std::cout << std::endl << std::endl;
	for (i = 0; i < 6; i++) {
		std::cout << ranking[i] << std::endl; 
	}
}

void tf_idf() {
	size_t t;
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
	
	t = clock();
	filter_stop_words(&sw1, &sw2, &sw3, &sw4, &sw5, &sw6, &sw7, &sw8, &sw9, &sw10, &sw11, &sw12, &sw13);
	t = clock() - t;
	std::cout << "\nTempo stopwords: " << float(t)/CLOCKS_PER_SEC << std::endl << std::endl;

	List input;
	FLVazia(&input);
	read_phrase(&input, "phrasetosearch.txt", &sw1, &sw2, &sw3, &sw4, &sw5, &sw6, &sw7, &sw8, &sw9, &sw10, &sw11, &sw12, &sw13);

	List document_1, document_2, document_3, document_4, document_5, document_6;
	std::string doc_name;
	FLVazia(&document_1);
	FLVazia(&document_2);
	FLVazia(&document_3);
	FLVazia(&document_4);
	FLVazia(&document_5);
	FLVazia(&document_6);

	t = clock();
	doc_name = "filosofia.txt";
	filter_documents(&document_1, doc_name, &sw1, &sw2, &sw3, &sw4, &sw5, &sw6, &sw7, &sw8, &sw9, &sw10, &sw11, &sw12, &sw13);

	doc_name = "filosofia2.txt";
	filter_documents(&document_2, doc_name, &sw1, &sw2, &sw3, &sw4, &sw5, &sw6, &sw7, &sw8, &sw9, &sw10, &sw11, &sw12, &sw13);

	doc_name = "globalizacao.txt";
	filter_documents(&document_3, doc_name, &sw1, &sw2, &sw3, &sw4, &sw5, &sw6, &sw7, &sw8, &sw9, &sw10, &sw11, &sw12, &sw13);

	doc_name = "politica.txt";
	filter_documents(&document_4, doc_name, &sw1, &sw2, &sw3, &sw4, &sw5, &sw6, &sw7, &sw8, &sw9, &sw10, &sw11, &sw12, &sw13);
	
	doc_name = "ti.txt";
	filter_documents(&document_5, doc_name, &sw1, &sw2, &sw3, &sw4, &sw5, &sw6, &sw7, &sw8, &sw9, &sw10, &sw11, &sw12, &sw13);

	doc_name = "ti2.txt";
	filter_documents(&document_6, doc_name, &sw1, &sw2, &sw3, &sw4, &sw5, &sw6, &sw7, &sw8, &sw9, &sw10, &sw11, &sw12, &sw13);
	t = clock() - t;

	std::cout << "\nTempo leitura de documentos: " << float(t)/CLOCKS_PER_SEC << std::endl << std::endl;


	List wordcounter_doc1, wordcounter_doc2, wordcounter_doc3, wordcounter_doc4, wordcounter_doc5, wordcounter_doc6;
	FLVazia(&wordcounter_doc1);
	FLVazia(&wordcounter_doc2);
	FLVazia(&wordcounter_doc3);
	FLVazia(&wordcounter_doc4);
	FLVazia(&wordcounter_doc5);
	FLVazia(&wordcounter_doc6);

	t = clock();
	fill_list_with_cont(&document_1, &wordcounter_doc1);
	fill_list_with_cont(&document_2, &wordcounter_doc2);
	fill_list_with_cont(&document_3, &wordcounter_doc3);
	fill_list_with_cont(&document_4, &wordcounter_doc4);
	fill_list_with_cont(&document_5, &wordcounter_doc5);
	fill_list_with_cont(&document_6, &wordcounter_doc6);
	t = clock() - t;
	std::cout << "\nTempo contador de cada palavra: " << float(t)/CLOCKS_PER_SEC << std::endl << std::endl;

	t = clock();
	verify_how_many_times_seen(&input, &document_1);
	verify_how_many_times_seen(&input, &document_2);
	verify_how_many_times_seen(&input, &document_3);
	verify_how_many_times_seen(&input, &document_4);
	verify_how_many_times_seen(&input, &document_5);
	verify_how_many_times_seen(&input, &document_6);
	t = clock() - t;
	std::cout << "\nTempo contador de cada palavra total documentos: " << float(t)/CLOCKS_PER_SEC << std::endl << std::endl;

	tf_idf_calc(&input, &wordcounter_doc1, &wordcounter_doc2, &wordcounter_doc3, &wordcounter_doc4, &wordcounter_doc5, &wordcounter_doc6,
	&document_1, &document_2, &document_3, &document_4, &document_5, &document_6);
}