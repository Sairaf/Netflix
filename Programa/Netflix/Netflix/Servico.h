#ifndef SERVICO_H
#define SERVICO_H

#include <iostream>
#include <cstdlib>
#include <string>

#include "Usuario.h"
#include "Data.h"

using namespace std;

class Servico
{
  friend ostream& operator<<(ostream&,const Servico&);

 protected:
           string nomeServico;
		   string cnpj;
		   int numeroFuncionarios;
		   string descricaoServico;
		   string enderecoSede;
		   string* aparelhos;// mudar este atributo para serviÃ§os podendo verificar mais tarde
           int numeroAparelhos;
		   Data* dataCriacao;
public:
           Servico();
           Servico(string nomeServico = "Servico", string cnpj = "000-000-000/0000-00");
		   Servico(string, string, int, string, string, int/*dia*/, int/*mÃªs*/, int/*anno*/);
		   Servico(const Servico&);
		   virtual ~Servico();


		   void setNome(const string&);
		   void setCnpj(const string&);
		   void setEndereco(const string&);
		   void setDescricao(const string&);
		   void setAparelhos (const string&);
		   void setQuantidadeFuncionarios(const int&);
		   void setData(const Data&);

		   string   getNome 					() const;
		   string   getCnpj 				    () const;
		   string   getEndereco 			    () const;
		   string   getDescricao 				() const;
		   int      getQuantidadeFuncionarios   () const;
		   int      getNumeroAparelhos          () const;
		   Data*    getData 					() const;
		   string*  getAparelhos           () const;

           const inline void Welcome(){cout << "BEM VINDO!" << endl;};

		   virtual void CadastrarAparelho(const string&) = 0;
		   void MostrarAparelhos(const Servico&);

		   virtual Servico* operator=(const Servico&);
};

#endif
