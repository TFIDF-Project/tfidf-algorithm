# Ranqueamento de documentos 

[![Linguagem C++](https://img.shields.io/badge/Linguagem-C%2B%2B-green.svg)](https://github.com/TFIDF-Project)
[![requirement](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-informational)](https://code.visualstudio.com/docs/?dv=linux64_deb)
![ISO](https://img.shields.io/badge/ISO-Linux-blueviolet)


<h1> Algoritmo TF/IDF

## Conteúdos

<p align="center">
 <a href="#-apresentação">Apresentação</a> •
 <a href="#-algoritmo-tf-idf">Algoritmo TF-IDF</a> •
 <a href="#%EF%B8%8F-como-o-cálculo-é-usado-pelo-google">Como o cálculo é usado pelo Google?</a> •
 <a href="#-lógica">Lógica</a> •
 <a href="#-stopwords-e-sua-implementação">Stopwords e sua implementação</a> •
 <a href="#-lógica-do-ranqueamento-de-documentos-e-do-cálculo-tf-idf">Lógica do ranqueamento e do cálculo TF-IDF</a> •
 <a href="#%EF%B8%8F-funções">Funções</a> •
 <a href="#-representação-gráfica">Representação gráfica</a> •
 <a href="#-execução-de-testes">Execução de testes</a> • 
 <a href="#-bibliotecas">Bibliotecas</a> •
 <a href="#-compilação-e-execução">Compilação e Execução</a> • 
 <a href="#%EF%B8%8F-autores">Autores</a>
</p>

---

## 🚀 Apresentação

Foi proposto pelo professor [Michel Pires da Silva](http://lattes.cnpq.br/1449902596670082) da matéria de Arquitetura e Estruturas de Dados 1 do curso de Engenharia da Computação um trabalho onde o objetivo é projetar uma estrutura de filtragem de documentos por ranqueamento de palavras tendo como base o <a href="#algoritmo-tf-idf">Algoritmo TF-IDF</a>, estrutura que já foi utilizada pelo algorítmo do Google no ínicio. Para ser validado à correção, o trabalho deve seguir os seguintes pré-requisitos:
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

O algoritmo do cálculo TF-IDF criado pelo nosso grupo utilizou de base a `Estruturas de Dados do Tipo Lista Dinâmica` pela suas vantagens onde o seu custo e tratamento são melhores que outras **Estruturas de Dados** já estudadas até o momento no curso de `Engenharia da Computação`, visto também que em aplicações em que não existe previsão sobre o crescimento da lista, é conveniente usar _listas dinâmicas_, onde permite utilizar posições não contíguas de memória sendo possível **inserir** e **retirar** elementos sem haver necessidade de deslocar os itens seguintes da lista e em um custo constante.
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

### 🔎 Lógica do ranqueamento de documentos e do cálculo TF-IDF

Com a filtragem das _stopwords_ concluída é possível iniciar o algoritmo com foco no cálculo e ranqueamento do TF-IDF onde primeiramente será tratada a pesquisa do usuário que vai ser inserida em um arquivo chamado `phrasetosearch.txt` onde a partir disso será chamada a função <a href="#função-read_phrase">_read_phrase_</a> (explicada melhor na aba <a href="#%EF%B8%8F-funções">Funções</a>), que vai receber como parâmetro os arquivos de filtragem das <i>stopwords</i> e o arquivo contendo a pesquisa do usuário, lendo então a frase de pesquisa e tratando-a, retirando pontuações (utilizando a função <a href="#função-string_treatment">_string_treatment_</a>) e suas <i>stopwords</i> deixando então somente _strings_ que tem relevância para a pesquisa evitando um falso positivo no processo de ranking. Feito isso, será criada seis **listas dinâmicas** que correspondem aos seis documentos que serão utilizados com base na pesquisa para o ranqueamento, onde a partir disso será chamada a função <a href="#função-filter_documents">_filter_documents_</a> que vai receber como parâmetro uma lista vazia (**document_x**) que ao final dessa função vai ser uma lista do documento tratado, uma string (**doc_name**) que antes de ser passada como parâmetro irá receber o nome do arquivo em que vai ser filtrado e as listas que possuem as filtragens de caracteres das _stopwords_, fazendo com que então o documento passado como parâmetro seja filtrado retirando todas as suas _stopwords_ e colocando aquelas palavras que não são na lista (**document_x**) deixando apenas as palavras relevantes e então estruturando os documentos para o início do cálculo `TF-IDF` e o ranqueamento. Após ser feito esse tratamento dos documentos de busca uma nova sequência de lista será criada (listas **wordcounter_docx**) em que serão usadas para serem passadas como parâmetros para uma nova função construída chamada <a href="#função-fill_list_with_cont">_fill_list_with_cont_</a> onde recebe também a lista do documento que foi tratada anteriormente e faz com que cada palavra dessa lista do documento de busca seja verificada e contada a cada vez que aparece nesse documento, inserindo essas informações em uma outra lista que possui em seu bloco um **contador** e uma **string** para mais a frente ser possível utilizar esses dados para os cálculos juntamente com os dados da função <a href="#função-verify_how_many_times_seen">_verify_how_many_times_seen_</a> que vai ser chamada logo em seguida fazendo também a contagem de vezes em que a palavra aparece mas com os parâmetros diferentes sendo eles: lista da pesquisa do usuário (**input**) e o documento de busca (**document_x**), ou seja, essa função vai fazer com que seja feita a verificação de quantas vezes as palavras da pesquisa do usuário vai aparecer no documento correspondente colocando um **contador** nessas palavras e armazenando no bloco **ContWordSeen** que possui um **contador** e uma **string** para que ao final de tudo seja possível chamar a função criada <a href="#função-tf_idf_calc">_tf_idf_calc_</a> (explicada com mais detalhes no tópico abaixo), que recebe como parâmetro a lista de pesquisa (**input**) e todas as outras listas sendo elas **wordcounter_docx** e **document_x** onde vai ser feito o cálculo `TF-IDF` de cada documento utilizando os dados das listas passadas como parâmetro, armazenando os valores do cálculo em um vetor do tipo (**_float_**) para melhor resultado, passando esses valores para um **vector** correspondente ao documento e assim então fazendo uma verificação de qual é maior colocando-o na primeira posição para ao final entregar o resultado imprenso da maneira como é visto a seguir:

<p align="center">
<img src="img/saida_ranqueamento.png" width="230px"/> 
</p>
<p align="center">
<i>Imagem 1: Saída do programa onde é imprenso o ranking de relevância dos documentos</i>
</p>

Levando em consideração o resultado da imagem acima os documentos utilizados foram todos padrões passados pelo professor sendo a pesquisa a frase inserida no arquivo `phrasetosearch.txt`: _**'Em que a expansão do mercado influencia no fluxo de informações?'**_.  

---

## ⚙️ Funções

O algoritmo TF-IDF construído pelo grupo é composto por um total de 17 funções, sendo 5 dessas funções utilizadas para o tratamento de 4 `Estruturas de Dados do Tipo Lista Dinâmica`, como por exemplo <i>inserções, remoções, impressões e verificações de espaços</i> dessas **listas**. As demais funções foram pensadas para a construção e tratamento do algoritmo TF-IDF, compondo o <i>cálculo, implementação, tratamento de **stop words** e ranqueamento</i>, sendo elas:

---

<p align="center">
 <a href="#função-tf_idf">Função "tf_idf"</a> |
 <a href="#função-read_phrase">Função "read_phrase"</a> |
 <a href="#função-check_if_stopword_final_cont">Função "check_if_stopword_final_cont"</a> |
 <a href="#função-filter_documents">Função "filter_documents"</a> | 
 <a href="#função-string_treatment">Função "string_treatment"</a> |
 <a href="#função-check_if_stopword">Função "check_if_stopword"</a> | 
 <a href="#função-fill_list_with_cont">Função "fill_list_with_cont"</a> |
 <a href="#função-verify_if_word_exist">Função "verify_if_word_exist"</a> |
 <a href="#função-verify_how_many_times_seen">Função "verify_how_many_times_seen"</a> |
 <a href="#função-tf_idf_calc">Função "tf_idf_calc"</a> |
 <a href="#função-find_word_cont">Função "find_word_cont"</a>
</p>

---



### •Função **_read_phrase_**

A função `read_phrase` recebe **phrasetosearch.txt**, um documento onde está a frase e/ou palavra de pesquisa do usuário. Lendo esse documento e chamando outras funções para tratá-lo, retirando stopwords e caracteres especiais com a ajuda de outras funções. Por fim, o documento de pesquisa está tratado somente com palavras que possui relevância facilitanto assim o cálculo do tfidf.

```c++
	read_phrase(&input, "phrasetosearch.txt", &sw1, &sw2, &sw3, &sw4, &sw5, &sw6, &sw7, &sw8, &sw9, &sw10, &sw11, &sw12, &sw13);
```
_Representação 1: chamada da função read_phrase_

### •Função **_check_if_stopword_final_cont_**

Assim como a função `check_if_stopword`, essa função verefica se as palavras são stopwords recebendo como parâmetro uma lista com stopwords, entretanto essa função tem um contador para a quantidade de vezes que cada palavra aparece fazendo com que dessa forma, não hajam palavras replicadas.

```c++
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
```
_Representação 1: implementação da função check_if_stopword_final_cont_

```c++
	check_if_stopword_final_cont(doc, sw1, aux);
```
_Representação 2: chamada da função para a lista de stopwords de um único caracter_

### •Função **_filter_documents_**

Esta função tem como parâmetro a criação de 14 listas, uma para o documento principal a ser comparado e as outras 13 para as *stopwords*, separando as *stopwords* pela quantidade de caracteres. O que esta função faz é bem simples, mas muito importante para a otimização do algoritmo, a principal função dela é identificar as *stopwords* presentes em cada documento e em seguida removê-las gerando um novo documento sem as *stopswords*.

```c++
void filter_documents(List *doc, std::string doc_name, List *sw1, List *sw2, List *sw3, List *sw4, List *sw5, List *sw6, List *sw7, List *sw8, List *sw9, 
List *sw10, List *sw11, List *sw12, List *sw13)
```
Dentro da função são criados alguns variáveis para auxiliar na abertura e na leitura dos arquivos.
```c++
std::ifstream myfile;
	std::string line, auxiliar, auxiliar_2, delimiter = " ";
	Item aux;
	size_t pos = 0;
	int cont = 0;
```
Logo, após abrirmos o arquivo principal, entramos em uma estrutura de repetição `while` e lemos linhas por linha deste arquivo, bem como salvamos na variável **aux** do tipo `Item`.
```c++
if (myfile.is_open()) {
		while(!myfile.eof()) {
			getline(myfile, line);
			aux.word = line;
```

Após as linhas salvas, a função entra em uma estrutura de repetição `While`, usamos um delimitador chamado **delimiter**, o qual identifica espaços em branco na linha em que está sendo lida, apaga estes espaços e salva as palavras separadas em uma variável chamada **auxliliar**. Em seguida, é onde tratamos cada string e identificamos se ela é uma palavra ou apenas um símbolo, chamando a variável `string_treatment` e passando como parâmentro a `string` **auxiliar**. As strings identificadas como palavras são salvas na variável **auxiliar_2** e, logo após, retornam para a variável `Item` **aux**.
```c++
while ((pos = line.find(delimiter)) != std::string::npos) {
				aux.word = (line.substr(0, pos));
				line.erase(0, pos + delimiter.size());
				auxiliar = aux.word;
				auxiliar_2 = string_treatment(auxiliar);
				aux.word = auxiliar_2;
```
Ainda dentro da estrutura `while` começamos a comparar as palavra salvas com as *stop words* e removemos as palavras identificadas como *stopwords*, cada palavra é comparada respectivamente com alguma *stopword* do memso tamanho. Assim, otimizando o tempo de execução do algoritmo. Após isto, todas as palavras restantes são salvas novamente em um arquivo principal, porém agora sem as *stopwords*.
```c++
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

```
Caso o arquivo não atenda a nenhum parâmetro, será printado na tela uma mensagem ao usuário que o arquivo não pôde ser aberto.
```c++
else {
		std::cout << "nao abriu";
	}
```

### •Função **_string_treatment_**

A função `string_treatment` retira caracteres indesejados em string como pontos de acentuação, números e também deixando todas as letra em minúsculo. Esssa função recebe como parâmetro uma string que retorna a mesam tratada facilitando assim a pesquisa nos documentos.

```c++
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
```
_Representação 1: implementação da função string_treatment_

```c++
	auxiliar_2 = string_treatment(auxiliar);
```
_Representação 2: chamada da função string_treatment_

### •Função **_check_if_stopword_**

Essa função recebe como parâmetro uma lista de stopwords com todas as stopwords pré-colocadas para serem deprezadas dos documentos verificando assim se as palavras dos documentos estão presente na lista de stopwords. 

```c++ void check_if_stopword(List *main_doc, List *sw, Item aux) {
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
```
_Representação 1: implementação da função check_if_stopword_

```c++
	check_if_stopword(doc, sw1, aux);
```
_Representação 2: chamanda da função para a lista de stopwords com um único caracter_

### •Função **_fill_list_with_cont_**

Essa função introduz a primeira parte do ranqueamento dos documentos, fazendo com que seja contado, com um contador **cont** dentro da função, a quantidade de vezes em que as palavras vão aparecer naquele documento. A função recebe como parâmetro duas listas, a lista em que contém a filtragem do documento em que vai ser feita o ranqueamento das palavras e uma outra lista vazia que vai ser preenchida dentro da função com a lista `WordCounter` como na representação abaixo:

```c++
    void fill_list_with_cont(List *document, List *wordcount);
```
_Representação 1: chamada da função _fill_list_with_cont__

Após ser feita a chamada da função ela inicia com a chamada da lista `WordCounter` que possui em seu bloco uma string e um contador onde vai auxiliar o ranqueamento das palavras com a quantidade de vezes em que ela apareceu nesse contador, com isso vai ser iniciado uma estrutura de repetição __*while*__ em que vai ser repetida enquanto o documento principal não terminar e dentro dessa estrutura uma variável auxiliar de string **aux_str** vai receber palavra por palavra desse documento a cada vez que a estrutura for repetida fazendo a verificação com uma estrutura de decisão `IF` verificando caso palavra não exista com a função <a href="#função-verify_if_word_exist">_verify_if_word_exist_</a> (explicada melhor no tópico abaixo), se não existir o programa vai entrar nessa estrutura e adicionar essa palavra que não existe na lista `WordCounter` com seu contador recebendo o número 1 de acordo com a representação abaixo:

```c++
    if (!verify_if_word_exist(wordcount, aux_str)) {
        aux_insert.word = aux_main_document->data.word;
        aux_insert.contador = 1;
        LInsertWordCounter(wordcount, aux_insert);
    }
```
_Representação 2: inserção da palavra não existente na lista WordCounter_

Ao sair dessa estrutura de decisão a variável **cont** vai acrescentar mais uma unidade em seu valor para que no final seja contabilizada a quantidade de palavras em que vai aparecer no documento analisado pela função adicionando esse valor ao bloco `Contador`.


### •Função **_find_word_cont_**

A função _find__cont_ foi construída pensando no auxílio do cálculo `TF-IDF` onde ela retorna um tipo **int** sendo o número de ocorrências presente na função <a href="#função-tf_idf_calc">_tf_idf_calc_</a>, que obtido com base nos parâmetros passados na chamada da função que consiste em uma lista com as palavras contadas de determinado documento (**wordcounter_doc1**) e em string que é passada a partir do bloco da lista **input** (lista que possui a pesquisa do usuário) como é possível ver na representação abaixo:

```c++
    int find_word_cont(List *wordcounter, std::string to_find);
```
_Representação 1: chamada da função _find_word_cont__

Após ser feita essa chamada a função introduzirá declarando um bloco auxiliar <b>*aux</b> onde vai receber a primeira posição da lista que contém as palavras contados do documento passado como parâmetro (lista **wordcounter_docx**) e através de uma estrutura de repetição `WHILE` vai percorrer essa lista até o final e a cada posição percorrida vai ser feita uma verificação a partir de uma estrutura de decisão `IF` verificando se a string presente em determinada posição da lista percorrida é igual a string passada como parâmetro e caso essa verificação seja verdadeira a função irá retornar o contador da string da lista **wordcounter_docx**, visto que isso vai auxiliar no cálculo como citado anteriormente pois ao retornar para a função <a href="#função-tf_idf_calc">_tf_idf_calc_</a> esse contador, vai ser possível ser feitos os cálculos com os valores obtidos de quantas vezes a palavra presente na pesquisa apareceu em determinado documento.



### •Função **_verify_if_word_exist_**

Essa função tem como objetivo apenas de ser utilizada na estrutura de decisão `IF` função <a href="#função-fill_list_with_cont">_fill_list_with_cont_</a> como verificação de existencia da palavra passada como parâmetro (**aux_str**) em conjunto com uma lista de palavras com um contador (**wordcount**) como na representação abaixo:

```c++
    bool verify_if_word_exist(List *wordcount, string word);
```
_Representação 1: chamada da função _verify_if_word_exist__

Dentro dessa função vai ser chamado um bloco auxiliar ***aux** que vai receber a primeira posição da lista `wordcount` para que seja possível percorre-la inteira dentro da estrutura de repetição __<i>while</i>__ até o final onde a cada posição percorrida vai ser feita uma verificação com a estrutura de decisão `IF` se a palavra passada como parâmetro já está dentro da lista, caso não estiver a função vai retornar o tipo booleano <b>false</b>, caso possua a palavra dentro da lista `wordcount` será acrescentando mais uma unidade no valor da variável <b>contador</b> do bloco daquela palavra possibilitando então o ranqueamento de palavras dentro do documento pois com isso será possível verificar a quantidade de vezes em que as palavras estão dentro dos documentos que vão ser feito o ranqueamento, retornando então no final o tipo booleano <b>true</b>.


### •Função **_verify_how_many_times_seen_**

Essa função foi construída com objetivo de verificar quantas vezes uma palavra pertencente a pesquisa do usuário aparece no documento passado como parâmetro (**document_x**) recebendo também a lista que contém as palavras da pesquisa como parâmetro (lista **input**) como na representação a seguir

```c++
    void verify_how_many_times_seen(List *input, List *document);
```
_Representação 1: chamada da função _verify_how_many_times_seen__

A função começa com a declaração de dois blocos auxiliares das listas sendo eles <b>*aux_input</b> e <b>*aux_document</b> onde a partir disso vai ser chamado duas estruturas de repetição `WHILE`, uma que vai percorrer a lista **input** com a ajuda do bloco auxiliar e outra que vai percorrer a lista **document** até o final e a cada posição percorrida vai ser feita a verificação, com uma estrutura de decisão `IF`, se a palavra pertencente a posição da lista **document**, ou seja, do documento de busca é igual a palavra da posição do documento que possui a pesquisa do usuário. Caso essa verificação prossiga vai ser acrescentado mais uma unidade no valor do contador possuente do bloco da pesquisa do usuário e após isso é colocada a posição do **aux_document** (variável que ajuda a percorrer a lista) no final da lista para que seja possível começar uma outra verificação de outra posição da lista **input** até o final dessa lista. 



### •Função **_tf_idf_calc_**

A próxima função talvez seja a mais importante do algoritmo, ele tem como objetivo fazer o cálculo do TF-IDF e retornar os arquivos mais relevantes de acordo com a pesquisa feita pelo usuário.

A função recebe como parâmetro 13 estruturas do tipo lista, sendo 1(input) para salvar o termo pesquisado pelo usuário, 6(wordcouter_doc...) que serão utilizados no cálculo do TF para salvar o número que cada termo aparece em cada documento, e 6(document_...) para salvar os documentos a serem analizados.

```c++
void tf_idf_calc(List *input, List *wordcounter_doc1, List *wordcounter_doc2, List *wordcounter_doc3, List *wordcounter_doc4, List *wordcounter_doc5, List *wordcounter_doc6,
List *document_1, List *document_2, List *document_3, List *document_4, List *document_5, List *document_6)

```

Na primeira interação do código são salvos em um vector valores do tipo `string` para que servirão para definir o ranking dos documentos, após isso uma estrutura de repetição `for` define os valores do vetor `final_tfidf[i]` para zero.

```c++
	ranking.push_back("1st Document");
	ranking.push_back("2nd Document");
	ranking.push_back("3rd Document");
	ranking.push_back("4th Document");
	ranking.push_back("5th Document");
	ranking.push_back("6th Document");

	for (i = 0; i < 6; i++) {
		final_tfidf[i] = 0;
	}
 ```

Calculo do IDF:

A função começa a calcular o IDF, chamando uma estrutura de decisão `while`, que deve se repetir enquanto o valor da variável `aux_input` for diferente de **NULL**. Dentro desta estrutura, entramos em uma estrutura de decisão `if`, onde se o valor do termo por documento for diferente de zero o algoritmo entra nesta estrutura de decisão e calcula o IDF do termo em questão, se a condição não for atendida significa que o termo não aparece no documento. Logo, seu IDF sera igual a zero.

```c++
while (aux_input != NULL) {
		i = 0;

		if (aux_input -> cont_all_documents.contador != 0) {
			idf = log10(6 / aux_input->cont_all_documents.contador);
		} else {
			idf = 0;
		}
```

Calculo do tf:

Após calcular o IDF a função inicia o cálculo do TF, primeiramente, são atribuídos a uma variável **ocurrences** o valor que conta na função `find_word_cont`, que nada mais é a quantidade de vezes que o termo apareceu em um documento específico. Logo após, são salvos na variável **total** o total de palavras que existem no documento. Após todas a variáveis necessárias serem setadas com os devidos valores o algoritmo chama uma estrutura de decisão `if`, verificando se o termo analisado aparece no documento em questão. Se o valor da variável "occurrencs" for "0", logo o *TF* deste termo também é zero, caso contrário o algoritmo entra em uma estrutura `else`, fazendo o cálculo do *TF*. Nesse sentido, ao sair desta estrutura é feito o cálculo do *TFxIDF*, o valor é atribuído a uma posiçao do vetor "final_tfidf[i]". Esta estrutura se repete "6" vezes, uma vez para cada arquivo principal passsado.
 
```C++
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
```


Por último, a função entra em duas estruturas de repetição `for` e em uma estrutura de decisão `if`, que tem como parâmetro de comparação o cálculo final do *TF-IDF*. Estas últimas estruturas do código tem como função ordernar de forma descresente os documentos analisados, fazendo assim um ranking de documentos mais relevantes de acordo com o *TF-IDF*.

```c++
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
```
---



### •Função **_tf_idf_**

Esta é utiliza como função principal, seu objetivo é executar todas as outras funções secundárias e registrar o tempo de execução de cada função.  

```c++
void tf_idf() {
```

## 📷 Representação gráfica

A representação abaixo demonstra detalhadamente cada etapa em que o algoritmo foi pensado e funciona utilizando como exemplo a frase de pesquisa _**'Em que a expansão do mercado influencia no fluxo de informações?'**_ buscando os seis documentos padrões fornecidos pelo professor [Michel Pires da Silva](http://lattes.cnpq.br/1449902596670082). 

<div align="center">
  <a href="https://www.youtube.com/watch?v=bJOeznIbGag"><img src="https://yt-embed.herokuapp.com/embed?v=bJOeznIbGag" alt="Animação TF-IDF" width="800px"></a>
</div>

_Representação 1: Vídeo contendo detalhadamente etapas do algoritmo_

---

## 🔩 Execução de testes

### Tempo de execução

O tempo de execução do algoritmo `TF-IDF` foi medido utilizando da biblioteca **time.h** que desenvolve a leitura do relógio em segundos ao utilizar sua função _clock_ que devolve o tempo de CPU decorrido desde o início da execução do programa, onde o tempo é medido em ciclos do relógio interno como no exemplo de medição abaixo:

```c++
    size_t t;
    t = clock();
    tf_idf(); //Chamada da função que implementa o algoritmo TF-IDF
    t = clock() - t;

    cout << "\nTempo total: " << float(t)/CLOCKS_PER_SEC << " segundos" << std::endl << std::endl;
```
_Representação 1: Exemplo de implementação da função **time.h**_

<p align="left">
<img src="img/saida_ex_tempo.png" width="350px"/> 
</p>

_Imagem 1: Exemplo de saída do tempo de execução da implementação acima_

Com a aplicação dessa função então foi possível medir o tempo de execução das 5 diferentes etapas do programa até chegar ao seu final onde efetua toda a proposta com êxito, sendo essas etapas <b><i>implementação das stopwords</b></i>, <b><i>leitura e filtragem dos documentos</b></i>, <b><i>contagem de palavra por palavra</b></i>, <b><i>verificação da contagem total de cada palavra presente nos documentos</b></i> e o<b><i> cálculo TF-IDF</b></i>, segue então a tabela abaixo onde possibilita visualizar a quantidade de vezes medida e a média aritmética entre as mesmas
 
_Tabela 1: Resultado dos testes de tempo de execução de cada etapa do algoritmo_
| Etapas | Teste 1 | Teste 2 | Teste 3 | Teste 4 | Teste 5 |                                              
|------------------|------------|------------|------------|------------|------------|
|  <b>Etapa 1</B>  | 7.4e-05 s  | 8.1e-05 s  | 7.4e-05 s  | 7.9e-05 s  | 8.2e-05 s  |                                
|  <b>Etapa 2</B>  | 0,235741 s | 0.231393 s | 0.224697 s | 0.225507 s | 0.221642 s |               
|  <b>Etapa 3</B>  | 0.459084 s | 0.461116 s | 0.455663 s | 0.454371 s | 0.440808 s |
|  <b>Etapa 4</B>  | 0.004293 s | 0.004784 s | 0.004476 s | 0.004548 s | 0.004129 s |
|  <b>Etapa 5</B>  | 0.000155 s | 0.000171 s | 0.000157 s | 0.000151 s | 0.000121 s |
|  <b>Total</B>    | 0.699649 s | 0.697839 s | 0.685403 s | 0.684977 s | 0.667042 s |

    Média Aritmética das medições feitas: 0.686982 segundos

**_Observação:_** Todos os testes foram feitos em um computador com o sistema operacional Windows, utilizando _WSL (Windows Subsystem for Linux)_ para compilação, que possui um processador _AMD Ryzen 5 1600 Six-Core Processor 3.20 GHz_ com _16,0 GB de RAM DDR4_ utilizando uma frase padrão de pesquisa inserida no arquivo `phrasetosearch.txt`, sendo ela _**'Em que a expansão do mercado influencia no fluxo de informações?'**_.

A figura abaixo consegue demonstrar a saída do programa onde fornece os tempos de execução em cada etapa:

<p align="center">
<img src="img/saída_calculotempo.png" width="800px"/> 
</p>

_Imagem 2: Saída do programa onde imprime os resultados dos testes de tempo de execução de cada etapa do algoritmo_

### Cálculo do tempo de execução total de cada integrante

Em conjunto com o grupo em que foi responsável pela criação do algoritmo foi organizado uma tabela possuindo os dados de seus **processadores**, **memória RAM** e **Sistema Operacional** de cada integrante do grupo (um total de 9), sendo esses hardwares que possuem relevância para a diferença do cálculo de tempo, onde cada um compilou e executou o código em sua máquina aferindo o tempo de execução em um total de 5 vezes tornando possível visualizar com um menor desvio padrão do resultado possibilitando na criação da tabela abaixo:

| Nome | Processador | Mémoria (GB) | Sistema Operacional |  Tempo 1 (s) |  Tempo 2 (s) |  Tempo 3 (s) |  Tempo 4 (s) |  Tempo 5 (s) |  Média Aritmética (s) |                                            
|------------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|
| <b>Caio</b> | Processador | Mémoria (GB) | Sistema Operacional |  Tempo 1 (s) |  Tempo 2 (s) |  Tempo 3 (s) |  Tempo 4 (s) |  Tempo 5 (s) |  Média Aritmética (s) |                                
| <b>Felipe</b> | Processador | Mémoria (GB) | Sistema Operacional |  Tempo 1 (s) |  Tempo 2 (s) |  Tempo 3 (s) |  Tempo 4 (s) |  Tempo 5 (s) |  Média Aritmética (s) |               
| <b>Henrique</b> | Intel i7-4790K | 16 | Windows 10 (WSL) |  0,695625 |  0,695431 |  0,685270 |  0,684731 |  0,679782 |  0,688168 |
| <b>João Marcelo</b> | Intel i5-8265U | 8 | Ubuntu 20.04.4  |  1.34769 |  1.36259 |  1.38506 |  1.38253 |  1.34472 |  1,364518  |
| <b>João Pedro | Processador | Mémoria (GB) | Sistema Operacional |  Tempo 1 (s) |  Tempo 2 (s) |  Tempo 3 (s) |  Tempo 4 (s) |  Tempo 5 (s) |  Média Aritmética (s) |
| <b>Livia</b> | Processador | Mémoria (GB) | Sistema Operacional |  Tempo 1 (s) |  Tempo 2 (s) |  Tempo 3 (s) |  Tempo 4 (s) |  Tempo 5 (s) |  Média Aritmética (s) |
| <b>Lucas</b> | Intel i7-6700K | 16GB | UBUNTU 20.04 |  0.509106 |  0.51278 |  0.513569 |  0.509033 |  0.517417 |  0.512381 |
| <b>Pedro Louback</b> | AMD Ryzen 5 1600 | 16 | Windows 10 (WSL) |  0,662935 |  0,679511 |  0,676082 |  0,680472 |  0,678130 |  0,675426 |
| <b>Pedro Pinheiro</b> | Intel i7-9750H | 8 | Windows 11 (WSL) |  0.571197 |  0.584476 |  0.580301 |  0.574252 |  0.578098 |  0.5776648 |

• Obtendo então a Média Aritmética de todas as aferições:

	Média Aritmética: 0,6265454 segundos

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
|  `make`                | Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação             


---

## ✒️ Autores

Projeto elaborado por [Caio Fernando Dias](https://github.com/Caio-Fernando-Dias), [Felipe Coelho de Oliveira Campos](https://github.com/fco3lho), [Henrique Souza Fagundes](https://github.com/ohenriquesouza), [João Marcelo Gonçalves Lisboa](https://github.com/joaojmgl), [João Pedro Martins Espíndola](https://github.com/JoaoMEspindola?tab=repositories), [Livia Gonçalves](https://github.com/Livia-Goncalves-01), [Lucas Farinelli Crivellari de Pinho](https://github.com/farinellizin), [Pedro Henrique Louback Campos](https://github.com/PedroLouback) e [Pedro Pinheiro de Siqueira](https://github.com/ppinheirosiqueira) 

Alunos da matéria de Arquitetura e Estruturas de Dados 1 do curso de `Engenharia da Computação` no [CEFET-MG](https://www.cefetmg.br)

