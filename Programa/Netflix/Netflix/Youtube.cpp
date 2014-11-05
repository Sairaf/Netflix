#include "Youtube.h"

Youtube::Youtube(const string cnpj)
:ServicoStreaming("Youtube", cnpj)
{
 this->qtdListaReproducao = 0;
 this->listaReproducao = new Filme;

}

Youtube::Youtube(const string& cnpj,const int& numeroFuncionarios,const string& descricao,const string& endereco,const int& dia, const int& mes, const int& ano,const float& velocidade)
:ServicoStreaming("Youtube", cnpj,numeroFuncionarios, descricao, endereco, dia,mes,ano,velocidade)
{
 this->qtdListaReproducao = 0;
 this->listaReproducao = new Filme;
}

Youtube::~Youtube()
{
 delete [] this->listaReproducao;
}

Youtube::Youtube(const Youtube& youtubeCpy)
:ServicoStreaming(youtubeCpy)
{
 int cont;
 this->qtdListaReproducao = youtubeCpy.qtdListaReproducao;
 delete [] this->listaReproducao;
 this->listaReproducao = new Filme[this->qtdListaReproducao];
 for(cont = 0 ; cont < this->qtdListaReproducao; cont++)
 {
  this->listaReproducao = youtubeCpy.listaReproducao;
 }
}

ostream& operator<<(ostream& output, const Youtube& youtube)
{
 int cont;
 Filme* listaReproducao = new Filme[youtube.getQtdReproducao()];
 output << static_cast<const Servico&> (youtube) <<";\n";
 if(youtube.getListaReproducao() == NULL)
 {
  output << endl;
 }else if(youtube.getQtdReproducao() == 0)
 {
  output << "Nao existe uma lista de reproducao para Usuario" << endl;
 }else
 {
  output << "Lista de reproducao:" << endl;
  listaReproducao = youtube.getListaReproducao();
  for(cont = 0; cont < youtube.getQtdReproducao(); cont++)
  {
   output << listaReproducao[cont]<< endl;
  }

 }
 delete []listaReproducao;
 return output;
}

Youtube* Youtube::operator=(const Youtube& youtube)
{
int cont;
 Youtube* auxYoutube;
 Youtube::operator=(youtube);
 Youtube::operator=(youtube);

 auxYoutube->saldo = youtube.getSaldo();
 auxYoutube->qtdRecomendacoes = youtube.getQtdRecomendacoes();
 delete auxYoutube->recomendacoes;
 auxYoutube->recomendacoes = new Filme[youtube.getQtdRecomendacoes()];

 for(cont = 0; cont < youtube.getQtdRecomendacoes(); cont++)
 {
  auxYoutube->recomendacoes[cont] = youtube.recomendacoes[cont];
 }
 return auxYoutube;
}


void Youtube::CadastrarUsuario(const Usuario& usuario)
{
 int cont;
 Usuario * auxUsuario = new Usuario[this->numeroUsuarios];
 for(cont = 0; cont < this->numeroUsuarios; cont++)
 {
  auxUsuario[cont] = this->listaUsuarios[cont];
 }

 delete [] this->listaUsuarios;
 this->listaUsuarios = new Usuario[++this->numeroUsuarios];
 for(cont = 0 ; cont < this->numeroUsuarios-1; cont++)
 {
  this->listaUsuarios[cont] = auxUsuario[cont];
 }
 this->listaUsuarios[this->numeroUsuarios-1] = usuario;
 delete [] auxUsuario;
}


void Youtube::CadastrarAparelho(const string& aparelho)
{
int cont;
if(aparelho.empty())
 {

 string* auxAparelhos = new string[this->getNumeroAparelhos()];
 for(cont = 0; cont < this->getNumeroAparelhos(); cont++)
 {
  auxAparelhos[cont] = this->aparelhos[cont];
 }
 delete [] this->aparelhos;
 this->aparelhos = new string[this->getNumeroAparelhos()];
 for(cont = 0; cont < this->getNumeroAparelhos()-1;cont++)
 {
  this->aparelhos[cont] = auxAparelhos[cont];
 }
  this->aparelhos[this->getNumeroAparelhos()-1] = aparelho;

 delete [] auxAparelhos;
 }
}

const void Youtube::AdicionarProtocolo(const string& protocolo)
{
 if(protocolo.empty() == false && protocolo.compare("RDP") != 0 && protocolo.compare("RTSP"))
 {
  int cont;
  string* auxProtocolo = new string[this->numProtocolos]	 ;
  for(cont = 0; cont < this->getNumProtocolos(); cont++)
  {
   auxProtocolo[cont] = this->protocolos[cont];
  }

  delete [] this->protocolos;
  this->protocolos = new string[++this->numProtocolos];
  for(cont = 0; cont < this->getNumProtocolos(); cont++)
  {
   this->protocolos[cont] = auxProtocolo[cont] ;
  }

  this->protocolos[this->getNumProtocolos() -1] = protocolo;

  delete [] auxProtocolo;
 }else
 {
  cout << "Protocolo invalido"    << endl;
 }
}


int Youtube::getQtdReproducao() const
{
 return this->qtdListaReproducao;
}

Filme* Youtube::getListaReproducao() const
{
 return this->listaReproducao;
}
