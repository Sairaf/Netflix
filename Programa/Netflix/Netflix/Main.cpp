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
 int pos = 0, pos2 = 0, dia, mes, ano, escolhido = MAXFILMES+ 1;
 Data data;
 string login, senha, titulo, genero;	
 Usuario* usuariosPtr;	
 Filme* filmesPtr;
 Netflix *netflix;
//nome, vector<Filme> filmes, vector <Usuario> usuarios 
 int opcao;
 
 netflix->Welcome();
 MenuPrincipal();
 cin >> opcao;
 
 //usuariosPtr = new Usuario;
// filmesPtr = new Filme;
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
		cout << "Digite o dia da inscricao do usuario:" << endl;
		cin >> dia;
		cout << "Digite o mes inscricao do usuario:" << endl;	
		cin >> mes;
		cout << "Digite o ano inscricao do usuario:" << endl;
		cin >> ano;
		data.setDia(dia);
		data.setMes(mes);
		data.setAno(ano);
		//netflix->AdicionarUsuario(netflix, pos, login, senha, data);
		pos++;
		cout << endl;
		cout << endl;
		cout << "Usuario numero " << pos << " Adicionado" << endl;
		cout << "Total de usuarios" << netflix->getQuantidadeUsuarios() <<  endl;
		system("pause");
		system("cls");
 	    MenuPrincipal();
	    cin >> opcao;		
	break;
  case 2:
		system("cls");
		cout << "hue" << endl;
		cout << "Digite o titulo do filme:" << endl;
		cin >> titulo;
		cout << "Digite o genero do filme:" << endl;
		cin >> genero;
		cout << "Digite o dia do lancamento do filme:" << endl;
		cin >> dia;
		cout << "Digite o mes do lancamento do filme:" << endl;	
		cin >> mes;
		cout << "Digite o ano do lancamento do filme:" << endl;
		cin >> ano;
		data.setDia(dia);
		data.setMes(mes);
		data.setAno(ano);
		while((escolhido > MAXFILMES) || (escolhido < 0) )
		{
		 cout << "Digite a qual usuario voce deseja adicionar este filme" << endl;
		 cin >> escolhido;
		}
		
		
		pos2++;
		cout << endl;
		cout << endl;
		cout << "Filme numero " << pos2 << " Adicionado" << endl;
		cout << "Total de filmes" << netflix->getQuantidadeFilmes() <<  endl;
		system("pause");
		system("cls");
 	    MenuPrincipal();
	    cin >> opcao;		
  break;
  case 3:
       cout << "DATABASE WOW WOW" <<endl;        
  	   MenuPrincipal();
	   cin >> opcao;
  break;
  case 4:
        system("cls");
		download = netflix->CalculoDownload(netflix->getVelMaxima(),velAtual);
		system("cls");
		if(download > netflix->getVelMaxima())
		{
		 cout << "Velocidade de download: " << netflix->getVelMaxima()<< " MBPS"<< endl;	  
		}else
		{
		 cout << "Velocidade de download: " << download << " MBPS"<< endl;	  	  
		}
		MenuPrincipal();
	    cin >> opcao;		
  break;
  case 5:
        system("cls");
        ganhos = netflix->CalculoGanhos(netflix->getQuantidadeUsuarios(), netflix->getMensalidade());
		if(ganhos > 0)
		{
		 cout << "Ganhos somente com o pagamento das mensalidades"<< ganhos;		
		}
		MenuPrincipal();
	    cin >> opcao;		
  break;
  case 0:
        system("cls");
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
 cout << "0 - Sair" << endl;
}