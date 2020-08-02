package com.unesc.rh;

public interface Empregado {

    //tipos de empregados
    public static final int GERENTE = 1;
    public static final int BALCONISTA = 2;
    public static final int VENDEDOR = 3;

    public int getTipoEmpregado();//deve ser retornado GERENTE, BALCONISTA ou VENDEDOR
    public String getCodigo();
    public String getNome();
    public double getSalario();
    public void setSalario(double salario);
}
