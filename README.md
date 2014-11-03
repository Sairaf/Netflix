
Requisitos funcionais
Polimorfismo

1.	Duas classes abstratas, sendo que uma classe abstrata herda da outra classe abstrata na hierarquia de classes;
2.	Cada classe abstrata deve ter pelo menos um parâmetro, o construtor vazio e o construtor default. Deve ter também um método não virtual, que não pode ser set ou get;
3.	Pelo menos três classes concretas na hierarquia de classes;
4.	Usar coerção de tipo C++ e não C, ou seja usar o static_cast para fazer o máximo de reutilização de código. 
5.	Usar um vector de classes concretas, o dynamic_cast e o typeid como indicado aqui: https://basecamp.com/2595605/projects/7018448/messages/33080741
6.	Criar uma função no arquivo do main, que aceita um ponteiro da classe genérica e mostrar o seu uso para as classes concretas;


Importante:Todos os Requisitos abaixo ainda devem ser feitos e serão avaliados



Todos os atributos e funções membros devem estar relacionados a classe
  
7.	Pelo menos 4 atributos - ok
8.	Pelo menos 4 funções membros sem incluir get e set- ok

Requisitos de implementação
3.	Todos os atributos devem ser inicializados. Fez validação de dados
4.	Três construtores, incluindo um construtor de cópia e construtor com parâmetros defaults. Verifica alocação dentro do construtor de cópia.- ok
5.	Deve ter um atributo string - ok
6.	Um atributo static. Correta modelagem dos statics? - ok
7.	Um atributo const static - ok
8.	Dois métodos constantes (não pode ser get) - ok
9.	Um array - ok
10.	Uma função inline (não pode ser get ou set) - ok
11.	Método com passagem por referência usando ponteiro - ok
12.	Método static – deve ser chamado no main 
13.	Composição com a classe Data. Fez uso do objeto criado? 
14.	O que é const deve ser const. - ok
15.	Alocação dinâmica de memória. A memória é desalocada? - ok
16.	friend Operator<< - ok
17.	Operator= - ok
18.	vector push_back - ok

Requisitos para as classes adicionais (pelo menos duas)

	Operator = - ok
	Alocação dinâmica - se houver vazamento de memória a classe toda é desconsiderada - ok
	Usar o destrutor - ok
	Construtor de cópia - ok
	Operator << friend - ok
	Um const static - ok







Requisitos herança
•	Diagrama de classes (obrigatório salvar também o png do diagrama no gitHub)
o	Herança pública - ok
o	Construtor de cópia, e sobrecargas dos operadores de atribuição (=) e << (cout << base) para a classe base e derivada - ok
o	Usar Protected acessando diretamente os atributos na classe derivada - ok
o	Alocação dinâmica de memória na classe base e derivada - ok
o	Sobrescrita de método: chamar dentro do método da classe derivada o método correspondente da classe base usando :: - ok
o	No main: criar um ponteiro da classe base para alocar memória para a classe derivada e chamar os vários métodos implementados - ok


