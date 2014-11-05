#include "ServicoStreaming.h"

ServicoStreaming::ServicoStreaming()
:Servico("Desconhecido", "00.000.000/0000-00")
{
 this->velocidadeStreaming = 0.0;
 this->espacoOcupado = 0.0;
 this->numProtocolos = 0;
 this->protocolos = new string;
 this->numeroUsuarios = 0;
 this->listaUsuarios = new Usuario[this->numeroUsuarios];
}

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
 this->velocidadeStreaming= this->CalcularVelocidadeStreaming(velocidade);
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

ostream& operator<<(ostream& output, const ServicoStreaming& servicoStreaming)
{
 int cont;
 output << static_cast <const Servico&> (servicoStreaming) << ";\n";
 output << "Velocidade de streaming: " << servicoStreaming.getVelocidade() << endl;
 output << "Espaço consumido em disco: " << servicoStreaming.getEspaco() << endl;
 string* auxProtocolo = new string;
 auxProtocolo = servicoStreaming.getProtocolo();
 if(auxProtocolo == NULL)
 {
  output << endl;
 } else if(servicoStreaming.getNumProtocolos() == 0)
 {
  output << "Nenum protocolo listado"    << endl;
 }else
 {
  output << "Protocolos utilizados:" << endl ;
  for(cont = 0; cont <servicoStreaming.getNumeroAparelhos(); cont++)
  {
   output << "==========================="    << endl;
   output << "Dispositivo de numero "  << cont << ": " << endl;
   output << auxProtocolo[cont] << endl;
   output << "==========================="    << endl;
  }

 }
 if(servicoStreaming.getNumProtocolos() != 0)
 {
  delete []auxProtocolo;

 }
  return output;
}

ServicoStreaming* ServicoStreaming::operator=(const ServicoStreaming& streaming)
{
 int cont;
 //ServicoStreaming* auxStreaming = new ServicoStreaming;
 ServicoStreaming::operator=(streaming);
 this->velocidadeStreaming = streaming.velocidadeStreaming;
 this->espacoOcupado = streaming.espacoOcupado;
 this->numProtocolos = streaming.numProtocolos;
 this->numeroUsuarios = streaming.numeroUsuarios;

 for(cont = 0; cont < this->numProtocolos; cont++)
 {
  this->protocolos[cont] = streaming.protocolos[cont];
 }

 return this;
}
/*
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
*/

float ServicoStreaming::CalcularVelocidadeStreaming(const float& velocidadeConexao)
{
 float auxVelocidade = velocidadeConexao*0.55;
 return auxVelocidade;
}

float ServicoStreaming::CalcularEspacoOcupado(const int& encode, const int& duracao /* em minutos*/ , const int& numPessoas)
{
 float espaco = (encode * duracao * numPessoas)/(8*1024*1024);
 return espaco;
}

void ServicoStreaming::CalcularMediaAnual(const float* saldoAnual)
{
 float maiorLucro;
 int posicao, cont;	
 for(cont = 1; cont < 12; cont++)
 {
  if(saldoAnual[cont-1] > saldoAnual[cont])	 
  {
   maiorLucro = saldoAnual[cont-1];
   posicao = cont-1;	  
  }else
  {
   maiorLucro = saldoAnual[cont];
   posicao = cont;	  	  
  }
 }
  cout << "O Mes com o maior lucro foi o mes" << posicao << ", com " << maiorLucro << " unidades monetarias de lucro" << endl;

}
 

float ServicoStreaming::getVelocidade() const
{
 return this->velocidadeStreaming;
}

float ServicoStreaming::getEspaco() const
{
 return this->espacoOcupado;
}

string* ServicoStreaming::getProtocolo() const
{
 return this->protocolos;
}

int ServicoStreaming::getNumProtocolos() const
{
 return this->numProtocolos;
}
