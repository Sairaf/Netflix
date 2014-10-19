
#include "Data.h"

#include <iostream>
using std::cout;

Data::Data(int d, int m, int a) 
{
    if ( m > 0 && m <= 12 ) // validate the month
        mes = m;
    
    if ( a < 0 )
        ano = 1900;
    else
        ano = a;
   
    dia = VerificaDia(d);

}

void Data::setAno(const int& ano) 
{
 if((ano < 1849) && (ano > ANOATUAL))	
 {	 
  cout << "Ano invalido" << endl;;
 }else
 {
  this-> ano = ano;
 }
}
void Data::setDia(const int& dia) 
{
 
 if((dia < 0) && (ano > 31))	
 {	 	 
  cout << "Dia invalido"<< endl;	 
 }else
 {
  this->dia = dia;
 }
}

void Data::setMes(const int& mes) 
{
 if((mes< 0) && (mes > 12))	
 {	 
  cout << "Mes invalido" << endl;
 }else
 this->mes = mes;

}
	
int Data::getAno() const 
{
 return ano;
}
int Data::getDia() const
{
 return dia;
}
int Data::getMes() const 
{
 return mes;
}

void Data::print() const
{
   cout << dia << '/' << mes << '/' << ano;
   
}

int Data::VerificaDia(int diaTeste) const
{
    static const int diasPorMes[ 13 ] = 
       { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    if ( diaTeste > 0 && diaTeste <= diasPorMes[ mes ] )
        return diaTeste;
    
    if ( mes == 2 && diaTeste == 29 && ( ano % 400 == 0 ||
            ( ano % 4 == 0 && ano % 100 != 0 ) ) )
        return diaTeste;
    
    cout << "Dia invalido (" << diaTeste << ") configurado para 1.\n";
    return 1; 

    
}

ostream &operator<<(ostream& output, const Data& dt)
{
 output << dt.getDia() << '/' << dt.getMes() << '/' << dt.getAno();
 return output; 	
}

Data Data::operator=(const Data& dt) const
{
 Data aux;
 aux.setDia(dt.getDia());	
 aux.setMes(dt.getMes());
 aux.setAno(dt.getAno());
 return aux;
}