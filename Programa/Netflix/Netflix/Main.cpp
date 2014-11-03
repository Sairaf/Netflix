#include <iostream>
#include <cstdlib>
#include "Netflix.h"

int main()
{
 Usuario* usuario= new Usuario("IUGUGPUG");
 Usuario* usuario2= new Usuario[3];
 //Netflix* netflix = new Netflix("MAMSMASA")   ;
 //Netflix* netflix2 = new Netflix("21312S")   ;
 //Servico* netflix = new Netflix("21312S")   ;
 //netflix2->AdicionarUsuario(netflix2, usuario);
 usuario2 = usuario;
 cout << usuario[0];
 return EXIT_SUCCESS;
}
