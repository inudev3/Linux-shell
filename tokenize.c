//
// Created by inust33 on 21. 11. 21..
//

#include <string.h>

extern int tokenize(char* buf, char* tokens[], int maxTokens){
    char* s;

    char delims[] = " \r\n\t";
    int argv=0;
    s = strtok(buf, delims);
    while(s!=NULL && argv<maxTokens){
        tokens[argv] = s;
        argv++;
        s= strtok(NULL, delims);
    }
    tokens[argv] = (char*)0;
    return argv;
}
