package com.unesc.rh;

public class Funcionario implements Empregado{

    //os alunos devem implementar esta classe
    String codigo, nome;
    double salario;
    int tipoEmpregado;

    public Funcionario(String codigo, String nome, int tipoEmpregado) {
        this.codigo = codigo;
        this.nome = nome;
        this.tipoEmpregado = tipoEmpregado;

    }

    public String getCodigo() {
        return codigo;
    }

    public String getNome() {
        return nome;
    }

    public double getSalario() {
        return salario;
    }

    public int getTipoEmpregado() {
        return tipoEmpregado;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

}
