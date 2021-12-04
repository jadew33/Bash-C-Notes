#include <stdio.h>

void main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        puts(argv[i]);
    }
}