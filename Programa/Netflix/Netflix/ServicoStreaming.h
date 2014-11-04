#include <iostream>
#include <cstdlib>
#include <vector>
#include "Servico.h"

using namespace std;

class ServicoStreaming: public Servico// ex: Twitch, Netflix, WebCast
{
 protected:
		   float velocidadeStreaming;   //55% da velocidade da conexÃ£o
		   float espacoOcupado;	       //EspaÃ§o que o video ocuparÃ¡ na memÃ³ria secundÃ¡ria, dada pela fÃ³rmula- tamanho =   encoder speed (in bit/s) Ã— number of seconds Ã— number of viewers / (8*1024*1024) -dado em MB o resultado
		   string* protocolos;        //html, tcp/ip, mp3, video, etc.   
           int numProtocolos ;
public:
		  ServicoStreaming(string nomeServico = "Servico de Streaming", string cnpj = "000-000-000/0000-00");
		  ServicoStreaming(string, string, int, string, string, float, float, string);
		  ServicoStreaming(const ServicoStreaming&);
		  ~ServicoStreaming();
 
 
	      void setProtocolo(const string&);
		  
		  string* getProtocolo	() const;
          float   getVelocidade () const;		   
		  float   getEspaco		() const;
		  
		  float calcularEspacoOcupado(const int,const int, const int); // velocidade do encode, duracao do filme em segundos e numero de pessoas assistindo
		  float calcularVelocidadeStreaming(const float&);
};