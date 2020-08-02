#include<stdio.h>
#include<conio.h>
#include<math.h>
main(){
	float peso,multa,aux;
	printf("informe o peso:");
	scanf("%f",&peso);
	if (peso>50){
	  printf("Excesso");
	  aux=(peso-50)*4.00;
	  multa=aux;
	}
	else 
	printf("peso dentro dos limites");
	
	getch();
	}
