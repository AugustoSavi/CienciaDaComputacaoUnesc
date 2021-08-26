package com.unesc.rh;

public class FolhaPagamento implements Folha{

    //os alunos devem implementar esta classe
    ControlePessoal controlePessoal;
    double salarioBase;
    public FolhaPagamento(ControlePessoal controlePessoal){
        this.controlePessoal = controlePessoal;
    }

    public void adicionarSalarioInicialFuncionarios(double salarioBase) {
        Empregado[] empregados = controlePessoal.getListaEmpregados();
        for (int i = 0; i < empregados.length; i++) {
            if (empregados[i].getTipoEmpregado() == Empregado.GERENTE) {
                empregados[i].setSalario((salarioBase * 0.25) + salarioBase);
            } else if (empregados[i].getTipoEmpregado() == Empregado.BALCONISTA) {
                empregados[i].setSalario((salarioBase * 0.45) + salarioBase);
            } else if (empregados[i].getTipoEmpregado() == Empregado.VENDEDOR) {
                empregados[i].setSalario((salarioBase * 0.35) + salarioBase);
            }

        }
    }

    public void aplicarAumentoEmpregados(double percentual) {
        Empregado[] empregados = controlePessoal.getListaEmpregados();
        for (int i = 0; i < empregados.length; i++) {
            empregados[i].setSalario((empregados[i].getSalario() * percentual) + empregados[i].getSalario());

        }

    }

}
