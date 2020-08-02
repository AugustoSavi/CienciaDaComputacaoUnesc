public class TestarContas {

    public static void main(String args[]){
        
        Conta[] contas = new Conta[3];
        
        contas[0]=new ContaCorrente("1030", 100.00);
        contas[1]=new ContaCorrente("1040", 200.00);
        contas[2]=new ContaCorrente("1050", 300.00);
        
        MovimentoConta movimento = new MovimentoConta(contas);
        movimento.movimentaConta(contas);
        movimento.imprimirSaldoContas(contas);
    }
}
