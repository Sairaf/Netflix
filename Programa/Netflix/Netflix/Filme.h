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
