public class ContaCorrente implements Conta {
    private String numeroConta;
    private double saldo;
    Conta[] conta = new Conta[3];
    
    public ContaCorrente(String numeroConta, double saldo) {
        this.numeroConta = numeroConta;
        this.saldo = saldo;
    }

    public void setNumeroConta(String numeroConta){
        this.numeroConta = numeroConta; 
    }

    @Override
    public String getNumeroConta(){
        return this.numeroConta; 
    }

    public void setNumeroConta(double saldo){
        this.saldo = saldo; 
    }

    @Override
    public double getSaldo(){
        return this.saldo; 
    }


    public void credita(double valor){ 
        saldo =saldo+valor;
        
    }
    
    public void debita(double valor) {
     saldo=saldo-valor;
    
    }
    
    
}
