/*6) Calcule o valor da express�o �x2 - y + 10� por meio de um programa em C, seguindo as seguintes regras:
	- o c�lculo da express�o deve ser feito numa fun��o do tipo void;
	- utilize apenas vari�veis locais;
	- a leitura dos dados e exibi��o dos resultados deve ser feita em main().*/	

	
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
