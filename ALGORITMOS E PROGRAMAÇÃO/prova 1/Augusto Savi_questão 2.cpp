#include<stdio.h>
#include<conio.h>
#include<math.h>
main(){
	float desconto,litro,total,aux;
	int esc;
	printf("1-Alcool\n2-Gasolina\n");
	printf("escolha a opcao:");
	scanf("%d",&esc);
	printf("informe a quantidade de litros vendidos:");
	scanf("%f",&litro);
	switch(esc){
		case 1:{
			if(litro<20)
				{
				aux=litro*2.50;
				desconto=(aux/100)*3;
				total=aux-desconto;
				printf("valor a ser pago e:%.2f",total);
			}
			 else if (litro>=20)
			{
				aux=litro*2.50;
				desconto=(aux/100)*5;
				total=aux-desconto;
				printf("valor a ser pago e:%.2f",total);
			}
			break;
		}
		
		case 2:{
			if(litro<20)
			{
				aux=litro*2.80;
				desconto=(aux/100)*4;
				total=aux-desconto;
				printf("valor a ser pago e:%.2f",total);
			}
			else if (litro>=20)
			{
				aux=litro*2.80;
				desconto=(aux/100)*6;
				total=aux-desconto;
				printf("valor a ser pago e:%.2f",total);
	
				
			}
			break;
        }	
	
	getch();
	}
}
