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

Alocação dinâmica de memória.
fried Operator<<
Operator=
vector push_back
Requisitos de implementação (3):

Duas classes. Classes devem possuir:
Operator =
Alocação dinâmica - se houver vazamento de memória a classe toda é desconsiderada
Usar o destrutor
Construtor de cópia
Operator << friend
Um const static









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
