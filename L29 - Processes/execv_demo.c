#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    pid_t id = getpid();
    fprintf(stderr, "Process %d using execv\n", id);
    // only works if go_to_sleep is in this directory
    char *const args[] = {
        "go_to_sleepn",    // name of program
        "5",               // number of seconds to sleep
        NULL
    };

    execv("./go_to_sleepn", args);
    puts("hello!!!");  // never prints
}