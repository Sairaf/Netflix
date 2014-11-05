#ifndef SERVICOSTREAMING_H
#define SERVICOSTREAMING_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string.h>
#include "Servico.h"

using namespace std;

class ServicoStreaming: public Servico// ex: Twitch, Netflix, WebCast
{
friend ostream& operator<<(ostream& output, const ServicoStreaming&)	;
protected:
	float velocidadeStreaming;   //55% da velocidade da conexÃ£o
	float espacoOcupado;	       //Espaco que o video ocuparÃ¡ na memÃ³ria secundÃ¡ria, dada pela fÃ³rmula- tamanho =   encoder speed (in bit/s) Ã— number of seconds Ã— number of viewers / (8*1024*1024) -dado em MB o resultado
	string* protocolos;        //html, tcp/ip, mp3, video, etc.
	int numProtocolos ;
	int numeroUsuarios;
	Usuario* listaUsuarios;
    vector <float> SaldoAnualServico;
    const MAXSALDO = 11;
public:
    ServicoStreaming();
	ServicoStreaming(string nomeServico = "Servico de Streaming", string cnpj = "000-000-000/0000-00");
	ServicoStreaming(const string&,const string&,const int&,const string&,const string&,const int&,const int&,const int&,const float&);
	ServicoStreaming(const ServicoStreaming&);
	virtual void CadastrarUsuario(Servico*, const Usuario&) = 0;
	virtual ~ServicoStreaming();


	void setProtocolo(const string&);
	void setSaldoMes(const float&); /* Falta realizar sto*/

	string* getProtocolo	 () const;
	float   getVelocidade   () const;
	float   getEspaco		 () const;
	int     getNumProtocolos() const;
    float   getSaldo         () const;

	virtual const void AdicionarProtocolo(const string&)= 0 ; /**/
	virtual void CadastrarUsuario(const Usuario&) = 0;/**/
	float CalcularEspacoOcupado(const int&,const int&, const int&);/**/ // velocidade do encode, duracao do filme em segundos e numero de pessoas assistindo
	float CalcularVelocidadeStreaming(const float&);/**/
    void CalcularMediaAnual(const float[]);/**/

	ServicoStreaming* operator=(const ServicoStreaming&);/**/
};
#endif // SERVICOSTREAMING_H
