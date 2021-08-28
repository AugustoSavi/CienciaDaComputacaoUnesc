// FABIO DE STEFANI

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <locale.h>
#include <langinfo.h>

#define VERSAO  "0.2"
#define STR     128
#define TOKEN   " "

#define CLS     printf("\033[2J\033[0;0H")
#define NEGRITO "\033[1m"
#define SIMPLES "\033[0m"

typedef struct history
{
  char *str;
  history *prox;
} *pHist;

pHist addHist(pHist h, char *str)
{
  if (!str)
    return h;
  pHist novo = new history;
  novo->str = str;
  novo->prox = h;
  return novo;
}

pHist getHist(pHist h, char *str)
{
  int i = atoi(str);
  while ((--i > 0) && h)
    h = h->prox;
  return h;
}

void freeHist(pHist h)
{
  pHist del;
  while (h)
  {
    del = h;
    free(del->str);
    delete del;
    h = h->prox;
  };
}

void printHist(pHist h)
{
  printf("Historico:\n");
  for (int i=0; h; h = h->prox)
    printf("%2d: %s\n", ++i, h->str);
}

//GLOBAL
pHist HISTORICO = NULL;

int param(char *cmd, char* toked)
{
  if (!toked)
    printf("%s%s%s: falta de parametros\n", NEGRITO, cmd, SIMPLES);
  else
    return 1;
  return 0;
}

int param(char *cmd, char* toked1, char* toked2)
{
  if (!toked1 || !toked2)
    printf("%s%s%s: falta de parametros\n", NEGRITO, cmd, SIMPLES);
  else
    return 1;
  return 0;
}

