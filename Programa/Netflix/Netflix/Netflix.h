#ifndef NETFLIX_H
#define NETFLIX_H
#include <vector>
#include "Servico.h"

using namespace std;

class Netflix : public Servico
{
 friend ostream& operator<<(ostream&, const Netflix&);
 protected:
        float media;
        int contadorSaldo;
        int numUsuarios;
        vector <float> saldoEmpresaAno;
        Usuario* listaUsuarios;
        const static float MENSALIDADE;

  public:
        Netflix(string nome = "Netflix", string cnpj = "000.00.000/0000-00");
        Netflix(const string&,const string&,const int&,const string&,const string&,const int &,const int&, const int&, const string&);
        Netflix(const Netflix&);
        ~Netflix();


        void setSaldoConta(const float&);
        
		 string* getLista () const;
		 int getNumUsuarios () const;
        float getMedia () const;
        const float getMENSALIDADE() const;

        inline const void Welcome()
        {
         cout << "Bem vindo ao teste: " /*<< this->getNome()*/ << endl << endl;
        };

        void CadastrarUsuario(Netflix*,const Usuario&);
        const void MediaSaldoAnual(Netflix* );
        Netflix* operator=(const Netflix&);
};

#endif // NETFLIX_H

