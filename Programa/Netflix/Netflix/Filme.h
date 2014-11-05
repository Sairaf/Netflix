/*isempty() = Verifica se uma string e vazia
 * atoi() = verifica se uma string e numero e pega esta parte

*/
#ifndef FILME_H
#define FILME_H

#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>

using namespace std;
using std::string;
using std::ostream;

class Filme
{
	friend ostream &operator<<(ostream&, const Filme&);
private:
	string nomeFilme;
	int numAtores;
	string sinopse;
	string diretorFilme;
	string* atores;
	const static int MAXATORES;
	float avaliacaoCritica;
    float bilheteria;
public:
	//construtores
	Filme(string nomeFilme = "Default", string sinopse = "Default");
	Filme(string, string, string, string, float, float);
	Filme(const Filme&);
	~Filme();

	//setters

	void setNomeFilme(const string&);
	void setSinopse(const string&);
	void setDiretorFilme(const string&);
	void setAvaliacaoCritica(const float&);
	void setBilheteria(const float&);
	void setAtores(const string&);

	//getters

	string  getNomeFilme() const;
	string  getSinopse() const;
	string  getDiretorFilme() const;
	float   getBilheteria() const;
	float   getAvaliacaoCritica () const;
	string* getAtores() const;



	Filme* operator=(const Filme&) ;


};

#endif // FILME_H
