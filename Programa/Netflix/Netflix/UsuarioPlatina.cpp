#include "UsuarioPlatina.h"

const static bool ultraHd = true;

UsuarioPlatina::UsuarioPlatina(const string& login,const string& senha)
:UsuarioOuro(login, senha)
{
 this->setPerfil("Familia");                            
 this->qtdPerfil = 1;       
 this->mensalidade = 26.90;    
}     
               
UsuarioPlatina::UsuarioPlatina(const string& login,const string& senha, const string& apRegistrado, const float& saldo)
:UsuarioOuro(login, senha, apRegistrado, saldo)
{      
 this->mensalidade = 26.90;    
 this->qtdFilmesConta = 0;                           
}        
