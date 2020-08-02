/* Faça um programa em Java que leia a média final de um aluno e
forneça uma mensagem associada ao conceito obtido. Utilize "if/else”.
Informações a serem apresentadas:

- Se a média é menor que 7, “Você precisa estudar mais”;

- Se a média é igual a 7, “Você foi aprovado”;

- Se a média está entre 7 e 8, ou seja de 7.1 à 7.99 “Parabéns, suas notas
ficaram acima da média”;

- Se a média é maior ou igual a 8 e menor que 9, “Parabéns,sua média
ficou próxima da nota máxima”;

- Se a média é maior ou igual a 9, “Parabéns, você é um excelente aluno”;*/
import java.util.Scanner;

public class Ex3 {
    public static void main(String[] args) {
        
      Scanner Cin = new Scanner(System.in);
      
      float Nota;
      
        System.out.println("Informe a nota:");
        Nota=Cin.nextFloat();
        
      if(Nota<7){
          System.out.println("Você precisa estudar mais");
      }
      if(Nota==7){
          System.out.println("Você foi aprovado");
      }
      if(Nota>7&&Nota<8){
          System.out.println("Parabéns, suas notas\n" +
            "ficaram acima da média");
      }  
      if(Nota>=8&&Nota<9){
          System.out.println("Parabéns,sua média\n" +
            "ficou próxima da nota máxima");
      }
          
          
      if(Nota>9||Nota==9){
          System.out.println("Parabéns,você é um excelente aluno"); 
      }
        
    }
}