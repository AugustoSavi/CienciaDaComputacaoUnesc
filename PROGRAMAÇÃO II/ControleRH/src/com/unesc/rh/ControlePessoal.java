package com.unesc.rh;

public interface ControlePessoal {

    public void contratar(Empregado empregado);

    public void demitir(Empregado empregado);

    public Empregado[] getListaEmpregados();

    public void imprimirListaFuncionarios();

}
