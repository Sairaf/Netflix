/*
Função Usuario: Armazenar os atributos básicos de um usuario

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
Alocação dinâmica - se houver vazamento de memória a classe toda é desconsiderada ok
Usar o destrutor ok 
Construtor de cópia ok
Operator << friend ok 
Um const static ok

A classe usuário deverá ser responsável por armazenar os dados deste e dos filmes que ele comprou.

Atributos:

login: string - armazena o login do usuário
senha: string - armazena a senha do usua´rio
saldoConta: float - recebe o saldo do usuário. Caso ele queira comprar alguma coisa, este deverá ser maior que o preço do filme
qtdFilmesComprads: static int - O número atual de filmes comprados. Caso ele seja menor que o limite, o usuário poderá adicionar um filme a sua conta
filmesComprados: Filme* - Ponteiro que receberá os filmes do usuário. A adição de novos será dada através da alocação dinâmica de memória
MAXFILMES: int - Limite para quantos filmes o usuário pode ter

Métodos:

setters para todos os atributos exceto saldoConta
getters para todos os atributos
construtores de cópia, default e com passagem de parâmetros
destrutor
<<friend>> operator << : Facilita a escrita na tela dos atributos
operator = : Funciona similarmente a um construtor de cópia
void ComprarFilme: Adiciona um filme a conta do usuário. ELe pode comprar até alcançar o limite determinado por MAXFILMES


*/
#ifndef USUARIO_H
#define USUARIO_H
//=================================================
#include <iostream>
#include <string>
#include <vector>
//=================================================
#include "Filme.h"
//==================================================
#define MAXFILMES 10


class Usuario
{

 friend ostream& operator<<(const ostream, const Usuario&)	;
 private:
		 string login;
		 string senha;
		 Filme* filmesComprados;
		 static int qtdFilmesComprados;
		 static float saldoConta;
 public:
		//construtores
		
		 Usuario();
		 Usuario(const Usuario&);
		~Usuario();
		 Usuario(const string,const string, Filme&);
		
		//setters
		
		void setLogin(const string&);
		void setSenha(const string&);
		void setfilmesComprados(const Filme&, const int&);
		void setQuantidadefilmesComprados(const int&);
		void setNumUsuarios(const int&);
		
		//getters
		
		int    getNumUsuarios() const;
		string getLogin() const;
		string getSenha() const;
		Filme* getfilmesComprados () const;
		int    getQtdfilmesComprados() const;
		float  getSaldoConta() const;
		
		void ComprarFilme(Usuario*,const Filme&);
		Usuario operator=(const Usuario&);
};

#endif // USUARIO_H
