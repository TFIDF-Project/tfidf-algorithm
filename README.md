# <i>Stopwords</i> e sua implementação

Foi criado um arquivo contendo todas as <i>stopwords</i> em português, que é derivada das <i>stopwords</i> em inglês do Natural Language Toolkit, comumente chamado de NLTK, que é um conjunto de bibliotecas e programas para processamento simbólico e estatístico da linguagem natural para inglês. A partir das <i>stopwords</i> do NLKT foi feita a tradução das possíveis <i>stopwords</i> para o português, dando resultado ao arquivo de texto <code>stopwords_portuguese.txt</code>.

## Leitura das <i>stopwords</i>

Depois da criação do arquivo contendo todas as <i>stopwords</i>, foi feita a implementação de uma função para que seja feita a leitura do arquivo e que essa função separe e insira palavra por palavra em uma estrutura de lista dinâmica. 

### <i>Mas por que uma estrutura de lista dinâmica?</i>

Nesse caso, usamos a lista dinâmica por ser de maior facilidade de uso, mas caso usássemos estrutura de pilha ou fila, a função teria a mesma finalidade que é de armazenar as <i>stopwords</i> e não haveria mudança alguma quanto a custo computacional, já que seria feito apenas a inserção das <i>stopwords</i> primeiramente.

### A função citada é a seguinte:

<ul>
	<li><i>list.hpp</i></li>
</ul>

```c++
	void readStopWords(List *lw1, List *lw2, List *lw3, List *lw4, List *lw5, List *lw6, List *lw7, List *lw8, List *lw9, List *lw10, List *lw11, List *lw12, List *lw13, Item d);
```
<ul>
	<li><i>list.cpp</i></li>
</ul>

```c++
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
```

### Análise

Foi analisado nas <i>stopwords</i> padrões em português que as mesmas possuem de 1 a 13 caracteres, então a fim de diminuir o custo computacional de comparações das palavras encontradas nos documentos com as <i>stopwords</i>, foram criadas 13 listas diferentes, cada uma representando palavras com uma quantidade de caracteres que varia de 1 a 13 como dito anteriormente.

Após a criação das listas, vamos para a leitura do arquivo das <i>stopwords</i>, onde o parâmetro para a separação das palavras é a quebra de linha ou o caractere <code>\n</code>, ou seja, é feita a leitura do arquivo linha por linha até que a leitura chegue ao final do arquivo. Mas no meio desta leitura foram criadas 13 condições de inserção de <i>stopwords</i> à listas dinâmicas. 

<strong>Exemplo para explicação:</strong>

```c++
	if(my_file.is_open()){
		while(! my_file.eof()){
			getline(my_file, line);
			d.word = line;
			numberCaracters = line.length();

			if(numberCaracters == 2){
				LInsert(lw1, d);
			}
		}
		
		my_file.close(); 
	}
	
	else{
		cout << "Arquivo não abriu.\n";
	} 
	
```

<ol>
	<li><code>if(my_file.is_open())</code> : Cria a condição que, se o arquivo com nome salvo na variável <i>my_file</i> abrir, executa o que está contido dentro da condição.</li>
	<li><code>while(! my_file.eof())</code> : Laço de repetição que só finaliza quando a leitura do arquivo chegar ao final do arquivo.</li>
	<li><code>getline(my_file, line)</code> : Armazena o que está contido naquela linha no momento do laço de repetição na variável <code>line</code>.</li>
	<li><code>d.word = line</code> : <code>d</code> é uma <i>struct</i> que contém em seu interior uma <i>string</i> chamada <code>word</code>, então à <code>d.word</code> é feita a atribuição de <code>line</code>.</li>
	<li><code>numberCaracters = line.length()</code> : <code>numberCaracters</code> é a variável que irá armazenar o número de caracteres de <code>line</code>, onde foi feita a contagem pela função <code>length()</code>, por isso <code>line.length()</code>.</li>
</ol>

A partir daqui são criadas as condições baseadas no tamanho da variável <code>numberCaracters</code> para a inserção nas listas dinâmicas. Exemplo de condição:

```c++
	if(numberCaracters == 2){
		LInsert(lw1, d);
	}
```

A condição acima analisa se a variável <code>numberCaracters</code> é igual a 2, e se for, ela faz a inserção da <i>struct</i> <code>d</code> à lista dinâmica <code>lw1</code>.

### Observações sobre o código apresentado

<ul>
	<li>Nas condições de inserção à lista, para as <i>stopwords</i> de <i>x</i> caracteres a condição é valida para quando <code>numberCaracters</code> for igual a <i>x + 1</i> porque na leitura do arquivo, o caractere <code>/0</code> ao final da linha é contado também.</li>
	<li>Foi feita a separação das stopwords em 13 diferentes listas dinâmicas a fim de diminuir o custo computacional de comparação com as palavras dos documentos  posteriormente, fazendo a contagem de caracteres da palavra do documento onde, se a palavra possuir de 1 a 13 caracteres será feita a comparação com a lista de <i>stopwords</i> que possuir a mesma quantidade de caracteres desta palavra e se houver mais que 13 caracteres, essa palavra não se encaixa às <i>stopwords</i>, então será uma comparação a menos para ser feita.</li>
	
</ul>

