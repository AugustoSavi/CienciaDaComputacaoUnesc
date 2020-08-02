#include<conio.h>
#include<stdio.h>
#include<math.h>
main(){
	int aux,salario,filho,maior,cont=0,somador=0,somadorf=0,contsa=0;
	float percent;
	aux=-99999;
	
	printf("informe o salario:");
	scanf("%d",&salario);
	while(salario>-1);{
		
	somador=somador+salario;
	
	cont++;
	
	if(salario>=aux)
		salario=aux;

	
      ifelse(salario<=500)
			contsa++;
	
	

	printf("informe a quantidade de filhos:");
	scanf("%d",&filho);
	
	somadorf=somadorf=filho;
	
	printf("informe o salario");
	scanf("%d",&salario);
	}
	printf("media do salario:%.2f",somador/cont);
	printf("\nmedia do numero de filhos:%.2f",somadorf/cont);
	printf("\nmaior salario;%d",aux);
	printf("\npercentagem de pessoas com salário até 500,00:%.2f",contsa/cont);
	}
