#ifndef FILME_H
#define FILME_H

#include <string>
#include "Data.h"

using std::string;

class Filme
{
private:
	string titulo;
	string genero;
	Data dataDeLancamento;
public:
	//construtors
	Filme();
	Filme(string, string, const  Data&);

	//setters

	void setTitulo(const string&);
	void setGenero(const string&);
	void setDataDeLancamento(const Data&);


	// getters
	string getTitulo() const;
	string getGenero() const;
	Data getDataDeLancamento() const;

	void AdicionarFilme(Filme[], const string,const string, const Data&, int);


	
};

#endif// FILME_H
