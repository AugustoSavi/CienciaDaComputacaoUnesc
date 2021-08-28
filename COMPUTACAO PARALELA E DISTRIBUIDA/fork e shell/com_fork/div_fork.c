#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
     float a, b;
     printf("Entre com o valor de A: ");
     scanf("%f", &a);
     printf("Entre com o valor de B: ");
     scanf("%f", &b);
     if (b != 0)
          printf("Divisão = %f\n", a / b);
     else
          printf("Impossível divisão por zero\n");
     sleep(3);
     execv("main", NULL);
}
