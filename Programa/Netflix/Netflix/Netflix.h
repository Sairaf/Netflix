#include <iostream>
#include <cstdlib>
#include <string>
//=============================================
#include "Data.h"
#include "Filme.h"
#include "Usuario.h"
//================================
#define MAXFILMES 10
#define MAXUSUARIO 10

class Netflix
{
	
	friend ostream &operator<<(ostream &, const Netflix &); 
private:
	string cnpj;
	static float velMaxima; // Dada em MBPS
	const static float MENSALIDADE;
//============================================
	//string login;
	//string senha;
//============================================	
	//string titulo;	
//==========================================	
	static int quantidadeUsuarios;
	static int quantidadeFilmes;
	
	Filme* listaDeFilmes;
	Usuario* listaDeUsuarios;
	
	
public:
      //construtores
      Netflix();
	  Netflix(string, Filme, Usuario);
      Netflix(const Netflix&);
	 ~Netflix();

      //setters
	  void setCnpj(const string&) ;
	  void setFilmeComprados(const Filme&, const int&);
	  void setListaDeFilmes(const string&) ;
	  void setQuantidadeFilmes(const int&)  ;
	  void setVelMaxima(const float&); 
	  void setLogin(const string&);
	  void setSenha(const string&);
	  void setTitulo(const string&,const int&);
	  void setExisteUsuario(const int&);

  //getters
	  
	  string getCnpj() const;
	  const string& getListaDeFilmes() const ;
	  int getQuantidadeFilmes() const ;
	  int getQuantidadeUsuarios() const ;
	  string getLogin() const;
	  string getSenha() const;
	  string getTitulo(const int&) const;
	  float getVelMaxima() const ;
	  float getMensalidade() const;
	  int   getExisteUsuario() const;
	  
	  const inline void Welcome(){cout<< "Bem vindo ao sistema Netflix :D. \n"<<endl;};
	  void AdicionarFilme(Netflix *, Filme*, const int&,  const string& ,const string& , const Data&);  
	  void AdicionarUsuario(Netflix*, const int&,const string&,const string&, const Data&);
	  void ListarUsuarios(Netflix*, int);
	  float CalculoDownload(float, float);
	  static float CalculoGanhos(int,const float);
	  
	  Netflix operator=(const Netflix&) const;

};
