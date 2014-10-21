#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
//=============================================
#include "Data.h"
//==============================================
#define MAXFILMES 10
#define MAXUSUARIO 10
using namespace std;

class Netflix
{
	
friend ostream &operator<<(ostream &, const Netflix &); 
	
private:
	static string cnpj;
	static int existeUsuario;
	static float velMaxima; // Dada em MBPS
	const static float MENSALIDADE;
//============================================
	string usuarioLogin;
    string usuarioSenha;
	string* tituloFilme;
	static Data data;
//==========================================	
	static int quantidadeFilmes;
	
	
public:
      //construtores
	  
	  Netflix(string usuarioLogin = "Default", string senha = "1rfdew");
	  Netflix(string,string,string);
      Netflix(const Netflix&);
	 ~Netflix();

      //setters
	  void setCnpj(const string&) ;
	  void setListaDeFilmes(const string&) ;
	  void setQuantidadeFilmes(const int&)  ;
	  void setVelMaxima(const float&); 
	  void setLogin(const string&);
	  void setSenha(const string&);
	  void setTitulo(const string&);
	  void setExisteUsuario(const int&);

  //getters
	  
	  string getCnpj() const;
	  const string& getListaDeFilmes() const ;
	  int getQuantidadeFilmes() const ;
	  string getLogin() const;
	  string getSenha() const;
	  string getTitulo(const int&) const;
	  float getVelMaxima() const ;
	  float getMensalidade() const;
	  int   getExisteUsuario() const;
	  
	  const inline void Welcome(){cout<< "Bem vindo ao sistema Netflix. "<<endl;};
	  
	  void AdicionarUsuario(Netflix*, string, string);
	  void AdicionarFilme(Netflix*, string);

	  const void ListarUsuario(Netflix*, int);
	  float CalculoDownload(float, float);
	  static float CalculoGanhos(int,const float);
	  
	  Netflix operator=(const Netflix&) const;
};