int comando(char *str, char *dir, char *const envp[])
{
  char *origCmd = strdup(str); // copia linha de comando
  char histCmdCpy[STR]; // copia do comando retornado do historico
  pHist histCmd; // comando retornado do historico
  char *toked1, *toked2;
  char *argv[3];
  dirent *dp; // dir
  DIR *odir; // dir
  struct stat entry; // dir
  struct passwd *pwd; // dir
  struct group *grp; // dir
  struct tm *tm; // dir
  char screen[STR], datestring[STR]; // dir

  if (strlen(str) == 0)
    return 1;

  strtok(str, " ");

  if ((strcmp(str, "exit") == 0) || (strcmp(str, "q") == 0))
    return 0;
  else if (strcmp(str, "hist") == 0)
    {
      toked1 = strtok(NULL, TOKEN);

      if (!toked1)
      {
        printHist(HISTORICO);
        return 1;
      }
      else
        {
          if (!(histCmd = getHist(HISTORICO, toked1)))
          {
            printf("Numero invalido no historico\n");
            return 1;
          }
          else
          {
            free(origCmd);
            origCmd = NULL;
            str = strcpy(histCmdCpy, histCmd->str);
            strtok(str, " ");
          }
        }
    }
    
  if (strcmp(str, "cls") == 0)
    CLS;
  else if (strcmp(str, "cd") == 0)
    {
      toked1 = strtok(NULL, TOKEN);
      if (param(str, toked1))
        if (chdir(toked1))
          printf("cd: %s%s%s: O sistema nao encontrou o caminho especificado\n", NEGRITO, toked1, SIMPLES);
    }
  else if (strcmp(str, "md") == 0)
    {
      toked1 = strtok(NULL, TOKEN);
      if (param(str, toked1))
        if (mkdir(toked1, 755))
          printf("md: %s%s%s: Nao foi possiver criar o diretorio\n", NEGRITO, toked1, SIMPLES);
    }
  else if (strcmp(str, "rd") == 0)
    {
      toked1 = strtok(NULL, TOKEN);
      if (param(str, toked1))
        if (rmdir(toked1))
          printf("rd: %s%s%s: Nao foi possiver remover o diretorio\n", NEGRITO, toked1, SIMPLES);
    }
  else if (strcmp(str, "move") == 0)
    {
      toked1 = strtok(NULL, TOKEN);
      toked2 = strtok(NULL, TOKEN);
      if (param(str, toked1, toked2))
        if (rename(toked1, toked2))
          printf("move: %s%s%s: Nao foi possiver mover o diretorio\n", NEGRITO, toked1, SIMPLES);
    }
  else if (strcmp(str, "del") == 0)
    {
      toked1 = strtok(NULL, TOKEN);
      if (param(str, toked1))
        if (remove(toked1))
          printf("del: %s%s%s: Nao foi possiver excluir o arquivo\n", NEGRITO, toked1, SIMPLES);
    }
  else if (strcmp(str, "dir") == 0)
    {
      //system("ls");
      odir = opendir(dir);
      while (dp = readdir(odir))
      {
        /* Get entry's information. */
        if (stat(dp->d_name, &entry) == -1)
            continue;

        mode_t st_modeTemp = entry.st_mode;
        /* Print out type, permissions. */
        if (S_ISREG(entry.st_mode))
             st_modeTemp &= ~S_IFREG;
        if (S_ISDIR(entry.st_mode))
             st_modeTemp &= ~S_IFDIR;
          printf("%4.3lo ", 0x0000FFFFL & (long) st_modeTemp);

        /* Print out owner's name if it is found using getpwuid(). */
        if ((pwd = getpwuid(entry.st_uid)) != NULL)
            printf(" %-8.8s", pwd->pw_name);
        else
            printf(" %-8d", entry.st_uid);

        /* Print out group name if it is found using getgrgid(). */
        if ((grp = getgrgid(entry.st_gid)) != NULL)
            printf(" %-8.8s", grp->gr_name);
        else
            printf(" %-8d", entry.st_gid);

        /* Print size of file. */
        printf(" %7d", entry.st_size);

        tm = localtime(&entry.st_mtime);

        /* Get localized date string. */
        strftime(datestring, sizeof(datestring), nl_langinfo(D_T_FMT), tm);
        printf(" %s ", datestring);

        if (S_ISDIR(entry.st_mode))
          strcpy(screen, "\033[1;33m%s\033[0m/\n");
          else
            if (entry.st_mode & 0000700 == 0000700)
              strcpy(screen, "\033[1;32m%s\033[0m*\n");
            else
              strcpy(screen, "%s\n");
        printf(screen, dp->d_name);
      }
    }
  else if (strcmp(str, "run") == 0)
    {
      toked1 = strtok(NULL, TOKEN);
      toked2 = strtok(NULL, TOKEN);
      argv[0] = toked1;
      argv[1] = toked2;
      argv[2] = NULL; // define que soh tem 2 argumentos
      if (param(str, toked1))
        if (fork() == 0)
        {
          if (execve(toked1, argv, envp))
            if (execvp(toked1, argv))
              printf("run: %s%s%s: Nao foi possiver executar o programa\n", NEGRITO, toked1, SIMPLES);
          exit(0);
        }
        else
          wait(0);
    }

  
  //NOVAS FUNCOES DO SHELL IMPLEMENTADAS POR FABIO DE STEFANI
  //
  //------------------------------------------------------------------------------------------------------
  else if  (strcmp(str, "pwd")==0)
  {
	  toked1 = strtok(NULL, TOKEN);
	  if (fork()==0)
	    {
		if (system("pwd"))
		  printf("pwd: %s%s%s: Nao foi possivel exibir o diretorio aual\n", NEGRITO, toked1, SIMPLES);  
		exit(0);
	    }
	  else
	    wait(0);
  }
  //------------------------------------------------------------------------------------------------------
  else if(strcmp(str, "log")==0)
  {
	  toked1 = strtok(NULL, TOKEN);
	  if (!toked1)
	  {
	    if (fork()==0)
	    {
   	      if (system("who"))
		printf("log: Nao foi possivel exibir os usuarios logados\n", NEGRITO, SIMPLES);
	      exit(0);		      
	    }
	    else
		wait(0);
	  }
	  else
	  {
  	    if (fork()==0)
	    {
		if (execl("/usr/bin/who","",toked1,(char *)0))
		    printf("log: %s%s%s: Nao foi possivel exibir os usuários logados\n", NEGRITO, toked1, SIMPLES);	
		exit(0);
	    }
	    else
	      wait(0); 
	  }
  }
  //---------------------------------------------------------------------------------------------------
  else if (strcmp(str, "disk")==0)
  {
	toked1 = strtok(NULL, TOKEN);
	if (!toked1)
	{
	  if (fork()==0)
	  {
	    if (system("df"))
	      printf("disk:  nao foi possivel exibir o status do disco\n", NEGRITO, SIMPLES);
	    exit(0);
	  }
	  else
	    wait(0);
	
	}
	else
	{
	  if (fork()==0)
	  {
	    if (execl("/bin/df","", toked1, (char *)0))
		  printf("df: %s%s%s: Nao foi possivel exibir o status do disco\n", NEGRITO, toked1, SIMPLES);
	    exit(0);
	  }
	  else
	  wait(0);
	}
  }
  //--------------------------------------------------------------------------------------------------
  else if (strcmp(str, "memo")==0)
  {
	toked1 = strtok(NULL, TOKEN);
	toked2 = strtok(NULL, TOKEN);
	if (!toked1)
	{
	  if (fork()==0)
	  {
	    if (system("free"))
		printf("memo: Nao foi possivel exibit o status da memoria\n", NEGRITO, SIMPLES);
	    exit(0);
	  }
	  else
	    wait(0);
	}
	else
	{
	  if (fork()==0)
	  {
	    if (execl("/usr/bin/free","", toked1,toked2, (char *)0))
 	      printf("free: %s%s%s: Nao foi possivel exibir o status da memoria\n", NEGRITO, toked1, SIMPLES);
	    exit(0);
	  }
	  else
	    wait(0);
	}
  }
  //--------------------------------------------------------------------------------------------------
  else if (strcmp(str, "manual")==0)
  {
    toked1 = strtok(NULL, TOKEN);
    if (strcmp(toked1,"pwd")==0)
    {
      if (fork()==0)
        {
	  if (execl("/usr/bin/man","", toked1, (char *)0))
            printf("manual: %s%s%s: Nao foi possivel mostrar referencia\n",NEGRITO, toked1, SIMPLES);
	  exit(0);
	}
      else
        wait(0);
    }
    else if (strcmp(toked1,"log")==0)
    {
      if (fork()==0)
        {
          if (execl("/usr/bin/man","", "who", (char *)0))
    	    printf("manual: %s%s%s: Nao foi possivel mostrar referencia\n", NEGRITO, toked1, SIMPLES);
	  exit(0);
	 }
      else
        wait(0);
    }
    else if (strcmp(toked1,"disk")==0)
    {
      if (fork()==0)
      {
        if (execl("/usr/bin/man","","df", (char *)0))
	  printf("manual: %s%s%s: Nao foi possivel mostrar referencia\n", NEGRITO, toked1, SIMPLES);
	exit(0);
      }
      else
	wait(0);
    }
    else if (strcmp(toked1, "memo")==0)
    {
      if (fork()==0)
      {
        if (execl("/usr/bin/man","","free", (char *)0))
          printf("manual: %s%s%s: Nao foi possivel mostrar a referencia\n", NEGRITO,toked1, SIMPLES);
	exit(0);
      }
      else
	      wait(0);
    }
    else if (strcmp(toked1, "passwd")==0)
    {
      if (fork()==0)
      {
        if (execl("/usr/bin/man","",toked1, (char *)0))
	  printf("manual: %s%s%s: Nao foi possivel mostrar a referencia\n", NEGRITO, toked1, SIMPLES);
	exit(0);
      }
      else
	      wait(0);
    }
    else if (strcmp(toked1, "cat")==0)
    {
      if (fork()==0)
      {
        if (execl("/usr/bin/man","", toked1, (char *)0))
	  printf("manual: %s%s%s: Nao foi possivel mostrar a referencia\n", NEGRITO, toked1, SIMPLES);
	exit(0);
      }
      else
	      wait(0);
    }
    else if (strcmp(toked1, "chmod")==0)
    {
      if (fork()==0)
      {
        if (execl("/usr/bin/man","", toked1, (char *)0))
  	  printf("manual: %s%s%s: Nao foi possivel mostrar a referencia\n", NEGRITO, toked1, SIMPLES);
	exit(0);
      }
      else
	      wait(0);
    }
    else if (strcmp(toked1, "cal")==0)
    {
      if (fork()==0)
      {
        if (execl("/usr/bin/man","",toked1, (char *)0))
  	  printf("manual: %s%s%s: Nao foi possivel mostrar a referencia\n",NEGRITO, toked1, SIMPLES);
	exit(0);
      }
      else
	      wait(0);
    }
    else if (strcmp(toked1, "ls")==0)
    {
      if (fork()==0)
        {
          if (execl("/usr/bin/man","", toked1, (char *)0));
	    printf("manual : %s%s%s : Nao foi possivel mostrar a referencia\n", NEGRITO, toked1, SIMPLES);
	  exit(0);
        }
      else
	      wait(0);
    }
    else if (strcmp(toked1, "gzip")==0)
    {
      if (fork()==0)
      {
        if (execl("/usr/bin/man","",toked1, (char *)0))
	  printf("manual: %s%s%s : Nao foi possivel mostrar a referencia\n", NEGRITO, toked1, SIMPLES);
	exit(0);
      }
      else
	      wait(0);
    }
    else if (strcmp(toked1, "ps")==0)
    {
      if (fork()==0)
      {
        if (execl("/usr/bin/man","",toked1, (char *)0))
		printf("manual: %s%s%s : Nao foi possivel mostrar a referencia\n", NEGRITO, toked1, SIMPLES);
	exit(0);
      }
      else
	      wait(0);
    }
    else if (strcmp(toked1, "kill")==0)
    {
      if (fork()==0)
      {
        if (execl("/usr/bin/man","",toked1, (char *)0))
  	  printf("manual: %s%s%s: Nao foi possivel mostrar a referencia\n", NEGRITO, toked1, SIMPLES);
	exit(0);
      }
      else
	      wait(0);
    }
    else if (strcmp(toked1, "top")==0)
    {
      if (fork()==0)
      {
        if (execl("/usr/bin/man","",toked1, (char *)0))
		printf("manual : %s%s%s : Nao foi possveil mostrar a referencia\n", NEGRITO, toked1, SIMPLES);
	exit(0);
      }
      else
	      wait(0);
    }
  }
  //-------------------------------------------------------------------------------------------------
  else if (strcmp(str, "passwd")==0)
  {
    toked1 = strtok(NULL, TOKEN);
    toked2 = strtok(NULL, TOKEN);
    if (!toked1)
    {
	  
      if (fork()==0)
      {
	  if (system("passwd"))
		  printf("passwd: Nao foi possivel alterar a senha do usuario\n", NEGRITO, SIMPLES);
	    exit(0);
      }
      else
	    wait(0);
    }
    else
    {
      if (param(str, toked1, toked2)) 
      {
        if (fork()==0)
        {
	  if (execl("/usr/bin/passwd","",toked1,toked2,(char *)0))
	    printf("passwd: %s%s%s: Nao e possivel alterar a senha do usuario\n", NEGRITO, toked2, SIMPLES);
	  exit(0);
	}
	else
  	  wait(0);
      }
    }
  }
  //---------------------------------------------------------------------------------------------
  else if (strcmp(str,"cat")==0)
  {
    toked1 = strtok(NULL, TOKEN);
    toked2 = strtok(NULL, TOKEN);
    if (param(str,toked1))
    {
      if (fork()==0)
      {
        if (execl("/bin/cat","", toked1, toked2, (char *)0))
	  printf("cat: %s%s%s: Nao foi possivel exibir o conteudo\n", NEGRITO, toked1, SIMPLES);
	exit(0);
      }
      else
	      wait(0);
    }
  }
  //-------------------------------------------------------------------------------------------
  else if (strcmp(str, "chmod")==0)
  {
    toked1 = strtok(NULL, TOKEN);
    toked2 = strtok(NULL, TOKEN);
    if (param(str, toked1, toked2))
    {
      if (fork()==0)	    
      {
	if (execl("/bin/chmod","",toked1, toked2, (char *)0))
	  printf("chmod: %s%s%s : Nao foi possivel trocar a permissao do arquivo\n", NEGRITO, toked1, SIMPLES);
	exit(0);
      }
      else
	      wait(0);
    }
  }
  //-------------------------------------------------------------------------------------------
  else if (strcmp(str, "cal")==0)
  {
    toked1 = strtok(NULL, TOKEN);
    toked2 = strtok(NULL, TOKEN);
    if (!toked1)
    {
      if (fork()==0)
      {
	if (system("cal"))
  	  printf("cal: Nao foi possivel mostrar o calendario\n", NEGRITO, SIMPLES);
	exit(0);	
      }
      else
	      wait(0);
    }
    else if (!toked2)
    {
      if (fork()==0)
      {
	  if (execl("/usr/bin/cal","",toked1, (char *)0))
	    printf("cal : %s%s%s: Nao foi possivel mostrar o calendario\n", NEGRITO, toked1, SIMPLES);
	  exit(0);
     }   
      else
          wait(0);
    }
    else if (fork()==0)
    {
	    if (execl("/usr/bin/cal","", toked1, toked2, (char *)0))
		    printf("cal: %s%s%s %s%s%s: Nao foi possivel mostrar o calendario\n", NEGRITO, toked1, toked2, SIMPLES);
	    exit(0);
    }
    else
	    wait(0);
  }
  //-------------------------------------------------------------------------------------------
  else if (strcmp(str,"ls")==0)
  {
    toked1 = strtok(NULL, TOKEN);
    toked2 = strtok(NULL, TOKEN);
    if (!toked1)
    {
      if (fork()==0)
      {
        if (system("ls"))
          printf("ls : Nao foi possivel listar os arquivos\n", NEGRITO, SIMPLES);
	exit(0);
      }
      else
	      wait(0);
    }
    else if (!toked2)
    {
      if (fork()==0)
      {
        if (execl("/bin/ls","", toked1, (char *)0))
		printf("ls: %s%s%s : Nao foi possivel listar os arquivos\n",NEGRITO, toked1, SIMPLES);
	exit(0);
      }
      else
	      wait(0);
    }
    else if (fork()==0)
    {
	    if (execl("/bin/ls","", toked1, toked2, (char *)0))
		    printf("ls: %s%s%s: %s%s%s : nao foi possivel listar os arquivos\n", NEGRITO, toked1, toked2, SIMPLES);
	    exit(0);
    }
    else
	    wait(0);
  }
  //-------------------------------------------------------------------------------------------
  else if (strcmp(str, "gzip")==0)
  {
    toked1 = strtok(NULL, TOKEN);
    toked2 = strtok(NULL, TOKEN);
    printf("gzip : %s%s%s t\n", NEGRITO, toked1, SIMPLES);
    printf("gzip : %s%s%s t\n", NEGRITO, toked2, SIMPLES);
    if (param(str, toked1))
    {
      if (fork()==0)
      {
        if (execl("/bin/gzip","",toked1, (char *)0))
		printf("gzip: %s%s%s: Nao foi possivel compactar arquivo\n", NEGRITO, toked1, SIMPLES);
	exit(0);
      }
      else
	      wait(0);
    }
    else
    {
      if (param(str, toked1, toked2))
      {
        if (fork()==0)
	{
  	  if (execl("/bin/gzip","",toked1, toked2, (char *)0))
		  printf("gzip: %s%s%s: %s%s%s : Nao foi possivel compactar arquivo\n", NEGRITO, toked1, toked2, SIMPLES);
	  exit(0);
	}
	else
		wait(0);
      }
    }    
  }
  //-------------------------------------------------------------------------------------------
  else if (strcmp(str,"ps")==0)
  {
    toked1 = strtok(NULL, TOKEN);
    if (!toked1)
    {
      if (fork()==0)
      {
        if (system("ps"))
		printf("ps: Nao foi possivel listar os processos\n", NEGRITO, SIMPLES);
	exit(0);
      }
      else
	      wait(0);
    }
    else
    {
    if (param(str, toked1))
    {
      if (fork()==0)
      {
        if (execl("/bin/ps","", toked1, (char *)0))
		printf("ps: %s%s%s: Nao foi possivel listar os processos\n", NEGRITO, toked1, SIMPLES);
	exit(0);
      }
      else
	      wait(0);
    }
    }
  }
  //-------------------------------------------------------------------------------------------
  else if (strcmp(str,"kill")==0)
  {
    toked1 = strtok(NULL, TOKEN);
    toked2 = strtok(NULL, TOKEN);
    if (param(str, toked1, toked2))
    {
      if (fork()==0)
      {
	if (execl("/bin/kill","",toked1, toked2, (char *)0))
		printf("kill: %s%s%s: Nao foi possivel cancelar o processo\n", NEGRITO, toked1, SIMPLES);
	exit(0);
      }
      else
	      wait(0);
    }
  }
  //-------------------------------------------------------------------------------------------
  else if (strcmp(str, "top")==0)
  {
    toked1 = strtok(NULL, TOKEN);
    if (!toked1)
    {
      if (fork()==0)
      {
        if (system("top"))
		printf("top: Nao foi possivel mostrar os processos\n", NEGRITO, SIMPLES);
	exit(0);
      }
      else
	      wait(0);
    }
  }
  //------------------------------------------------------------------------------------------
  else if (strcmp(str, "config")==0)
  {
    if (fork()==0)
    {
	    if (system("linuxconf"))
		    printf("config: Nao foi possivel abrir o módulo de configuracao\n", NEGRITO, SIMPLES);
	    exit(0);
    }
    else
	    wait(0);
  }
  //-------------------------------------------------------------------------------------------
  else if (strcmp(str, "desligar")==0)
  {
    if (fork()==0)
    {
      if (system("init 0"))
	      printf("desligar : nao foi possivel desligar o computador\n", NEGRITO, SIMPLES);
      exit(0);
    }
    else
	    wait(0);
  }
  //------------------------------------------------------------------------------------------
  else if (strcmp(str,"reiniciar")==0)
  {
    if (fork()==0)
    {
      if (system("init 6"))
	      printf("reiniciar: nao foi possivel reiniciar o computador\n", NEGRITO, SIMPLES);
      exit(0);
    }
    else
	    wait(0);
  }
  //-------------------------------------------------------------------------------------------
  else if (strcmp(str, "?") == 0)
    {
      printf("%sShell teste%s, ajuda\n", NEGRITO, SIMPLES);
      printf(" comandos disponiveis:\n");
      printf(" - %scls%s: limpa tela\n", NEGRITO, SIMPLES);
      printf(" - %sdir%s: lista diretorio atual\n", NEGRITO, SIMPLES);
      printf(" - %scd%s 'pasta': muda o diretorio atual para 'pasta'\n", NEGRITO, SIMPLES);
      printf(" - %smd%s 'pasta': cria diretorio 'pasta'\n", NEGRITO, SIMPLES);
      printf(" - %srd%s 'pasta': remove o diretorio 'pasta'\n", NEGRITO, SIMPLES);
      printf(" - %smove%s 'arquivo' 'novo': move 'arquivo' 'novo'\n", NEGRITO, SIMPLES);
      printf(" - %sdel%s 'arquivo': exclui 'arquivo'\n", NEGRITO, SIMPLES);
      printf(" - %srun %s 'programa': executa 'programa'\n", NEGRITO, SIMPLES);
      printf(" - %shist%s: mostra historico\n", NEGRITO, SIMPLES);
      printf(" - %sexit%s ou %sq%s: sair\n", NEGRITO, SIMPLES, NEGRITO, SIMPLES);
      //------------------------------------------------------------------------------------
      printf(" - %spwd%s : exibe o diretorio atual\n", NEGRITO, SIMPLES);
      printf(" - %slog%s [-mHa]: Mostra quem esta logado na maquina\n", NEGRITO, SIMPLES);
      printf(" - %sdisk%s [-ahP]: mostra status do disco\n", NEGRITO, SIMPLES);
      printf(" - %smemo%s [-bkmotVs retardo]: mostra status da memoria\n", NEGRITO, SIMPLES);
      printf(" - %smanual%s 'comando': exibe manual de referencia\n", NEGRITO, SIMPLES);
      printf(" - %spasswd%s: altera a senha do usuário atual\n", NEGRITO, SIMPLES);
      printf(" - %scat%s [-vetn] <arquivo>: exibe o conteudo do arquivo\n", NEGRITO, SIMPLES);
      printf(" - %schmod%s [permissao] <arquivo>: ajusta permissao de arquivo\n", NEGRITO, SIMPLES);
      printf(" - %sls%s [-larhR] <arquivo> : mostra os arquivos do diretorio\n", NEGRITO, SIMPLES);
      printf(" - %scal%s [mes][ano] : exibe o calendario\n", NEGRITO, SIMPLES);
      printf(" - %sgzip%s [-cvfrd] <arquivo> : compacta um arquivo\n", NEGRITO, SIMPLES);
      printf(" - %sps%s [-aelux] : mostra a lista dos processos\n", NEGRITO, SIMPLES);
      printf(" - %skill%s [sinal] [pid]: envia sinais a processos\n",NEGRITO, SIMPLES);
      printf(" - %stop%s : mostra os processos que estao executando\n", NEGRITO, SIMPLES);
      printf(" - %sreiniciar%s : reinicia o computador\n", NEGRITO, SIMPLES);
      printf(" - %sdesligar%s : desliga o computador\n", NEGRITO, SIMPLES);
      printf(" - %sconfig%s : configurar o computador\n", NEGRITO, SIMPLES);
    }
  else
    printf("%s : %scomando invalido%s\n", str, NEGRITO, SIMPLES);

  HISTORICO = addHist(HISTORICO, origCmd);

  return 1;
}

int main(int argc, char *argv[], char *const envp[])
{
  char input[STR];
  char hostname[STR];
  char str[STR], str2[STR], str3[STR];
  struct passwd *pwd;

  CLS;
  printf("%sShell by FABIO DE STEFANI, v%s%s\n", NEGRITO, VERSAO, SIMPLES);

  pwd = getpwuid(getuid());
  gethostname(hostname, STR);
  do
  {
    getcwd(str, STR);
    printf("%s@%s:%s> ", pwd->pw_name, hostname, str);
    gets(input);
  } while (comando(input, str, envp));

  return EXIT_SUCCESS;
}
