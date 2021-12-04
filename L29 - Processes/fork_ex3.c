#include <unistd.h>
#include <stdio.h>

int main(void) {
    printf("Hello, world!");
    fork();
    return 0;
}