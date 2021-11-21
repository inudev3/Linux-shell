//
// Created by inust33 on 21. 11. 21..
//
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <stdlib.h>


extern void background(char** tokens, int index){
    tokens[index] = NULL;
    pid_t pid;
    if((pid=fork())==0){
        if(execvp(tokens[0], tokens)==-1){
            printf("No such command : %s\n",tokens[0]);
            exit(1);
        }
    }
    else if(pid<0){
        printf("fork error\n");
        exit(1);
    }
        //기다리지 않음
    else{
        exit(1);
    }
}