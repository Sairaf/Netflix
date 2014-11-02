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
//atualizar o diagrama de classes
//Talvez trocar as variaveis
		int qtdFilmesConta;
		int numeroAparelhos; //aparelhos aonde possa se utilizar o Netflix - Pc, console(XBOX/XONE,PS3/PS4, Wii),Tablet- registrado na conta do usuario
        Filme* filmesConta;
		float saldoConta;
        Data data;
 public:

        Usuario(string login = "Usuario", string senha = "senha");
        virtual ~Usuario();
        Usuario(string, string, string, float);
        Usuario(const Usuario&);

        //setters
        void setLogin(const string&);
        void setSenha(const string&);
        void setSaldoConta(const float&);
        void setAparelho(const string&);

        string  getLogin             () const;
        string  getSenha             () const;
        string* getAparelho          () const;
        float   getMensalidade       () const;
        float   getSaldo             () const;
        int     getnumeroAparelhos   () const;
        int     getQtdFilmes         () const;

        virtual const inline void welcome(){cout << "Bem vindo, usuario normal " << endl;};
        //void InformacoesGeraisConta(Usuario*);
        void AdicionarFilmeAConta(Usuario*, Filme&);
        void AdicionarCreditosAConta(Usuario*,const float&);
        void AdicionarAparelhoAConta(Usuario*, const string&);
        Usuario* operator=(const Usuario&);
};




#endif // USUARIO_H
