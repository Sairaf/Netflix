#include "ServicoStreaming.h"

ServicoStreaming::ServicoStreaming(string nomeEmpresa, string cnpj)
:Servico(nomeEmpresa, cnpj)
{
 this->velocidadeStreaming = 0.0;
 this->espacoOcupado = 0.0;
 this->numProtocolos = 0;
 this->protocolos = new string;
 this->numeroUsuarios = 0;
 this->listaUsuarios = new Usuario[this->numeroUsuarios];
}

ServicoStreaming::ServicoStreaming(const string& nomeEmpresa,const string& cnpj,const int& numeroFuncionarios,const string& descricao,const string& endereco,const int& dia, const int& mes, const int& ano,const float& velocidade)
:Servico(nomeEmpresa, cnpj,numeroFuncionarios, descricao, endereco, dia,mes,ano)
{
 this->velocidadeStreaming= this->calcularVelocidadeStreaming(velocidade);
 this->espacoOcupado = 0.0;
 this->numProtocolos = 0;
 this->numeroUsuarios = 0;
 this->protocolos = new string[this->numProtocolos];
 this->listaUsuarios = new Usuario[this->numeroUsuarios];
}

ServicoStreaming::~ServicoStreaming()
{
 if(this->numProtocolos != 0)
    delete [] this->protocolos;
 if(this->numeroUsuarios != 0)
    delete [] this->listaUsuarios;
}

ServicoStreaming::ServicoStreaming(const ServicoStreaming& streamingCpy)
:Servico(streamingCpy)
{
 this->velocidadeStreaming = streamingCpy.velocidadeStreaming;
 this->espacoOcupado = streamingCpy.espacoOcupado;
 this->numeroAparelhos = streamingCpy.numeroAparelhos;
 this->numeroUsuarios = streamingCpy.numeroUsuarios;
 this->listaUsuarios = streamingCpy.listaUsuarios;
}

ostream& operator<<(ostream& output, const ServicoStreaming& ServicoStreaming)
{
 int cont;
 output << ServicoStreaming;
 output << "Velocidade de streaming: " << ServicoStreaming.velocidadeStreaming << endl;
 output << "Espa�o consumido em disco: " << ServicoStreaming.espacoOcupado << endl;
 if(ServicoStreaming.numProtocolos == NULL)
 {
  output << endl;
 } else if(ServicoStreaming.numProtocolos == 0)
 {
  output << "Nenum protocolo listado"    << endl;
 }else
 {
  output << "Protocolos utilizados:" << endl ;
  for(cont = 0; cont <ServicoStreaming.numeroAparelhos; cont++)
  {
   output << "==========================="    << endl;
   output << "Dispositivo de numero "  << cont << ": " << endl;
   output << ServicoStreaming.protocolos[cont] << endl;
   output << "==========================="    << endl;
  }
  return output;
 }

}

ServicoStreaming* ServicoStreaming::operator=(const ServicoStreaming& streaming)
{
 int cont;
 ServicoStreaming* auxStreaming;
 ServicoStreaming::operator=(streaming);
 auxStreaming->velocidadeStreaming = streaming.velocidadeStreaming;
 auxStreaming->espacoOcupado = streaming.espacoOcupado;
 auxStreaming->numProtocolos = streaming.numProtocolos;
 auxStreaming->numeroUsuarios = streaming.numeroUsuarios;

 for(cont = 0; cont < auxStreaming->numProtocolos; cont++)
 {
  auxStreaming->protocolos[cont] = streaming.protocolos[cont];
 }

 return this;
}

void ServicoStreaming::AdicionarProtocolo(ServicoStreaming* streaming, const string& protocolo)
{
 int cont;
 if(protocolo.empty() == false)
 {

  if(streaming->protocolos == 0)
  {
    cout << "Nao ha memoria suficiente para armazenadlo" << endl;
  }

  else
  {
   string* auxProtocolo = new string[streaming->numProtocolos]    ;

   for(cont = 0; cont < streaming->numProtocolos; cont ++)
   {
    auxProtocolo[cont] = streaming->protocolos[cont];
   }

    delete [] streaming->protocolos;
    streaming->protocolos = new string[++streaming->numProtocolos];

    for(cont = 0; cont< streaming->numProtocolos - 1; cont++)
    {
     streaming->protocolos[cont] = auxProtocolo[cont];
    }

     streaming->protocolos[streaming->numProtocolos] = protocolo;

     delete [] auxProtocolo;
  }

 }else
 {
  cout << "Strign invalida" << endl;
 }



}

float ServicoStreaming::calcularVelocidadeStreaming(const float& velocidadeConexao)
{
 float auxVelocidade = velocidadeConexao*0.55;
 return auxVelocidade;
}

float ServicoStreaming::calcularEspacoOcupado(const int& encode, const int& duracao /* em minutos*/ , const int& numPessoas)
{
 float espaco = (encode * duracao * numPessoas)/(8*1024*1024); return espaco;
}
