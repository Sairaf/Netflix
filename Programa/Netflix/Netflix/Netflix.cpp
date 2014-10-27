#include <iostream>
#include "Netflix.h"

float Netflix::velMaxima = 15;

Netflix::Netflix(string nome, string cnpj)
:Empresa(nome, cnpj)
{
 this->listaUsuario = NULL;

}

Netflix::Netflix( const string& nome,const string& cnpj,const int& numFuncionarios, const string& endereco)
:Empresa(nome,cnpj, numFuncionarios, endereco)
{
 this->listaUsuario = NULL;
}

Netflix::~Netflix()
{
 delete [] listaUsuario;

}

Netflix::Netflix(const Netflix& netflixCpy)
:Empresa(netflixCpy)
{
 this->listaUsuario = netflixCpy.listaUsuario;                    
}		


void Netflix::AdicionarUsuario(Netflix*& netflix, Usuario usuario)
{
 netflix->setUsuario(usuario);
 netflix->qtdUsuarios++;
}
 
 
 float Netflix::CalculoDownload(float velMaxima, float velAtual)
 {
  velAtual = -1;	 
  float velDownload;
  while(velAtual < 0)
  {
   cout << "Digite a velocidade de sua conexao"<< endl;
   cin >> velAtual;	  
  }
  velDownload = velAtual/8;	 
  return velDownload;
 }
 
float Netflix::CalculoGanhos(Netflix* netflix)
{
 int i;      
 float saldo;
 for(i = 0; i <netflix->qtdUsuarios;i++)
 {
  saldo+=netflix->listaUsuario[i].getMensalidade();     
 }  
 
 return saldo;           
}
  
ostream &operator<<(ostream &output, const Netflix& empresa)  
{
int i;         
 output << "Nome da Empresa: "<< empresa.getNome() << endl;         
 output << "Cnpj: " << empresa.getCnpj() <<endl;
 output << "Numero de Funcionarios: " << empresa.getNumFuncionarios() << endl;                
 output << "Endereco(s): " ;
 if(empresa.getQtdEnderecos() == 0 )
 {
  output << endl;                                
 }else               
 for(i =0; i <empresa.qtdEnderecos; i++)
 {
  output << empresa.enderecos[i] << endl;     
 }
 
 output << "Usuarios: " ;
 if(empresa.getQtdUsuario() == 0 )
 {
  output << endl;                                
 }else               
 for(i =0; i <empresa.getQtdUsuario(); i++)
 {
  output << empresa.listaUsuario[i] << endl;     
 }
 
 return output;
}
  
Netflix Netflix::operator=(const Netflix& ntf) const
{
 Netflix aux;	
 aux.listaUsuario = ntf.listaUsuario;
 return aux;
 
}
  
void Netflix::setUsuario(const Usuario& usuario)
{
 int i;        
 Usuario* auxUsuario = new Usuario[this->qtdUsuarios];
 for(i = 0; i < this->qtdUsuarios; i++)
 {
  auxUsuario[i] = this->listaUsuario[i];      
 }                
 
 delete [] this->listaUsuario;
 this->listaUsuario = new Usuario[qtdUsuarios++];

 for(i = 0; i < this->qtdUsuarios-1; i++)
 {
   this->listaUsuario[i] = auxUsuario[i];      
 }                
  this->listaUsuario[this->qtdUsuarios] = usuario;
}          
  
float Netflix::getVelMaxima() const
{
 return velMaxima;	
}
   	 
int Netflix::getQtdUsuario() const
{
 return this->qtdUsuarios;         
}     

Usuario* Netflix::getLista() const
{
 return this->listaUsuario;        
}         
