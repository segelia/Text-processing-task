#include "rand_malloc.h"
#include <stdio.h>
#include <stdlib.h>

char *get_line()
{
    char symbol;
    char *buf = NULL;
    int len = 0;

    while ((symbol = getchar()) != EOF)
    {
        buf = realloc(buf, sizeof(char) * (len + 1));
        buf[len++] = symbol;
    }

    if (EOF && len == 0)
    {
        return NULL;
    }

    buf = realloc(buf, sizeof(char) * (len + 1));
    buf[len] = '\0';

    return buf;
}

void print_line(char *buf)
{
    if (buf != NULL)
    {
        int printing = 1;
        while (printing){
            if (buf == '\n'){
                printf("\n");
            }
        }
        printf("%s\n", buf);
    }
}

int main()
{
    char *buf = get_line();
    print_line(buf);
    free(buf);
}