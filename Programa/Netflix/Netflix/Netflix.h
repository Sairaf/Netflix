#include <iostream>
#include <cstdlib>
#include <string>
//=============================================
#include "Data.h"
#include "Usuario.h"
#include "Filme.h"
//==============================================
#define MAXFILMES 50
#define MAXUSUARIOS 30

class Netflix
{
private:
	string cnpj;
	static float velMaxima; // Dada em MBPS
	const static float MENSALIDADE;
//============================================
	
	static int quantidadeUsuarios;
	static int quantidadeFilmes;
	vector <Filme> listaDeFilmes;
	vector <Usuario> listaDeUsuarios;
public:
      //construtores
	  
	  Netflix();
	  Netflix(string,vector<Filme>, vector <Usuario>);
      Netflix(const Netflix&);
	 ~Netflix();

      //setters
	  void setCnpj(const string&) ;
	  void setListaDeFilmes(const string&) ;
      void setListaDeUsuarios(const string&) ;
	  void setQuantidadeFilmes(const int&)  ;
	  void setQuantidadeUsuarios(const int&) ;
      void setVelMaxima(const int&); 
	  
	  //getters
	  

	  string getCnpj() const;
	  const string& getListaDeFilmes() const ;
	  const string& getListaDeUsuarios() const ;
	  int getQuantidadeFilmes() const ;
	  int getQuantidadeUsuarios() const;
	  int getVelMaxima() const ;
	  
	  inline void Welcome(){cout<< "Bem vindo :D\n"<<endl; }
	  void ListarUsuarios(Netflix*, int);
	  const float CalculoDownload(float, float);
};
