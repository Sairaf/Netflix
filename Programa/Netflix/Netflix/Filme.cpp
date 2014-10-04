#include <iostream>
#include "Filme.h"

Filme::Filme(string titulo, string genero, const Data& dt)
//:dataDeLancamento(dt)
{
	Filme::setTitulo(titulo);
	this->genero = genero;
	this->dataDeLancamento = dt;
}

Filme::Filme()
:dataDeLancamento()
{
    this->titulo = " ";
	this->genero = " ";
}

void Filme::setTitulo(const string& tit)
{
 this->titulo = titulo;	
}

void Filme::setGenero(const string& gen)
{
 this->titulo = titulo;	
}

void Filme::setDatadeLancamento(const Data& dat)
{
 this->dataDeLancamento = dat;	
}

string Filme::getTitulo() const
{
 return this->titulo;	
}

string Filme::getGenero() const
{
 return this->genero;	
}

Data Filme::getDataDeLancamento() const
{
 return this->dataDeLancamento;	
}

void Filme::AdicionarFilme(string titulo, string genero, const Data& dt)
{
	this->titulo = titulo;
	this->genero = genero;
	this->dataDeLancamento = dt(dt);	
}
