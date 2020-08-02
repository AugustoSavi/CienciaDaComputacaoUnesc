/*4) Faça uma função que tenha como argumento o salário de um funcionário e que retorne o valor do salário atualizado conforme a tabela de bonificação abaixo.
 A função deve retornar também o valor da bonificação. Escreva também o protótipo.

Salário 							Bonificação

Até R$ 500,00 						 5% do salário

Mais de R$ 500,00 e menos de R$ 1.200,00 		12% do salário

R$ 1.200,00 ou mais 					Sem bonificação (zero)
*/
#include<conio.h>
#include<stdio.h>

void atequi(float *salario,float *bonificação){
	
	*bonificação=*salario*0.05;
	
	*salario=*salario+*bonificação;
	
	printf("salario aumentado:%f",sala);
	
	printf("bonificação: %f",bonus);
}

void atemil(float *salario,float *bonificação){
	
	*bonificação=*salario*0.12;
	
	*salario=*salario+*bonificação;	
	
	printf("salario aumentado:%f",sala);
	
	printf("bonificação: %f",bonus);
}


main(){
	float sala,bonus;
	
	printf("informe o salario: ");
	
	scanf("%f",&sala);
	
	if(sala<=500){
		
		atequi(&sala,&bonus);
	
	}
     if else ( sala>500&&sala<=1200){
		
		atemil(&sala,&bonus);
	}
	
	else{
		printf("sem bonificação");
	}
	getch();
}
