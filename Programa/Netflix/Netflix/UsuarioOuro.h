#ifndef USUARIOOURO_H
#define USUARIOOURO_H

#include <cstdlib>
#include <iostream>
#include <string>
#include "Usuario.h"
#define MAXPERFIS 5
#define MAXAPARELHO 2

class UsuarioOuro : public Usuario
{
 friend ostream &operator<<(ostream&, const UsuarioOuro&);      
 protected:
          
          int qtdPerfil;
          string* perfil;

          void setPerfil(const string&);                            

 public:
          UsuarioOuro(const string& login = "Usuario",const string& senha = "senha");         
          UsuarioOuro(const UsuarioOuro&);
          UsuarioOuro(const string&,const string&,const string&,const float&,const string&);
          virtual ~UsuarioOuro(); 
                  
          string* getPerfil() const;        
                      
          virtual const inline void welcome(){cout << "bem vindo, usuario normal " << endl;};
          UsuarioOuro operator=(const UsuarioOuro&);
          virtual void AdicionarPerfil(UsuarioOuro*, const string&);
          virtual void AdicionarAparelhoAconta(UsuarioOuro*, const string&);
          
};
#endif // UsuarioOuro
