/*
Função Netflix: Armazena usuários e seus filmes, além de realizar operações como verificar qual seria a velocidde do download

Iniciar todos os atributos ok
Iniciar 3 construtores (Default, cópia e um normal) ok
Ter atributo string ok
Ter atributo static ok
Ter atributo const static ok
Dois métodos constantes ok
um array ok
uma função inline (mensagem de boas vindas) ok
método com passagem por referência ok
Método static (chamado no main) ok

Requisitos de implementação (2):

Operator = ok 
Alocação dinâmica - se houver vazamento de memória a classe toda é desconsiderada 
Usar o destrutor ok 
Construtor de cópia ok
Operator << friend ok 
Um const static ok


Atributos:

cnpj: string - Recebe o cnpj da empresa
velMaxima: static float - Velocidade maxima do download que os usuários podem fazer
MENSALIDADE: const static int - Mensalidade do serviço
qtdUsuarios: static int - Recebe o número de usuários. Atributo necessário para algumas operações
listaDeUsuarios: Usuario* - Lista que contém todos os suários adicionados
MAXUSUARIO: const int - Número máximo de usuários que o sistema permite

Métodos:

setters para todos os atributos exceto listaDeUsuario, qtdUsuarios e MENSALIDADE
getters para todos os atributos exceto listaDeUsuario
construtores de cópia, default e com passagem de parâmetros
destrutor
<<friend>> operator << : Facilita a escrita na tela dos atributos
operator = : Funciona similarmente a um construtor de cópia
void AdicionarUsuario: Adiciona um usuário e sua lista de filme na listaDeUsuario enquanto a quantidade não for maior que o limite
const void AdicionarUsuario: Adiciona um usuário e sua lista de filme na listaDeUsuario enquanto a quantidade não for maior que o limite


*/





#include <iostream>
#include <cstdlib>
#include <string>
//=============================================
#include "Data.h"
#include "Filme.h"
#include "Usuario.h"
//================================
#define MAXUSUARIO 10

class Netflix
{
	
friend ostream &operator<<(ostream &, const Netflix &); 
private:
	string cnpj;
	static float velMaxima; // Dada em MBPS
	const static float MENSALIDADE;
	
	static int qtdUsuarios;
	Usuario* listaDeUsuarios;
	
	
public:
      //construtores
          Netflix();
	  Netflix(const string&,const Usuario&, const int&);
          Netflix(const Netflix&);
	 ~Netflix();

      //setters
	  void setCnpj(const string&) ;
	  void setFilmeComprados(const Filme&, const int&);
	  void setVelMaxima(const float&); 
	  
      //getters
	  string getCnpj() const;
	  int getqtdUsuarios() const ;
	  float getVelMaxima() const ;
	  float getMensalidade() const;
	  
	  const inline void Welcome(){cout<< "Bem vindo ao sistema Netflix :D. \n"<<endl;};
	  
	  void AdicionarUsuario(Netflix*, const int&,const string&,const string&, const Data&, const Filme&);
	  const void ListarUsuarios(Netflix*, int);
	  float CalculoDownload(float, float);
	  static float CalculoGanhos(int,const float);
	  
	  Netflix operator=(const Netflix&) const;

};
