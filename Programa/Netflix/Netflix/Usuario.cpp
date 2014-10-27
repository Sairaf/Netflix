#include "Usuario.h"

Usuario::Usuario(string login, string senha)
:login("default"), senha("default")
{
 this->setAparelho("Computador");
 this->setSaldoConta(0.00);
 this->qtdAparelhoRegistrado= 1;           
 this->mensalidade = 17.90;    
 this->qtdFilmesConta = 0;
}                

Usuario::Usuario(string login, string senha, string apRegistrado, float saldo)
{
 this->setLogin(login);
 this->setSenha(senha);
 this->setSaldoConta(saldo);
 this->setAparelho(apRegistrado);
 this->mensalidade = 17.90;  
 this->qtdAparelhoRegistrado= 1;           
 this->qtdFilmesConta = 0;
}                

Usuario::~Usuario()
{
 delete [] aparelhoRegistrado;
 delete [] filmesConta;                  
}                   


Usuario::Usuario(const Usuario& usuarioCpy)
{
 this->login = usuarioCpy.login;
 this->senha = usuarioCpy.senha;
 this->filmesConta = usuarioCpy.filmesConta;
 this->aparelhoRegistrado = usuarioCpy.aparelhoRegistrado;
 this->mensalidade = usuarioCpy.mensalidade;
 this->qtdAparelhoRegistrado= usuarioCpy.qtdAparelhoRegistrado;//*
 this->saldoConta = usuarioCpy.saldoConta;
 this->qtdFilmesConta = usuarioCpy.qtdFilmesConta;//**
}                       

ostream &operator<<(ostream& output, const Usuario& usuario)
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
 
}
                             
Usuario Usuario::operator=(const Usuario& usuario)
{
 Usuario auxUsuario;
 auxUsuario.setLogin(usuario.getLogin());
 auxUsuario.setSenha(usuario.getSenha());
 auxUsuario.setSaldoConta(usuario.getSaldo());
 auxUsuario.aparelhoRegistrado = usuario.aparelhoRegistrado;
 auxUsuario.mensalidade = usuario.mensalidade;
 auxUsuario.qtdAparelhoRegistrado= usuario.qtdAparelhoRegistrado;//*
 auxUsuario.qtdFilmesConta = usuario.qtdFilmesConta;//**  
 return auxUsuario;
}

void Usuario::AdicionarCreditosAConta(Usuario* usuario,const float& saldo)
{   
 usuario->setSaldoConta(usuario->saldoConta + saldo);    
}     

void Usuario::AdicionarFilmeAConta(Usuario* usuario, Filme& filme)
{
 int i;    
 Filme* auxFilme;     
 auxFilme =  new Filme[usuario->qtdFilmesConta]; 
 if(usuario->qtdFilmesConta == 0)
 {
  usuario->filmesConta[0] = filme;     
  usuario->qtdFilmesConta++;                    
 }else if(usuario->qtdFilmesConta > 0)
 {
  for(i = 0; i <usuario->qtdFilmesConta; i++) 
  {
   auxFilme[i] = usuario->filmesConta[i];     
  }
  
  delete [] usuario->filmesConta;
  this->filmesConta = new Filme[usuario->qtdFilmesConta++];
  
  for(i = 0; i <usuario->qtdFilmesConta-1; i++) 
  {
   usuario->filmesConta[i] = auxFilme[i];     
  }
   usuario->filmesConta[qtdFilmesConta] = filme;
   delete [] auxFilme;
 }                                
 
}      

void Usuario::AdicionarAparelhoAConta(Usuario* usuario, const string& aparelho)
{   
 usuario->setAparelho(aparelho);    
} 


void Usuario::setLogin(const string& login)
{
 if(login.empty() != 0 && login.size() < 50)
 {
  this->login = login;                  
 }else
 {
  cout << "Login invalido. Recebendo o login ""Usuario"" " << endl;
  this->login = "Usuario";    
 }                         
}     



void Usuario::setSenha(const string& senha)
{
 if(senha.empty() != 0)
 {
  this->senha= senha;               
 }else
 {
  cout << "Senha invalido. Recebendo a senha ""Senha"" " << endl;
  this->login = "Senha";          
 }                      
}     
    
void Usuario::setSaldoConta(const float& saldo)
{
 if(saldo > 0)
 {
  this->saldoConta = saldo;        
 }else
 {
  cout << "Valor invalido para o saldo. Este sera definido como ""0"" " << endl;
  this->saldoConta = 0;   
 }                     
}         
    
void Usuario::setAparelho(const string& aparelho)
{
 if(this->qtdAparelhoRegistrado == 0 && aparelho.empty() !=0  && aparelho.size() < 30)
 {
   this->aparelhoRegistrado = new string;
   this->aparelhoRegistrado[0] = aparelho; 
   this->qtdAparelhoRegistrado++;  
 }else
 {
  cout << "Limite de aparelhos atingido" << endl;    
 }        
}    

string Usuario::getLogin() const
{
 return this->login;      
}       

string Usuario::getSenha () const
{
 return this->senha;      
}       

float Usuario::getSaldo () const
{
 return this->saldoConta;     
}               

float Usuario::getMensalidade () const
{
 return this->mensalidade;     
}      
