/*Elabore um algoritmo que entre com números enquanto forem positivos
e imprimir quantos números positivos foram digitados.
*/
import java.util.Scanner;

public class Ex9 {
    public static void main(String[] args) {
        Scanner Cin= new Scanner(System.in);
     float Num;
     int Soma=0;
        do{
            System.out.println("Digite o numero:");
            Num=Cin.nextFloat();
            if(Num>0){
            Soma++;
            }
        }while(Num>0);
        System.out.println("Quantos numeros posiitivos foram digitados:"+Soma);
    }
    
}
