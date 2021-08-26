public class MovimentoConta{
Conta[] conta;
    public MovimentoConta(Conta conta[]) {
        this.conta = conta;
    }
    


public void movimentaConta(Conta conta[]){
    
    for(int i=0;i<conta.length;i++){
        
        conta[i].credita(200.00);
    }
}
public void imprimirSaldoContas(Conta conta[]){
    
    for(int j=0;j<conta.length;j++){
        
        System.out.println("Numero Conta:"+conta[j].getNumeroConta());
        
        System.out.println("Saldo Conta:"+conta[j].getSaldo());
    
    }

}
}
