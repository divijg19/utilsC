#include <ctype.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <file> ... <fileN> \n", argv[0]);
        return 1;
    }
    int c;
    for (int i = 1; i < argc; i++)
    {
        int in_word = 0;
        FILE *file = fopen(argv[i], "r");
        if (file == NULL)
        {
            fprintf(stderr, "%s cannot open: %s\n", argv[0], argv[i]);
            continue;
        }
        long words = 0;
        long bytes = 0;
        long lines = 0;
        while ((c = fgetc(file)) != EOF)
            {
                bytes++;
                if (c == '\n')
                {
                    lines++;
                }
                if (isspace(c))
                {
                    in_word = 0;
                }
                else if (!in_word)
                {
                    words++;
                    in_word = 1;
                }
            }
        fclose(file);
        printf("%ld %ld %ld %s\n", lines, words, bytes, argv[i]);
    }
    return 0;
}