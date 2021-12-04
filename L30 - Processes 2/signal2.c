#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void do_something() {
    printf("parent doing something\n");
    sleep(1);
}

void notice_termination(int pid, int status) {
    printf("child %d exited with status %d\n", pid, status);
}

void sigchld_handler(int sig) {
    int status;
    int old_errno = errno;
    while (1) {
        int pid = waitpid (WAIT_ANY, &status, WNOHANG);
        if (pid < 0) {
            perror ("waitpid");
            break;
        }
        if (pid == 0) {
            break;
        }
        // perhaps call a function to process the exit status
        notice_termination(pid, status);
    }
    errno = old_errno;
}


int main(void) {
    // install signal handler before fork
    signal(SIGCHLD, &sigchld_handler);

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
        while (1) {
            do_something();
        }
    }
    return 0;
}