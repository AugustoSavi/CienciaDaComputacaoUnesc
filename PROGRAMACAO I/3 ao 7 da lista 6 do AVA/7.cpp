/*7)Implemente uma fun��o que calcule a �rea da superf�cie e o volume de uma esfera de raio "r". Essa fun��o deve obedecer ao prot�tipo:

	void calcularEsfera (float r, float *area, float *volume);

	- a �rea da superf�cie � dada por 4   r2 e o volume � dado por   4     r3;  
 3
	- utilize o valor 3,14159 para*/
	
	#include<conio.h>
	#include<stdio.h>
	#include<math.h>
    pi=3.14;
	void calcularesfera (float r,float *area,float *volume){

		*area=4*pi*r^2;
		*volume=4/3*pi*r^3;
		printf("%f",area);
		printf("%f",volume);
	}
	main(){
		
		float raio;
		
		printf("informe o raio:");
		scanf("%f",&raio);
		calcularesfera(raio);
		getch();
	}
