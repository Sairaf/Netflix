#ifndef DATA_H
#define	DATA_H

class Data
{
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

private:

	int mes;
	int dia;
	int ano;

	int VerificaDia( int ) const;
	
};

#endif	// DATA_H 
