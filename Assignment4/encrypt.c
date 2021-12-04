#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: encrypt shift str\n");
        exit(1);
    }
    int shift = (int)atof(argv[1]);
    char *msg = argv[2];
    int msg_len = strlen(msg);
    char alpha[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char enc[msg_len + 1];
    enc[msg_len] = '\0';
    for (int i = 0; i < msg_len; i++)
    {
        int index = -1;
        for (int j = 0; j < sizeof(alpha); j++)
            if (alpha[j] == toupper(argv[2][i]))
                index = j;
        if ((index+shift) < 0)
            enc[i] = alpha[26+((index + shift) % 26)];
        else
            enc[i] = alpha[(index + shift) % 26];
        if (index == -1)
            enc[i] = argv[2][i];
    }
    printf("%s\n", enc);
}