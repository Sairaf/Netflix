#ifndef NETFLIX_H
#define NETFLIX_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include "ServicoStreaming.h"

class Netflix: public ServicoStreaming
{
 friend ostream& operator<<(ostream& output, const Netflix&);
 protected:
			 const static float MENSALIDADE;
			 float saldo;
			 Filme* recomendacoes;
			 int qtdRecomendacoes;

 public:
			 Netflix(const string& cnpj = "00.000.000/0000-00",const float& Saldo = 0.0);
			 Netflix(const float&,const string&,const int&,const string&,const string&,const int&,const int&,const int&, const float&);
			 Netflix(const Netflix&);
			 ~Netflix();

             void setSaldo(const float&);
             void setRecomendacoes(const Filme&);

             float       getSaldo             () const;
			 const float getMensalidade       () const;
             Filme*      getRecomendacoes     () const;
             int         getQtdRecomendacoes   () const;


             void  CadastrarAparelho(const string&) ;/**/
             void  AdicionarRecomendacao(const Filme&); /**/
             void  CadastrarUsuario(const Usuario&);/**/
			 int   DuracaoSaldoConta(const float&);/**/
		     const void AdicionarProtocolo(const string&);/**/
			 Netflix* operator=(const Netflix&);/**/
};

#endif
