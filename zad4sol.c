#include "rand_malloc.h"
#include <stdio.h>
#include <stdlib.h>

char *get_line()
{
    char symbol;
    char *buf = NULL;
    int len = 0;
    int is_newline = 0;

    while ((symbol = getchar()) != EOF)
    {
        if (symbol == '\n')
        {
            is_newline = 1;
            break;
        }
        buf = realloc(buf, sizeof(char) * (len + 1));
        buf[len++] = symbol;
    }

    if (!is_newline && len == 0)
    {
        return NULL;
    }

    buf = realloc(buf, sizeof(char) * (len + 1));
    buf[len] = '\0';

    return is_newline ? buf : NULL;
}

void print_line(char *buf)
{
    if (buf != NULL)
    {
        printf("%s\n", buf);
    }
}

int main()
{
    char *buf = get_line();
    print_line(buf);
    free(buf);
}