//Faça um programa em Java que leia um inteiro e mostre a seguinte
//tabela de multiplicação. No exemplo, n=9.
import java.util.Scanner;

public class Ex11 {
    public static void main(String[] args) {
        
        Scanner Cin = new Scanner(System.in);
        int Number;

        System.out.println("Informe o numero");
        Number= Cin.nextInt();
                
        
        for(int i=1;i<Number;i++){
            System.out.println("\t");
            
            for(int j=1;j<Number;j++){
                
                     if(i>=j){
                         
                    System.out.print("\t"+i*j);
                    
                     } 
        }
        }
    
    }
    
}