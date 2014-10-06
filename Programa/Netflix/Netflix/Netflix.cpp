#include <iostream>
#include "Netflix.h"

const float Netflix::MENSALIDADE = 17;
float       Netflix::velMaxima = 50;
int         Netflix::quantidadeUsuarios = 0;
int			Netflix::quantidadeFilmes = 0;
Data        Netflix::data(Data(06,10,2014));

Netflix::Netflix()
: cnpj("00.000.000/0000-00"), tituloFilme(10)
{
 quantidadeUsuarios++;	
 quantidadeFilmes++;
 
  setLogin("default") ;
  setSenha("def_ault");
  for(int j = 0; j< 10; j++)
   {
	this->tituloFilme[j].setTitulo("Def-aul-t") ;
   }
}

Netflix::Netflix(string cnpj, string login, string senha)
: cnpj(cnpj), tituloFilme(10)
{
 quantidadeUsuarios++;	
 quantidadeFilmes++;
 
  setLogin(login) ;
  setSenha(senha);
  for(int j = 0; j< 10; j++)
   {
	this->tituloFilme[j].setTitulo(" ") ;  
   }
}

Netflix::~Netflix()
{
 
}


Netflix::Netflix(const Netflix& netflixCpy)
:cnpj(netflixCpy.cnpj), tituloFilme(netflixCpy.tituloFilme)
{
 quantidadeUsuarios++;	
 quantidadeFilmes++;
 
  setLogin(netflixCpy.usuarioLogin) ;
  setSenha(netflixCpy.usuarioSenha);
  for(int j = 0; j< 10; j++)
   {
	this->tituloFilme = netflixCpy.tituloFilme;  
   }
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
 
 void Netflix::setTitulo(const string& titulo) 
 {
  if((titulo != "") || (titulo != "\0") )	 
  {
  this->tituloFilme = titulo;
  }
 }
 
 string Netflix::getLogin() const
 {
  return usuarioLogin;
 }

 string Netflix::getsenha() const
 {
  return usuarioSenha;
 }

 string Netflix::getTitulo() const
 {
  return tituloFilme;
 } 
 
 float Netflix::getVelMaxima() const
 {
  return velMaxima;	
 }
   
 int Netflix::getQuantidadeUsuarios() const
 {
  return quantidadeUsuarios;	 
 }
 
 int Netflix::getQuantidadeFilmes() const
 {
  return quantidadeUsuarios;	 
 }
 
 float Netflix::getMensalidade () const
 {
  return MENSALIDADE;	 
 }

void Netflix::ListarUsuarios(Netflix * ntf, int tamanho)
 {
  cout << ntf->getLogin()	<< endl;
  cout << ntf->getSenha()<< endl;
  for(int i = 0; i< tamanho; i++)	 
  {
   cout <<ntf->tituloFilme[i].getTitulo();
  }
 }
 
 void Netflix::AdicionarUsuario(Netflix ntf, int pos, string lg, string snh, Data data)
 {
  if(pos < MAXUSUARIOS)	 
  {
   ntf.listaDeUsuarios[pos].setLogin(lg);	  
   ntf.listaDeUsuarios[pos].setSenha(snh);
   ntf.listaDeUsuarios[pos].setDataDeInscricao(Data(1,1,1100));
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
 
 float Netflix::CalculoGanhos(int nUsuarios, const float MENSALIDADE)
 {
  if(nUsuarios > 0)
  {	 
   float ganhos = nUsuarios* MENSALIDADE;
   return ganhos;
  }
 }
  
 void Netflix::AdicionarFilme(Netflix ntf, int pos, string tt, string gen, Data data)
 {
  if(pos < MAXUSUARIOS)	 
  {
   ntf.listaDeFilmes[pos].setTitulo(tt);	  
   ntf.listaDeFilmes[pos].setGenero(gen);
   ntf.listaDeFilmes[pos].setDataDeLancamento(Data(1,1,1100));
  }
 }
 

