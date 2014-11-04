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
// friend ostream& operator<<(ostream&, Servico);
 
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
           Servico(string nomeServico = "Servico", string cnpj = "000-000-000/0000-00");
		   Servico(string, string, int, string, string, int/*dia*/, int/*mÃªs*/, int/*anno*/);
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
		   Data*    getData 					() const;

		   virtual void CadastrarAparelho() = 0;
		   virtual void CadastrarUsuario() = 0;
		   virtual Servico* operator=(const Servico&);
		   void MostrarAparelhos(const Servico&);
};

#endif