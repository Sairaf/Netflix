#include <iostream>
#include <cstdlib>
#include <vector>
#include "Filme.h"
#include "Servico.h"

class ServicoStreaming: public Servico// ex: Twitch, Netflix, WebCast
{
 friend ostream& operator<<(ostream&, const ServicoStreaming&);
 protected:
		   float velocidadeStreaming;   //55% da velocidade da conexão
		   float espacoOcupado;	       //Espaço que o video ocupará na memória secundária, dada pela fórmula- tamanho =   encoder speed (in bit/s) × number of seconds × number of viewers / (8*1024*1024) -dado em MB o resultado
		   string* protocolos;        //html, tcp/ip, mp3, video, etc.
		   int numProtocolos;
		   Usuario* listaUsuarios;
		   int numeroUsuarios;
 public:
		  ServicoStreaming(string nomeServico = "Servico de Streaming", string cnpj = "000-000-000/0000-00");
		  ServicoStreaming(const string&,const string&,const int&,const string&,const string&,const int &,const int&, const int&,const float&);
		  ServicoStreaming(const ServicoStreaming&);
		  virtual ~ServicoStreaming();

	      void setProtocolo(const string&);

		  string* getProtocolo	() const;
          float   getVelocidade () const;
		  float   getEspaco		() const;

          virtual void AdicionarUsuarios (ServicoStreaming*, const Usuario& ) = 0;
          void AdicionarProtocolo(ServicoStreaming*, const string&);
		  float calcularEspacoOcupado(const int&,const int&, const int&); // velocidade do encode, duracao do filme em segundos e numero de pessoas assistindo
		  float calcularVelocidadeStreaming(const float&);

		  ServicoStreaming* operator=(const ServicoStreaming &);
};
