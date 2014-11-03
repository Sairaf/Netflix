#include "Usuario.h"

// Assumindo que todos os usuarios são usuarios normais
int Usuario::maxFilmes = 10;

Usuario::Usuario(string login, string senha)
:login(login), senha(senha)
{
 this->qtdFilmesConta = 0;
 //this->setSaldoConta(0.00);
 this->filmesConta = new Filme;
}

Usuario::Usuario(string login, string senha, string apRegistrado, float saldo)
{
 this->qtdFilmesConta = 0;
 this->setLogin(login);
 this->setSenha(senha);
// this->setSaldoConta(saldo);
}

Usuario::~Usuario()
{
 if(this->qtdFilmesConta != 0)
    delete [] filmesConta;
}


Usuario::Usuario(const Usuario& usuarioCpy)
{
 int cont;
 this->login = usuarioCpy.login;
 this->senha = usuarioCpy.senha;
 this->filmesConta = usuarioCpy.filmesConta;
 this->qtdFilmesConta = usuarioCpy.qtdFilmesConta;//**
//this->saldoConta = usuarioCpy.saldoConta;
 for(cont = 0; cont < qtdFilmesConta; cont++)
 {
  this->filmesConta[cont] = usuarioCpy.filmesConta[cont];
 }
}

ostream &operator<<(ostream& output, const Usuario& usuario)
{
 int cont;
 output << "Login: " << usuario.getLogin() << endl;
 output << "Senha: " << usuario.getSenha() << endl;
 //output << "Credito na sua conta: " << usuario.getSaldo() << endl;
 output << endl;
 if(usuario.filmesConta == NULL)
 {
  output << "Problema na alocacao de memoria" <<  endl;
 }else if(usuario.qtdFilmesConta > 0)
 {
  output << endl;
  output << "Filmes em sua conta: "<< endl;
  output << endl;
  for(cont = 0; cont < usuario.qtdFilmesConta; cont++)
  {
   output <<"==========================" << endl;
   output <<usuario.filmesConta[cont] <<  endl;
   output <<"==========================" << endl;
  }
 }else
 {
  output << "Nao ha filmes registrado nesta conta" << endl;
 }
 cout << endl;
 return output;
}

Usuario Usuario::operator=(const Usuario& usuario)
{
 int contador;
 this->setLogin(usuario.getLogin());
 this->setSenha(usuario.getSenha());
 cout <<"TESTE" << endl;
// auxUsuario->setSaldoConta(usuario.getSaldo());
 this->qtdFilmesConta = usuario.qtdFilmesConta;//**
 if(this->filmesConta == 0)
 {
  this->filmesConta = 0;
 }else if(this->qtdFilmesConta == 1)
 {
  this->filmesConta = new Filme();
  this->filmesConta[0] = usuario.filmesConta[0];
 }else
 {
  this->filmesConta = new Filme[this->qtdFilmesConta];
  for(contador = 0; contador < this->qtdFilmesConta;contador++)
 {
  this->filmesConta[contador] = usuario.filmesConta[contador];
 }

 }

 return *this;
}

void Usuario::AdicionarFilmeAConta(Usuario* usuario, Filme& filme)
{
 int cont;
 if(qtdFilmesConta < maxFilmes)
 {

 Filme* auxFilme;
 auxFilme =  new Filme[usuario->qtdFilmesConta];
 if(usuario->getQtdFilmes() == 0)
 {
  ++usuario->qtdFilmesConta;
  usuario->filmesConta[qtdFilmesConta-1]= filme;
 }else if(usuario->getQtdFilmes() > 0)
 {
 for(cont = 0; cont <usuario->qtdFilmesConta; cont++)
 {
  auxFilme[cont] = usuario->filmesConta[cont];
 }
  delete usuario->filmesConta;
  this->filmesConta = new Filme[++usuario->qtdFilmesConta];
  for(cont = 0; cont <usuario->qtdFilmesConta-1; cont++)
  {
   usuario->filmesConta[cont] = auxFilme[cont];
  }

   usuario->filmesConta[qtdFilmesConta-1] = filme;
   delete [] auxFilme;
  }

 }else
 {
  cout << "Limite de filmes alcancado"    << endl;
 }

}

void Usuario::setLogin(const string& login)
{
 if(login.empty() == false && login.size() < 50)
 {
  this->login = login;
 }else
 {
  cout << "Login invalido. Recebendo o login ""Usuario"" " << endl;
  this->login = "Usuario";
 }
}



void Usuario::setSenha(const string& senha)
{
 if(senha.size() <= 50 && senha.empty() == false)
 {
  this->senha= senha;
 }else
 {
  cout << "Senha invalido. Recebendo a senha ""Senha"" " << endl;
  this->senha = "Senha";
 }
}


string Usuario::getLogin() const
{
 return this->login;
}

string Usuario::getSenha () const
{
 return this->senha;
}


int Usuario::getQtdFilmes() const
{
 return this->qtdFilmesConta;
}
