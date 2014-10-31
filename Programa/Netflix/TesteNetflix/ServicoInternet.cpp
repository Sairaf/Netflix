#include "ServicoInternet.h"

ServicoInternet::ServicoInternet(string nome, string cnpj)
:nomeEmpresa(nome), cnpj(cnpj)
{
 Usuario auxUsuario("Indefinido", "000-000-000/0000-00");	
 Data auxData(1,1,1990);
 this->setDescricao("Desconhecido");
 this->numeroUsuario = 0;
 this->numeroFuncionarios = 0;
 this->setEndereco("Desconhecido");
 this->usuariosRegistrados = new Usuario;
 this->setUsuario(auxUsuario);
 this->setData(auxData);
 //delete [] auxUsuario; // provavelmente vai ter algum erro aqui. Watch out, Abby
} 

ServicoInternet::ServicoInternet(string nomeEmpresa, string cnpj, int numeroFuncionarios, string descricao, string endereco, int numUsuarios, int dia, int mes, int ano)
{
 Data auxData(dia, mes,ano)	;
 this->setNome(nome);
 this->setCnpj(cnpj);
 this->setDescricao(descricao);
 this->setEndereco(endereco); 
 this->setQuantidadeFuncionarios(numeroFuncionarios)
 this->setNumeroUsuarios(numUsuarios);
 this->usuariosRegistrados = new Usuario[this->numeroUsuario];
 this->setData(auxData);
}

ServicoInternet::~ServicoInternet()
{
 delete []	this->usuariosRegistrados;
}

ServicoInternet::ServicoInternet(const ServicoInternet servicoCpy)
{
 int cont;	
 this->nomeServico = servicoCpy.nomeServico;
 this->cnpj = servicoCpy.cnpj;
 this->descricaoServico = servicoCpy.descricaoServico;
 this->enderecoSede = netflix.enderecoSede;
 this->dataCriacao = servicoCpy.dataCriacao;
 this->numeroFuncionarios = servicoCpy.numeroFuncionarios;
 this->numeroUsuarios = servicoCpy.numeroUsuarios;
 for(cont = 0; cont < numeroUsuarios; cont ++)
 {
  this->usuariosRegistrados[cont] = servicoCpy.usuariosRegistrados[cont];
 }
}