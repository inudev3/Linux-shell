#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <fcntl.h>
#define MAX_LINE 1024

void background(char** tokens, int index);
void redirect(char** tokens, int index);
bool run(char *);
pid_t pid;



int main() {
    char buf[256];
    char pwd[MAX_LINE];
 while(1){
     getcwd(pwd, MAX_LINE);
     printf("%s $", pwd);
     fgets(buf, sizeof(buf)-1, stdin);
     if(run(buf)==false)
         break;
 }
 return 0;
}



