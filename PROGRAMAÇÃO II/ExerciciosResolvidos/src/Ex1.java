/*Faça um algoritmo em Java que receba três notas e seus respectivos
pesos, calcule e mostre a média ponderada dessas notas.
*/
import java.util.Scanner;

public class Ex1 {
    public static void main(String[] args) {
    
     Scanner Cin = new Scanner(System.in);
     
     double Not1,Not2,Nota3,ponderada;
     int P1,P2,P3;
     
        System.out.println("informe a primeira nota:");
        Not1=Cin.nextDouble();
        
        System.out.println("informe a segunda nota:");
        Not2=Cin.nextDouble();
        
        System.out.println("informe a terceira nota:");
        Nota3=Cin.nextDouble();
        
        System.out.println("informe o peso1:");
        P1=Cin.nextInt();
        
        System.out.println("informe o peso2:");
        P2=Cin.nextInt();
        
        System.out.println("informe o peso3:");
        P3=Cin.nextInt();
        
     ponderada=(((Not1*P1)+(Not2*P2)+(Nota3*P3))/(P1+P2+P3));
     
     System.out.println(""+ponderada);
    }
}
        
