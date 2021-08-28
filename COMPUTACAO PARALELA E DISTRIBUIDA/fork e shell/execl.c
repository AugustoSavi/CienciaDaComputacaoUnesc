#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Vou chamar o programa head para ler o cabeçalho de /etc/passwd e /etc/group.\n");
    execl("/usr/bin/head", "head", "/etc/passwd", "/etc/group", (char *)0);
    printf("Esta mensagem não será impressa.\n");
}
