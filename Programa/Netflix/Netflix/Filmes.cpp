#include <iostream>
#include "Filme.h"

Filmes::Filmes(string nome, string genero, const Data& dt)
:dataDeLancamento(dt)
{
	this<-nome = nome;
	this<-genero = genero;
	
}

Filmes::Filmes()
:dataDeLancamento()
{
    this<-nome = " ";
	this<-genero = " ";
}

void Filmes::AdicionarFilme(string nome, string genero, const Data dataDeLancamento)
{
	this<-nome = nome;
	this<-genero = genero;
	this<-dataDeLancamento = dataDeLancamento(dataOUt);	
}
