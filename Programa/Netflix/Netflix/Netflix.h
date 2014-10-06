#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
//=============================================
#include "Data.h"
//==============================================
#define MAXFILMES 50
#define MAXUSUARIOS 30

using std::string;
using std::vector;
class Netflix
{
private:
	string cnpj;
	static float velMaxima; // Dada em MBPS
	const static float MENSALIDADE;
//============================================
	string usuarioLogin;
    string usuarioSenha;
	vector <string> tituloFilme;
	static Data data;
//==========================================	
	static int quantidadeUsuarios;
	static int quantidadeFilmes;
	
	
public:
      //construtores
	  
	  Netflix();
	  Netflix(string, string,string);
      Netflix(const Netflix&);
	 ~Netflix();

      //setters
	  void setCnpj(const string&) ;
	  void setListaDeFilmes(const string&) ;
      void setListaDeUsuarios(const string&) ;
	  void setQuantidadeFilmes(const int&)  ;
	  void setQuantidadeUsuarios(const int&) ;
      void setVelMaxima(const float&); 
	  void setLogin(const string&);
	  void setSenha(const string&);
	  void setTitulo(const string&);
	

  //getters
	  
	  string getCnpj() const;
	  const string& getListaDeFilmes() const ;
	  const string& getListaDeUsuarios() const ;
	  int getQuantidadeFilmes() const ;
	  int getQuantidadeUsuarios() const;
	  string getLogin() const;
	  string getSenha() const;
	  string getTitulo() const;
	  float getVelMaxima() const ;
	  float getMensalidade() const;
	  
	  inline void Welcome(){cout<< "Bem vindo :D\n"<<endl;};
	  
	  void AdicionarUsuario(Netflix, int, string, string, Data);
	  void AdicionarFilme(Netflix, int, string, string, Data);
	  
	  void ListarUsuarios(Netflix*, int);
	  const float CalculoDownload(float, float);
	  static float CalculoGanhos(int,const float);
};
