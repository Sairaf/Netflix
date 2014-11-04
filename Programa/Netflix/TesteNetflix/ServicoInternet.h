#include <iostream>
#include <cstdlib>
#include <vector>
#include "Data.h"
#include "Usuario.h"
using namespace std;

class ServicoInternet //ex: Amazon, Steam, Twitch,' Google Play
{
 friend ostream& operator<<(ostream&, const ServicoInternet&);
 
 protected:	
		   string nomeServico;
		   string cnpj;
		   int numeroFuncionarios;
		   string descricaoServico;
		   string enderecoSede;
		   Usuario* usuariosRegistrados;
		   int numeroUsuarios;
		   Data dataCriacao;
		 //string* linkSite;
 public:		   
		   ServicoInternet(string nomeServico = "Servico", string cnpj = "000-000-000/0000-00");
		   ServicoInternet(string, string, int, string, string, int, int, int, int);
		   ServicoInternet(const ServicoInternet&);
		   virtual ~ServicoInternet();
		   
		   void setNome(const string&);
		   void setCnpj(const string&);
		   void setEndereco(const string&);
		   void setDescricao(const string&);
		   void setUsuario(const Usuario&);
		   void setNumeroUsuarios(const int&);
		   void setQuantidadeFuncionarios(const int&);
		   void setData(const Data&);
		   
		   string   getNome 					() const;
		   string   getCnpj 				    () const;
		   string   getEndereco 			    () const;
		   string   getDescricao 				() const;
		   int      getNumeroUsuarios 			() const;
		   int      getQuantidadeFuncionarios   () const;
		   Usuario* getUsuario				    () const;
		   Data     getData 					() const;
		   
		   void Adicionar_Usuario_Ao_Servico(ServicoInternet *, Usuario*);
		   ServicoInternet operator=(const ServicoInternet&);
};