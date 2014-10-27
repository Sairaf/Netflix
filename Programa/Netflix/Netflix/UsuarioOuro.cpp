#include "UsuarioOuro.h"


UsuarioOuro::UsuarioOuro(const string& login, const string& senha)
:Usuario(login, senha)
{

 this->setAparelho("Computador");      
 this->mensalidade = 19.90;    
}     

UsuarioOuro::UsuarioOuro(const string& login,const string& senha, const string& apRegistrado,const float& saldo,const string& perfil)
:Usuario(login, senha,apRegistrado, saldo)
{
 this->mensalidade = 19.90;                 
 this->setPerfil(perfil);
 this->qtdPerfil = 1;                
}                

UsuarioOuro::~UsuarioOuro()
{
 delete [] aparelhoRegistrado;
 delete [] filmesConta;                             
 delete [] perfil;
}                   

UsuarioOuro::UsuarioOuro(const UsuarioOuro& ouroCpy)
:Usuario(ouroCpy)
{
 this->perfil = ouroCpy.perfil;
 this->qtdPerfil = ouroCpy.qtdPerfil;                               
}                               

ostream &operator<<(ostream& output, const UsuarioOuro& usuario)
{
 int i;       
 output << "Login: " << usuario.getLogin() << endl;
 output << "Senha: " << usuario.getSenha() << endl;
 output << "Credito na sua conta: " << usuario.getSaldo() << endl;
 output << "Aparelho registrado em sua conta: ";
 
 if(usuario.qtdAparelhoRegistrado == 0)
 {
  output << endl;
 }else  if(usuario.qtdAparelhoRegistrado > 0)
 {
        
  for(i = 0; i < usuario.qtdAparelhoRegistrado; i++)	 
  {
   output <<"==========================" << endl;     
   output <<usuario.aparelhoRegistrado[i] <<  endl;
   output <<"==========================" << endl;
  }
  
 }
 
 output << endl;
 output << "Filmes em sua conta: "<< endl;	 
 
 if(usuario.qtdFilmesConta == 0)
 {
  output << endl;
 }else if (usuario.qtdFilmesConta > 0)
 {
       
  for(i = 0; i < usuario.qtdFilmesConta; i++)	 
  {
   output <<"==========================" << endl;     
   output <<usuario.filmesConta[i] <<  endl;
   output <<"==========================" << endl;
   
  }
 } 
 
 if(usuario.qtdPerfil == 0)
 {
  output << endl;                    
 }else if(usuario.qtdPerfil > 0)
 {
       
  for(i = 0; i < usuario.qtdPerfil; i++)	 
  {
   output <<"==========================" << endl;     
   output <<usuario.perfil[i] <<  endl;
   output <<"==========================" << endl;
   
  } 
       
 }                    
 
 return output;              
}        

UsuarioOuro UsuarioOuro::operator=(const UsuarioOuro& usuario)
{
 UsuarioOuro auxUsuario;
 auxUsuario.setLogin(usuario.getLogin());
 auxUsuario.setSenha(usuario.getSenha());
 auxUsuario.setSaldoConta(usuario.getSaldo());
 auxUsuario.aparelhoRegistrado = usuario.aparelhoRegistrado;
 auxUsuario.mensalidade = usuario.mensalidade;
 auxUsuario.qtdAparelhoRegistrado= usuario.qtdAparelhoRegistrado;//*
 auxUsuario.qtdFilmesConta = usuario.qtdFilmesConta;//**  
 auxUsuario.qtdPerfil = usuario.qtdPerfil;
 auxUsuario.perfil = usuario.perfil;
 return auxUsuario;          
}           

void UsuarioOuro::AdicionarPerfil(UsuarioOuro* usuario,const string& perfil)
{
 if(usuario->qtdPerfil < MAXPERFIS)
 {
  usuario->setPerfil(perfil);                       
  usuario->qtdPerfil++;
 }else
 {
  cout << "Limite maximo de perfis atingido" << endl;    
 }                                 
}     

void UsuarioOuro::AdicionarAparelhoAconta(UsuarioOuro* usuario, const string& aparelho)
{
 if(usuario->qtdAparelhoRegistrado < MAXAPARELHO)
 {
  usuario->setAparelho(aparelho);                       
 }else
 {
  cout << "Limite maximo de aparelhos alcançado" << endl;    
 }                                   
}     

void UsuarioOuro::setPerfil(const string& perfil)
{
 int i;     
 string* auxPerfil =new string[this->qtdPerfil];
 for(i = 0 ; i < this->qtdPerfil; i++)
 {
  auxPerfil[i] = this->perfil[i];     
 }       
  delete [] this->perfil;
  
 this->perfil=new string[this->qtdPerfil++];
 for(i = 0 ; i < this->qtdPerfil-1; i++)
 {
  this->perfil[i] = auxPerfil[i];
 }       
  this->perfil[qtdPerfil] = perfil;
  delete [] auxPerfil;
}     

string* UsuarioOuro::getPerfil() const
{
 return this->perfil;       
}        

