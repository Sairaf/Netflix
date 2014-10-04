#ifndef USUARIO_H
#define USUARIO_H
//=================================================
#include <iostream>
#include <string>
#include <vector>
//=================================================
#include "Filme.h"
#include "Data.h"	

class Usuario
{
 private:
		 string login;
		 string senha;
		 const Data DATADEINSCRICAO;
		 vector <Filme> filmesAlugados;
 public:
		//construtores
		
		Usuario();
		~Usuario();
		Usuario(string, string, const Data, string);
		
		//setters
		
		void setLogin(const string&);
		void setSenha(const string&);
		void setDATADEINSCRICAO(const Data&);
		void setFilmesAlugados(const string&);
		
		//getters
		
		string getLogin() const;
		string getSenha() const;
		Data   getDATADEINSCRICAO() const;
		string getAssistindoQualFilme() const;
		
		void AdicionarUsuario(Usuario[], const string, const string, const Data, const string);
		void AlugarFilme(Usuario[], Filme);
		
};

#endif