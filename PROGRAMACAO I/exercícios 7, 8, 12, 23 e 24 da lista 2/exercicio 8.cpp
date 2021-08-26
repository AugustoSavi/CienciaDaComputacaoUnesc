//Escreva um programa que leia n elementos, crie um vetor com tais valores e informe,
//a seguir, qual a média dos valores positivos e qual a média dos valores negativos.
#include<conio.h>
#include<stdio.h>
main(){
	int x,i,aux,mediap,ip=0,in=0,median,somadorp=0,somadorn=0;
	printf("informe o tamanho do vetor:");
	scanf("%d",&x);
	
	for(i=0;i<x;i++){
		printf("informe o numero[%d]:",i+1);
		scanf("%d",&aux);
		
		if(aux>0){
			somadorp=somadorp+aux;
			ip++;
		}
		else{
			somadorn=somadorn+aux;
			in++;
			
		}
	}

	printf("media dos positivos:%.2f",somadorp/ip*1.00);

if(in=0){
	printf("meida dos pnegativos não existe");
}
else{

	printf("/nmedia dos negativos:%.2f",somadorn/in*1.00);
}
	getch();
}
