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
		int qtdFilmesConta;
		static int maxFilmes;
        Filme* filmesConta;
        Data data;
 public:

        Usuario(string login = "Usuario", string senha = "senha");
        virtual ~Usuario();
        Usuario(string, string, string, float);
        Usuario(const Usuario&);

        //setters
        void setLogin(const string&);
        void setSenha(const string&);
        void setAparelho(const string&);

        string  getLogin             () const;
        string  getSenha             () const;
        string* getAparelho          () const;
        float   getMensalidade       () const;
        int     getnumeroAparelhos   () const;
        int     getQtdFilmes         () const;

        virtual const inline void welcome(){cout << "Bem vindo, usuario normal " << endl;};

        void AdicionarFilmeAConta(Usuario*, Filme&);
        Usuario operator=(const Usuario&);

};




#endif // USUARIO_H
