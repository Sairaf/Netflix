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
 int pos = 0, pos2 = 0, dia, mes, ano;
 Data data;
 string login, senha, titulo, genero;	
 vector <Usuario> usuarios;	
 vector <Filme> filmes;
 Netflix netflix;
//nome, vector<Filme> filmes, vector <Usuario> usuarios 
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
		cout << "hue" << endl;
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
		netflix.AdicionarUsuario(netflix, pos, login, senha, data);
		pos++;
		cout << endl;
		cout << endl;
		cout << "Usuario numero " << pos << " Adicionado" << endl;
		cout << "Total de usuarios" << netflix.getQuantidadeUsuarios() <<  endl;
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
		netflix.AdicionarFilme(netflix, pos, titulo, genero, data);
		pos2++;
		cout << endl;
		cout << endl;
		cout << "Filme numero " << pos2 << " Adicionado" << endl;
		cout << "Total de filmes" << netflix.getQuantidadeFilmes() <<  endl;
		system("pause");
		system("cls");
 	    MenuPrincipal();
	    cin >> opcao;		
  break;
  case 3:
  cout << "DATABASE WOW WOW" <<endl;
  break;
  case 4:
  cout << "DATABASE WOW WOW" <<endl;
  break;
  case 5:
       cout << "DATABASE WOW WOW" <<endl;        
  	   MenuPrincipal();
	   cin >> opcao;
  break;
  case 6:
		download = netflix.CalculoDownload(netflix.getVelMaxima(),velAtual);
		system("cls");
		if(download > netflix.getVelMaxima())
		{
		 cout << "Velocidade de download: " << netflix.getVelMaxima()<< " MBPS"<< endl;	  
		}else
		{
		 cout << "Velocidade de download: " << download << " MBPS"<< endl;	  	  
		}
		MenuPrincipal();
	    cin >> opcao;		
  break;
  case 7:
        ganhos = netflix.CalculoGanhos(netflix.getQuantidadeUsuarios(), netflix.getMensalidade());
		if(ganhos > 0)
		{
		 cout << "Ganhos somente com o pagamento das mensalidades"<< ganhos;		
		}
		MenuPrincipal();
	    cin >> opcao;		
  break;
  case 8:
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
 cout << "2 - Adicionar Filme" << endl;
 cout << "3-  Listar Usuario" << endl;
 cout << "4 - Listar filmes disponiveis" << endl;
 cout << "5 - Adicionar filme a lista de um usuario" << endl;
 cout << "6 - Verificar velocidade de Download" << endl;	
 cout << "7 - Calcular ganhos com mensalidAdes:" << endl;
 cout << "8 - Limpar tela" << endl;
 cout << "0 - Sair" << endl;
}