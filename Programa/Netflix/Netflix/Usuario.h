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
 protected:	
		string login;
		string senha;
		string* aparelhoRegistrado;
		int qtdFilmesConta;
		int qtdAparelhoRegistrado; //aparelhos aonde possa se utilizar o Netflix - Pc, console(XBOX/XONE,PS3/PS4, Wii),Tablet- registrado na conta do usuario
		Filme* filmesConta;
		float saldoConta;
        float mensalidade;
        Data inscricao(int dia = 1, int mes = 1, int ano = 2014);
        //bool hd;
       // bool ultraHd;        
        //setters
        void setLogin(const string&);
        void setSenha(const string&);
        void setSaldoConta(const float&);
        virtual void setAparelho(const string&);         
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
       
        virtual const inline void welcome(){cout << "Bem vindo, usuario normal " << endl;};
        //void InformacoesGeraisConta(Usuario*);
        void AdicionarFilmeAConta(Usuario*,  Filme&);
        void AdicionarCreditosAConta(Usuario*,const float&);
        virtual void AdicionarAparelhoAConta(Usuario*, const string&);
        Usuario operator=(const Usuario&);    
        void verificarDisponibilidadeHd(const bool&);
};




#endif // USUARIO_H
