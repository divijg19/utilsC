/* mycat.c */
/* A simple implementation of the cat command in C */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int c;
    if (argc < 2)
    {
        printf("Usage: %s <file> \n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }
    while ((c = fgetc(file)) != EOF)
    {
        putchar(c);
    }
    fclose(file);
    return 0;
}