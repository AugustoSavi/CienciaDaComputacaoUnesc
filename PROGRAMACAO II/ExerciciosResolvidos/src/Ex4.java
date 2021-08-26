/*Elabore um algoritmo que leia um número inteiro entre 1 e 12 e imprima
o mês correspondente. Caso seja digitado um valor fora desse intervalo,
deverá ser exibida uma mensagem informando que não existe mês com
esse número.*/

import java.util.Scanner;

public class Ex4 {
    public static void main(String[] args) {
    int Mes;
        
        Scanner Cin=new Scanner(System.in);
        while(true){
        System.out.println("Informe o numero");
        Mes=Cin.nextInt();
        if(Mes>=1&&Mes<=12){
        switch(Mes){
            case(1):{
                System.out.println("Janeiro");
                break;
            }
            case(2):{
                System.out.println("Fevereiro");
                break;
            }
            case(3):{
                System.out.println("Março");
                break;
            }
            case(4):{
                System.out.println("Abril");
                break;
            }
            case(5):{
                System.out.println("Maio");
                break;
            }
            case(6):{
                System.out.println("Junho ");
                break;
            }
            case(7):{
                System.out.println("Julho");
                break;
            }
            case(8):{
                System.out.println("Agosto");
                break;
            }
            case(9):{
                System.out.println("Setembro");
                break;
            }
            case(10):{
                System.out.println("Outubro");
                break;
            }
            case(11):{
                System.out.println("Novembro");
                break;
            }
            case(12):{
                System.out.println("Dezembro");
                break;
            }
        }
        }
        else{
            System.out.println("não existe mês com esse número");
        }
        }
    }
    
}

