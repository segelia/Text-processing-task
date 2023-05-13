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
        // checking for realloc overflow (add here)
        buf = realloc(buf, sizeof(char) * (len + 1));
        if (buf == NULL) //in case realloc is not sucessful and it returns null
        {
            printf("reallloc failed");
            exit(1);
        }
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

void reverse_line(char *buf){

}

void print_line(char* buf) {
    if (buf != NULL) {
        printf("%s\n", buf);
    }
}

int main()
{
    char *buf = get_line();
    print_line(buf);
    free(buf);
}