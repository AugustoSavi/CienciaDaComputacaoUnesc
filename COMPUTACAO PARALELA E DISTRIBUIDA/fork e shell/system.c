#include <stdio.h>
#include <unistd.h>

int main()
{ 
 printf("Vou chamar o programa cat para ler o conteúdo de /etc/issue. \n");
 system("/bin/cat /etc/issue");
 printf("Esta mensagem será impressa. \n");
}
