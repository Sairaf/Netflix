#include <iostream>
#include "Filme.h"

int Filme::numeroFilmes;

Filme::Filme(string titulo,string gen, const Data& dt)
:dataDeLancamento(dt)
{
  Filme aux;		
  this->setTitulo(titulo);
  this->setGenero(gen);
  this->setNumeroFilmes(0);
}

Filme::~Filme()
{
}

Filme::Filme()
:dataDeLancamento()
{
 this->titulo = " ";
 this->genero = " "; 
 this->setNumeroFilmes(0);
}
Filme::Filme(const Filme& fm)
{
 this->titulo = fm.titulo;
 this->genero = fm.genero;
 this->dataDeLancamento = fm.dataDeLancamento;	
 this->numeroFilmes = fm.numeroFilmes;
}

void AdicionarFilme(Filme* fm, const string& titulo,const string& genero, const Data& data)
{
  fm->setTitulo(titulo);
  fm->setGenero(genero);
  fm->setDataDeLancamento(data);
  fm->setNumeroFilmes(0);
  cout << "Numero de filmes: " << fm->getNumeroFilmes() << endl;
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


void Filme::setDataDeLancamento(const Data& data)
{
 int auxData;	
 auxData = data.VerificaDia(data.getDia());
 if(auxData == 1)
 {
  cout << "Data invalida" << endl;
 }else
 {
  this->dataDeLancamento = data;
 }
}

void Filme::setNumeroFilmes(const int& i )
{
 this->numeroFilmes+= i;  	
}

string Filme::getTitulo() const
{
 return this->titulo;	
}

string Filme::getGenero() const
{
 return this->genero;	
}

Data Filme::getDataDeLancamento() const
{
 return this->dataDeLancamento;	
}

int Filme::getNumeroFilmes() const
{
 return this->numeroFilmes;	
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

