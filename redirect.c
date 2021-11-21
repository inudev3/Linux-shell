//
// Created by inust33 on 21. 11. 21..
//
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
extern void redirect(char** tokens, int index) {

    int fd;
    if (tokens[index]) {
        if (!tokens[index + 1]) {
            exit(1);
        } else {
            if ((fd = open(tokens[index + 1], O_RDWR | O_CREAT | S_IROTH, 0644)) == -1) {
                perror(tokens[index + 1]);
                exit(1);
            }
        }
        dup2(fd, STDOUT_FILENO);
        close(fd);
        tokens[index] = NULL;
        if (execvp(tokens[0], tokens) == -1) {
            printf("No such command : %s\n", tokens[0]);
            exit(1);
        }
    }
}