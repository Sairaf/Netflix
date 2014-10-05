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
#define MAXALUGUEL 10


using namespace std;

class Usuario
{
 private:
		 string login;
		 string senha;
		 Data dataDeInscricao;
		 int numUsuarios;
		 vector <Filme> filmesAssistidos;
		 int quantidadeFilmesAssistidos;
		 
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
		void setFilmesAssistidos(const Filme&);
		void setQuantidadeFilmesAssistidos(const int&);
		void setNumUsuarios(const int&);
		
		//getters
		
		int    getNumUsuarios() const;
		string getLogin() const;
		string getSenha() const;
		Data   getDataDeInscricao() const;
		vector <Filme>  getFilmesAssistidos () const;
		int    getQuantidadeFilmesAssistidos() const;
		
		void AdicionarUsuario(Usuario, const string, const string, const Data&, vector<Filme>&);
		void AlugarFilme(Usuario, Filme);
		
};

#endif // USUARIO_H