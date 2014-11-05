#include "Netflix.h"

const float Netflix::MENSALIDADE =17.90;

Netflix::Netflix(const string& cnpj,const float& saldo)
:ServicoStreaming(cnpj, cnpj,0,"Um servico de streaming na internet", "Desconhecido", 5,10,2010, 0), saldo(saldo)
{
 this->setSaldo(0.0);
 this->qtdRecomendacoes = 0;
 this->recomendacoes = new Filme;
}

Netflix::Netflix(const float& saldo, const string& cnpj,const int& numeroFuncionarios,const string& descricao,const string& endereco,const int& dia, const int& mes, const int& ano,const float& velocidade)
:ServicoStreaming("Netflix", cnpj,numeroFuncionarios,descricao,endereco, dia, mes, ano,0), saldo(saldo)
{
 //this->setSaldo(0.0);
 this->qtdRecomendacoes = 0;
 this->recomendacoes = new Filme;
}

Netflix::~Netflix()
{
 delete [] this->recomendacoes;
}

Netflix::Netflix(const Netflix& netflixCpy)
:ServicoStreaming(netflixCpy)
{
 int cont;
 this->saldo = netflixCpy.saldo;
 this->qtdRecomendacoes = netflixCpy.qtdRecomendacoes;
 delete [] this->recomendacoes;
 this->recomendacoes = new Filme[netflixCpy.qtdRecomendacoes];
 for(cont = 0; cont < netflixCpy.qtdRecomendacoes; cont++)
 {
  this->recomendacoes[cont] = netflixCpy.recomendacoes[cont];
 }

}


Netflix* Netflix::operator=(const Netflix& netflix)
{
int cont;
 Netflix* auxNetflix;
 Netflix::operator=(netflix);
 Netflix::operator=(netflix);
 return auxNetflix;

 auxNetflix->saldo = netflix.getSaldo();
 auxNetflix->qtdRecomendacoes = netflix.getQtdRecomendacoes();
 delete auxNetflix->recomendacoes;
 auxNetflix->recomendacoes = new Filme[netflix.getQtdRecomendacoes()];

 for(cont = 0; cont < netflix.getQtdRecomendacoes(); cont++)
 {
  auxNetflix->recomendacoes[cont] = netflix.recomendacoes[cont];
 }
 return auxNetflix;
}

ostream& operator<<(ostream& output, const Netflix& netflix)
{
 output << static_cast<const Servico&> (netflix) <<";\n";
}


void Netflix::CadastrarAparelho(const string& aparelho)
{
int cont;
if(aparelho.empty() )
 {

 string* auxAparelhos = new string[this->getNumeroAparelhos()];
 for(cont = 0; cont < this->getNumeroAparelhos(); cont++)
 {
  auxAparelhos[cont] = this->aparelhos[cont];
 }
 delete [] this->aparelhos;
 this->aparelhos = new string[this->getNumeroAparelhos()];
 for(cont = 0; cont < this->getNumeroAparelhos()-1;cont++)
 {
  this->aparelhos[cont] = auxAparelhos[cont];
 }
  this->aparelhos[this->getNumeroAparelhos()-1] = aparelho;

 delete [] auxAparelhos;
 }
}

void Netflix::setSaldo(const float& saldo)
{
 if(saldo >= 0)
 {
  this->saldo = saldo;
 }else
 {
  this->saldo = 0.0;
 }
}

void Netflix::CadastrarUsuario(const Usuario& usuario)
{
 int cont;
 Usuario * auxUsuario = new Usuario[this->numeroUsuarios];
 for(cont = 0; cont < this->numeroUsuarios; cont++)
 {
  auxUsuario[cont] = this->listaUsuarios[cont]
 }

 delete [] this->listaUsuarios;
 this->listaUsuarios = new Usuario[++this->numeroUsuarios];
 //Falta acabar aqui
}

int Netflix::getQtdRecomendacoes() const
{
 return this->qtdRecomendacoes;
}
