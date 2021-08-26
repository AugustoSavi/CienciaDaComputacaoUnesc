/*Elabore um algoritmo que leia dois números e faça uma das quatro
operações. A operação (soma, subtração, multiplicação ou divisão) será
escolhida pelo usuário*/
import java.util.Scanner;

public class Ex5 {
    public static void main(String[] args) {
     double Num1,Num2;
     
        Scanner Cin=new Scanner(System.in);
        
        System.out.println("Informe o primeiro numero:");
        Num1=Cin.nextDouble();
        
        System.out.println("Informe o Segundo numero:");
        Num2=Cin.nextDouble();
        
        System.out.println("Informe a Operação a ser realiazada(1=soma,2=subtração,3=multiplicação,4=divisão):");
        int Op=Cin.nextInt();
        
        switch(Op){
            case(1):{
                System.out.println("Operação realizada\nResultado:"+(Num1+Num2));
                break;
        }
            case(2):{
                System.out.println("Operação realizada\nResultado:"+(Num1-Num2));
                break;
        }
            case(3):{
                System.out.println("Operação realizada\nResultado:"+(Num1*Num2));
                break;
        }
            case(4):{
                System.out.println("Operação realizada\nResultado:"+(Num1/Num2));
                break;
        }
        }
        
    }
    
}

