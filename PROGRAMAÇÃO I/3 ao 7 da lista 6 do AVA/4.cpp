/*4) Fa�a uma fun��o que tenha como argumento o sal�rio de um funcion�rio e que retorne o valor do sal�rio atualizado conforme a tabela de bonifica��o abaixo.
 A fun��o deve retornar tamb�m o valor da bonifica��o. Escreva tamb�m o prot�tipo.

Sal�rio 							Bonifica��o

At� R$ 500,00 						 5% do sal�rio

Mais de R$ 500,00 e menos de R$ 1.200,00 		12% do sal�rio

R$ 1.200,00 ou mais 					Sem bonifica��o (zero)
*/
#include<conio.h>
#include<stdio.h>

void atequi(float *salario,float *bonifica��o){
	
	*bonifica��o=*salario*0.05;
	
	*salario=*salario+*bonifica��o;
	
	printf("salario aumentado:%f",sala);
	
	printf("bonifica��o: %f",bonus);
}

void atemil(float *salario,float *bonifica��o){
	
	*bonifica��o=*salario*0.12;
	
	*salario=*salario+*bonifica��o;	
	
	printf("salario aumentado:%f",sala);
	
	printf("bonifica��o: %f",bonus);
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
		printf("sem bonifica��o");
	}
	getch();
}
