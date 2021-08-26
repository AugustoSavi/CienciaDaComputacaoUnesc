//Faça um programa que leia um vetor de n elementos com números inteiros e
//divida todos os seus elementos pelo maior valor do vetor. Mostre o vetor após os cálculos.

#include<conio.h>
#include<stdio.h>

main(){
	
int x,i,aux,vet[0],maior=-999999,somador=0;

	printf("informe o tamanho do vetor:");
	 scanf("%d",&x);
	
	vet[0]=vet[x];
	
	for(i=0;i<x;i++){
		printf("informe o numero[%d]:",i+1);
		scanf("%d",&vet[x]);
		
		somador=somador+vet[x];
		
		if(vet[x]>maior){
			maior=vet[x];
		}
	
		
	}
	printf("divisão de todos os elementos pelo maior numero:%.2f",somador/maior);
	
	
	
	for(i=x;i=0;i--){
		x--;
		printf("numero alocado na posição[%d]:%D",i,vet[x]);


	getch();
}
}
