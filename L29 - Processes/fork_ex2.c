#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void) {
    int x = 1;
    double y = 2.0;
    pid_t child_id = fork();

    // fork returns -1 on failure
    if (child_id == -1) {
        fprintf(stderr, "can't fork, error %d\n", errno);
        exit(EXIT_FAILURE);
    }
    // in the child process, fork returns 0
    else if (child_id == 0) {
        pid_t id = getpid();
        pid_t parent_id = getppid();
        x = 1000;
        y = 2000.0;
        printf("Process %d with parent %d : x = %d, y = %f\n", 
            id, parent_id, x, y);
    }
    // parent process
    else {
        pid_t id = getpid();
        pid_t parent_id = getppid();
        printf("Process %d with parent %d and child %d : x = %d, y = %f\n", 
            id, parent_id, child_id, x, y);
    }
    return 0;
}