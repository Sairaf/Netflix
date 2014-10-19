#ifndef DATA_H
#define	DATA_H
#include <iostream>
#define ANOATUAL 2014

using namespace std;
class Data
{
friend ostream &operator<<(ostream &, const Data &); 	
	
public:
   //construtor
	Data( int = 1, int = 1, int = 1900 );
	
	//setters
	
	void setDia(const int&);
	void setMes(const int&);
	void setAno(const int&);
	
	//getters
	
	int getDia() const;
	int getMes() const;
	int getAno() const;
	
	void print() const;
	int VerificaDia( int ) const;
    Data operator=(const Data&) const;

private:

	int mes;
	int dia;
	int ano;

	
	
};

#endif	// DATA_H 
