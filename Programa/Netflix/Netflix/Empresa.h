#ifndef EMPRESA_H
#define EMPRESA_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Empresa
{
 friend ostream& operator<<(ostream& output, const Empresa&);      
 protected:
           string  nomeEmpresa;
           string  cnpj;
           int     qtdEnderecos;
           string* enderecos;
           int     numFuncionarios;
           
 public:                      
           Empresa(string nome = "Default", string cnpj = "000.000.000/0000-00");
           Empresa(const string& ,const string&,const int&,const string&);
           virtual ~Empresa();
           Empresa(const Empresa&);
           virtual const inline void Welcome(){cout<< "Bem vindo ao sistema Netflix. "<<endl;}; 
           void setNome(const string&);
           void setCnpj(const string&);
           void setEndereco(const string&);
           void setFuncionarios(const int&); 
           
           string  getNome() const;
           string  getCnpj() const;
           int     getNumFuncionarios() const;
           int     getQtdEnderecos() const;
           string* getEnderecos() const;
           
           Empresa operator=(const Empresa&);
           virtual float CalculoGanhos(float, float);
           void AdicionarEndereco(Empresa*, const string&);                   
};      


#endif// EMPRESA_H
