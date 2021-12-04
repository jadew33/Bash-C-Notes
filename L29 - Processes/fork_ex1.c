#include <unistd.h>
#include <stdio.h>

int main(void) {
    int x = 1;
    double y = 2.0;
    fork();
    printf("x = %d, y = %f\n", x, y);
    return 0;
}