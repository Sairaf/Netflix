#ifndef SERVICO_H
#define SERVICO_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string.h>
#include "Data.h"
#include "Usuario.h"

using namespace std;

class Servico //ex: Amazon, Steam, Twitch,' Google Play
{
 friend ostream& operator<<(ostream&, const Servico&);
 protected:
           string nomeServico;
		   string cnpj;
		   int numeroFuncionarios;
		   string descricaoServico;
		   string enderecoSede;
		   string* aparelhos;// mudar este atributo para serviços podendo verificar mais tarde
           int numeroAparelhos;
		   Data* dataCriacao;


           //realizar um operator== para o USuario
		 //string* linkSite;
 public:
		   Servico(string nomeServico = "Servico", string cnpj = "000-000-000/0000-00");
		   Servico(string, string, int, string, string, int/*dia*/, int/*mês*/, int/*anno*/);
		   Servico(const Servico&);
		   virtual ~Servico();

		   void setNome(const string&);
		   void setCnpj(const string&);
		   void setEndereco(const string&);
		   void setDescricao(const string&);
		   void setaparelhos (const string&);
		   void setQuantidadeFuncionarios(const int&);
		   void setData(const Data&);

		   string   getNome 					() const;
		   string   getCnpj 				    () const;
		   string   getEndereco 			    () const;
		   string   getDescricao 				() const;
		   int      getQuantidadeFuncionarios   () const;
		   int      getNumeroAparelhos          () const;
		   int     getData 					() const;

           virtual inline const void Welcome()
           {
            cout << "Bem vindo ao servico: " /*<< this->getNome()*/ << endl << endl;
           };
           void teste() {cout<<"teste" <<endl;};
           void CadastrarAparelho (Servico*, const string&);
		   virtual Servico* operator=(const Servico&);
};
#endif
