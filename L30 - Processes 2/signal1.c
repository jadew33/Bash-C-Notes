#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void catcher(int sig) {
	// prevents Ctrl-C from working:	
	if (sig == SIGINT) {		
		printf("detected SIGINT.\n");	
	}
    // prevents Ctrl-Z from working:
    else if (sig == SIGTSTP) {
        printf("detected SIGTSTP.\n");
    }
}

int main(void) {
    // DON'T uncomment both lines in WSL
    //signal(SIGINT, &catcher);
    signal(SIGTSTP, &catcher);
    while (1) {
        sleep(1);
    }
}