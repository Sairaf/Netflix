#include <iostream>
#include "Usuario.h"

int  Usuario::qtdFilmesComprados = 0;
float Usuario::saldoConta = 0;

Usuario::Usuario()
:login(""),senha("")
{
 filmesComprados = NULL;;
 
 
}

Usuario::~Usuario()
{
 delete [] Usuario::filmesComprados;	
}

Usuario::Usuario(const string login, const string senha, Filme& fAssistidos)
{
 int i;	
 Filme* auxFilme = new Filme[MAXFILMES];
 this->setLogin(login);
 this->setSenha(senha);
 
 if(qtdFilmesComprados < MAXFILMES)
 {
  this->filmesComprados = new Filme[qtdFilmesComprados];
  this->filmesComprados[qtdFilmesComprados] = fAssistidos;
  qtdFilmesComprados++;
 }
 /*
 for(i = 0; i < MAXFILMES; i++)
 {
   auxFilme[i] = this->filmesComprados[i];
 }
 
 delete [] this->filmesComprados;
 this->filmesComprados = new Filme[++qtdFilmesComprados];

 for(i = 0; i < MAXFILMES-1; i++)
 {
   this->filmesComprados[i] = auxFilme[i] ;
 }
 this->filmesComprados[MAXFILMES-1] = fAssistidos;
 delete [] auxFilme;*/
}

Usuario::Usuario(const Usuario &usuarioCpy)
{
 login = usuarioCpy.login;
 senha = usuarioCpy.senha;
 //dataDeInscricao = usuarioCpy.dataDeInscricao;
 this->filmesComprados = usuarioCpy.filmesComprados;
}

void Usuario::ComprarFilme(Usuario* us,const Filme& filme		)
{
 int i;	
 Filme* fm = new Filme[qtdFilmesComprados];
 if((us->qtdFilmesComprados < MAXFILMES) ||(us->saldoConta > fm->getPreco())) 	
 {
  us->filmesComprados = new Filme[qtdFilmesComprados];
  for(i =0; i < us->qtdFilmesComprados; i++)
  {
	fm[i] = us->filmesComprados[i];
  }
  delete [] us->filmesComprados;
  us->filmesComprados = new Filme[++qtdFilmesComprados];
  for(i =0; i < qtdFilmesComprados-1; i++)
  {
	us->filmesComprados[i] = fm[i];
  }  
    us->filmesComprados[qtdFilmesComprados-1] = fm[qtdFilmesComprados-1];
    delete [] fm;	
 }else if(us->saldoConta > fm->getPreco())
 {
  cout << "Limite de filmes em sua conta foi alcancado" << endl;	 
 }else
 {
  cout << "Saldo insuficiente" << endl;	 
 }
}

void Usuario::setLogin(const string& login)
{
 string auxLogin = login;
 while(auxLogin == "\0")
 {
  cout << "Login invalido. Por favor, Digite novamente" << endl;
  cin >> auxLogin;
 }
  this->login = login;	 	
}

void Usuario::setSenha(const string& senha)
{
 string auxSenha = senha;
 while(auxSenha == "\0")	
 {
  cout << "Senha invalida. Por favor, Digite novamente" << endl;
  cin >> auxSenha;
 }
 this->senha = senha;	 	 
}
 
 //Verificar validacao

string Usuario::getLogin() const
{
 return this->login;	
}

string Usuario::getSenha() const
{
 return this->senha;	
}

Filme* Usuario::getfilmesComprados() const
{
 return filmesComprados;	
}

float Usuario::getSaldoConta() const
{
 return this->saldoConta;	
}

int Usuario::getQtdfilmesComprados() const
{
 return this->qtdFilmesComprados;	
}