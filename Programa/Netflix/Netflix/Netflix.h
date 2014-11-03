#ifndef NETFLIX_H
#define NETFLIX_H
#include <vector>
#include "ServicoStreaming.h"

using namespace std;

class Netflix : public ServicoStreaming
{
 friend ostream& operator<<(ostream&, const Netflix&);
 protected:
        int numRecomendacoes;
        vector <float> saldoEmpresaAno;
        Filme* Recomendacoes;
        const float MENSALIDADE = 17.90;
 public:
        Netflix(string nome = "Netflix", string cnpj = "000.00.000/0000-00");
        Netflix(const string&,const string&,const int&,const string&,const string&,const int &,const int&, const int&,const float&, const string&);
        virtual ~Netflix();
        Netflix(const Netflix&);


        void setSaldoConta(const float&);

        float getSaldo() const;
        const int getMENSALIDADE() const;

        void AdicionarUsuario(Netflix*,const Usuario&);
        void AdicionarFilme(Netflix*, const Filme&);
        const void MediaSaldoAnual(const float&);
        Netflix& operator=(const Netflix&);
};

#endif // NETFLIX_H

