/*
Função Netflix.h

Criar pelo menos 4 atributos ok
Criar pelo menos 4 funções (sem contar get e set) ok
Iniciar todos os atributos ok
Iniciar 3 construtores (Default, cópia e um normal) ok
Ter atributo string ok
Ter atributo static (Velocidade máxima?) ok
Ter atributo const static (cnpj) ok
Dois métodos constantes ok
um array ok
uma função inline (mensagem de boas vindas) ok
método com passagem por referência ok
Método static (chamado no main) ok
composição com a classe Data ok

Acréscimos

Alocação dinâmica de memória. ok
fried Operator<< ok
Operator= ok
vector push_back

Atributos:
cnpj : string - Armazena o cnpj
existeUsuario: int - verifica se existe algum usuario
velMaxima: static float - recebe o valor da velocidade maxima
MENSALIDADE: const static float

usuarioLogin: string - Recebe o login do usuário
usuarioSenha: string - Recebe a senha do usuário
tituloFilme: string* - Recebe um certo numero de filmes através da laocação dinâmica de memória
data: Data - Recebe uma data colocada pelo usuário
quantidadeFilmes: int - Recebe o numero atual de filmes

MAXFILMES: const int - Numero maximo de iflmes que o usuario pode ter


Métodos:
Construtores de cópia,default e com passagem de parâmetros
gets e sets para a maioria dos atributos

const inline void Welcome - Escreve na tela uma pequena mensagem de boas vindas
	  
void AdicionarUsuario - Adiciona um usuário
void AdicionarFilme - Adiciona um filme para a conta do usuario enquanto o atributo quantidadeFIlmes for menor que o MAXFILMES
const void ListarUsuario - escreve o usuário e seus filmes
float CalculoDownload(float, float) - Calcula a velocidade do download
static float CalculoGanhos(int,const float) - calcula quanto seriam os ganhos com x usuarios
Netflix operator=(const Netflix&) const - Sobrecarga de operador para =
friend ostream &operator<<(ostream &, const Netflix &) : Método friend que auxilia a escrita dos atributos na tela.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
//=============================================
#include "Empresa.h"
//==============================================
#define MAXFILMES 10
#define MAXUSUARIO 10

using namespace std;

class Netflix: public Empresa
{
	
friend ostream &operator<<(ostream &, const Netflix &); 
	
protected:     
	static float velMaxima; // Dada em MBPS
//============================================
    Usuario* listaUsuario;
	static Data data;
	int qtdUsuarios;
//==========================================	
	
public:
      //construtores
	  
	  Netflix(string nomeEmpresa = "Netflix", string cnpj = "000.000.000/0000-00");
      Netflix(const string& ,const string&,const int&,const string&);
      Netflix(const Netflix&);
	 ~Netflix();

      //setters
	  void setUsuario(const Usuario*);

      //getters
	  
	  float getVelMaxima() const ;
	  float getMensalidade() const;
	  int   getExisteUsuario() const;
	  int   getQtdUsuario() const;
	  
	  const inline void Welcome(){cout<< "Bem vindo ao sistema Netflix. "<<endl;};
	  
	  void AdicionarUsuario(Netflix*, Usuario*);
	  float CalculoDownload(float, float);
	  static float CalculoGanhos(Netflix*);
	  
	  Netflix operator=(const Netflix&) const;
};
