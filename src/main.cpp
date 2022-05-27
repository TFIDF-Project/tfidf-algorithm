#include "list.hpp"

int main()
{
	List lw1, lw2, lw3, lw4, lw5, lw6, lw7, lw8, lw9, lw10, lw11, lw12, lw13;
	Item aux;

	FLVazia(&lw1);
	FLVazia(&lw2);
	FLVazia(&lw3);
	FLVazia(&lw4);
	FLVazia(&lw5);
	FLVazia(&lw6);
	FLVazia(&lw7);
	FLVazia(&lw8);
	FLVazia(&lw9);
	FLVazia(&lw10);
	FLVazia(&lw11);
	FLVazia(&lw12);
	FLVazia(&lw13);

	readStopWords(&lw1, &lw2, &lw3, &lw4, &lw5, &lw6, &lw7, &lw8, &lw9, &lw10, &lw11, &lw12, &lw13, aux);

	//Testando as inserções das listas de stopswords.

	cout << "\n\tLista de 1 caractere\n\n";
	LImprime(&lw1);

	cout << "\n\tLista de 2 caracteres\n\n";
	LImprime(&lw2);

	cout << "\n\tLista de 3 caracteres\n\n";
	LImprime(&lw3);

	cout << "\n\tLista de 4 caracteres\n\n";
	LImprime(&lw4);

	cout << "\n\tLista de 5 caracteres\n\n";
	LImprime(&lw5);

	cout << "\n\tLista de 6 caracteres\n\n";
	LImprime(&lw6);

	cout << "\n\tLista de 7 caracteres\n\n";
	LImprime(&lw7);	

	cout << "\n\tLista de 8 caracteres\n\n";
	LImprime(&lw8);

	cout << "\n\tLista de 9 caracteres\n\n";
	LImprime(&lw9);

	cout << "\n\tLista de 10 caracteres\n\n";
	LImprime(&lw10);

	cout << "\n\tLista de 11 caracteres\n\n";
	LImprime(&lw11);

	cout << "\n\tLista de 12 caracteres\n\n";
	LImprime(&lw12);

	cout << "\n\tLista de 13 caracteres\n\n";
	LImprime(&lw13);			


	return 0;
}