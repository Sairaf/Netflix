#include <iostream>
#include "Netflix.h"

const float Netflix::MENSALIDADE = 17;
float       Netflix::velMaxima = 50;
int			Netflix::quantidadeFilmes = 0;
Data        Netflix::data(Data(06,10,2014));

Netflix::Netflix()
: cnpj("00.000.000/0000-00"), tituloFilme(MAXFILMES)
{
 
  setLogin("default") ;
  setSenha("default");
  for(int j = 0; j< 10; j++)
   {
	this->setTitulo("default", j);
   }
}

Netflix::Netflix(string cnpj, string login, string senha)
: cnpj(cnpj), tituloFilme(MAXFILMES)
{
 
  setLogin(login) ;
  setSenha(senha);
  this->tituloFilme.push_back("tatatete ") ;  
   
}

Netflix::~Netflix()
{
 
}


Netflix::Netflix(const Netflix& netflixCpy)
:cnpj(netflixCpy.cnpj), tituloFilme(netflixCpy.tituloFilme)
{
 
  setLogin(netflixCpy.usuarioLogin) ;
  setSenha(netflixCpy.usuarioSenha);
  for(int j = 0; j< 10; j++)
   {
	this->tituloFilme[j] = netflixCpy.tituloFilme[j];  
   }
 }		
 
 
void Netflix::ListarUsuario(Netflix *ntf, int tamanho)
 {
  cout << "Usuario: "<< ntf->getLogin() <<endl;
  cout << "Senha: "<< ntf->getSenha()<<endl;
  for(int i = 0; i < tamanho; i++)
  {
   cout << "Filmes Alugados: "<< ntf->getTitulo(i) <<endl;  
  }
 }
 
 void Netflix::AdicionarUsuario(Netflix* ntf, string lg, string snh)
 {
   ntf->setLogin(lg);	  
   ntf->setSenha(snh);
  
 }
 
void Netflix::AdicionarFilme(Netflix *ntf, string titulo, int pos)
{
 

 if((pos < MAXFILMES) || (pos >=0) )
 {
  ntf->setTitulo(titulo, pos)  ;	 
  quantidadeFilmes++;
 }else
 {
  cout << "Limite de filmes atingido. " << endl;	 

 }
} 
  
 
 const float Netflix::CalculoDownload(float velMaxima, float velAtual)
 {
  velAtual = -1;	 
  float velDownload;
  while(velAtual < 0)
  {

   cout << "Digite a velocidade de sua conexao"<< endl;
   cin >> velAtual;	  
  }
  
  velDownload = velAtual/8;	 
  
  return velDownload;
 }
 
 const float Netflix::CalculoGanhos(int nUsuarios, const float MENSALIDADE)
 {
  if(nUsuarios > 0)
  {	 
   float ganhos = nUsuarios* MENSALIDADE;
   return ganhos;
  }else
  {
   cout << "Valor invalido. Usuarios tem de ser maior que zero." << endl;	  
  }
 }
  
ostream &operator<<(ostream &output, const Netflix& ntf)  
{
 output <<"Usuario: "<< ntf.getLogin()<< endl;
 output <<"Senha:  "<< ntf.getSenha()<< endl;
 int i = 0;
 for(i; i < ntf.quantidadeFilmes; i++)
 //output << ntf.getLogin();
 output << "Filme numero " << i << ": "<< ntf.getTitulo(i) << endl;
 return output;
}
  
  
void Netflix::setCnpj(const string& cnpj) 
 {
  this->cnpj = cnpj;	 
 }
 
void Netflix::setLogin(const string& login) 
{
 this->usuarioLogin = login;	 
}
 
 void Netflix::setSenha(const string& senha) 
 {
  this->usuarioSenha = senha;	 
 }
 
 void Netflix::setTitulo(const string& titulo, const int& pos) 
 {
  this->tituloFilme[pos] = titulo;
  }
 
string Netflix::getCnpj() const
{
 return this->cnpj;	
}


string Netflix::getLogin() const
{
  return usuarioLogin;
 }

string Netflix::getSenha() const
{
  return usuarioSenha;
 }

string Netflix::getTitulo(const int& pos) const
{
  return tituloFilme[pos];
 } 

int Netflix::getQuantidadeFilmes() const
{
 return quantidadeFilmes;	
}
 
 float Netflix::getVelMaxima() const
 {
  return velMaxima;	
 }
   	 
float Netflix::getMensalidade () const
{
 return MENSALIDADE;	 
}
