#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    int op, a, b, id;
    printf("\033[2J\033[0;0H");
    id = fork();
    if (id != 0)
        wait(0);
    else
    {
        printf("\033[2J\033[0;0H");
        printf("Programa calculadora \n");
        printf("1 - Soma \n");
        printf("2 - Subtração \n");
        printf("3 - Multiplicação \n");
        printf("4 - Divisão \n");
        printf("5 - Encerrar \n");
        do
        {
            printf("Escolha a sua opção: ");
            scanf("%d", &op);
        } while (op < 1 || op > 5);
        switch (op)
        {
        case 1:
            execv("som_fork", NULL);
            break;
        case 2:
            execv("sub_fork", NULL);
            break;
        case 3:
            execv("mul_fork", NULL);
            break;
        case 4:
            execv("div_fork", NULL);
            break;
        }
    }
}
