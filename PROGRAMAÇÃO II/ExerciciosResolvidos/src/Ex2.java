/*Faça um algoritmo em Java que receba o salário-base de um
funcionário e mostre o salário a receber, sabendo-se que esse funcionário
tem gratificação de 5% sobre o salário-base e paga imposto de 7% sobre
o salário-base.
*/

import java.util.Scanner;

public class Ex2 {
    public static void main(String[] args) {   
    
     Scanner Cin = new Scanner(System.in);
     
     double Salario;
     
        System.out.println("informe o salario:");
        Salario=Cin.nextDouble();
        
        double SalarioLi=(Salario*0.05)-(Salario*0.07)+Salario;
        
        System.out.println("Salario Liquido:"+SalarioLi);
        
    }   
}

