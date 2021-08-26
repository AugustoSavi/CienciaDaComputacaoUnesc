#include<conio.h>
#include<stdio.h>
//questão A
float calcalt(float altura,float peso,float *maioral,float *menorpe);
//questão B
void calcaci(int sexo,float altura,float *altacima);
//questão C
void calcpe(int sexo,float peso, float *menorpeso);



main(){
	int i,sexo[3];
	float altura[3],peso[3],maioraltura=1.0,menorpeso=1.0,alturaacima=1,homp=1.0;
	//entrada
	for(i=0;i<3;i++){
		
		printf("informe sexo(1=masculino;2=feminino:");
		scanf("%d",&sexo[i]);
		
		printf("informe a altura:");
		scanf("%d",&altura[i]);
		
		printf("informe o peso:");
		scanf("%d",&peso[i]);
	}
	
	//questao a
     calcalt(altura,peso,&maioraltura,&menorpeso);
	//questao b
	calcaci(sexo,altura,&alturaacim);
	//questao c
	calcpe (sexo,peso,&homp);
}
//questão A
float calcalt (float altura,float peso,float *maioral,float *menorpe){
	
	int i;
	
	float maior=-9999,menor=9999;
	
	for(i=0;i<3;i++){
		
		*maioral[i]>maior;
		maior=*maioral;
		
	}
	*maioralt=maior;
	
	for(i=0;i<3;i++){
		
		
		menor=*menorpe[i]
	}
	*menorpe[i]=menor;
}
//questão B
void calcaci( int sexo,float altura,*altacima){
	int i;
	float alt=-9999,media,somador=0,cont=0;
	
	for(i=0;i<3;i++){
		
		if(sexo[i]==2){
			cont++
			somador=somador+altura[i];
		
		}
	 
	}media=somador/cont;
	*altacima=cont;
	
}
//questão C
void calcpe (float sexo,float peso,*hompe){
    int i;
	float mepeso-9999,media,somador=0,cont=0;
	
	for(i=0;i<3;i++){
		
		if(sexo[i]==1){
			cont++
			somador=somador+peso[i];
		
		}
	 
	}
	media=somador/cont;
	*hompe=cont;
}

