#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
main(){
	float salario,aumento,horatrab;
	char nome[40];
	int cargo;
	printf("informe o nome do funcionario:");
	gets(nome);
	printf("informe o codigo do cargo:");
	scanf("%d",&cargo);
	printf("informe o salario:");
	scanf("%f",&salario);
	printf("informe o numero de horas trabalhadas:");
	scanf("%f",&horatrab);
	
	switch (cargo){
		case 10:{
			if(salario<=2300)
			{
				
				printf("nome:%c",nome);
				printf("\nsalario mensal:%.3f",salario);
				printf("\nhoras trabalhadas:%.1f",horatrab);
				printf("\nMotorista");	
			}
			    else if (salario<2300&&salario>4000)
			{
			
				printf("nome:%c",nome);
				printf("\nsalario mensal:%.3f",salario);
				printf("\nhoras trabalhadas:%.1f",horatrab);
				printf("\nMotorista");
		}	
				else if (salario<2300&&salario>4000)
				{
				
				printf("nome:%c",nome);
				printf("\nsalario mensal:%.3f",salario);
				printf("\nhoras trabalhadas:%.1f",horatrab);
				printf("\nMotorista");
			}
			break;
		}
		case 20:{
			if(salario<=2300)
			{

				printf("nome:%c",nome);
				printf("\nsalario mensal:%.3f",salario);
				printf("\nhoras trabalhadas:%.1f",horatrab);
				printf("\nFaxineiro");	
			}
			    else if (salario<2300&&salario>4000)
			{

				printf("nome:%c",nome);
				printf("\nsalario mensal:%.3f",salario);
				printf("\nhoras trabalhadas:%.1f",horatrab);
				printf("\nFaxineiro");
		}	
				else if (salario<2300&&salario>4000)
				{

				printf("nome:%c",nome);
				printf("\nsalario mensal:%.3",salario);
				printf("\nhoras trabalhadas:%.1f",horatrab);
				printf("\nFaxineiro");
			}
			break;
		}
		case 30:{
			if(salario<=2300)
			{

				printf("nome:%c",nome);
				printf("\nsalario mensal:%.3f",salario);
				printf("\nhoras trabalhadas:%.1f",horatrab);
				printf("\nPresidente");	
			}
			    else if (salario<2300&&salario>4000)
			{

				printf("nome:%3",nome);
				printf("\nsalario mensal:%.3f",salario);
				printf("\nhoras trabalhadas:%.1f",horatrab);
				printf("\nPresidente");
		}	
				else if (salario<2300&&salario>4000)
				{
	
				printf("nome:%c",nome);
				printf("\nsalario mensal:%.3f",salario);
				printf("\nhoras trabalhadas:%.1f",horatrab);
				printf("\nPresidente");
			}
			break;
		}
		case 40:{
			if(salario<=2300)
			{
				aumento=(salario/100)*15+salario;
				printf("nome:%c",nome);
				printf("\nsalario mensal:%.3f",aumento);
				printf("\nhoras trabalhadas:%.1f",horatrab);
				printf("\nGerente");	
			}
			    else if (salario<2300&&salario>4000)
			{
				aumento=(salario/100)*10+salario;
				printf("nome:%c",nome);
				printf("\nsalario mensal:%.3f",aumento);
				printf("\nhoras trabalhadas:%.1f",horatrab);
				printf("\nGerente");
		}	
				else if (salario<2300&&salario>4000)
				{
				aumento=(salario/100)*5+salario;
				printf("nome:%c",nome);
				printf("\nsalario mensal:%.3f",aumento);
				printf("\nhoras trabalhadas:%.1f",horatrab);
				printf("\nGerente");
			}
			break;
		}
	}
	getch();
	}
