/*5)Considere o prot�tipo da fun��o a seguir e depois fa�a um programa para elevar um n�mero ao cubo.
	void cubo (double numero, double *result);
	Esta fun��o eleva um n�mero ao cubo e atualiza o par�metro �result� com o resultado.
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

