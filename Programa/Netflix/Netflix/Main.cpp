#include <iostream>
#include "Servico.h"
#include "ServicoStreaming.h"
#include "Netflix.h"
#include "Usuario.h"
#include "Filme.h"

using namespace std;
/*
void IdentificarServico(Servico* s)
{
 if(typeid(*s).name() == typeid(Netflix). name)	
 {
  cout << "Este servico e o Netflix" << endl;	 
 }//else if(typeid(*s).name() == typeid(Netflix). name)	
}	
*/
int main(void)
{
 Servico* t = new ServicoStreaming("P", "T");
 
ServicoStreaming * strPtr = dynamic_cast<ServicoStreaming *>(t);
if (strPtr != 0) 
{
 cout << strPtr[0];
}


  system("pause");
  return EXIT_SUCCESS;
}

