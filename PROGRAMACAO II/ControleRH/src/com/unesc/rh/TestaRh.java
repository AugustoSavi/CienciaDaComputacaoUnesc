package com.unesc.rh;

public class TestaRh {

    public static void main(String args[]) {

        //crie uma instância para cada um dos empregados
        Empregado rodrigo = new Funcionario("1010", "Rodrigo", Empregado.BALCONISTA);
        Empregado pedro = new Funcionario("1020", "Pedro", Empregado.GERENTE);
        Empregado joao = new Funcionario("1030", "João", Empregado.VENDEDOR);
        Empregado maria = new Funcionario("1040", "Maria", Empregado.BALCONISTA);

        ControlePessoal rh = new RecursosHumanos();

        //contrata funcionários
        rh.contratar(rodrigo);
        rh.contratar(pedro);
        rh.contratar(joao);
        rh.contratar(maria);

        //monta a folha de pagamento dos funcionários
        Folha folhaPgto = new FolhaPagamento(rh);
        folhaPgto.adicionarSalarioInicialFuncionarios(4000.00);

        //mostra a lista de funcionários contratados
        System.out.println();
        System.out.println("-- FUNCIONÁRIOS CONTRATADOS JÁ COM OS SALÁRIOS ADICIONADOS --");
        rh.imprimirListaFuncionarios();

        folhaPgto.aplicarAumentoEmpregados(30.00);

        //mostra a lista de funcionários contratados
        System.out.println();
        System.out.println("-- FUNCIONÁRIOS CONTRATADOS COM O AUMENTO DE SALÁRIO --");
        rh.imprimirListaFuncionarios();

        //demite funcionários
        rh.demitir(pedro);
        rh.demitir(maria);

        //mostra a lista de funcionários que ainda estão contratados
        System.out.println();
        System.out.println("-- FUNCIONÁRIOS DA EMPRESA APÓS A DEMISSÃO --");
        rh.imprimirListaFuncionarios();

    }
}
