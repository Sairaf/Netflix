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
	
}