#include "Filme.h"

const int Filme::MAXATORES = 10;

Filme::Filme(string nomeFilme, string sinopse)
:nomeFilme(nomeFilme), sinopse(sinopse)
{
 this->numAtores = 0;
 this->setDiretorFilme("Desconhecido");
 this->atores = new string[numAtores];
 this->setAtores("Desconhecido");
 this->setBilheteria(0);
 this->setAvaliacaoCritica(0);
}

Filme::~Filme()
{
 if(this->numAtores != 0)
 delete [] this->atores;
}

Filme::Filme(string nomeFilme, string sinopse, string diretor, string atores, float bilheteria, float nota )
{
 this->numAtores = 0;
 this->setNomeFilme(nomeFilme);
 this->setSinopse(sinopse);
 this->setDiretorFilme(diretor);
 this->setBilheteria(bilheteria);
 this->setAvaliacaoCritica(nota);
}

Filme::Filme(const Filme& filmeCpy)
{
 int cont;
 this->numAtores =filmeCpy.numAtores;
 this->nomeFilme = filmeCpy.nomeFilme;
 this->sinopse 	= filmeCpy.sinopse;
 this->bilheteria = filmeCpy.bilheteria;
 this->diretorFilme = filmeCpy.diretorFilme;
 this->avaliacaoCritica = filmeCpy.avaliacaoCritica;
 for(cont = 0 ; cont < this->numAtores;cont++)
  this->setAtores(filmeCpy.atores[cont]);

}

ostream& operator<<(ostream& output, const Filme& filme)
{
 int i;
 output << "Nome do filme: " << filme.nomeFilme << endl;
 output << "Sinopse: " << filme.getSinopse() << endl;
 output << "Diretor do filme: " << filme.getDiretorFilme() << endl;//filme.getDiretorFilme() << endl;
 output << "Atores principais: " << endl;
 if(filme.atores == NULL)
 {
  output << endl;
 }else
 {
  for(i = 0; i < filme.numAtores; i++)
  {
   output << "| "<<filme.atores[i] << " |" << endl;
  }
 }
 output << "Nota da critica especializada: " << filme.getAvaliacaoCritica() << endl;
 output << "Bilheteria: " <<filme.getBilheteria() << endl;
 return output;
}


Filme* Filme::operator=(const Filme& filme)
{
 int cont;
 this->nomeFilme = filme.nomeFilme;
 this->avaliacaoCritica = filme.avaliacaoCritica;
 this->bilheteria = filme.bilheteria;
 this->diretorFilme = filme.diretorFilme;
 this->sinopse = filme.sinopse;
 for(cont = 0; cont < this->numAtores; cont++)
 {
  this->atores[cont] = filme.atores[cont];
 }
return this;
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
 if(nota >= 0 && nota <= 10)
 {
  this->avaliacaoCritica = nota;
 }else
 {
  cout << "Nota da avaliacao critica e invalida. este atributo recebera valor 0" << endl;
  this->avaliacaoCritica = 0;
 }
}
void Filme::setBilheteria(const float &saldo)
{
 if(saldo >= 0)
 {
  this->bilheteria = saldo;
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

void Filme::setAtores(const string& ator)
{
 int cont;
 if(this->numAtores < MAXATORES)
 {

 string* auxAtores = new string[numAtores];
 for(cont = 0; cont < numAtores; cont++)
 {
  auxAtores[cont] = this->atores[cont];
 }

 delete [] this->atores;
 this->atores = new string[++numAtores];

 for(cont = 0; cont < numAtores-1;cont++)
 {
  this->atores[cont] = auxAtores[cont];
 }
 this->atores[numAtores-1] = ator;
 delete [] auxAtores;
 }
}

string Filme::getNomeFilme() const
{
 return this->nomeFilme;
}

string Filme::getDiretorFilme() const
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
