#include <iostream>
#include "Netflix.h"

float       Netflix::velMaxima = 15;
int         Netflix::existeUsuario = 0;

Netflix::Netflix(string nome, string cnpj)
:empresa(
{
 
}

Netflix::Netflix(string login, string senha, string  tituloFilme)
{
  this->setLogin(login) ;
  this->setSenha(senha);  
  this->setTitulo(tituloFilme);
}

Netflix::~Netflix()
{
 delete Netflix::tituloFilme;

}


Netflix::Netflix(const Netflix& netflixCpy)
:tituloFilme(netflixCpy.tituloFilme)
{
  setLogin(netflixCpy.usuarioLogin) ;
  setSenha(netflixCpy.usuarioSenha);
  for(int j = 0; j< MAXFILMES; j++)
   {
	this->tituloFilme[j] = netflixCpy.tituloFilme[j];  
   }
 }		
 
 /*
const void Netflix::ListarUsuario(Netflix *ntf, int tamanho)
{ 
 int i;
  cout << "Usuario: "<< ntf->getLogin() <<endl;
  cout << "Senha: "<< ntf->getSenha()<<endl;
 for(i=0; i < ntf->quantidadeFilmes; i++)
 {
  cout << "Filme numero " << i << ": "<< ntf->tituloFilme[i] << endl;
 }
 }
 */
 void Netflix::AdicionarUsuario(Netflix* ntf, string lg, string snh)
 {
	delete ntf->tituloFilme; 
	ntf->quantidadeFilmes = 1;
    ntf->setLogin(lg);	  
    ntf->setSenha(snh);
    ntf->tituloFilme = new string;
	existeUsuario = 1;
 }
 
void Netflix::AdicionarFilme(Netflix *ntf, string titulo)
{
  ntf->setTitulo(titulo)  ;	 
  this->quantidadeFilmes++;
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
  
  /*
 Você pode assistir online em qualquer nível de velocidade de banda larga, no entanto, a própria empresa recomenda uma velocidade mínima de 500 kbps (0,5 MB).

Veja abaixo as velocidades de download:

0,5 megabits por segundo – velocidade de conexão de banda larga mínima necessária
1,5 megabits por segundo –recomendada para apreciar melhor os filmes/séries;
3,0 megabits por segundo – recomendada para qualidade de DVD.
5,0 megabits por segundo – recomendada para qualidade de HD.
7,0 megabits por segundo – recomendada para qualidade Super HD
12 megabits por segundo – recomendada para qualidade 3D. 
  */
  return velDownload;
 }
 
float Netflix::CalculoGanhos(int nUsuarios, const float MENSALIDADE)
{
  if(nUsuarios > 0)
  {	 
   float ganhos = nUsuarios * MENSALIDADE;
   return ganhos;
  }else
  {
   cout << "Valor invalido. Usuarios tem de ser maior que zero." << endl;	  
   return 0;
  }
 }
  
ostream &operator<<(ostream &output, const Netflix& ntf)  
{
 int i;	
 output <<"Usuario: "<< ntf.getLogin()<< endl;
 output <<"Senha:  "<< ntf.getSenha()<< endl;
 for(i=0; i < ntf.quantidadeFilmes; i++)
 {
  output << "Filme numero " << i << ": "<< ntf.tituloFilme[i] << endl;
 }
 return output;
}
  
Netflix Netflix::operator=(const Netflix& ntf) const
{
 Netflix aux;	
 aux.usuarioLogin = ntf.usuarioLogin;
 aux.usuarioSenha = ntf.usuarioSenha;
 aux.tituloFilme = ntf.tituloFilme;
 return aux;
 
}
  
void Netflix::setCnpj(const string& cnpj) 
 {
  if((cnpj != "\0") && (this->cnpj.size() > 14)	 )
  {
   this->cnpj = cnpj;	 
  }
 }
 
void Netflix::setLogin(const string& login) 
{
 if(usuarioLogin != "\0")	
 {
  this->usuarioLogin = login;	 
 }
}
 
 void Netflix::setSenha(const string& senha) 
 {
  if(senha != "\0")	 
   this->usuarioSenha = senha;	  
 }

void Netflix::setTitulo(const string& titulo) 
{
if((this->getQuantidadeFilmes() < MAXFILMES)&& (titulo != "\0")) 	 
 {
  int i;	 
  string* auxTitulo = new string[getQuantidadeFilmes()];

  for( i = 0; i <this->getQuantidadeFilmes();i++)
  { 
   auxTitulo[i] = this->tituloFilme[i];  
  }
  delete this->tituloFilme;
  
  this->tituloFilme = new string[getQuantidadeFilmes()+1];
  
  for(i = 0; i <this->getQuantidadeFilmes(); i++)
  {
	this->tituloFilme[i] = auxTitulo[i];  
  }
  
  this->tituloFilme[getQuantidadeFilmes()] = titulo;
  delete [] auxTitulo;
  
  }else if (getQuantidadeFilmes() < MAXFILMES)
 {
  cout << "Titulo invalido" << endl;	 
 }else
 {
  cout << "Limite atingido" << endl;	 
 }
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

int Netflix::getExisteUsuario () const 
{
 return existeUsuario;	
}
