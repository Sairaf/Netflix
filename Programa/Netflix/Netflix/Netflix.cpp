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
 
 for(int i = 0; i < MAXUSUARIOS; i++)
 {
  this->listaDeUsuarios[i].setLogin("") ;
  this->listaDeUsuarios[i].setSenha("");
  this->listaDeUsuarios[i].setDataDeInscricao(Data(1,1,1990));
   for(int j = 0; j< 10; j++)
   {
	this->listaDeUsuarios[i].setFilmesAssistidos(listaDeFilmes[j]);    
   }
 } 
 
  for(int k = 0; k < MAXFILMES; k++)
  {
   this->listaDeFilmes[k].setTitulo("") ;	 
   this->listaDeFilmes[k].setGenero("") ;
   this->listaDeFilmes[k].setDataDeLancamento(Data(1,1,1990));
  }  
}

Netflix::Netflix(string cnpj, vector<Filme> filmes, vector <Usuario>  usuarios )
{
 this->cnpj = cnpj;	
 this->quantidadeUsuarios++ ;	
 this->quantidadeFilmes++;
 
 for(int i = 0; i < this->quantidadeUsuarios; i++)
 {
  this->listaDeUsuarios[i].setLogin(usuarios[i].getLogin()) ;
  this->listaDeUsuarios[i].setSenha(usuarios[i].getSenha());
  this->listaDeUsuarios[i].setDataDeInscricao(usuarios[i].getDataDeInscricao());
  
  for(int j = 0; j< 10; j++)
   {
	this->listaDeUsuarios[i].setFilmesAssistidos(listaDeFilmes[j]);    
   }
 } 
  for(int k = 0; k < quantidadeFilmes; k++)
  {
   this->listaDeFilmes[k].setTitulo(filmes[k].getTitulo()) ;	 
   this->listaDeFilmes[k].setGenero(filmes[k].getTitulo()) ;
   this->listaDeFilmes[k].setDataDeLancamento(filmes[k].getDataDeLancamento());
  }  
 }

Netflix::~Netflix()
{
 
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
	this->listaDeUsuarios[i].setFilmesAssistidos(netflixCpy.listaDeFilmes[j]);    
   }
 } 
  for(int k = 0; k < quantidadeFilmes; k++)
  {
   this->listaDeFilmes[k].setTitulo(netflixCpy.listaDeFilmes[k].getTitulo()) ;	 
   this->listaDeFilmes[k].setGenero(netflixCpy.listaDeFilmes[k].getGenero()) ;
   this->listaDeFilmes[k].setDataDeLancamento(netflixCpy.listaDeFilmes[k].getDataDeLancamento());
  }  
 }		
 /*
 void Netflix::ListarUsuarios(Netflix * ntf, int tamanho)
 {
  int k = 0;	 
  for(int i = 0; i< tamanho; i++)	 
  {
    cout << ntf->listaDeUsuarios[i].getLogin();	<< endl;
   cout << ntf->listaDeUsuarios[i].getSenha();<< endl;
   cout <<  ntf->listaDeUsuarios[i].getDataDeInscricao().<< endl;
   cout << ntf->listaDeUsuarios[i].getFilmesAssistidos()<< endl;
  }
 }*/
 
 float CalculoVelocidade(float velMaxima, float velAtual)
 {
  velAtual = -1;	 
  float velDownload;
  while(velAtual < 0)
  {
   cout << "Digite a velocidade de sua conexao"<< endl;
   cin >> velAtual;	  
  }
  
  velDownload = velAtual/8;	 
  if(velAtual < 0)
  if(velDownload > velMaxima)
  {
   cout << "Velocidade de download: " << velMaxima << " MBPS"<< endl;	  
  }else
  {
   cout << "Velocidade de download: " << velDownload << " MBPS"<< endl;	  	  
  }
  
  return velDownload;
 }