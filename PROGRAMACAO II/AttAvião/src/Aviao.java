public class Aviao {
  private int nrPassageiros;
  private float velocidadeAtual;
  
  public void informarPassageiros(int passageiros){
  nrPassageiros = passageiros; }
  
 public void acelerar(){
 velocidadeAtual++;
 }
 public void mostrarDados(){
 System.out.println("Veloc: " + velocidadeAtual + " Pass: " +nrPassageiros);
 } 
} 

