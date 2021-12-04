#include <stdio.h>
#include <string.h>

void main(int argc, char *argv[])
{
    char res[500] = "";
    for (int i = 1; i < argc; i++)
    {
        if (argc > 2 && i >= 2)
            strcat(res, " ");
        strcat(res, argv[i]);
    }
    printf("%s\n", res);
}