#include<conio.h>
#include<stdio.h>
#include<math.h>
main(){
	int M[3][4],i,j,cont=0,soma=0,aux;
	
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			printf("informe o valor[%d][%d]:",i,j);
			scanf("%d",&M[i][j]);
			if(M[i][j]==3){
				cont++;
			}
			if(M[i][j]>5){
				soma=soma+M[i][j];
			}
		}
	}
	printf("quantidade de numeros 3:%d",cont);
	printf("\nsoma dos numeros maiores que 5:%d",soma);
	
	getch();
	// (Valor 2,0) Fa�a um programa em C que gere armazene em um matriz 3 x 4 n�meros inteiros,
//calcule e exiba a quantidade de n�meros �3� e a soma dos n�meros maiores que �5�.
}
