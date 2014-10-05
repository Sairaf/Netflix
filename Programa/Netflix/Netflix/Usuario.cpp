#include <iostream>
#include "Usuario.h"



Usuario::Usuario()
:dataDeInscricao(), filmesAssistidos(MAXALUGUEL) 
{
 this->login = " ";
 this->senha = " ";
 
 for(int i = 0; i < filmesAssistidos.size(); i++)
 {
  filmesAssistidos[i].setTitulo("0") ;	 
  filmesAssistidos[i].setGenero("0") ;
  filmesAssistidos[i].setDataDeLancamento(Data(1,1,1990));
  	 
 }
 this->quantidadeFilmesAssistidos = 0;
}


Usuario::~Usuario()
{
	
}

Usuario::Usuario(const string login, const string senha, const Data& data, vector<Filme>& fAssistidos)
:dataDeInscricao(data)
{
 this->login = login;
 this->senha = senha;
 for(int i = 0; i < filmesAssistidos.size(); i++)
 {
  this->filmesAssistidos[i].setTitulo(fAssistidos[i].getTitulo());
 }	 
}

Usuario::Usuario(const Usuario &usuarioCpy)
{
 login = usuarioCpy.login;
 senha = usuarioCpy.senha;
 dataDeInscricao = usuarioCpy.dataDeInscricao;
 for(int i = 0; i < filmesAssistidos.size(); i++)
 {
  filmesAssistidos[i] = usuarioCpy.filmesAssistidos[i];	 
 }	
 this-> numUsuarios++;
 this-> quantidadeFilmesAssistidos = 0;
}

void Usuario::setLogin(const string& login)
{
 this->login = login;
}

void Usuario::setSenha(const string& senha)
{
 this->senha = senha;	
}

void Usuario::setDataDeInscricao(const Data& data)
{
 this->dataDeInscricao = data;	
}

void Usuario::setFilmesAssistidos(const Filme& fm)
{
 if(this->quantidadeFilmesAssistidos <= this->filmesAssistidos.size())
 {
  this->filmesAssistidos[this->quantidadeFilmesAssistidos].setTitulo(fm.getTitulo()); 
  this->filmesAssistidos[this->quantidadeFilmesAssistidos].setGenero(fm.getTitulo());  
  this->filmesAssistidos[this->quantidadeFilmesAssistidos].setDataDeLancamento(fm.getDataDeLancamento());	
  this->quantidadeFilmesAssistidos++;
 }	
}

void Usuario::setNumUsuarios(const int& num)
{
 this->numUsuarios = num;	
}

string Usuario::getLogin() const
{
 return this->login;	
}

string Usuario::getSenha() const
{
 return this->senha;	
}

Data Usuario::getDataDeInscricao() const
{
 return this->dataDeInscricao;	
}

vector <Filme> Usuario::getFilmesAssistidos() const
{
 return filmesAssistidos;	
}

int Usuario::getNumUsuarios() const
{
 return numUsuarios;	
}