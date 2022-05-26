#include "list.hpp"

int main()
{
	List l;
	Item aux;

	FLVazia(&l);
	readStopWords(&l, aux);
	LImprime(&l);

	return 0;
}