//Fa�a um programa que l� uma matriz Amxm e calcula a m�dia aritm�tica dos elementos da diagonal principal
#include<stdio.h>
#include<conio.h>
main(){
	
	int i,j,m[2][3],coluna,linha,somador=0,contador=0;
	
	printf("informe a quantidade de colunas:");
	scanf("%d",&coluna);
		printf("informe a quantidade de linhas:");
	 scanf("%d",&linha);
	m[2][3]=m[coluna][linha];
	
	
	for(i=0;i<coluna;i++){
		for(j=0;j<linha;j++){
			printf("mat[%d][%d]:",i,j);
			scanf("%d",&m[i][j]);
			
			if(i==j){
				somador=somador+m[i][j];
				contador++;
				
			}
			
		}
	}
 printf("media poderada da diagonal principal:%.2f",somador/contador*1.00);


	getch();
}
