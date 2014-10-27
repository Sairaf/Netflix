//Utiliza o insert/header do DevCpp aqui

#include <iostream>
#include <cstdlib>
#include <vector>

#include <string>
#include "Netflix.h"

using namespace std;

void MenuPrincipal();

int main()
{
 float download, velAtual = 0.0, ganhos;	
 int dia, mes , ano, numUsuarios;
 string login, senha, titulo, cnpj, op;	
 int opcao;
  
 Empresa* empresa = new Netflix;

 
 cout << "Digite o dia de hoje" << endl;
 cin >> dia;
 cout << "Digite o mes que estamos" << endl;
 cin >> mes;
 cout << "Digite o nosso ano" << endl;
 cin >> ano;
 Data data(dia,mes,ano);
 system("cls");
 cout <<  "Digite o cnpj da Empresa:" << endl;
 cin >> cnpj;
 empresa->setCnpj(cnpj);
 
 empresa->Welcome();
 cout << " Hoje e dia:";
 data.print();
 cout << endl;
 MenuPrincipal();
 cin >> opcao;
 system("cls");
 
  
  do
  {
   switch (opcao)
   {
    case 1:
		{
		  system("cls");
          cout << "Digite o login do usuario:" << endl;
		  cin.sync();
		  getline(cin,login);
		  cout << "Digite a senha do usuario:" << endl;
		  cin.sync();
		  cin >> senha;	  
//     	  empresa-> 
		  cout << endl;
		  cout << endl;
		  cout << "Usuario adicionado com sucesso!!!" << endl;
 		  cout << endl;						
		  system("pause");
		  system("cls");
		  MenuPrincipal();
	      cin >> opcao;		
		  cin.sync();
		 }
  break;
  case 2:
		system("cls");
		cout << "Digite o titulo do filme:" << endl;
		cin >> titulo;
		cin.sync();
//		netflix.AdicionarFilme(&netflix,titulo);
		cout << endl;
		cout << endl;
//		cout << "Total de filmes: " << netflix.getQuantidadeFilmes() <<  endl;
		cout << endl;
		system("pause");
		system("cls");
 	    MenuPrincipal();
	    cin >> opcao;		
		cin.sync();
  break;
  case 3:
        if(login.size() != 0)
		{	
//         cout << netflix << endl; 
		 system("pause");
		 system("cls");
		}else
		{
		 cout << "Erro. Não há usuario declarado" << endl;	
		} 
		system("pause");
		system("cls");
		MenuPrincipal();
	    cin >> opcao;			
		cin.sync();
  break;
  case 4:
		download = netflix.CalculoDownload(netflix.getVelMaxima(),velAtual);
		system("cls");
		cout << "CNPJ: " <<netflix.getCnpj() << endl;
		if(download > netflix.getVelMaxima())
		{
		 cout << "Velocidade de download: " << netflix.getVelMaxima()<< " MBPS"<< endl;	  
		}else
		{
		 cout << "Velocidade de download: " << download << " MBPS"<< endl;	  	  
		}
		cout << endl;
		system("pause");
		system("cls");
		MenuPrincipal();
	    cin >> opcao;	
        cin.sync();		
  break;
  case 5:
        system("cls");
        cout << "CNPJ: " <<netflix.getCnpj() << endl;
	    cout << "Digite o numero de usuarios a ser calculado o lucro" << endl;
		cin >> numUsuarios;
        ganhos = netflix.CalculoGanhos(numUsuarios, netflix.getMensalidade());
		
		if(ganhos > 0)
		{
		 cout << "Ganhos somente com o pagamento das mensalidades: "<< ganhos << "dolares. " << endl;		
		 cout << endl;
		}
		system("pause");
		system("cls");
		MenuPrincipal();
	    cin >> opcao;	
		cin.sync();
  break;
  case 0:
		system("pause");
		return 0;
  break;
  default: 
        system("cls");
        cout << "ERRO: OPERACAO INVALIDA" <<endl;
		MenuPrincipal();
	    cin >> opcao;	
		cin.sync();
  break;
  }
 }while(opcao != 0);	
 system("pause");
 return (EXIT_SUCCESS); 
 }

void MenuPrincipal()
{
 cout << "Escolha uma das opcoes abaixo" << endl;
 cout << "1 - Adicionar Usuario" << endl;
 cout << "2 - Adicionar filme a lista de um usuario" << endl;
 cout << "3 - Listar usuario e filmes deste" << endl;
 cout << "4 - Verificar velocidade de Download" << endl;	
 cout << "5 - Calcular ganhos com mensalidades com N nummero de usuarios:" << endl;
 cout << "0 - Sair" << endl;
}
