#ifndef USUARIO_H
#define USUARIO_H

#include <cstdlib>
#include <iostream>
#include <string>
#include "Filme.h"
#include "Data.h"

class Usuario
{
 friend ostream &operator<<(ostream&, const Usuario&);
 private:	
		string login;
		string senha;
		string* aparelhoRegistrado;
		int qtdFilmesConta;
		int qtdAparelhoRegistrado; //aparelhos aonde possa se utilizar o Netflix - Pc, console(XBOX/XONE,PS3/PS4, Wii),Tablet- registrado na conta do usuario
		Filme* filmesConta;
		float saldoConta;
        float mensalidade;
        Data inscricao(int dia = 1, int mes = 1, int ano = 2014);
protected:        
       //setters
       void setLogin(const string&);
       void setSenha(const string&);
       void setSaldoConta(const float&);
       void setAparelho(const string&);
public:

       Usuario(string login = "Usuario", string senha = "senha");
       virtual ~Usuario();
       Usuario(string, string, string, float);
       Usuario(const Usuario&);
                                   
       string  getLogin() const;
       string  getSenha() const;
       string* getAparelho () const; 
       float   getMensalidade () const;
       float   getSaldo() const;
       int     getQtdAparelho() const;
       
       
       //void InformacoesGeraisConta(Usuario*);
       void AdicionarFilmeAConta(Usuario*,  Filme&);
       void AdicionarCreditosAConta(Usuario*,const float&);
       virtual void AdicionarAparelhoAConta(Usuario*, const string&);
       Usuario operator=(const Usuario&);    
       
};


class UsuarioOuro : public Usuario
{
 friend ostream &operator<<(ostream&, const UsuarioOuro&);      
 private: 
          int maxApRegistrados;       
          int hd;          
          int qtdPerfil;
          string* perfil;
 protected:
          void setPerfil(const string&);                            
 public:
          UsuarioOuro(string login = "Usuario", string senha = "senha");         
          UsuarioOuro(const UsuarioOuro&);
          UsuarioOuro(string, string, string, float);
          virtual ~UsuarioOuro();             
       
          UsuarioOuro operator=(const UsuarioOuro&);
          void AdicionarPerfil(UsuarioOuro&, const string&);
          virtual void AdicionarAparelhoAconta(Usuario*, const string&);
          
};

class UsuarioPlatina : public UsuarioOuro
{
 friend ostream &operator<<(ostream&, const UsuarioPlatina&);           
 private:
        int maxApRegistrados;         
        string* paisesPossibiladeAcesso; 
        int ultraHd;
 public:
        UsuarioPlatina(string nome = "Usuario", string senha = "senha");
        UsuarioPlatina(const UsuarioPlatina&);
        UsuarioPlatina(string, string, string, float);
        virtual ~UsuarioPlatina();             
           
        UsuarioPlatina operator=(const UsuarioPlatina&);
        virtual void AdicionarAparelhoAconta(Usuario*, string);   
               
};

#endif // USUARIO_H
