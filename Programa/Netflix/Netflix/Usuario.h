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

//using namespace std;

class Usuario
{

 friend ostream& operator<<(const ostream, Usuario&)	;
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
		Usuario operator<<(const Usuario);
};

#endif // USUARIO_H