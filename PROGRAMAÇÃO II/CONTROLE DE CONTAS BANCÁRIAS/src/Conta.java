public interface Conta {
    String getNumeroConta();
    double getSaldo();
    void credita(double valor);
    void debita(double valor);
}
