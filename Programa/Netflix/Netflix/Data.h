#ifndef DATA_H
#define	DATA_H

class Data
{
public:
   //construtor
	Data( int = 1, int = 1, int = 1900 );
	
	void print() const;
	int VerificaDia( int ) const;
private:

	int mes;
	int dia;
	int ano;

	//int VerificaDia( int ) const;
	
};

#endif	// DATA_H 
