#include <iostream>
#include "empresa.h"
#include "folhadepagamento.h"
using namespace std;

Funcionario::Funcionario() { // OBS: a classe funcionário está redundante, ela só passa e pega valores da classe contracheque. Mas vou deixar assim só pelo exercício. 
  nome = "";
  categoria = 0;
  horas_trab = 0;
};

Contracheque Funcionario::get_contracheque() {
  return contracheque;
}

string Funcionario::get_nome() {
  return nome;
};

void Funcionario::set_nome(string nome_func) {
  nome = nome_func;
};

int Funcionario::get_categoria() {
  return categoria;
};

void Funcionario::set_categoria(int num_categoria) {
  categoria = num_categoria;
};

int Funcionario::get_horas_trab() {
  return horas_trab;
};

void Funcionario::set_horas_trab(int total_horas) {
  horas_trab = total_horas;
};

void Funcionario::gerar_contracheque() {
    contracheque.pass_nome(nome);
    contracheque.pass_categoria(categoria);
    contracheque.pass_horas_totais(horas_trab);
    contracheque.calcular_contracheque();
};

void Funcionario::imprime_contracheque() {
  contracheque.imprime();
};


Empresa::Empresa() {
  nome = "";
  num_funcionarios = 0;
  Funcionario funcionario;
};

string Empresa::get_nome() {
  return nome;
};

void Empresa::set_nome(string nome_empresa) {
  nome = nome_empresa;
};

int Empresa::get_num_funcionarios() {
  return num_funcionarios;
};

void Empresa::set_num_funcionarios(int num) {
  num_funcionarios = num;
};

void Empresa::add_funcionario(string nome, int categoria, int horas_trabalhadas) {
  funcionario.set_nome(nome);
  funcionario.set_categoria(categoria);
  funcionario.set_horas_trab(horas_trabalhadas);
  funcionario.gerar_contracheque();
  funcionario.imprime_contracheque();
};

void Empresa::incluir_contracheque() {
  folha.incluir_contracheque(funcionario.get_contracheque());
}

void Empresa::imprimir_folha() {
  folha.imprime();
}

