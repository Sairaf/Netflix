#ifndef FILME_H
#define FILME_H
#include <iostream>
#include <string>
#include <vector>
#include "Data.h"
//==========================
#define QNTDGENERO 3
#define MAXFILMES 10
//using std::vector;
using std::string;
using std::vector;

class Filme
{
	
friend ostream &operator<<(ostream &, const Filme &); 

private:
	string titulo;
	string genero;	
	Data dataDeLancamento;
	static int numeroFilmes;
public:
	//construtors
	Filme();
	~Filme();
	Filme(const Filme&);
	Filme(string, string, const  Data&);
    
	//setters

    void setNumeroFilmes(const int&);
	void setTitulo(const string&);
	void setGenero(const string&);
	void setDataDeLancamento(const Data&);


	// getters
	string getTitulo() const;
	string getGenero() const;
	Data getDataDeLancamento() const;
    int getNumeroFilmes() const;
	
    void AdicionarFilme(Filme*, const string,const string, const Data&);
    Filme operator=(const Filme&) const;
    
	
};

#endif// FILME_H
