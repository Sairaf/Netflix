#ifndef USUARIO_H
#define USUARIO_H
//=================================================
#include <iostream>
#include <string>
#include <vector>
//=================================================
#include "Filme.h"
#include "Data.h"	
//==================================================
#define MAXFILMES 10
#define MAXUSUARIO 10

using namespace std;

class Usuario
{

 friend ostream& operator<<(const ostream, Usuario&)	;
 private:
		 string login;
		 string senha;
		 Data dataDeInscricao;
		 int numUsuarios;
		 Filme* filmesComprados;
		 int quantidadefilmesComprados;
		 
 public:
		//construtores
		
		 Usuario();
		 Usuario(const Usuario&);
		~Usuario();
		 Usuario(const string,const string, const Data&, vector <Filme>&);
		
		//setters
		
		void setLogin(const string&);
		void setSenha(const string&);
		void setDataDeInscricao(const Data&);
		void setfilmesComprados(const Filme&, const int&);
		void setQuantidadefilmesComprados(const int&);
		void setNumUsuarios(const int&);
		
		//getters
		
		int    getNumUsuarios() const;
		string getLogin() const;
		string getSenha() const;
		Data   getDataDeInscricao() const;
		Filme*  getfilmesComprados () const;
		int    getQuantidadefilmesComprados() const;
		
		void Adicionar(Usuario* us, const string&, const string&, const Data&);
		void AlugarFilme(Usuario&,const Filme);
		Usuario operator<<(const Usuario);
};

#endif // USUARIO_H