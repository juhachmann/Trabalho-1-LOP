#ifndef empresa
#define empresa
#include <iostream>
#include "folhadepagamento.h"
using namespace std;


class Funcionario { 
public:
    Funcionario();
    string get_nome();
    void set_nome(string nome_func);
    int get_categoria();
    void set_categoria(int num_categoria);
    int get_horas_trab();
    void set_horas_trab(int total_horas);
//    float get_valor_hora();
    void gerar_contracheque();
    void imprime_contracheque();
    Contracheque get_contracheque();

private:
    string nome;
    int categoria;
    int horas_trab;
    Contracheque contracheque;
};


class Empresa {
public:
    Empresa();
    string get_nome();
    void set_nome(string nome_empresa);
    int get_num_funcionarios();
    void set_num_funcionarios(int num);
    void incluir_contracheque();
    void imprimir_folha();
    void add_funcionario(string nome, int categoria, int horas_trabalhadas);

private:
    string nome;
    int num_funcionarios;
    Funcionario funcionario;
    FolhaPagamento folha;
};

#endif