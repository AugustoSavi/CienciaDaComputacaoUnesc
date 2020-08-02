
package com.unesc.rh;

import java.util.ArrayList;


public final class RecursosHumanos implements ControlePessoal{

    private ArrayList<Empregado> empregadoslist = new ArrayList<Empregado>();

    public RecursosHumanos(){

    }

    public void contratar(Empregado empregado){
        empregadoslist.add(empregado);
    }

    public void demitir(Empregado empregado){
        for(int i = 0; i < empregadoslist.size(); i++){
            if(empregadoslist.get(i).getCodigo().equals(empregado.getCodigo())){
                empregadoslist.remove(i);
                break;
            }
        }
    }

    public Empregado[] getListaEmpregados(){
        Empregado[] result = new Empregado[empregadoslist.size()];
        empregadoslist.toArray(result);
        return result;
    }

     public void imprimirListaFuncionarios(){
         System.out.println("-------- Lista de Funcionários --------");
         for(int i = 0; i < empregadoslist.size(); i++){
             Empregado e = empregadoslist.get(i);
             System.out.println("Código: [" + e.getCodigo() + "] Nome: [" + e.getNome() + "] Salário: [" + e.getSalario() + "]");
         }
         System.out.println("---------------------------------------");
    }
}
