#ifndef NETFLIX_H
#define NETFLIX_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "ServicoStreaming.h"

class Netflix: public ServicoStreaming
{
 protected:
			 const static float MENSALIDADE;
			 float saldo;
 public:
			 Netflix(string nomeEmpresa = "Default" , string cnpj = "00.000.000/0000-00");
			 Netflix(const string&,const string&,const int&,const string&,const string&,const int&,const int&,const int&,const float&);
			 Netflix(const Netflix&);
			 ~Netflix();
			 
			 float getMensalidade() const;
			 
			 int SaldoMeses(const float&);
}

#endif