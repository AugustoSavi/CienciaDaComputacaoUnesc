#include <stdio.h>
#include <unistd.h>

int main()
{
    char *cmd[] = {"ls", "-l", (char *)0};
    printf("Imprimindo o conteúdo do diretório local\n\n");
    fflush(stdout);
    execv("/bin/ls", cmd);
}
