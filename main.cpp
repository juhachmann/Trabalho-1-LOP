#include <iostream>
#include <locale.h>
#include "empresa.h"
#include "validacoes.cpp"
using namespace std;

int main() {
  char resposta;
  string nome_empr, nome;
  int i, num_func, cat, horas_trab;
  Validacoes msg;

  setlocale(LC_ALL, "Portuguese");

  cout << "- - - - - - - - - - - - - - - - - - - - - -\n- - - - - - - - - - - - - - - - - - - - - -" << endl;
  cout << endl;
  cout << "::: Programa de Folha de Pagamentos :::" << endl;
  cout << endl;
  cout << "- - - - - - - - - - - - - - - - - - - - - -\n- - - - - - - - - - - - - - - - - - - - - -" << endl;

  do {
    Empresa empr;
    
    cout << "\n\n|| Iniciando cadastro de empresa || \n" << endl;
    
    nome_empr = msg.pedir_nome_empresa();
    num_func = msg.pedir_num_funcionarios();
    empr.set_nome(nome_empr);
    empr.set_num_funcionarios(num_func);
    
    if(num_func) {   
        for (i = 1; i <= num_func; i++) {
          cout << "Cadastro nº " << i << endl;
          nome = msg.pedir_nome_func();
          horas_trab = msg.pedir_horas_trabalhadas();
          cat = msg.pedir_categoria();
          empr.add_funcionario(nome, cat, horas_trab);
          empr.incluir_contracheque();   
        }        
        empr.imprimir_folha();
    }
    
    else {
        cout << "Esta empresa não possui funcionários ativos neste mês." << endl;
    }
    
    cout << "\n\n\n";
    cout << "Deseja continuar o cadastro para outra empresa? (S/N) ";
    cin >> resposta;
    resposta = tolower(resposta);
    
  } while (resposta == 's');
    
  cout << "\n\n\nEncerrando o programa!\nObrigado por utilizar." << endl;
}