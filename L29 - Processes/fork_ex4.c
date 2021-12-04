#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void) {
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
        printf("Child process %d with parent %d\n", 
            id, parent_id);
        char *const args[] = {
            "go_to_sleepn",    // name of program
            "5",               // number of seconds to sleep
            NULL
        };
        execv("./go_to_sleepn", args);
    }
    // parent process
    else {
        pid_t id = getpid();
        pid_t parent_id = getppid();
        printf("Process %d with parent %d and child %d\n", 
            id, parent_id, child_id);
    }
    return 0;
}