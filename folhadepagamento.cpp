#include <iostream>
#include "empresa.h"

using namespace std;


Contracheque::Contracheque() {
  nome = "";
  categoria = 0;
  valor_hora = 0.0;
  horas_totais = 0;
  horas_extra = 0;
  salario_extra = 0.0;
  salario_bruto = 0.0;
  desc_inss = 0.0;
  desc_ir = 0.0;
  perc_ir = 0.0;
  isento = true;
  obs_ir = "";
  salario_liquido = 0.0;
}

void Contracheque::calcular_contracheque() {
  define_valor_hora();
  calcular_horas_extra();
  calcular_bruto(); 
  calcular_salario_extra();
  calcular_desc_inss();
  calcular_desc_ir();
  calcular_salario_liquido();
}

bool Contracheque::is_isento() {
  return isento;
}

void Contracheque::pass_nome(string nome_func) {
  nome = nome_func;
}

void Contracheque::pass_categoria(int categoria_func) {
  categoria = categoria_func;
}

void Contracheque::pass_horas_totais(int horas_trabalhadas) {
  horas_totais = horas_trabalhadas;
}

string Contracheque::get_nome() {
  return nome;
};
 
int Contracheque::get_categoria() {
  return categoria;
}

int Contracheque::get_horas_totais() {
  return horas_totais;
}

int Contracheque::get_horas_extra() {
  return horas_extra;
}

float Contracheque::get_salario_extra() {
  return salario_extra;
}

float Contracheque::get_salario_bruto() {
  return salario_bruto;
}

float Contracheque::get_desc_inss() {
  return desc_inss;
}

float Contracheque::get_desc_ir() {
  return desc_ir;
}

float Contracheque::get_salario_liquido() {
  return salario_liquido;
}

void Contracheque::imprime() {
  cout << fixed;
  cout.precision(2);
  cout << endl;
  cout << "CONTRACHEQUE DO/A FUNCIONÁRIO/A:" << endl;
  cout << endl;
  cout << "Nome: " << nome << endl;
  cout << endl;
  cout << "Categoria: " << categoria << "\tValor/Hora: R$ " << valor_hora << endl;
  cout << "Horas Trabalhadas: " << horas_totais << endl;
  cout << endl;
  cout << "SALÁRIO BRUTO:" << endl;
  cout << "+ Salário Bruto (horas normais): \tR$ " << salario_bruto - salario_extra << endl;
  cout << "+ Adicional Horas Extra (" << horas_extra << "hrs): \tR$ " << salario_extra << endl;
  cout << "= Salário Bruto Total: \t\t\tR$ " << salario_bruto << endl;
  cout << endl;
  cout << "DESCONTOS" << endl;
  cout << "- INSS (8%): \t\tR$ " << desc_inss << endl;
  cout.precision(0);
  cout << "- IRRF (" << perc_ir*100 << "%):\t\tR$ ";
  cout.precision(2);
  cout << desc_ir << " " << obs_ir << endl;
  cout << "= Total Descontos: \tR$ " << desc_inss + desc_ir << endl;
  cout << endl;
  cout << "SALÁRIO LÍQUIDO: \tR$: " << salario_liquido << endl;
  cout << endl;
}

void Contracheque::define_valor_hora () {
  switch(categoria) {
    case 1:
      valor_hora = 15.0;
      break;
    case 2:
      valor_hora = 30.0;
      break;
    case 3:
      valor_hora = 45.0;
      break;
  }
}

void Contracheque::calcular_horas_extra() {
  if (horas_totais > 160) {
    horas_extra =  horas_totais - 160;
  }
  else {
    horas_extra = 0;
  }
}

void Contracheque::calcular_bruto() {
  salario_bruto = (horas_totais * valor_hora) + calcular_salario_extra();
}

float Contracheque::calcular_salario_extra() {
  if (horas_extra == 0) {
    salario_extra = 0;
  }
  else {
    salario_extra =  horas_extra * valor_hora * 0.5;
  }
  return salario_extra;
}

void Contracheque::calcular_desc_inss() {
  desc_inss = salario_bruto * 0.08f;
}

