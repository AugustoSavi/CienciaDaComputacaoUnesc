/*6) Calcule o valor da expressão “x2 - y + 10” por meio de um programa em C, seguindo as seguintes regras:
	- o cálculo da expressão deve ser feito numa função do tipo void;
	- utilize apenas variáveis locais;
	- a leitura dos dados e exibição dos resultados deve ser feita em main().*/	

	
	#include<conio.h>
	#include<stdio.h>
	#include<math.h>
	
	void calc(int *x,int *y,int *resu);
	
    main(){
	 	
		int x,y,resu;
		
		printf("informe x: ");
		scanf("%d",&x);
		
		printf("informe y: ");
		scanf("%d",&y);
		
		calc(&x,&y,&resu);	
		
		printf("%d",calc);
		
		getch();
	}
	void calc(int *x,int *y,int *resu){
		
	resu=*x*2-*y+10;	
		
	}
