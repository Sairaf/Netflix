#include <iostream>
#include "Filme.h"

int Filme::quantidadeAtores = 0;
const float Filme::preco = 3.0;
Filme::Filme(string titulo,string gen, string* ator)
{
  int i;	
  this->setTitulo(titulo);
  this->setGenero(gen);
  
  this->atores = new string[MAXATORES];
  for(i = 0; i < MAXATORES; i++)
  {
   if(ator[i] != "\0")	  
   this->atores[i] = ator[i]	  ;
  }
  delete [] ator;
}

Filme::~Filme()
{
	delete [] Filme::atores;
}

Filme::Filme()
:titulo(" "), genero(" "), atores(NULL)
{
 cout << "Filme iniciado com valores default" << endl; 	
}

Filme::Filme(const Filme& fm)
{
 this->titulo = fm.titulo;
 this->genero = fm.genero;
 this->atores = fm.atores;
}


void Filme::setTitulo(const string& tit)
{ 
 string auxTitulo;	
 auxTitulo = tit;
 while((auxTitulo == "") || (auxTitulo == " ")|| (auxTitulo == "\0"))
 {
  cout << "Titulo invalido. Por favor, digite novamente este." << endl;
  cin >> auxTitulo;   	 
 }
	
 this->titulo = titulo;	
}

void Filme::setGenero(const string& gen)
{
 string aux = gen;
  while((aux == "") || (aux == " ")|| (aux == "\0"))
  {
   cout << "Genero de invalido. Por favor, digite novamente este quesito. " << endl;
   cin >> aux;   
  }
  this->genero = aux;
 }

string Filme::getTitulo() const
{
 return this->titulo;	
}

string Filme::getGenero() const
{
 return this->genero;	
}

float Filme::getPreco() const
{
 return this->preco;	
}

ostream &operator<<(ostream &output, const Filme& fm)
{
 int i;	
 output << "Titulo do Filme: " << fm.getTitulo() << endl;
 output << "Genero : " << fm.getGenero( )<< endl;
 //fm.atores = new string[3];
 for(i = 0; i < fm.quantidadeAtores; i++)
 {
  output <<"Ator principal de numero" << i << fm.atores[i]	;
	 
 }
 
 return output;
}

Filme Filme::operator=(const Filme& fm) const
{
 int i;	
 Filme aux;
 aux.setTitulo(fm.getTitulo());	
 aux.setGenero(fm.getGenero());
 for(int i = 0; i< fm.quantidadeAtores;i++)
 {
  if(fm.atores[i] != "\0")	 
  aux.atores[i] = fm.atores[i];
 }
 return aux;
 }

