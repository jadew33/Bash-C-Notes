#include <unistd.h>
#include <stdio.h>

int main(void) {
    fprintf(stderr, "Going to sleep now...\n");
    sleep(10);
    fprintf(stderr, "I'm awake!\n");
}