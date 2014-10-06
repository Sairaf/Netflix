#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "Netflix.h"

using namespace std;

void MenuPrincipal();

int main(int argc, char** argv)
{
 float download, velAtual = 0.0, ganhos;	
 int pos = 0, pos2 = 0, numUsuarios;
 Data data;
 string login, senha, titulo, cnpj;	
 Netflix netflix(cnpj, login, senha);

 int opcao;
 
 netflix.Welcome();
 MenuPrincipal();
 cin >> opcao;
 

  do
  {
   switch (opcao)
   {
    case 1:
		system("cls");

		cout << "Digite o login do usuario:" << endl;
		cin >> login;
		cout << "Digite a senha do usuario:" << endl;
		cin >> senha;
		netflix.AdicionarUsuario(&netflix,login, senha);
		cout << endl;
		cout << endl;
		cout << "Usuario adicionado com sucesso!!!" << endl;
		cout << endl;
		system("pause");
		system("cls");
 	    MenuPrincipal();
	    cin >> opcao;		
	break;
  case 2:
		system("cls");
		cout << "Digite o titulo do filme:" << endl;
		cin >> titulo;
		netflix.AdicionarFilme(&netflix,titulo, pos);
		pos++;
		cout << endl;
		cout << endl;
		cout << "Total de filmes: " << netflix.getQuantidadeFilmes() <<  endl;
		cout << endl;
		system("pause");
		system("cls");
 	    MenuPrincipal();
	    cin >> opcao;		
  break;
  case 3:
        if(login.size() != 0)
		{	
         netflix.ListarUsuario(&netflix, pos);
		 system("pause");
		 system("cls");
 	     MenuPrincipal();
	     cin >> opcao;			
		}else
		{
		 cout << "Erro. Não há usuario declarado" << endl;	
		} 
		system("pause");
		system("cls");
		MenuPrincipal();
	    cin >> opcao;			
  break;
  case 4:
		download = netflix.CalculoDownload(netflix.getVelMaxima(),velAtual);
		system("cls");
		
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
  break;
  case 5:
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
  break;
  case 6:
        system("cls");
 	    MenuPrincipal();
	    cin >> opcao;			    	
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
  break;
  }
 }while(opcao != 0);	 
 system("pause");
 return 0; 
}

void MenuPrincipal()
{
 cout << "Escolha uma das opcoes abaixo" << endl;
 cout << "1 - Adicionar Usuario" << endl;
 cout << "2 - Adicionar filme a lista de um usuario" << endl;
 cout << "3 - Listar usuario e filmes deste" << endl;
 cout << "4 - Verificar velocidade de Download" << endl;	
 cout << "5 - Calcular ganhos com mensalidades com N nummero de usuarios:" << endl;
 cout << "6 - Limpar tela" << endl;
 cout << "0 - Sair" << endl;
}