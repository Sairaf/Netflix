#include <iostream>
#include <cstdlib>
#include <vector>
#include "ServicoInternet.h"

class ServicoStreaming: public ServicoInternet// ex: Twitch, Netflix, WebCast
{
 protected:
		   float velocidadeStreaming;   //55% da velocidade da conexão
		   float espacoOcupado;	       //Espaço que o video ocupará na memória secundária, dada pela fórmula- tamanho =   encoder speed (in bit/s) × number of seconds × number of viewers / (8*1024*1024) -dado em MB o resultado
		   string* protocolos;        //html, tcp/ip, mp3, video, etc.    
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
}