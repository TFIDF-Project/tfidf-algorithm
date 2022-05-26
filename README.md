# Retirada das 'stopwords' dos documentos

Este repositório terá a finalidade de armazenar a parte do programa que irá remover as 'stopwords' dos documentos de texto.

## Tokenização das 'stopwords'

Foi criada uma função que lê o arquivo de texto contendo as 'stopwords' e às tokeniza, inserindo-as cada uma em uma posição na lista dinâmica.

<i>Declaração da função no arquivo .hpp</i>
```c++
  void readStopWords(List *l, Item d);
```

<i>Lógica da função no arquivo .cpp</i>

```c++
  void readStopWords(List *l, Item d){
	string line;
	ifstream my_file;

	my_file.open("stopwords.txt");

	if(my_file.is_open()){
		while(! my_file.eof()){
			getline(my_file, line);
			d.word = line;
			LInsert(l, d);
		}
		my_file.close();
		cout << "\n";
	}

	else{
		cout << "Arquivo não abriu.\n";
	} 
}
```
