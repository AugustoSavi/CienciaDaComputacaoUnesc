#include<conio.h>
#include<stdio.h>
#include<math.h>
main(){
	int i,a,b,c,d,maior,menor,somador=0,cont=0;
    c=99999;
    d=-99999;
	for(i=1;i<50;i++){
		printf("informe o valor %d:",i);
		scanf("%d",&a);
		somador=somador+a;
		cont++;
		
		if(a>d)
			d=a;
		
		
		fflush(stdin);
		
		if else(a<c)
			c=a;
		
		
	}
	printf("maior numero:%d",a);
	printf("\nmenor numero:%d",c);
	printf("\nmedia:%d",somador/cont);
	getch();
	
	}
