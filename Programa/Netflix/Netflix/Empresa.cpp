#include "Empresa.h"

Empresa::Empresa(string nomeEmpresa, string cnpj)
:nomeEmpresa("DEFAULT"), cnpj("000.000.000./0000-00")
{
 this->setEndereco("N/A");
 this->qtdEnderecos = 1;
 this->numFuncionarios = 0;   
 this->nomeEmpresa = "Default";                         
}                            

Empresa::~Empresa()
{
 delete [] enderecos;                  
}                   

Empresa::Empresa( const string& nome,const string& cnpj,const int& numFuncionarios, const string& endereco)
{
 this->setCnpj(cnpj);
 this->setFuncionarios(numFuncionarios);
 this->setEndereco(endereco);                                              
 this->qtdEnderecos = 1;
 this->setNome(nome);
}                        

Empresa::Empresa(const Empresa& empresaCpy)
{
 this->cnpj = empresaCpy.cnpj;
 this->numFuncionarios = empresaCpy.numFuncionarios;                      
 this->enderecos = empresaCpy.enderecos;
 this->qtdEnderecos = empresaCpy.qtdEnderecos;
 this->nomeEmpresa = empresaCpy.nomeEmpresa;
}                       

ostream& operator<<(ostream& output, const Empresa& empresa)
{
 int i;         
 output << "Nome da Empresa: "<< empresa.getNome() << endl;         
 output << "Cnpj: " << empresa.getCnpj() <<endl;
 output << "Numero de Funcionarios: " << empresa.getNumFuncionarios() << endl;                
 output << "Endereco(s): " ;
 if(empresa.getQtdEnderecos() == 0 )
 {
  output << endl;                                
 }else               
 for(i =0; i <empresa.qtdEnderecos; i++)
 {
  output << empresa.enderecos[i] << endl;     
 }
 return output;
}         

Empresa Empresa::operator=(const Empresa& empresa)
{
 Empresa auxEmpresa;
 auxEmpresa.setNome(empresa.getNome());
 auxEmpresa.setCnpj(empresa.getCnpj());
 auxEmpresa.setFuncionarios(empresa.getNumFuncionarios());
 auxEmpresa.enderecos = empresa.enderecos;
 auxEmpresa.qtdEnderecos = empresa.qtdEnderecos;
 return auxEmpresa;       
}        

void Empresa::AdicionarEndereco(Empresa* empresa, const string& endereco)                   
{                   
 empresa->setEndereco(endereco);
 empresa->qtdEnderecos++;                      
}
     
void Empresa::setNome(const string& nome)
{
 if(nome.empty() != 0 && nome.size() < 255)
 {
  this->nomeEmpresa = nome;               
 }else
 {
  cout << "Nome invalido. Recebendo o nome de ""Default"" " << endl;
  this->nomeEmpresa = "Default";   
 }                           
}     

float CalculoGanhos(float saldo, float prejuizo)
{
 float total = (saldo - prejuizo)/10;
 return total;     
}      

void Empresa::setCnpj(const string& cnpj)
{
 if(cnpj.size() < 20 && cnpj.empty() != 0)
 {
  this->cnpj = cnpj;       
 }else
 {
  cout << "Cnpj invalido. Recebendo o cnpj de ""123.456.789/1011-12"" " << endl;
  this->cnpj = "123.456.789/1011-12";      
 }      
}     

void Empresa::setFuncionarios(const int& funcionario)
{
 if(funcionario > 0)
 {
  this->numFuncionarios = funcionario;              
 }else
 {
  cout << "Numero de funcionarios invalidos. Recebendo o numero "" 0 "" " << endl;
  this->numFuncionarios = 0;           
 }                          
}     

void Empresa::setEndereco(const string& endereco)
{
 int i;    
 string* auxEndereco = new string[this->qtdEnderecos];
 for(i = 0; i < this->qtdEnderecos;i++)
 {
  auxEndereco[i] = this->enderecos[i];     
 }            
 
 delete [] this->enderecos;
 this->enderecos = new string[this->qtdEnderecos++];
 for(i = 0; i <this->qtdEnderecos-1; i++)
 {
  this->enderecos[i] = auxEndereco[i];     
 }       
 
 this->enderecos[this->qtdEnderecos] = endereco;
 delete [] auxEndereco;
}     

string Empresa::getNome() const
{
 return this->nomeEmpresa;      
}       

string Empresa::getCnpj() const
{
 return this->cnpj;      
}       

string* Empresa::getEnderecos() const
{
 return this->enderecos;       
}        

int Empresa::getNumFuncionarios() const
{
 return this->numFuncionarios;   
}    

int Empresa::getQtdEnderecos() const
{
 return this->numFuncionarios;       
}    
