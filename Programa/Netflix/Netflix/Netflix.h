#include <iostream>
#include <cstdlib>
#include <string>
//=============================================
#include "Data.h"
#include "Filme.h"
#include "Usuario.h"
//================================
#define MAXUSUARIO 10

class Netflix
{
	
friend ostream &operator<<(ostream &, const Netflix &); 
private:
	string cnpj;
	static float velMaxima; // Dada em MBPS
	const static float MENSALIDADE;
	
	static int qtdUsuarios;
	Usuario* listaDeUsuarios;
	
	
public:
      //construtores
      Netflix();
	  Netflix(const string&,const Usuario&, const int&);
      Netflix(const Netflix&);
	 ~Netflix();

      //setters
	  void setCnpj(const string&) ;
	  void setFilmeComprados(const Filme&, const int&);
	  void setVelMaxima(const float&); 
	  
      //getters
	  string getCnpj() const;
	  int getqtdUsuarios() const ;
	  float getVelMaxima() const ;
	  float getMensalidade() const;
	  
	  const inline void Welcome(){cout<< "Bem vindo ao sistema Netflix :D. \n"<<endl;};
	  
	  void AdicionarUsuario(Netflix*, const int&,const string&,const string&, const Data&, const Filme&);
	  void ListarUsuarios(Netflix*, int);
	  float CalculoDownload(float, float);
	  static float CalculoGanhos(int,const float);
	  
	  Netflix operator=(const Netflix&) const;

};
