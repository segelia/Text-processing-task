#include "rand_malloc.h"
#include <stdio.h>
#include <stdlib.h>

char *get_line()
{
    char symbol;
    char *buf = NULL;
    int len = 0;

    while ((symbol = getchar()) != '\n')
    {
        if (symbol == EOF){
            buf = realloc(buf, sizeof(char) * (len + 1));
            buf[len] = '\0';
            return buf;
        }
        buf = realloc(buf, sizeof(char) * ++len);
        buf[len - 1] = symbol;
    }

    //save the memory location of newline

    return buf;
}

void print_line(buf){
    
}
