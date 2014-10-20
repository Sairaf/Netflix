#include <iostream>
#include "Netflix.h"

const float Netflix::MENSALIDADE = 17;
float       Netflix::velMaxima = 50;
int         Netflix::qtdUsuarios = 0;

Netflix::Netflix()
: cnpj("00000000/0000-00"), listaDeUsuarios()
{
 qtdUsuarios++;	

}

Netflix::Netflix(const string& cnpj, const Usuario& usuarios, const int& pos )
{
 int i;	
 this->cnpj = cnpj;	
 if((usuarios.getLogin() != "\0") && (usuarios.getSenha() != "\0"))
 {
  this->listaDeUsuarios = new Usuario[qtdUsuarios];
  Usuario *auxUsuario  = new Usuario[qtdUsuarios];
  for(i = 0; i < qtdUsuarios; i++)
  {
   auxUsuario[i] = this->listaDeUsuarios[i];	 
  }
  
   delete [] this->listaDeUsuarios;
   this->listaDeUsuarios = new Usuario[++qtdUsuarios];
   for(i = 0; i < qtdUsuarios-1; i++)
   {
    this->listaDeUsuarios[qtdUsuarios] = auxUsuario[qtdUsuarios];
   }
  this->listaDeUsuarios[qtdUsuarios-1] = usuarios;
  delete [] auxUsuario;
  this->qtdUsuarios++; 
 } 
} 
   
 

Netflix::~Netflix()
{
 delete [] listaDeUsuarios;
 
}


Netflix::Netflix(const Netflix& netflixCpy)
{
 this->cnpj = netflixCpy.cnpj;	
 this->qtdUsuarios++;
 this->listaDeUsuarios = netflixCpy.listaDeUsuarios;
 
 }		


void Netflix::ListarUsuarios(Netflix * ntf, int tamanho)
 {
   
  for(int i = 0; i< ntf->qtdUsuarios; i++)	 
  {
   cout << ntf->listaDeUsuarios[i].getLogin()<< endl;
   cout << ntf->listaDeUsuarios[i].getSenha()<< endl;
   cout << ntf->listaDeUsuarios[i].getfilmesComprados()<< endl;
  }
 }
 
 
 void Netflix::AdicionarUsuario(Netflix* ntf, const int& pos,const string& login,const string& senha,const Data& data, const Filme& fm)
 {
  Usuario x;	 
  if(pos < MAXUSUARIO)
  {	 
   ntf->listaDeUsuarios[pos].setLogin(login);
   ntf->listaDeUsuarios[pos].setSenha(senha);
   ntf->listaDeUsuarios[pos].ComprarFilme(ntf->listaDeUsuarios, fm,ntf->listaDeUsuarios[pos].getSaldoConta() );
  }
 }
  
 
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
 for (i = 0; i < ntf.qtdUsuarios;i++)  	
 {
  output << "Usuario de numero " << i+1 << ntf.listaDeUsuarios[i].getLogin()<< endl;
  output << "Senha deste usuario:"  << ntf.listaDeUsuarios[i].getSenha() << endl;
  for(j = 0; j < ntf.listaDeUsuarios->filmesComprados->getQuantidadeFilmesComprados(); j++)
  {
   output << "Filme de numero " << i+1 << ntf.listaDeUsuarios[i].filmesComprados.getTitulo();	  
   output << "Genero " << i+1 << ntf.listaDeUsuarios[i].filmesComprados.getGenero();	  
   output << "Filme de numero " << i+1 << ntf.listaDeUsuarios[i].filmesComprados.getTitulo();	  
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

int Netflix::getqtdUsuarios() const
{
 return qtdUsuarios;	
}

int Netflix::getQuantidadeFilmes() const
{
 return quantidadeFilmes;	
}