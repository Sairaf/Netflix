#include <iostream>
#include "Usuario.h"

Usuario::Usuario()
:dataDeInscricao()
{
 this->login = " ";
 this->senha = " ";
  
 filmesComprados = new Filme[0];
 filmesComprados->setTitulo("");
 filmesComprados->setGenero("");
 //filmesComprados->setDataDeLancamento(13/05/2014);
 this-> quantidadefilmesComprados = 0; 
}

Usuario::~Usuario()
{
 Usuario us;	
 delete [] us.filmesComprados;	
}

Usuario::Usuario(const string login, const string senha, const Data& data, vector<Filme>& fAssistidos)
:dataDeInscricao(data)
{
 this->login = login;
 this->senha = senha;
 
 filmesComprados = new Filme;
 filmesComprados->setTitulo("");
 filmesComprados->setGenero("");	 
 this-> quantidadefilmesComprados = 0; 
}

Usuario::Usuario(const Usuario &usuarioCpy)
{
 login = usuarioCpy.login;
 senha = usuarioCpy.senha;
 dataDeInscricao = usuarioCpy.dataDeInscricao;
 filmesComprados = new Filme[quantidadefilmesComprados];
 for(int i = 0; i < quantidadefilmesComprados; i++)
 {
  filmesComprados[i] = usuarioCpy.filmesComprados[i];	 
 }	
}

void Usuario::AlugarFilme(Usuario& us,const Filme fm)
{
 int i;	
 if(quantidadefilmesComprados < MAXFILMES)	
 {
  Filme* aux = new Filme[quantidadefilmesComprados];
  for(i =0; i < quantidadefilmesComprados; i++)
  {
	aux[i] = filmesComprados[i];
  }
  delete [] us.filmesComprados;
  us.filmesComprados = new Filme[++quantidadefilmesComprados];
 for(i =0; i < quantidadefilmesComprados-1; i++)
  {
	us.filmesComprados[i] = aux[i];
  }  
    us.filmesComprados[quantidadefilmesComprados-1] = fm;
    delete [] aux;	
 }else
 {
  cout << "Limite de filmes em sua conta foi alcancado" << endl;	 
 }
}

void Usuario::Adicionar(Usuario *us, const string& login, const string& senha, const Data& data)
{
 us->setLogin(login);
 us->setSenha(senha);
 us->setDataDeInscricao(data);
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
 
void Usuario::setNumUsuarios(const int& i)
{
 if(numUsuarios < MAXUSUARIO)	
 {
  this->numUsuarios+= i;	 
 }
}

void Usuario::setDataDeInscricao(const Data& data)
{

 //Verificar validacao
 /*
 int auxData;
 auxData = data.VerificaDia(data.getDia());
 while(auxData = 1)	
 {
  cout << "Senha invalida. Por favor, Digite novamente" << endl;
  cin >> auxSenha;	 
 }*/
 this->dataDeInscricao = data;	
}

void Usuario::setfilmesComprados(const Filme& fm, const int& pos)
{
 if(pos < MAXFILMES)	
 {
  this->filmesComprados[pos] = fm;
 }else
 {
  cout << "Limite de filmes atingido" << endl;	 
 }
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

Filme* Usuario::getfilmesComprados() const
{
 return filmesComprados;	
}

int Usuario::getNumUsuarios() const
{
 return numUsuarios;	
}