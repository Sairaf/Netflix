#include <iostream>
#include "Filme.h"

Filme::Filme(string titulo, string genero, const Data& dt)
:dataDeLancamento(dt)
{
	this->titulo = titulo;
	this->genero = genero;
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

void Filme::setDataDeLancamento(const Data& data)
{
 dataDeLancamento = data;
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
/*
void Filme::AdicionarFilme(Filme fm[], const string titulo, const string genero, const Data& dt, int pos)
{
	fm[pos].setTitulo(titulo);
	fm[pos].setGenero(genero);
	fm[pos].setDataDeLancamento(dt);
}
*/