#include "list.hpp"

void Swap(Block *a, Block *b){
	Item aux;
	aux = a->data;
	a->data = b->data;
	b->data = aux;
}

void FLVazia(List *l){
	l->first = (Block*) malloc (sizeof(Block));
	l->last  = l->first;
	l->first->prox = NULL;
}

void LInsert(List *l, Item d){
	l->last->prox = (Block*) malloc (sizeof(Block));
	l->last = l->last->prox;
	l->last->data = d;
	l->last->prox = NULL;
}

void LRemove(List *l, Item d){
	Block *aux, *tmp;

	if(l->first == l->last || l == NULL || l->first->prox == NULL){
		printf("LISTA VAZIA!\n");
		return;
	}
	
	aux = l->first;
	while(aux->prox != NULL){
		if (aux->prox->data.word == d.word){
			tmp = aux;
			aux = aux->prox;
			tmp->prox = aux->prox;
			if (aux == l->last)
				l->last = tmp;
			free(aux);
			aux->prox = NULL;
		}
		else
			aux = aux->prox;
	}
}


void LImprime(List *l){
	Block *aux;

	aux = l->first->prox;
	while(aux != NULL){
		cout << aux->data.word << endl;
		aux = aux->prox;
	}
}


//Função que lê o arquivo .txt contendo as stopwords e às tokeniza inserindo-as cada uma em uma posição da lista dinâmica.
void readStopWords(List *lw1, List *lw2, List *lw3, List *lw4, List *lw5, List *lw6, List *lw7, List *lw8, List *lw9, List *lw10, List *lw11, List *lw12, List *lw13, Item d){
	FLVazia(lw1);
	FLVazia(lw2);
	FLVazia(lw3);
	FLVazia(lw4);
	FLVazia(lw5);
	FLVazia(lw6);
	FLVazia(lw7);
	FLVazia(lw8);
	FLVazia(lw9);
	FLVazia(lw10);
	FLVazia(lw11);
	FLVazia(lw12);
	FLVazia(lw13);

	string line;
	ifstream my_file;
	int numberCaracters;

	my_file.open("stopwords_portuguese.txt");

	if(my_file.is_open()){
		while(! my_file.eof()){
			getline(my_file, line);
			d.word = line;
			numberCaracters = line.length(); //Contagem do número de caracteres das stopwords.

			//Se a palavra ter 1 caractere, será inserida na Lista lw1.
			if(numberCaracters == 2){
				LInsert(lw1, d);
			}
			//Se a palavra ter 2 caracteres, será inserida na Lista lw2.
			else if(numberCaracters == 3){
				LInsert(lw2, d);
			}
			//Se a palavra ter 3 caracteres, será inserida na Lista lw3.
			else if(numberCaracters == 4){
				LInsert(lw3, d);
			}
			//Se a palavra ter 4 caracteres, será inserida na Lista lw4.
			else if(numberCaracters == 5){
				LInsert(lw4, d);
			}
			//Se a palavra ter 5 caracteres, será inserida na Lista lw5.
			else if(numberCaracters == 6){
				LInsert(lw5, d);
			}
			//Se a palavra ter 6 caracteres, será inserida na Lista lw6.
			else if(numberCaracters == 7){
				LInsert(lw6, d);
			}
			//Se a palavra ter 7 caracteres, será inserida na Lista lw7.
			else if(numberCaracters == 8){
				LInsert(lw7, d);
			}
			//Se a palavra ter 8 caracteres, será inserida na Lista lw8.
			else if(numberCaracters == 9){
				LInsert(lw8, d);
			}
			//Se a palavra ter 9 caracteres, será inserida na Lista lw9.
			else if(numberCaracters == 10){
				LInsert(lw9, d);
			}
			//Se a palavra ter 10 caracteres, será inserida na Lista lw10.
			else if(numberCaracters == 11){
				LInsert(lw10, d);
			}
			//Se a palavra ter 11 caracteres, será inserida na Lista lw11.
			else if(numberCaracters == 12){
				LInsert(lw11, d);
			}
			//Se a palavra ter 12 caracteres, será inserida na Lista lw12.
			else if(numberCaracters == 13){
				LInsert(lw12, d);
			}
			//Se a palavra ter 13 caracteres, será inserida na Lista lw13.
			else if(numberCaracters == 14){
				LInsert(lw13, d);
			}
		}
		my_file.close(); //Fecha o arquivo de texto.
		cout << "\n";
	}

	else{
		cout << "Arquivo não abriu.\n";
	} 
}


//Printa todas as listas de stopwords.
void printStopWordsLists(List *lw1, List *lw2, List *lw3, List *lw4, List *lw5, List *lw6, List *lw7, List *lw8, List *lw9, List *lw10, List *lw11, List *lw12, List *lw13){
	
	cout << "\n\tLista de 1 caractere\n\n";
	LImprime(lw1);

	cout << "\n\tLista de 2 caracteres\n\n";
	LImprime(lw2);

	cout << "\n\tLista de 3 caracteres\n\n";
	LImprime(lw3);

	cout << "\n\tLista de 4 caracteres\n\n";
	LImprime(lw4);

	cout << "\n\tLista de 5 caracteres\n\n";
	LImprime(lw5);

	cout << "\n\tLista de 6 caracteres\n\n";
	LImprime(lw6);

	cout << "\n\tLista de 7 caracteres\n\n";
	LImprime(lw7);	

	cout << "\n\tLista de 8 caracteres\n\n";
	LImprime(lw8);

	cout << "\n\tLista de 9 caracteres\n\n";
	LImprime(lw9);

	cout << "\n\tLista de 10 caracteres\n\n";
	LImprime(lw10);

	cout << "\n\tLista de 11 caracteres\n\n";
	LImprime(lw11);

	cout << "\n\tLista de 12 caracteres\n\n";
	LImprime(lw12);

	cout << "\n\tLista de 13 caracteres\n\n";
	LImprime(lw13);		
}


//Função para ler os documentos de texto para fazer ranqueamento das palavras encontradas nestes documentos. (DANDO ERRO)
void readDocuments(List *ldoc, Item d){
	FLVazia(ldoc);

	string line;
	ifstream my_file;
	int numberDocuments;

	cout << "Insira a quantidade de documentos que deseja ler: ";
	cin >> numberDocuments;

	string vetDocuments[numberDocuments];

	for(int i = 0; i < numberDocuments; i++){
		cout << "Insira o nome do documento " << i << " que deseja ler: ";
		cin >> vetDocuments[i];
	}

	for(int i = 0; i < numberDocuments; i++){
		
		my_file.open(vetDocuments[i]);

		if(my_file.is_open()){
			while(! my_file.eof()){
				getline(my_file, line);
				d.word = line;
				LInsert(ldoc, d);
			}
			my_file.close();
			cout << "\n";
		}

		else{
			cout << "Arquivo não abriu.\n";
		} 
	}
}