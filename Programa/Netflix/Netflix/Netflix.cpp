#include "Netflix.h"

const float Netflix::MENSALIDADE = 17.90;


Netflix::Netflix(string nome, string cnpj)
:Servico(nome, cnpj)
{
 int cont;
 this->media = 0.0;
 this->contadorSaldo = 0;
 this->numUsuarios = 0;
 this->saldoEmpresaAno.reserve(11);
 for(cont = 0; cont < this->saldoEmpresaAno.size(); cont++)
 {
  this->saldoEmpresaAno[cont] = 0.0;
 }

 this->listaUsuarios= new Usuario[this->numUsuarios];
}

Netflix::Netflix(const string& nomeEmpresa,const string& cnpj,const int& numeroFuncionarios,const string& descricao,const string& endereco,const int& dia, const int& mes, const int& ano, const string& recomendacao)
:Servico(nomeEmpresa, cnpj, numeroFuncionarios, descricao, endereco, dia, mes, ano )
{
 int cont;
 this->contadorSaldo = 0;
 this->numUsuarios = 0;
 this->media = 0.0;
 this->saldoEmpresaAno.reserve(11);

 for(cont = 0; cont < this->saldoEmpresaAno.size(); cont++)
 {
  this->saldoEmpresaAno[cont] = 0.0;
 }
 this->listaUsuarios= new Usuario[this->numUsuarios];
}

Netflix::Netflix(const Netflix& netflixCpy)
:Servico(netflixCpy)
{
 int cont;
 this->numUsuarios = netflixCpy.numUsuarios;
 this->media = netflixCpy.media;
 for(cont = 0 ; cont <this->numUsuarios; cont++)
 {
  this->listaUsuarios[cont] = netflixCpy.listaUsuarios[cont];
 }
}

Netflix::~Netflix()
{
 delete [] this->listaUsuarios;
}

ostream& operator<<(ostream& output, const Netflix& netflix)
{
 int cont;
 output << endl;
 output <<"Nome : "<< netflix.getNome() << endl;
 output <<"Cnpj: " << netflix.getCnpj() << endl;
 output <<"Descricao do netflix: " <<netflix.getDescricao() << endl;
 output <<"Endereco de sua sede: " <<netflix.getEndereco() << endl;
 output <<"Numero de aparelhos aonde esta conta pode ser acessado: " << netflix.getNumeroAparelhos() << endl;
 output <<"Data: ";
 netflix.dataCriacao->print();
 output << endl;
 if(netflix.aparelhos == NULL)
 {
  output << endl;
 }else if(netflix.numeroAparelhos == 0)
 {
  output << "Nao existe aparelho registrado" <<endl;
 }else
 {
  for(cont = 0; cont < netflix.numeroAparelhos; cont++)
  {
   output << "| "<<netflix.aparelhos[cont] << " |" << endl;
  }
 }

 for(cont = 0; cont < netflix.contadorSaldo; cont++)
 {
  output << "Saldo do mes :"<<cont << netflix.saldoEmpresaAno[cont] << endl;
 }
 output << endl;
 for(cont = 0; cont < netflix.numUsuarios; cont++)
 {
  output << "Usuario numero "<< cont <<": " <<endl<< netflix.listaUsuarios[cont] << endl;
 }
  output << endl << "Numero de usuarios: " << netflix.numUsuarios << endl;
  output << "Media dos ultimos 12 meses: " << netflix.getMedia() << endl;
  return output;
}

Netflix* Netflix::operator=(const Netflix& netflixCpy)
{
 Netflix::operator=(netflixCpy);

 Netflix* auxNetflix;
 auxNetflix->media = netflixCpy.media;
 auxNetflix->contadorSaldo = netflixCpy.contadorSaldo;
 auxNetflix->numUsuarios = netflixCpy.numUsuarios;
 auxNetflix->dataCriacao = netflixCpy.dataCriacao;
 int cont;
 for(cont = 0; cont < auxNetflix->contadorSaldo; cont++)
 {
  auxNetflix->saldoEmpresaAno[cont] = netflixCpy.saldoEmpresaAno[cont];
 }

 for(cont = 0; cont < auxNetflix->numUsuarios; cont++)
 {
  auxNetflix->listaUsuarios[cont] = netflixCpy.listaUsuarios[cont];
 }

 return auxNetflix;
}

void Netflix::CadastrarUsuario(Netflix* netflix,const  Usuario& usuario)
{
  int cont;
  Usuario* auxUsuario = new Usuario[netflix->numUsuarios];
  for(cont = 0; cont < netflix->numUsuarios; cont++)
  {
   auxUsuario[cont] = netflix->listaUsuarios[cont];
  }
  delete [] netflix->listaUsuarios;
  netflix->listaUsuarios = new Usuario[++netflix->numUsuarios];
  for(cont = 0; cont <netflix->numUsuarios-1; cont++)
  {
   netflix->listaUsuarios[cont] = auxUsuario[cont];
  }
  netflix->listaUsuarios[netflix->numUsuarios-1] = usuario;
  delete [] auxUsuario;
 }

const void Netflix::MediaSaldoAnual(Netflix* netflix)
{
 int cont;
 for(cont = 0; cont < netflix->contadorSaldo; cont++)
 {
  this->media+= netflix->saldoEmpresaAno[cont];
 }

}

void Netflix::setSaldoConta(const float& saldo)
{
 if(this->contadorSaldo >=0 && this->contadorSaldo < 12)
 {
  this->saldoEmpresaAno.push_back(saldo);
  this->contadorSaldo++;
 }else
 {
  cout << "as posicoes de saldo chegaram ao sue limite." << endl;
 }
}

const float Netflix::getMENSALIDADE() const
{
 return this->MENSALIDADE;
}

float Netflix::getMedia() const
{
 return this->media;
}
