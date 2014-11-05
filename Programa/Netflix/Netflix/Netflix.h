#ifndef NETFLIX_H
#define NETFLIX_H
#include <iostream>
#include <cstdlib>
#include <string>
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
             int         getQtRecomendacoes   () const;

             void  AdicionarRecomendacao(Netflix*, Filme&);
             void  CadastrarUsuario(Servico*, const Usuario&);
			 int   DuracaoSaldoConta(const float&);
			 void MesMaisLucrativo(const float&);

			 Netflix* operator=(const Netflix&);
};

#endif
