### Este é um primeiro exercício de Orientação a Objetos em C++

### Log
* 28/10/2022 - Finalizei a versão 1
* 29/10/2022 - Arrumei um bug, em que o objeto Empresa estava sendo criado fora do escopo correto, causando erro nos dados. 
* 30/10/2022 - Permite entrada de nomes com espaço. Usando cin.ignore() e getline(cin, nome). Testei getchar() para pedir que o usuário pressione enter para nova ação, mas às vezes come uma letra da entrada de dados, então não entendi como usar.


### Problemas e considerações:

- [ ] Validação de tipos: ainda não consegui pesquisar e entender. O programa está quebrando quando insere um valor de tipo errado. A validação como está implementada agora ainda não dá conta destas situações. Ver Tratamento de Erros (try, catch)


- [ ] Como melhorar a modelagem de classes e o relacionamento entre elas? A modelagem das classes ainda não está satisfatória. Vou revisitar na medida que for aprendendo mais em ANS.

      
- [ ] Dar nome para classes e métodos é uma ARTE que eu não domino. Como melhorar isto?


- [ ] Quais são as melhores formas de realizar a comunicação entre os objetos? Passar argumentos OU chamar métodos? O que define isso? 


- [ ] Como inicializar objetos no arquivo Header passando argumentos para o construtor? Não consegui fazer isto..
Exemplo: 
Gostaria de inicializar um objeto com os valores dele todos zerados. Como em Funcionario funcionario(" ", 0, 0) --> para um construtor Funcionario(string nome, int cat, int horas_trabalhadas). 
Não consegui fazer isso. 


- [ ] Como ver os objetos que estão sendo criados e se eles estão sendo destruídos ou continuam ocupando espaço na memória? (Isto é importante e ainda não consegui ver).


- [ ] VETORES! Como trabalhar com vetores em C++? Como usar vetores como parâmetros de funções? E como retornar vetores em funções? Não consegui. 


- [ ] Existem vetores de tipos misturados em C++? Exemplo: ["ju", 2, 3.14]
Eu acho que não existe.. Como fazer isto? Acho que teria que criar uma classe especializada para isto =D (não, obrigada, ainda não)


- [ ] Objetivo em C++ : conseguir usar a manipulação de registros de memória! 
