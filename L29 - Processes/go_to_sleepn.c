#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: go_to_sleepn seconds\n");
        exit(1);
    }
    int n = atoi(argv[1]);
    pid_t id = getpid();
    pid_t parent_id = getppid();
    fprintf(stderr, "Process %d with parent %d going to sleep now...\n",
        id, parent_id);
    sleep(n);
    fprintf(stderr, "Process %d with parent %d, I'm awake!\n",
        id, parent_id);
}