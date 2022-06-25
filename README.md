# Ranqueamento de documentos 

[![Linguagem C++](https://img.shields.io/badge/Linguagem-C%2B%2B-green.svg)](https://github.com/TFIDF-Project)
[![requirement](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-informational)](https://code.visualstudio.com/docs/?dv=linux64_deb)
![ISO](https://img.shields.io/badge/ISO-Linux-blueviolet)


<h1> Algoritmo, TF/IDF

## Conteúdos

<p align="center">
 <a href="#🚀-apresentação">Apresentação</a> •
 <a href="#👨‍💻-algoritmo-tf-idf">Algoritmo TF-IDF</a> •
 <a href="#🖥️-como-o-cálculo-é-usado-pelo-google">Como o cálculo é usado pelo Google?</a> •
 <a href="#📦-lógica">Lógica</a> •
 <a href="#📋-stopwords-e-sua-implementação">Stopwords e sua implementação</a> •
 <a href="#🔎-lógica-do-ranqueamento-e-do-cálculo-tf-idf">Lógica do ranqueamento e do cálculo TF-IDF</a> •
 <a href="#⚙️-funções">Funções</a> •
 <a href="#📷-representação-gráfica">Representação gráfica</a> •
 <a href="#🔩-execução-de-testes">Execução de testes</a> • 
 <a href="#📚-bibliotecas">Bibliotecas</a> •
 <a href="#🔧-compilação-e-execução">Compilação e Execução</a> • 
 <a href="#✒️-autores">Autores</a>
</p>

---

## 🚀 Apresentação

Foi proposto pelo professor Michel Pires da Silva da matéria de Arquitetura e Estruturas de Dados 1 do curso de Engenharia da Computação um trabalho onde o objetivo é projetar uma estrutura de filtragem de documentos por ranqueamento de palavras tendo como base o <a href="#algoritmo-tf-idf">Algoritmo TF-IDF</a>, estrutura que já foi utilizada pelo algorítmo do Google no ínicio. Para ser validado à correção, o trabalho deve seguir os seguintes pré-requisitos:
  - [X] O código deve ser elaborado utilizando as linguagens <b>C</b> ou <b>C++</b>
  - [X] Exibir os documentos devidamente ranqueados
  - [X] O programa deve ser capaz de calcular o tempo de execução
  - [X] O código deve ser implementado de forma que vise o menor custo computacional possível
  - [X] O código deve utilizar algum dos tipos abstratos de estrutura de dados apresentados em sala

---

### 👨‍💻 Algoritmo TF-IDF

TF-IDF é um cálculo usado pelo Google para entender a importância dos termos nas páginas de um site. Conhecer esse modelo ajuda a entender o buscador, mas também a planejar e otimizar seus conteúdos. Essa sigla, TF-IDF, representa uma forma do Google determinar estatisticamente a importância de uma palavra-chave ou uma frase analisando centenas ou milhares de documentos.

<h4>O que é o TF-IDF?</h4>

<strong>TF-IDF</strong> significa <strong>Term Frequency – Inverse Document Frequency</strong>. Essa expressão pode ser traduzida para o português como <strong>“Frequência do Termo – Frequência Inversa dos Documentos”</strong>, que é um cálculo estatístico adotado pelo algoritmo do Google para medir quais termos são mais relevantes para um tópico, analisando a frequência com que aparecem em uma página, em comparação à sua frequência em um conjunto maior de páginas. O cálculo serve como fator de ponderação de termos, ou seja, para entender a importância de um termo ou frase específica para determinado documento.

<strong>TF</strong> se refere à <strong>“frequência do termo”</strong>. Essa parte do cálculo responde à pergunta: com que frequência o termo aparece nesse documento? <strong>Quanto maior for a frequência no documento, maior será a importância do termo</strong>.

<strong>IDF</strong> significa <strong>“frequência inversa dos documentos”</strong>. Nessa parte, a ferramenta responde: com que frequência o termo aparece em todos os documentos da coleção? <strong>Quanto maior for a frequência nos documentos, menor será a importância do termo</strong>.

<h4>Como é calculado?</h4>

<ul>
  <li>
    <strong>TF: Term Frequency</strong>, mede a frequência com que um termo ocorre em um documento. Como cada documento é diferente em tamanho, é possível que um termo apareça muito mais vezes em documentos longos do que em documentos mais curtos. Assim, a frequência do termo é frequentemente dividida pelo comprimento do documento, ou seja, a frequência do termo é frequentemente dividida pelo número total de termos no documento como forma de normalização:
    
  $$TF(t) = \frac{x}{y}$$
    
  <i>x= Número de vezes que o termo <i>t</i> aparece em um documento</i><br>
  <i>y = Número total de termos no documento</i> <br><br>
  </li>
  
  <li>
    <strong>IDF: Inverse Document Frequency</strong>, mede a importância de um termo. Ao calcular o TF, todos os termos são considerados igualmente importantes. No entanto, sabe-se que certos termos, como “é”, “de” e “isso”, podem aparecer muitas vezes, mas têm pouca importância. Assim, precisamos pesar os termos frequentes enquanto escalamos os raros, calculando o seguinte:
    
  $$IDF(t) = log{(\frac{w}{z})}$$
    
  <i>w = Número total de documentos</i><br>
  <i>z = Número de documentos com termo t nele</i><br><br>
  </li>
</ul>

Podemos resumir assim, que a importância do termo aumenta conforme o número de vezes que a palavra aparece no documento, mas é compensada pelo número de repetições na coleção de documentos, o que serve para ajustar o fato de que algumas palavras aparecem com mais frequência em geral.

### 🖥️ Como o cálculo é usado pelo Google?

O cálculo TF-IDF é um exemplo da tecnologia incorporada ao robô para processamento de linguagem. O Google adota sistemas que fazem esses cálculos automaticamente em milhões de documentos da web para dar sentido ao que eles estão dizendo.

TF-IDF é usado como parte da indexação semântica latente (LSI ou Latent Semantic Indexing). O Google utiliza essa abordagem de indexação para compreender as relações entre palavras, frases e conceitos, ou seja, a semântica dos textos de um site. Isso é essencialmente importante quando há palavras com significados semelhantes ou com mais de um significado.

Dentro dessa lógica, então, o TF-IDF serve para processar a linguagem utilizada nos conteúdos. Ele não serve para dar sentido aos termos, mas para entender a sua importância ao dar pesos diferentes para eles.

Resumindo, o TF-IDF ajusta esse cálculo para compreender a importância do termo ao comparar a frequência na página com a sua frequência em outros milhares de documentos. Dessa forma, o Google consegue refinar a qualidade da indexação para as palavras-chave corretas.

---

## 📦 Lógica

O algoritmo do cálculo TF-IDF criado pelo nosso grupo utilizou de base a `Estruturas de Dados do Tipo Lista Dinâmica` pela suas vantagens onde o seu custo e tratamento são melhores ques outras **Estruturas de Dados** já estudadas até o momento no curso de `Engenharia da Computação`, visto também que em aplicações em que não existe previsão sobre o crescimento da lista, é conveniente usar _listas dinâmicas_, onde permite utilizar posições não contíguas de memória sendo possivel **inserir** e **retirar** elementos sem haver necessidade de deslocar os itens seguintes da lista e em um custo constante.
Uma das principais ideias pensadas pelo grupo ao otimizar o algoritmo e reduzir o seu custo que ao nosso ver também difere da ideia principal dos outros grupos é o **tratamento das _stopwords_**, onde inicialmente seria a parte em que o custo computacional do programa seria maior por precisar de diversos tratamentos, com isso foi pensado então na lógica e implementação presente no tópico abaixo:

---

### 📋 Stopwords e sua implementação

Foi criado um arquivo contendo todas as <i>stopwords</i> em português, que é derivada das <i>stopwords</i> em inglês do Natural Language Toolkit, comumente chamado de NLTK, que é um conjunto de bibliotecas e programas para processamento simbólico e estatístico da linguagem natural para inglês. A partir das <i>stopwords</i> do NLKT foi feita a tradução das possíveis <i>stopwords</i> para o português, dando resultado ao arquivo de texto <code>stopwords.txt</code>.

### Leitura das <i>stopwords</i>

Depois da criação do arquivo contendo todas as <i>stopwords</i>, foi feita a implementação de uma função para que seja feita a leitura do arquivo e que essa função separe e insira palavra por palavra em uma estrutura de lista dinâmica. 

### <i>Mas por que uma estrutura de lista dinâmica?</i>

Nesse caso, usamos a lista dinâmica por ser de maior facilidade de uso, mas caso usássemos estrutura de pilha ou fila, a função teria a mesma finalidade que é de armazenar as <i>stopwords</i> e não haveria mudança alguma quanto a custo computacional, já que seria feito apenas a inserção das <i>stopwords</i> primeiramente.

### A função citada é a seguinte:

<ul>
	<li><i>list.hpp</i></li>
</ul>

```c++
	void filter_stop_words(List *lw1, List *lw2, List *lw3, List *lw4, List *lw5, List *lw6, List *lw7, List *lw8, List *lw9, List *lw10, List *lw11, List *lw12, List *lw13, Item d);
```
<ul>
	<li><i>list.cpp</i></li>
</ul>

```c++
	void filter_stop_words(List *lw1, List *lw2, List *lw3, List *lw4, List *lw5, List *lw6, List *lw7, List *lw8, List *lw9, List *lw10, List *lw11, List *lw12, List *lw13, Item d){
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

	my_file.open("stopwords.txt");

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

---

### 🔎 Lógica do ranqueamento e do cálculo TF-IDF

Com a filtragem das _stopwords_ concluída é possível iniciar o algoritmo com foco no cálculo e ranqueamento do TF-IDF onde primeiramente será tratada a pesquisa do usuário que vai ser inserida em um arquivo chamado `phrasetosearch.txt` onde a partir disso será chamada a função <a href="#função-readphrase">_read_phrase_</a> (explicada melhor na aba <a href="#⚙️-funções">Funções</a>), que vai receber como parâmetro os arquivos de filtragem das <i>stopwords</i> e o arquivo contendo a pesquisa do usuário, lendo então a frase de pesquisa e tratando-a, retirando pontuações (utilizando a função <a href="#função-stringtreatment">_string_treatment_</a>) e suas <i>stopwords</i> deixando então somente _strings_ que tem relevância para a pesquisa evitando um falso positivo no processo de ranking. Feito isso, será criada seis **listas dinâmicas** que correspondem aos seis documentos que serão utilizados com base na pesquisa para o ranqueamento, onde a partir disso será chamada a função <a href="#função-filterdocuments">_filter_documents_</a> que vai receber como parâmetro 


---

## ⚙️ Funções

O algoritmo TF-IDF construido pelo grupo é composto por um total de 17 funções, sendo 5 dessas funções utilizadas para o tratamento de 4 `Estruturas de Dados do Tipo Lista Dinâmica`, como por exemplo <i>inserções, remoções, impressões e verificações de espaços</i> dessas **listas**. As demais funções foram pensadas para a construção e tratamento do algoritmo TF-IDF, compondo o <i>cálculo, implementação, tratamento de **stop words** e ranqueamento</i>, sendo elas:

---

<p align="center">
 <a href="#•função-tfidf">Função "tf_idf"</a> |
 <a href="#•função-readphrase">Função "read_phrase"</a> |
 <a href="#•função-checkifstopwordfinalcont">Função "check_if_stopword_final_cont"</a> |
 <a href="#•função-filterdocuments">Função "filter_documents"</a> | 
 <a href="#•função-stringtreatment">Função "string_treatment"</a> |
 <a href="#•função-checkifstopword">Função "check_if_stopword"</a> | 
 <a href="#•função-filllistwithcont">Função "fill_list_with_cont"</a> |
 <a href="#•função-verifyifwordexist">Função "verify_if_word_exist"</a> |
 <a href="#•função-verifyhowmanytimesseen">Função "verify_how_many_times_seen"</a> |
 <a href="#•função-tfidfcalc">Função "tf_idf_calc"</a> |
 <a href="#•função-findwordcont">Função "find_word_cont"</a>
</p>

---

### •Função **_tf_idf_**
//Explicação João Marcelo

### •Função **_read_phrase_**
//Explicação Caio

### •Função **_check_if_stopword_final_cont_**
//Explicação Caio

### •Função **_filter_documents_**
//Explicação João Marcelo

### •Função **_string_treatment_**
//Explicação Caio

### •Função **_check_if_stopword_**
//Explicação Caio

### •Função **_fill_list_with_cont_**

Essa função introduz a primeira parte do ranqueamento dos documentos, fazendo com que seja contado, com um contador **cont** dentro da função, a quantidade de vezes em que as palavras vão aparecer naquele documento. A função recebe como parâmetro duas listas, a lista em que contém a filtragem do documento em que vai ser feita o ranqueamento das palavras e uma outra lista vazia que vai ser preenchida dentro da função com a lista `WordCounter` como na representação abaixo:

```c++
	void fill_list_with_cont(List *document, List *wordcount);
```
_Representação 1: chamada da função _fill_list_with_cont__

Após ser feita a chamada da função ela inicia com a chamada da lista `WordCounter` que possui em seu bloco uma string e um contador onde vai auxiliar o ranqueamento das palavras com a quantidade de vezes em que ela apareceu nesse contador, com isso vai ser iniciado uma estrutura de repetição __*while*__ em que vai ser repetida enquanto o documento principal não terminar e dentro dessa estrutura uma variável auxiliar de string **aux_str** vai receber palavra por palavra desse documento a cada vez que a estrutura for repetida fazendo a verificação com uma estrutura de decisão `IF` verificando caso palavra não exista com a função <a href="#•função-verifyifwordexist">_verify_if_word_exist_</a> (explicada melhor no tópico abaixo), se não existir o programa vai entrar nessa estrutura e adicionar essa palavra que não existe na lista `WordCounter` com seu contador recebendo o número 1 de acordo com a representação abaixo:

```c++
	if (!verify_if_word_exist(wordcount, aux_str)) {
		aux_insert.word = aux_main_document->data.word;
		aux_insert.contador = 1;
		LInsertWordCounter(wordcount, aux_insert);
	}
```
_Representação 2: inserção da palavra não existente na lista WordCounter_

Ao sair dessa estrutura de decisão a váriavel **cont** vai acrescentar mais uma unidade em seu valor para que no final seja contabilizada a quantidade de palavras em que vai aparecer no documento analisado pela função adicionando esse valor ao bloco `Contador`.

### •Função **_verify_if_word_exist_**

Essa função tem como objetivo apenas de ser utilizada na estrutura de decisão `IF` função <a href="#•função-filllistwithcont">_fill_list_with_cont_</a> como verificação de existencia da palavra passada como parâmetro (**aux_str**) em conjunto com uma lista de palavras com um contador (**wordcount**)como na representação abaixo:
```c++
	bool verify_if_word_exist(List *wordcount, string word);
```
_Representação 1: chamada da função _verify_if_word_exist__

Dentro dessa função vai ser chamado um bloco auxiliar ***aux** que vai receber a primeira posição da lista `wordcount` para que seja possível percorre-la inteira dentro da estrutura de repetição __<i>while</i>__ até o final onde a cada posição percorrida vai ser feita uma verificação com a estrutura de decisão `IF` se a palavra passada como parâmetro já está dentro da lista, caso não estiver a função vai retornar o tipo booleano <b>false</b>, caso possua a palavra dentro da lista `wordcount` será acrescentando mais uma unidade no valor da váriavel <b>contador</b> do bloco daquela palavra possibilitando então o ranqueamento de palavras dentro do documento pois com isso será possível verificar a quantidade de vezes em que as palavras estão dentro dos documentos que vão ser feito o ranqueamento, retornando então no final o tipo booleano <b>true</b>.

### •Função **_verify_how_many_times_seen_**

Essa função foi construida com objetivo de verificar quantas vezes uma palavra pertencente a pesquisa do usuário aparece no documento passado como parâmetro (**document_x**) recebendo também a lista que contém as palavras da pesquisa como parâmetro (lista **input**) como na representação a seguir

```c++
	void verify_how_many_times_seen(List *input, List *document);
```
_Representação 1: chamada da função _verify_how_many_times_seen__

A função começa com a declaração de dois blocos auxiliares das listas sendo eles <b>*aux_input</b> e <b>*aux_document</b> onde apartir disso vai ser chamado duas estruturas de repetição `WHILE`, uma que vai percorrer a lista **input** com a ajuda do bloco auxiliar e outra que vai percorrer a lista **document** até o final e a cada posição percorrida vai ser feita a verificação, com uma estrutura de decisão `IF`, se a palavra pertencente a posição da lista **document**, ou seja, do documento de busca é igual a palavra da posição do documento que possui a pesquisa do usuário. Caso essa verificação prossiga vai ser acrescentado mais uma unidade no valor do contador possuente do bloco da pesquisa do usuário e após isso é colocada a posição do **aux_document** (váriavel que ajuda a percorrer a lista) no final da lista para que seja possível começar uma outra verificação de outra posição da lista **input** até o final dessa lista. 

### •Função **_tf_idf_calc_**
//Explicação João Marcelo

### •Função **_find_word_cont_**

A função _find__cont_ foi construída pensando no auxilio do cálculo `TF-IDF` onde ela retorna um tipo **int** sendo o número de ocorrências presente na função <a href="#•função-tfidfcalc">_tf_idf_calc_</a>, que obtido com base nos parâmetros passados na chamada da função que consiste em uma lista com as palavras contadas de determinado documento (**wordcounter_doc1**) e em string que é passada a partir do bloco da lista **input** (lista que possui a pesquisa do usuário) como é possível ver na representação abaixo:

```c++
	int find_word_cont(List *wordcounter, std::string to_find);
```
_Representação 1: chamada da função _find_word_cont__

Após ser feita essa chamada a função introduzirá declarando um bloco auxiliar <b>*aux</b> onde vai receber a primeira posição da lista que contém as palavras contados do documento passado como parâmetro (lista **wordcounter_docx**) e através de uma estrutura de repetição `WHILE` vai percorrer essa lista até o final e a cada posição percorrida vai ser feita uma verificação apartir de uma estrutura de decisão `IF` verificando se a string presente em determinada posição da lista percorrida é igual a string passada como parâmetro e caso essa verificação seja verdadeira a função irá retornar o contador da string da lista **wordcounter_docx**, visto que isso vai auxiliar no cálculo como citado anteriormente pois ao retornar para a função <a href="#•função-tfidfcalc">_tf_idf_calc_</a> esse contador, vai ser possível ser feito os cálculos com os valores obtidos de quantas vezes a palavra presente na pesquisa apareceu em determinado documento.


---

## 📷 Representação gráfica



---

## 🔩 Execução de testes


---

## 📚 Bibliotecas

<p>Para o funcionamento do programa, é necessário incluir as seguintes bibliotecas: 
<ul>
    <li><code>#include 'iostream'</code></li>
    <li><code>#include 'time.h'</code></li>
    <li><code>#include 'unistd.h'</code></li>
    <li><code>#include 'cmath'</code></li>
    <li><code>#include 'fstream'</code></li>
    <li><code>#include 'string'</code></li>
    <li><code>#include 'vector'</code></li>
</ul>

---

## 🔧 Compilação e Execução

O programa feito de acordo com a proposta possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação             


---

## ✒️ Autores

Projeto elaborado por [Caio Fernando Dias](https://github.com/Caio-Fernando-Dias), [Felipe Coelho de Oliveira Campos](https://github.com/fco3lho), [Henrique Souza Fagundes](https://github.com/ohenriquesouza), [João Marcelo Gonçalves Lisboa](https://github.com/joaojmgl), [João Pedro Martins Espíndola](https://github.com/JoaoMEspindola?tab=repositories), [Livia Gonçalves](https://github.com/Livia-Goncalves-01), [Lucas Farinelli Crivellari de Pinho](https://github.com/farinellizin), [Pedro Henrique Louback Campos](https://github.com/PedroLouback) e [Pedro Pinheiro de Siqueira](https://github.com/ppinheirosiqueira) 

Alunos da matéria de Arquitetura e Estruturas de Dados 1 do curso de `Engenharia da Computação` no [CEFET-MG](https://www.cefetmg.br)
