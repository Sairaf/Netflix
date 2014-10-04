#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
//=============================================
#include "Data.h"
#include "Usuario.h"
#include "Filme.h"
//==============================================
#Define MAXFILMES 50
#Define MAXUSUARIOS 30

class Netflix
{
private:
	int cnpj;
	static int velMaxima;
	const static float MENSALIDADE;
//============================================

	string login;
	string senha;
	Data DATAINSCRICAOUSUARIO;
	string assistindoQualFilme;
//==============================
	int quantidadeUsuarios;
	int quantidadeFilmes;
	Filmes listaDeFilmes[MAXFILMES];
	string listaDeUsuarios[30];
public:
      //construtores
	  
	  Netflix();
	  Netflix(int, int,const static float, string[], string []);
      Netflix(Netflix);
	 ~Netflix();

      //setters
	  void setMENSALIDADE(float& ) ;
	  void setAssistindoQualFilme(const string&) ;
	  void setCnpj(int&) ;
	  void setListaDeFilmes(const string&) ;
      void setListaDeUsuarios(const string&) ;
	  void setLogin(const string&) ;
      void setQuantidadeFilmes(int&)  ;
	  void setQuantidadeUsuarios(int&) ;
      void setSenha(const string&) ;
	  void setVelMaxima(int&); 
	  
	  //getters
	  
	  float getMENSALIDADE() const;
	  const string& getAssistindoQualFilme() const ;
	  int getCnpj() const;
	  const string& getListaDeFilmes() const ;
	  const string& getListaDeUsuarios() const ;
	  const string& getLogin() const;
	  int getQuantidadeFilmes() const 
	  int getQuantidadeUsuarios() const 
	  const string& getSenha() const 
	  int getVelMaxima() const 
	  
	  inline void Welcome(){cout<< "Bem vindo"};
	  
};
