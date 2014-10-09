#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
//=============================================
#include "Data.h"
//==============================================
#define MAXFILMES 10

using namespace std;

class Netflix
{
	
friend ostream &operator<<(ostream &, const Netflix &); 
	
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
	  void setQuantidadeFilmes(const int&)  ;
	  void setVelMaxima(const float&); 
	  void setLogin(const string&);
	  void setSenha(const string&);
	  void setTitulo(const string&,const int&);
	

  //getters
	  
	  string getCnpj() const;
	  const string& getListaDeFilmes() const ;
	  int getQuantidadeFilmes() const ;
	  string getLogin() const;
	  string getSenha() const;
	  string getTitulo(const int&) const;
	  float getVelMaxima() const ;
	  float getMensalidade() const;
	  
	  inline void Welcome(){cout<< "Bem vindo ao sistema Netflix :D. \n"<<endl;};
	  
	  void AdicionarUsuario(Netflix*, string, string);
	  void AdicionarFilme(Netflix*, string, int);
	  

	  void ListarUsuario(Netflix*, int);
	  const float CalculoDownload(float, float);
	  static const float CalculoGanhos(int,const float);
};
