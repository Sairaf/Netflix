#include "Netflix.h"

//Netflix::MENSALIDADE = 17.90;
Netflix::Netflix(string nome, string cnpj)
:ServicoStreaming(nome, cnpj)
{
 int cont;
 this->saldoEmpresaAno.reserve(11);
 this->numRecomendacoes = 0;
 for(cont = 0; cont < this->saldoEmpresaAno.size(); cont++)
 {
  this->saldoEmpresaAno[cont] = 0.0;
 }

 this->Recomendacoes = new Filme[this->numRecomendacoes];
}

Netflix::Netflix(const string& nomeEmpresa,const string& cnpj,const int& numeroFuncionarios,const string& descricao,const string& endereco,const int& dia, const int& mes, const int& ano,const float& velocidade, const string& recomendacao)
:ServicoStreaming(nomeEmpresa, cnpj, numeroFuncionarios, descricao, endereco, dia, mes, ano,velocidade )
{
 int cont;
 this->saldoEmpresaAno.reserve(11);
 this->numRecomendacoes = 0;
 for(cont = 0; cont < this->saldoEmpresaAno.size(); cont++)
 {
  this->saldoEmpresaAno[cont] = 0.0;
 }
 this->Recomendacoes = new Filme[this->numRecomendacoes];
}

Netflix::Netflix(const Netflix& netflixCpy)
:ServicoStreaming(netflixCpy)
{
 int cont;
 this->numRecomendacoes = netflixCpy.numRecomendacoes;
 for(cont = 0 ; cont <this->numRecomendacoes; cont++)
 {
  this->Recomendacoes[cont] = netflixCpy.Recomendacoes[cont];
 }
}

Netflix::~Netflix()
{
 delete [] this->Recomendacoes;
}

