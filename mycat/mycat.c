/* mycat.c */
/* A simple implementation of the cat command in C */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int c;
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <file> \n", argv[0]);
        return 1;
    }
    for (int i = 1; i < argc; i++)
    {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL)
        {
            fprintf(stderr, "mycat: Could not open file %s\n", argv[i]);
            continue;
        }
    
        while ((c = fgetc(file)) != EOF)
        {
            putchar(c);
        }
        fclose(file);
        printf("\n");
    }
    return 0;
}