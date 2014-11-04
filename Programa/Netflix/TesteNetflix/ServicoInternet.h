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
		   Data dataCriacao;
           Usuario* listaUsuarios;
           int numeroUsuarios;
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
		   int      getNumeroUsuarios 			() const;
		   int      getQuantidadeFuncionarios   () const;
		   int      getNumeroAparelhos          () const;
		   Data     getData 					() const;

           inline void Welcome()
           {
            cout << "Bem vindo ao servico de internet" << this->getNome() << endl << endl;
           };

           virtual void VerificarDisponibilidadeAparelho () = 0;

           void CadastrarUsuario ();
		   Servico* operator=(const ServicoInternet&);
};
