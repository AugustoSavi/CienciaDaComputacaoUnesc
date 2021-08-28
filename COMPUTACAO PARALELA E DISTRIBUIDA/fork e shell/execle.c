#include <stdio.h>
#include <unistd.h>

int main(){
  int ret;
  char *env[] = { "HOME=/usr/home", "LOGNAME=home", (char *)0 };
  printf("Vou chamar o programa ls para ler o conteúdo do diretório corrente.\n");
  execl ("/bin/ls", "ls", "-l", (char *)0, env);
  printf("Esta mensagem não será impressa.\n");
}
