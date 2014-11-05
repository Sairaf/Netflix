#ifndef YOUTUBE_H
#define YOUTUBE_H
#include "ServicoStreaming.h"


class Youtube: public ServicoStreaming
{
 friend ostream& operator<<(ostream& output, const Youtube&);
 protected:
          int qtdListaReproducao;
		  Filme* listaReproducao;

public:
         Youtube(const string cnpj = "00.000.000/0000-00");
		 Youtube(const string&,const int&,const string&,const string&,const int&,const int&,const int&,const float&);
		 Youtube(const Youtube&);
		~Youtube();

		Filme* getListaReproducao() const;
		int    getQtdReproducao() const;

		void CadastrarAparelho(const string&);
		const void AdicionarProtocolo(const string&); /**/
	    void CadastrarUsuario(const Usuario&);/**/
		void AdicionarFIlmeLista(const Filme&);

		Youtube* operator=(const Youtube&);
};
#endif
