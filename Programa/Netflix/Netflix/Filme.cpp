#include "Filme.h"

Filme::Filme(string nomeFilme, string sinopse)
:nomeFilme("Default"), sinopse("======")
{
 
}

Filme::~Filme()
{
 delete [] this->atores;	
}

Filme::Filme(string nomeFilme, string sinopse, string diretor, string* atores, float bilheteria, float nota )
{
 this->setNomeFilme(nomeFilme);
 this->setSinopse(sinopse);
 this->setDiretorFilme(diretor);
 this->setBilheteria(bilheteria);
 this->setAvaliacaoCritica(nota);
}

Filme::Filme(const Filme& filmeCpy)
{
 this->nomeFilme = filmeCpy.nomeFilme;
 this->sinopse 	= filmeCpy.sinopse;
 this->bilheteria = filmeCpy.bilheteria;
 this->diretorFilme = filmeCpy.diretorFilme;
 this->atores = filmeCpy.atores;
 this->avaliacaoCritica = filmeCpy.avaliacaoCritica;
}

ostream& operator<<(ostream& output, const Filme& filme)
{
 int i;	
 output << "Nome do filme: " << filme.getNomeFilme() << endl;
 output << "Sinopse: " << filme.getSinopse() << endl;
 output << "Diretor: " << filme.getDiretorFilme() << endl;
 output << "Atores principais: ";	 
 if(filme.atores->size() == 0)
 {
  output << endl;
 }else if (filme.atores->size() > 0)
 {
  for(i = 0; i < (int)filme.atores->size(); i++)	 
  {
   output << "| "<<filme.atores[i] << " |" << endl;
  }
 }
 output << "Nota da critica especializada: " << filme.getAvaliacaoCritica() << endl;
 output << "Bilheteria: " <<filme.getBilheteria() << endl;
 return output;
}


Filme Filme::operator=(const Filme& filme) const
{
 Filme auxFilme;
 auxFilme.setNomeFilme(filme.getNomeFilme())	;
 auxFilme.setAtores(filme.getAtores());
 auxFilme.setAvaliacaoCritica(filme.getAvaliacaoCritica());
 auxFilme.setBilheteria(filme.getBilheteria());
 auxFilme.setDiretorFilme(filme.getDiretorFilme());
 auxFilme.setSinopse(filme.getSinopse());
 return auxFilme;
}

void Filme::setNomeFilme(const string& nomeFilme)
{
 if((nomeFilme.empty() == false && nomeFilme.size() < 200 ))
 {
  this->nomeFilme = nomeFilme;	 
 }else
 {
  cout << "O nome do filme e invalido ou muito grande. O nome recebera ""Nome indefinido"" " << endl; 	 
  this->nomeFilme =  "Nome indefinido";	 
 }
}

void Filme::setAvaliacaoCritica(const float& nota)
{
 if((nota > 0 && nota <= 10))	
 {
  this->avaliacaoCritica = nota;	 
 }else
 {
  cout << "Nota da avaliacao critica e invalida. este atributo recebera valor 0" << endl;	 
  this->avaliacaoCritica = 0;	 
 }
}

void Filme::setBilheteria(const float &bilheteria)
{
 if(bilheteria > 0)	
 {
  this->bilheteria = bilheteria;	 
 }else
 {
  cout << "Bilheteria invalida. Recebendo o valor 0" << endl;
  this->bilheteria = 0;	 
 }
}

void Filme::setDiretorFilme(const string& nomeDiretor) 
{
 if((nomeDiretor.empty() == false && nomeDiretor.size() < 100 ))
 {
  this->diretorFilme = nomeDiretor;	 
 }else
 {
  cout << "Nome do diretor invalido ou muito grande. Configurado como ""Diretor desconhecido"" " << endl;	 
  this->diretorFilme = "Diretor desconhecido";	 
 }
}

void Filme::setSinopse(const string& sinopse)
{
 if(sinopse.empty() == false)
 {
  this->sinopse = sinopse;	
 }else
 {
  cout << "Sinopse invalida. Outro valor sera colocado no atributo" << endl	 ;
  this->sinopse = "E um filme legal...Eu acho";
 }
}

void Filme::setAtores(const string* atores)
{
 int i;
 this->atores = new string[atores->size()];
 for(i = 0; i < (int)atores->size(); i++)	
 {
  if(atores[i].empty() == true)	 
  {
   cout << "Nome invalidos para ator " << i+1 <<". Colocando como nome de ""Indefinido""" << endl;
   this->atores[i] = "Indefinido" ;  
  }else
  {
   this->atores[i] = atores[i];	  
  }
 } 
}

string Filme::getNomeFilme() const
{
 return this->nomeFilme;	
}

string Filme::getDiretorFilme () const
{
 return this->diretorFilme;	
}

string Filme::getSinopse() const
{
 return this->sinopse;	
}

string * Filme::getAtores() const
{
 return this->atores;	
}

float Filme::getAvaliacaoCritica() const
{
 return this->avaliacaoCritica;	
}

float Filme::getBilheteria() const
{
 return this->bilheteria;	
}
