#include <iostream>
#include "Servico.h"
#include "ServicoStreaming.h"
#include "Netflix.h"
#include "Usuario.h"
#include "Filme.h"

using namespace std;

void IdentificarServico(Servico* s)
{
 if(typeid(*s).name() == typeid(Netflix). name)	
 {
  cout << "Este servico e o Netflix" << endl;	 
 }//else if(typeid(*s).name() == typeid(Netflix). name)	
}	

int main(void)
{
    Servico* sv = new Netflix("RAITONINGUE");
	



        //    cout << netflix[0];
}

