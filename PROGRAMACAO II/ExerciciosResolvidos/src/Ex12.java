/* Escreva um programa que lê Strings do teclado até que sejam lidas
duas Strings iguais em seqüência, uma imediatamente após a outra.
Quando isto ocorre, o programa imprime o número de Strings lidas, o
tamanho da maior String lida, e a concatenação de todas as Strings lidas
exceto a última. Lembre-se que o operador '==' não compara o conteúdo
das Strings. */
import java.util.Scanner;

public class Ex12 {
    public static void main(String[] args){
        
   Scanner Cin = new Scanner(System.in);
   int Soma=0;
   
   String frase1,frase2,frase3= "";
   
        do {
            System.out.println("Informe a primeira frase:");
            frase1 = Cin.nextLine();
            
            System.out.println("Informe a segunda frase:");
            frase2 = Cin.nextLine();
            
            frase3+=frase1+"\n"+frase2+"\n";
            
         Soma=Soma+2;
         
            if(frase1.equals(frase2)){
                System.out.println("Frases iguais");
                
                 
            }
            else{
                System.out.println("frases diferentes");
            }
             
}while(frase1.equals(frase2)==false);
        System.out.println("Quantidade de frases digitadas:"+Soma);
        System.out.println("Frase concatenada:"+ frase3);
}  
}
