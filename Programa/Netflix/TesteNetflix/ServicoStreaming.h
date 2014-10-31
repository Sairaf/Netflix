#include <iostream>
#include <cstdlib>
#include <vector>
#include "ServicoInternet.h"

class ServicoStreaming: public ServicoInternet// ex: Twitch, Netflix, WebCast
{
 protected:
		   float velocidadeStreaming;   //
		   float espacoOcupado;	       //Espaço que o video ocupará na memória secundária, dada pela fórmula- tamanho =   encoder speed (in bit/s) × number of seconds × number of viewers / (8*1024*1024) -dado em MB o resultado
		   string* protocolos;        //html, tcp/ip, mp3, video, etc.   
}