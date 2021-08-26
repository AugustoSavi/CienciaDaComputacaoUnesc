/*5)Considere o protótipo da função a seguir e depois faça um programa para elevar um número ao cubo.
	void cubo (double numero, double *result);
	Esta função eleva um número ao cubo e atualiza o parâmetro “result” com o resultado.
*/
#include<conio.h>
#include<stdio.h>
#include<math.h>
  void cubo (double numero, float *result);
  
    main(){
  	
  	float num,resu=0;
  	
  	printf("informe o numero:");
  	
  	scanf("%f",&num);
  	
  	cubo(num,&resu);
  	
  	printf("%f",resu);
  	
  	getch();
  }
  void cubo (double numero,float *result){	
   *result=pow(numero,3);
  }

