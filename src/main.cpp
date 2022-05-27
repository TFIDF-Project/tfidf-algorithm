#include "list.hpp"

int main()
{
	List lw1, lw2, lw3, lw4, lw5, lw6, lw7, lw8, lw9, lw10, lw11, lw12, lw13; //Listas de stopwords
	// List ldocs;
	Item aux, doc;

	readStopWords(&lw1, &lw2, &lw3, &lw4, &lw5, &lw6, &lw7, &lw8, &lw9, &lw10, &lw11, &lw12, &lw13, aux);

	// readDocuments(&ldocs, doc);
	// LImprime(&ldocs);

	printStopWordsLists(&lw1, &lw2, &lw3, &lw4, &lw5, &lw6, &lw7, &lw8, &lw9, &lw10, &lw11, &lw12, &lw13);

	return 0;
}