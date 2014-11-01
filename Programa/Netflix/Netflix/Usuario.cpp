#include "Usuario.h"

// Assumindo que todos os usuarios são usuarios normais

Usuario::Usuario(string login, string senha)
:login(login), senha(senha)
{
 this->numeroAparelhos= 0;
 this->qtdFilmesConta = 0;
 this->setSaldoConta(0.00);
 this->aparelhoRegistrado = new string;
 this->aparelhoRegistrado[0] = "Computador";
 this->filmesConta = new Filme;
}



Usuario::Usuario(string login, string senha, string apRegistrado, float saldo)
{
 this->numeroAparelhos= 0;
 this->qtdFilmesConta = 0;
 this->setLogin(login);
 this->setSenha(senha);
 this->setSaldoConta(saldo);
 this->setAparelho(apRegistrado);

}

Usuario::~Usuario()
{
 delete [] aparelhoRegistrado;
 delete [] filmesConta;
}


Usuario::Usuario(const Usuario& usuarioCpy)
{
 int cont;
 this->login = usuarioCpy.login;
 this->senha = usuarioCpy.senha;
 this->filmesConta = usuarioCpy.filmesConta;
 this->numeroAparelhos= usuarioCpy.numeroAparelhos;//*
 this->qtdFilmesConta = usuarioCpy.qtdFilmesConta;//**
 this->saldoConta = usuarioCpy.saldoConta;
 for(cont = 0; cont < numeroAparelhos; cont++)
 {
  this->setAparelho(usuarioCpy.aparelhoRegistrado[cont]);
 }
 for(cont = 0; cont < numeroAparelhos; cont++)
 {
  this->filmesConta[cont] = usuarioCpy.filmesConta[cont];
 }
}

ostream &operator<<(ostream& output, const Usuario& usuario)
{
 int cont;
 output << "Login: " << usuario.getLogin() << endl;
 output << "Senha: " << usuario.getSenha() << endl;
 output << "Credito na sua conta: " << usuario.getSaldo() << endl;
 output << endl;
 if(usuario.aparelhoRegistrado == NULL)
 {
  output << "Problema na alocacao de memoria" <<  endl;
 }else  if(usuario.numeroAparelhos > 0)
 {
  output << "Aparelhos registrados em sua conta: " << endl;
  for(cont = 0; cont < usuario.numeroAparelhos; cont++)
  {
   output <<"=========================="     << endl;
   output <<usuario.aparelhoRegistrado[cont] <<  endl;
   output <<"=========================="     << endl;
  }
 }else
 {
  output << "Nao ha aparelhos registrados nesta conta" << endl;
 }

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

Usuario* Usuario::operator=(const Usuario& usuario)
{
 int contador;
 Usuario *auxUsuario;
 auxUsuario->setLogin(usuario.getLogin());
 auxUsuario->setSenha(usuario.getSenha());
 auxUsuario->setSaldoConta(usuario.getSaldo());
 auxUsuario->numeroAparelhos= usuario.numeroAparelhos;//*
 auxUsuario->qtdFilmesConta = usuario.qtdFilmesConta;//**
 for(contador = 0; contador < numeroAparelhos; contador++)
 {
  auxUsuario->aparelhoRegistrado[contador] = usuario.aparelhoRegistrado[contador];
 }

 for(contador = 0; contador < qtdFilmesConta;contador++)
 {
  auxUsuario->filmesConta[contador] = usuario.filmesConta[contador];
 }

 return auxUsuario;
}

void Usuario::AdicionarCreditosAConta(Usuario* usuario,const float& saldo)
{
 usuario->setSaldoConta(usuario->saldoConta + saldo);
}



void Usuario::AdicionarAparelhoAConta(Usuario* usuario, const string& aparelho)
{
 usuario->setAparelho(aparelho);
}


void Usuario::AdicionarFilmeAConta(Usuario* usuario, Filme& filme)
{
 int cont;
 Filme* auxFilme;
 auxFilme =  new Filme[usuario->qtdFilmesConta];
 if(usuario->getQtdFilmes() == 0)
 {
 // cout << "Teste de filme: "<<filme.getNomeFilme() << endl << endl;
  ++usuario->qtdFilmesConta;
/*erro*/  usuario->filmesConta[qtdFilmesConta-1]= filme;
  cout << "Le saída: " << endl << usuario->filmesConta[0] << endl ;
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
 }
   delete [] auxFilme;

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

void Usuario::setSaldoConta(const float& saldo)
{
 if(saldo >= 0)
 {
  this->saldoConta = saldo;
 }else
 {
  cout << "Valor invalido para o saldo. Este sera definido como ""0"" " << endl;
  this->saldoConta = 0;
 }
}

void Usuario::setAparelho(const string& aparelho)
{
 int cont;
 string* auxAparelhos = new string[this->numeroAparelhos];
 for(cont = 0; cont <this->numeroAparelhos ; cont++)
 {
  auxAparelhos[cont] = this->aparelhoRegistrado[cont];
 }
 delete [] this->aparelhoRegistrado;
 this->aparelhoRegistrado = new string[++this->numeroAparelhos];
 for(cont = 0; cont < this->numeroAparelhos-1; cont++)
 {
  this->aparelhoRegistrado[cont] = auxAparelhos[cont];
 }
 this->aparelhoRegistrado[this->numeroAparelhos-1] = aparelho;
 delete [] auxAparelhos;
}

string Usuario::getLogin() const
{
 return this->login;
}

string Usuario::getSenha () const
{
 return this->senha;
}

float Usuario::getSaldo () const
{
 return this->saldoConta;
}

int Usuario::getnumeroAparelhos () const
{
 return this->numeroAparelhos;
}

int Usuario::getQtdFilmes() const
{
 return this->qtdFilmesConta;
}
