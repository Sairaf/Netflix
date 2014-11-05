#ifndef YOUTUBE_H
#define YOUTUBE_H
#include "ServicoInternet.h"


class Youtube: public ServicoStreaming
{
 protected:
		  Filme* listaReproducao;
		  
public:
         Youtube(const string cnpj = "00.000.000/0000-00")
		 Youtube(const string&,const int&,const string&,const string&,const int&,const int&,const int&,const float&);
		 Youtube(const Youtube&);
		~Youtube();
		
		Filme* getListaReproducao() const;
		
		void CadastrarAparelho(const string&)
		const void AdicionarProtocolo(const string&)= 0 ; /**/
	    void CadastrarUsuario(const Usuario&) = 0;/**/
		void AdicionarFIlmeLista(const Filme&);
}
#ifdef;