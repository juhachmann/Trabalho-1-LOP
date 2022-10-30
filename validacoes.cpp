#include <iostream>
using namespace std;

class Validacoes {
public:

  string pedir_nome_empresa() {
    string nome = "";
    cout << "Qual o nome da empresa? ";
    cin.ignore();
    getline(cin, nome);
    cout << endl;
    return nome;
  };
  
  int pedir_num_funcionarios() {
    int num;  
    cout << "Quantos funcionários a empresa possui? ";
    cin >> num;
    while (num < 0) {
      cout << "Ooops! Você digitou um valor inválido.\n Entre novamente com o número de funcionários (valores positivos) : ";
      cin >> num;
    }
    cout << endl;
    return num;
  };
  
  string pedir_nome_func() {
    string nome;
    cout << "Nome do/a funcionário/a: " << endl;
    cin.ignore();
    getline(cin, nome);
    cout << endl;
    return nome;
  };
  
  int pedir_horas_trabalhadas() {
    int horas = 0;
    cout << "Horas trabalhadas no mês: " << endl;
    cin >> horas;
    while (horas < 0) {
      cout << "Ooops você digitou um valor inválido! \nHoras trabalhadas no mês (valores positivos) : " << endl;
      cin >> horas;
    }
    cout << endl;
    return horas;
  };
    
  int pedir_categoria() {
    int cat = 0;
    cout << "Categoria de salário (1, 2, 3): " << endl;
    cin >> cat;
    while(cat != 1 && cat != 2 && cat != 3) {
      cout << "Ooops você digitou um valor inválido! \nCategoria de salário (1, 2, 3): " << endl;
      cin >> cat;
    }
    cout << endl;
    return cat;
  };
};
