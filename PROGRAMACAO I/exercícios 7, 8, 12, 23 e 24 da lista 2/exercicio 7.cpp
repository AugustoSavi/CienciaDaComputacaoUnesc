#include<conio.h>
#include<stdio.h>
main(){
	int x,i,aux,somador=0;
	printf("informe o valor do vetor:");
	scanf("%d",&x);
	
	for(i=0;i<x;i++){
		printf("informe o numero[%d]:",i+1);
		scanf("%d",&aux);
		if(aux%2==1){
			somador=somador+aux;
		}
	}
	printf("soma dos impares:%d",somador);
	getch();
}
