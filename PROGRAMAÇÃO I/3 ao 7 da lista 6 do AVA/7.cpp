/*7)Implemente uma função que calcule a área da superfície e o volume de uma esfera de raio "r". Essa função deve obedecer ao protótipo:

	void calcularEsfera (float r, float *area, float *volume);

	- a área da superfície é dada por 4   r2 e o volume é dado por   4     r3;  
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
