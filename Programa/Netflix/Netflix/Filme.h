/*
Filme.h 

Função: Armazenar os atributos básicos de um filme

Iniciar todos os atributos ok
Iniciar 3 construtores (Default, cópia e um normal) ok
Ter atributo string ok
Ter atributo static ok
Ter atributo const static ok
Dois métodos constantes ok
um array ok
uma função inline (mensagem de boas vindas) ok
método com passagem por referência ok
Método static (chamado no main) ok

Requisitos de implementação (2):

Operator = ok 
Alocação dinâmica - se houver vazamento de memória a classe toda é desconsiderada ok
Usar o destrutor ok 
Construtor de cópia ok
Operator << friend ok 
Um const static ok

A classe filme.h deverá armazenar o titulo de um filme, seu genero (ação, comédia, etc.), e qual(is) é(são) o(s) ator(es)/atriz(es) principais

atributos:
titulo: string - Recebe o título de um filme
genero: string - Recebe o gênero deste filme
atores: *string - Recebe os atores principais do filme em questão
quantidadeAtores: int - Recebe o número de atores principais. Esta variázel é utilizada para ter um controle na adição de novos atores
Métodos:
<<friend>> operator << : método friend que facilita a escrita na tela dos atributos, pois nãos será necessário colocar um cout para cada um
operator = : O método de atribuição funciona similarmente ao vetor de cópia.
*/



#ifndef FILME_H
#define FILME_H
//========================
#include <iostream>
#include <string>
#include <vector>
//==========================

#define MAXATORES 2
using namespace std;

class Filme
{
	
friend ostream &operator<<(ostream &, const Filme &); 

private:
	string titulo;
	string genero;	
	string* atores;
	static int quantidadeAtores;
	const static float preco;
	//Data dataDeLancamento;

public:
	//construtors
	Filme();
	~Filme();
	Filme(const Filme&);
	Filme(string, string, string*);
    
	//setters

    void setNumeroFilmes(const int&);
	void setTitulo(const string&);
	void setGenero(const string&);
	
	// getters
	string getTitulo() const;
	string getGenero() const;
	int getNumeroFilmes() const;
	float getPreco() const;
	
    Filme operator=(const Filme&) const;
    
	
};

#endif// FILME_H
