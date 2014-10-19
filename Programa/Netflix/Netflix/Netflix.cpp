#include <iostream>
#include "Netflix.h"

const float Netflix::MENSALIDADE = 17;
float       Netflix::velMaxima = 50;
int         Netflix::quantidadeUsuarios = 0;
int			Netflix::quantidadeFilmes = 0;

Netflix::Netflix()
: cnpj("0000")
{
 quantidadeUsuarios++;	
 quantidadeFilmes++;
 int pos = 0;
 listaDeUsuarios = new Usuario[MAXUSUARIO];
 listaDeFilmes = new Filme[MAXFILMES];

 for(int i = 0; i < MAXUSUARIO; i++)
 {
  this->listaDeUsuarios[i].setLogin("") ;
  this->listaDeUsuarios[i].setSenha("");
  this->listaDeUsuarios[i].setDataDeInscricao(Data(1,1,1990));
   for(int j = 0; j< 10; j++)
   {
	this->listaDeUsuarios[i].setfilmesComprados(listaDeFilmes[j], pos);    
   }
 } 
 
  for(int k = 0; k < MAXFILMES; k++)
  {
   this->listaDeFilmes[k].setTitulo("") ;	 
   this->listaDeFilmes[k].setGenero("") ;
   this->listaDeFilmes[k].setDataDeLancamento(Data(1,1,1990));
  }  
}

Netflix::Netflix(string cnpj, Filme filmes,  Usuario usuarios )
{
 this->cnpj = cnpj;	
 listaDeUsuarios = new Usuario[quantidadeUsuarios];
 listaDeFilmes = new Filme[quantidadeFilmes];
 int pos = 0;
 for(int i = 0; i <= this->quantidadeUsuarios; i++)
 {
  this->listaDeUsuarios[i].setLogin(usuarios.getLogin()) ;
  this->listaDeUsuarios[i].setSenha(usuarios.getSenha());
  this->listaDeUsuarios[i].setDataDeInscricao(usuarios.getDataDeInscricao());
  
  for(int j = 0; j< 10; j++)
   {
	this->listaDeUsuarios[i].setfilmesComprados(listaDeFilmes[j], pos);    
   }
 } 
  for(int k = 0; k <= quantidadeFilmes; k++)
  {
   this->listaDeFilmes[k].setTitulo(filmes.getTitulo()) ;	 
   this->listaDeFilmes[k].setGenero(filmes.getTitulo()) ;
   this->listaDeFilmes[k].setDataDeLancamento(filmes.getDataDeLancamento());
  }  
 }

Netflix::~Netflix()
{
 delete [] listaDeUsuarios;
 delete [] listaDeFilmes;
}


Netflix::Netflix(const Netflix& netflixCpy)
{
 this->cnpj = netflixCpy.cnpj;	
 this->quantidadeUsuarios++;
 this->quantidadeFilmes++;
 for(int i = 0; i < this->quantidadeUsuarios; i++)
 {
  this->listaDeUsuarios[i].setLogin(netflixCpy.listaDeUsuarios[i].getLogin());
  this->listaDeUsuarios[i].setSenha(netflixCpy.listaDeUsuarios[i].getSenha());
  this->listaDeUsuarios[i].setDataDeInscricao(netflixCpy.listaDeUsuarios[i].getDataDeInscricao());
  for(int j = 0; j< 10; j++)
   {
	this->listaDeUsuarios[i] = netflixCpy.listaDeUsuarios[i];
   }
 } 
  for(int k = 0; k < quantidadeFilmes; k++)
  {
   this->listaDeFilmes[k].setTitulo(netflixCpy.listaDeFilmes[k].getTitulo()) ;	 
   this->listaDeFilmes[k].setGenero(netflixCpy.listaDeFilmes[k].getGenero()) ;
   this->listaDeFilmes[k].setDataDeLancamento(netflixCpy.listaDeFilmes[k].getDataDeLancamento());
  }  
 }		


void Netflix::ListarUsuarios(Netflix * ntf, int tamanho)
 {
   
  for(int i = 0; i< ntf->quantidadeUsuarios; i++)	 
  {
   cout << ntf->listaDeUsuarios[i].getLogin()<< endl;
   cout << ntf->listaDeUsuarios[i].getSenha()<< endl;
   cout << ntf->listaDeUsuarios[i].getDataDeInscricao()<< endl;
   cout << ntf->listaDeUsuarios[i].getfilmesComprados()<< endl;
  }
 }
 
 
 void Netflix::AdicionarUsuario(Netflix* ntf, const int& pos,const string& lg,const string& snh,const Data& data)
 {
  Usuario *auxUsuario;	 
  if(quantidadeUsuarios < MAXUSUARIO)
  {
   ntf->listaDeUsuarios->Adicionar(auxUsuario, lg, snh, data);
   quantidadeUsuarios++;
  }else
  {
   cout << "Quantidade maxima de usuarios alcancada. Por favor entenda" << endl;	  
  }
 }
 
 /*
 void Netflix::AdicionarFilme(Netflix* ntf, Filme* fm, const int& pos, const string& titulo,const string& genero, const Data& data)
 {
  //Filme *auxFilme;	 
  if(quantidadeFilmes < MAXFILMES)	 
  {
   ntf->listaDeUsuarios->A 
   quantidadeFilmes++;
  }else
  {
   cout << "Limite de filmes atingido" << endl;	  
  }
 }*/
  
 
float Netflix::CalculoDownload(float velMaxima, float velAtual)
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
  


ostream &operator<<(ostream &output, const Netflix& ntf)  
{
 int i, j;
 for (i = 0; i < ntf.quantidadeUsuarios;i++)  	
 {
  output << "Usuario de numero " << i+1 << ntf.listaDeUsuarios[i].getLogin()<< endl;
  output << "Senha deste usuario:"  << ntf.listaDeUsuarios[i].getSenha() << endl;
  for(j = 0; j < ntf.quantidadeFilmes; j++)
  {
   output << "Filme de numero " << i+1 << ntf.listaDeFilmes[i];	  
  }
  
}
 return output;
}
  
Netflix Netflix::operator=(const Netflix& ntf) const
{
 Netflix aux;	
 aux.cnpj = ntf.cnpj;
 aux.listaDeUsuarios = ntf.listaDeUsuarios;
 aux.listaDeFilmes = ntf.listaDeFilmes;
 aux.quantidadeFilmes = ntf.quantidadeFilmes;
 return aux;
 
}
  
void Netflix::setCnpj(const string& cnpj) 
 {
  this->cnpj = cnpj;	 
 }

/* 
void Netflix::setLogin(const string& login) 
{
 this->usuarioLogin = login;	 
}
 
 void Netflix::setSenha(const string& senha) 
 {
  this->usuarioSenha = senha;	 
 }
 
 void Netflix::setExisteUsuario(const int& aux)
 {
  this->existeUsuario = aux;
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
 */
 float Netflix::getVelMaxima() const
 {
  return velMaxima;	
 }
   	 
float Netflix::getMensalidade () const
{
 return MENSALIDADE;	 
}

int Netflix::getQuantidadeUsuarios() const
{
 return quantidadeUsuarios;	
}

int Netflix::getQuantidadeFilmes() const
{
 return quantidadeFilmes;	
}