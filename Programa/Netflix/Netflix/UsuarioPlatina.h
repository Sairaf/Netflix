#ifndef USUARIOPLATINA_H
#define USUARIOPLATINA_H

#include <cstdlib>
#include <iostream>
#include <string>
#include "UsuarioOuro.h"
#define MAXPAISES 5;

class UsuarioPlatina : public UsuarioOuro
{
 friend ostream &operator<<(ostream&, const UsuarioPlatina&);           
 private:
        int qtdPaises; 
        string* paisesPossibiladeAcesso; 

 protected:          
        void setPais(const string&);                                                      
        virtual void setAparelho(const string&);         
 public:
        UsuarioPlatina(const string& nome = "Usuario",const string& senha = "senha");
        UsuarioPlatina(const UsuarioPlatina&);
        UsuarioPlatina(const string&,const string&,const string&,const float&);
        virtual ~UsuarioPlatina();             

        const inline void welcome(){cout << "Bem vindo, usuario platina " << endl;};
        UsuarioPlatina operator=(const UsuarioPlatina&);
        void AdicionarPerfil(UsuarioPlatina*, const string&);
        void AdicionarAparelhoAconta(UsuarioPlatina*, string);   
               
};

#endif
