#include <stdio.h>
#include <unistd.h>

int main(){
 int ret;
 char *cmd[] = { "ls", "-l", (char *)0};
 printf("Imprimindo o conteúdo do diretório corrente\n\n");
 ret - execvp ("ls", cmd);
}