void Contracheque::calcular_desc_ir() {
  float base = salario_bruto - desc_inss;
  if (base <= 2500.0f) {
    isento = true;
    perc_ir = 0.0f;
    obs_ir = "(ISENTO)";
  }
  else {
    isento = false;
    obs_ir = "";
    if (base <= 5000.0f) {
      perc_ir = 0.1f;
    }
    else if (base <= 8000.0f) {
      perc_ir = 0.2f;
    }
    else {
      perc_ir = 0.3f;
    }
  }
  desc_ir = base * perc_ir;
}

void Contracheque::calcular_salario_liquido() {
  salario_liquido = salario_bruto - desc_inss - desc_ir;
}


FolhaPagamento::FolhaPagamento() {    
  num_funcionarios = 0;
  horas_extra = 0;
  horas_trabalhadas = 0;
  valor_total_bruto = 0.0;
  valor_total_extra = 0.0;
  total_isentos = 0;
  maior_salario_liquido = 0.0;
  maior_salario_nome = "";
  maior_salario_categoria = 0;
  menor_salario_liquido = 1000000;
  menor_salario_nome = "";
  menor_salario_categoria = 0;};


void FolhaPagamento::incluir_contracheque(Contracheque contra) {
  num_funcionarios++;
  somar_horas_extra(contra.get_horas_extra());
  somar_valor_bruto(contra.get_salario_bruto());
  somar_valor_extra(contra.get_salario_extra());
  somar_isentos(contra.is_isento());
  float liq = contra.get_salario_liquido();
  string nome = contra.get_nome();
  int cat = contra.get_categoria();
  checar_maior_salario(liq, nome, cat);
  checar_menor_salario(liq, nome, cat);
}


void FolhaPagamento::somar_horas_extra(int horas) {
  horas_extra += horas;  
}


void FolhaPagamento::set_num_funcionarios(int num) {
  num_funcionarios = num;
}


void FolhaPagamento::somar_valor_bruto(float bruto) {
  valor_total_bruto += bruto;
}


void FolhaPagamento::somar_valor_extra(float extra) {
  valor_total_extra += extra;
}


void FolhaPagamento::somar_isentos(bool isento) {
  if (isento) {
    total_isentos++;
  }
}


void FolhaPagamento::checar_maior_salario(float salario, string nome, int cat) {
  if (salario >= maior_salario_liquido) {
    maior_salario_liquido = salario;
    maior_salario_nome = nome;
    maior_salario_categoria = cat;
  }
}


void FolhaPagamento::checar_menor_salario(float salario, string nome, int cat) {
  if (salario <= menor_salario_liquido) {
    menor_salario_liquido = salario;
    menor_salario_nome = nome;
    menor_salario_categoria = cat;
  }
}


void FolhaPagamento::imprime() {
  cout << fixed;
  cout.precision(2);
  cout << endl;
  cout << "- - - - - - - - - - - - - - - - - -" << endl;
  cout << "FOLHA DE PAGAMENTOS DA EMPRESA" << endl;
  cout << "- - - - - - - - - - - - - - - - - -" << endl;
  cout << endl;
  cout << "Total de Funcionários: " << num_funcionarios << endl;
  cout << endl;
  cout << "Total de Pagamentos (Bruto): \tR$ " << valor_total_bruto << endl;
  cout << "Média de Pagamentos (Bruto): \tR$ " << (valor_total_bruto / num_funcionarios) << endl;
  cout << endl;
  cout << "Adicionais de Hora Extra:" << endl;
  cout << "Total: R$ " << valor_total_extra << "\tPercentual: " << ((valor_total_extra*100.0)/valor_total_bruto) << "%" << endl;
  cout << endl;
  cout << "Nº de funcionários isentos de IRRF: " << endl;
  cout << "Total: " << total_isentos << "\tPercentual: " << (total_isentos*100)/num_funcionarios << "%" << endl;
  cout << endl;
  cout << "++ O maior salário líquido foi pago a/o funcionário/a " << maior_salario_nome << " (categoria " << maior_salario_categoria << "), no valor de R$ " << maior_salario_liquido << endl;
  cout << endl;
  cout << "-- O menor salário líquido foi pago a/o funcionário/a " << menor_salario_nome << " (categoria " << menor_salario_categoria << "), no valor de R$ " << menor_salario_liquido << endl;
  cout << endl; 
  cout << "- - - - - - - - - - - - - - - - - -" << endl;
  cout << "Fim da folha de pagamentos." << endl;
  cout << "- - - - - - - - - - - - - - - - - -" << endl;
}
