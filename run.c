//
// Created by inust33 on 21. 11. 21..
//

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


void redirect(char**, int);
void background(char**, int );
int tokenize(char* , char* [], int );
pid_t pid;
bool run(char* buf){
    char* tokens[MAX_LINE];
    char* dir;
    int i=0;
    int token_count;
    int back=0; int rd=0;
    int status;
    token_count = tokenize(buf, tokens, sizeof(tokens)/sizeof(char*));
    if(token_count==0)return true;

    if (!strcmp(tokens[0], "cd")) {
        if (tokens[1] == NULL) {
            printf("USEAGE : cd directory\n");
            return false;
        }
        chdir(tokens[1]);
    } else if (!strcmp(tokens[0], "quit")) {
        exit(1);
    } else {
        if ((pid = fork()) == 0) {
            while (tokens[i]) {
                if (!strcmp(tokens[i], ">")) {
                    redirect(tokens, i);
                } else if (!strcmp(tokens[i], "&")) {
                    background(tokens, i);
                }
                i++;
            }
            if(execvp(tokens[0],tokens)==-1){
                printf("%s : command not found\n",tokens[0]);
                exit(1);
            }
        }
        else if(pid< 0){
            printf("fork error\n");
            exit(1);
        }
        else
            wait(&status);
    }
    memset(tokens,0x00, MAX_LINE);
    return 1;
}