#include "Servico.h"

Servico::Servico()
{
 this->setNome("Desconhecido")   ;
 this->setCnpj("00.000.000/0000-00");
 this->dataCriacao = new Data(5,10,2010);
 this->setDescricao("Desconhecido");
 this->setEndereco("Desconhecido");
 this->numeroAparelhos = 0;
 this->aparelhos = new string[this->numeroAparelhos];
}

Servico::Servico(string nome, string cnpj)
:nomeServico(nome), cnpj(cnpj)
{
 this->dataCriacao = new Data(5,10,2010);
 this->setDescricao("Desconhecido");
 this->setEndereco("Desconhecido");
 this->numeroAparelhos = 0;
 this->aparelhos = new string[this->numeroAparelhos];

}

Servico::Servico(string nomeEmpresa, string cnpj, int numeroFuncionarios, string descricao, string endereco, int dia, int mes, int ano)
{

 this->dataCriacao = new Data(dia,mes,ano);
 this->setNome(nomeEmpresa);
 this->setCnpj(cnpj);
 this->setDescricao(descricao);
 this->setEndereco(endereco);
 this->setQuantidadeFuncionarios(numeroFuncionarios);
// this->setData(auxData);
 this->numeroAparelhos = 0;
 this-> aparelhos = new string[this->numeroAparelhos];
}

Servico::~Servico()
{
 delete []	this->aparelhos;
}

Servico::Servico(const Servico& servicoCpy)
{
 int cont;
 this->nomeServico = servicoCpy.nomeServico;
 this->cnpj = servicoCpy.cnpj;
 this->descricaoServico = servicoCpy.descricaoServico;
 this->enderecoSede = servicoCpy.enderecoSede;
 this->dataCriacao = servicoCpy.dataCriacao;
 this->aparelhos = servicoCpy.aparelhos;


}

ostream &operator<<(ostream& output, const Servico& servico)
{
 int cont;
 output <<"Nome do servico: "<< servico.getNome() << endl;
 output <<"Cnpj: " << servico.getCnpj() << endl;
 output <<"Descricao do servico: " <<servico.getDescricao() << endl;
 servico.getData();
 output << endl;
 output <<"Endereco de sua sede: " <<servico.getEndereco() << endl;
 string * auxAparelhos = new string;
 auxAparelhos = servico.getAparelhos();

 if(auxAparelhos != NULL)
 {
  if(servico.getNumeroAparelhos() == 0)
  {
	cout << "Nenhum aparelho foi registrado" << endl;
  }else
  {
   output <<"Numero de aparelhos aonde este servico pode ser acessado: " << servico.getNumeroAparelhos() << endl;
	for(cont = 0; cont < servico.getNumeroAparelhos(); cont++)
	{

	 output << auxAparelhos[cont]	<<endl;
	}
  }
 }else
 {
  output << "Nao existe aparelho registrado." << endl;
 }
 cout <<"TESTE" <<endl;
 if(servico.getAparelhos() != 0)
 {
  delete [] auxAparelhos;
     }
 return output;
}

Servico* Servico::operator=(const Servico& servico)
{
 int cont;
 Servico* auxServico;
 auxServico->nomeServico = servico.nomeServico;
 auxServico->cnpj = servico.cnpj;
 auxServico->dataCriacao = servico.dataCriacao;
 auxServico->enderecoSede = servico.enderecoSede;
 auxServico->numeroAparelhos = servico.numeroAparelhos;
 auxServico->numeroFuncionarios = servico.numeroFuncionarios;
 for(cont = 0; cont < auxServico->numeroFuncionarios; cont++)
 {
 auxServico->aparelhos[cont] = servico.aparelhos[cont];
 }
 return auxServico;
}

void Servico::MostrarAparelhos(const Servico& servico)
{
 int cont;
 if(servico.numeroAparelhos > 0 && servico.aparelhos != NULL)
 {
  for(cont =0; cont < servico.numeroAparelhos;cont++)
  {
   cout << servico.aparelhos[cont]	;
  }
 }
}
/*
void Servico::CadastrarAparelho(Servico* servico, const string& aparelho)
{
 int cont;
 if(aparelho.empty() != false)
 {
  string* auxAparelho = new string[servico->numeroAparelhos];
  for(cont = 0; cont < servico->numeroAparelhos; cont++)
  {
   auxAparelho[cont] = servico->aparelhos[cont];
  }
  delete servico->aparelhos;
  servico->aparelhos = new string[++servico->numeroAparelhos];
  for(cont = 0; cont <servico->numeroAparelhos-1; cont++)
  {
   servico->aparelhos[cont] = auxAparelho[cont];
  }

   servico->aparelhos[servico->numeroAparelhos-1] = aparelho;
   delete [] auxAparelho;
 }
}
*/


 void Servico::setNome(const string& nomeServico)
 {
  if(nomeServico.empty() == false)
  {
   this->nomeServico = nomeServico;
  }else
  {
   this->nomeServico = "default";
  }
 }

 void Servico::setCnpj(const string& cnpj)
 {
  if(cnpj.size() == 18 && cnpj.empty() == false) //alterar aqui
  {
   this->cnpj = cnpj;
  }else
  {
   this->cnpj = "00.000.000/0000-00";
  }
 }

 void Servico::setEndereco(const string& endereco)
 {
  if(endereco.empty() == false)
  {
   this->enderecoSede = endereco;
  }else
  {
   this->enderecoSede = "desconhecido";
  }
 }

 void Servico::setDescricao(const string& descricao)
 {
  if(descricao.empty() != false)
  {
   this->descricaoServico = descricao;
  }else
  {
   this->descricaoServico = "Nao declarado";
  }
 }

 void Servico::setAparelhos(const string& aparelho)
 {
  int cont;
  string* auxAparelho = new string;
  if(aparelho.empty() == false)
  {
   for(cont = 0; cont < this->numeroAparelhos; cont++)
   {
    auxAparelho[cont] = this->aparelhos[cont];
   }
   delete [] this->aparelhos;
   this->aparelhos = new string[++numeroAparelhos];
   for(cont = 0; cont < this->numeroAparelhos -1; cont++)
   {
    this->aparelhos[cont] = auxAparelho[cont];
   }
   this->aparelhos[this->numeroAparelhos-1] = aparelho;
  }else
  {
   ++this->numeroAparelhos;
   this->aparelhos[this->numeroAparelhos-1] = "Nao declarado";
  }
  delete [] auxAparelho;
 }

void Servico::setQuantidadeFuncionarios(const int& numFuncionarios)
{
 if(numeroFuncionarios > 0)
 {
  this->numeroFuncionarios = numFuncionarios;
 }else
 {
  this->numeroFuncionarios = 0;
 }
}

void Servico::setData(const Data& data)
{
 if(data.VerificaDia(4) != 1)
 {
  this->dataCriacao[0] = data;
 }else
 {
  this->dataCriacao = new Data(1,1,1990);
 }
}

 string Servico::getNome() const
 {
  return this->nomeServico;
 }

 string Servico::getCnpj() const
 {
  return this->cnpj;
 }

string Servico::getEndereco() const
{
  return this->enderecoSede;
 }

 string Servico::getDescricao() const
 {
  return this->descricaoServico;
 }

 int Servico::getQuantidadeFuncionarios() const
 {
  return this->numeroFuncionarios;
 }

 int Servico::getNumeroAparelhos() const
 {
  return this->numeroAparelhos;
 }

Data* Servico::getData() const
{
 return this->dataCriacao;
}

string* Servico::getAparelhos() const
{
 return this->aparelhos;
}
