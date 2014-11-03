#include <iostream>
#include "Servico.h"
#include "Netflix.h"

using namespace std;

int main(void)
{
    //Servico(string, string, int, string, string, int/*dia*/, int/*mês*/, int/*anno*/);
    Netflix * t = new Netflix("T", "Q",3,"V", "Z",1,1,1999, "V");
    Netflix * x = new Netflix("X");
    x = t;
    cout << x[0];


        //    cout << netflix[0];
}

