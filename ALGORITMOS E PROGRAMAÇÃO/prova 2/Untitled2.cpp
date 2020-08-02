#include<conio.h>
#include<stdio.h>
#include<string.h>
main(){
	
	int i=0,compras;
	float bonus;
	char cliente;

	for(i=1;i<150;i++){
	fflush(stdin);
	printf("informe o nome %d:",i);
	scanf("%c",&cliente);
	fflush(stdin);
	
	printf("valor das compras");
	scanf("%d",&compras);
	if(compras<=1000)
		bonus=compras*0.10;
	
	else
		bonus=compras*0.20;
	
	
}
getch();
}

