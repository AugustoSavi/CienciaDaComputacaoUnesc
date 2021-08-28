#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
   
int op, a, b;
printf("\033[2J\033[0;0H");
printf("Programa calculadora \n");
printf("1 - Soma \n");
printf("2 - Subtração \n");
printf("3 - Multiplicação \n");
printf("4 - Divisão \n");
printf("5 - Encerrar \n");
do {
    printf("Escolha a sua opção: ");
    scanf("%d", &op);
    } while (op <1 || op > 5);
switch (op) {
   case 1 : execv("som", NULL);
            break;
   case 2 : execv("sub", NULL);
            break;
   case 3 : execv("mul", NULL);
            break;
   case 4 : execv("div", NULL);
            break;
   }
  sleep(3);
}
