#include <iostream>
#include "Filme.h"

int Filme::quantidadeAtores = 0;

Filme::Filme(string titulo,string gen, string* atoress)
{
  int i;	
  this->setTitulo(titulo);
  this->setGenero(gen);
  
  this->atores = new string[MAXATORES]; // Maximo 3 atores princiapis por filme
  
  for(i = 0; i< MAXATORES; i++)
  {
   this->atores[i] = atoress[i];
  }
  delete [] atoress;
  if(MAXATORES > 0)
  {
   this->quantidadeAtores = MAXATORES;	   
  }
}

Filme::~Filme()
{
	delete [] Filme::atores;
}

Filme::Filme()
:titulo(" "), genero(" "), atores(NULL), quantidadeAtores(0)
{
 cout << "Filme iniciado com valores default" << endl; 	
}

Filme::Filme(const Filme& fm)
{
 int i;	
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

ostream &operator<<(ostream &output, const Filme& fm)
{
 output << "Titulo do Filme: " << fm.getTitulo() << endl;
 output << "Data de Lancamento: " << fm.getDataDeLancamento();	
 output << "Genero : " << fm.getGenero( )<< endl;
 return output;
}

Filme Filme::operator=(const Filme& fm) const
{
 //int i;	
 Filme aux;
 aux.setTitulo(fm.getTitulo());	
 aux.setDataDeLancamento(fm.getDataDeLancamento());
 aux.setGenero(fm.getGenero());
// aux.numeroFilmes++;
 return aux;
 }

