#ifndef folhadepagamento
#define folhadepagamento

#include <iostream>
#include "empresa.h"

using namespace std;


class Contracheque {
public:
    Contracheque();
    void calcular_contracheque();
    void pass_nome(string nome_func);
    void pass_categoria(int categoria_func);
    void pass_horas_totais(int horas_trabalhadas);
    string get_nome();
    int get_categoria();
    int get_horas_totais();
    int get_horas_extra();
    float get_salario_extra();
    float get_salario_bruto();
    float get_desc_inss();
    float get_desc_ir();
    float get_salario_liquido();
    bool is_isento();
    void imprime();

private:
    string nome;
    int categoria;
    float valor_hora;
    int horas_totais;
    int horas_extra;
    float salario_extra;
    float salario_bruto;
    float desc_inss;
    float desc_ir;
    float perc_ir;
    bool isento;
    string obs_ir;
    float salario_liquido;
    void define_valor_hora ();
    void calcular_horas_extra();
    void calcular_bruto();
    float calcular_salario_extra();
    void calcular_desc_inss();
    void calcular_desc_ir();
    void calcular_salario_liquido();
};


class FolhaPagamento {
public:
    FolhaPagamento();
    void incluir_contracheque(Contracheque contra);
    void somar_horas_extra(int horas);
    void set_num_funcionarios(int num);
    void somar_valor_bruto(float bruto);
    void somar_valor_extra(float extra);
    void somar_isentos(bool isento);
    void checar_maior_salario(float salario, string nome, int cat);
    void checar_menor_salario(float salario, string nome, int cat);
    void imprime();

private:
    int num_funcionarios;
    int horas_extra;
    int horas_trabalhadas;
    float valor_total_bruto;
    float valor_total_extra;
    int total_isentos;
    float maior_salario_liquido;
    string maior_salario_nome;
    int maior_salario_categoria;
    float menor_salario_liquido;
    string menor_salario_nome;
    int menor_salario_categoria;
};


#endif