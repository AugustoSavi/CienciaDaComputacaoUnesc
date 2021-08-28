#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main(){
   float a, b;
   printf("Entre com o valor de A: ");
   scanf("%f", &a);
   printf("Entre com o valor de B: ");
   scanf("%f", &b);
   printf("Soma = %f\n", a + b);
   sleep(3);
   execv("cpdexer61", NULL);
}
