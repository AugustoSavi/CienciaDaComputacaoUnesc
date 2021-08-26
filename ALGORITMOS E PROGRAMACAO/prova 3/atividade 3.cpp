#include<conio.h>
#include<stdio.h>
#include<math.h>
main(){
	int vetor[10]={2,3,4,5,6,7,8,9,10,11},vetorusu[10],i,pi,aux,soma=0,menor=999999,maior=-999999;
	for(i=0;i<10;i++){
		printf("\ninforme o valor[%d]:",i);
		scanf("%d",&vetorusu[i]);
		
		if(vetorusu[i]>1 && vetorusu[i]<12){
			pi=i;
			printf("\nnumero igual na posicao:%d",i);
		}
		 if(vetorusu[i]>maior){
			maior=vetorusu[i];
		}
		 if(vetorusu[i]<menor){
			menor=vetorusu[i];
		}
		 if(vetorusu[i]>0){
			soma=soma+vetorusu[i];
		}
		
	}
	printf("\nmenor numero:%d",menor);
	printf("\nmaior numero:%d",maior);
	printf("\nsoma dos numeros positivos:%d",soma);
	
	getch();
}
// (Valor 3,0) Crie um vetor com 10 elementos e:
//a) verifique se um valor digitado pelo usuário é um elemento do vetor. Se sim, informe a posição
//em que o elemento ocorre.
//b) percorrendo o vetor uma única vez, determine o menor e o maior elemento do vetor, e as
//posições em que ocorrem.
//c) calcule a soma de todos os elementos positivos do vetor.
