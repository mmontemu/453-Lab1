#include "forkhelp.h"

int main(int argc, char *argv[]) {
    pid_t parent, pid, child;
    int wstatus;
    printf("Hello World\n");
    /*forks and gets the pid
     *to prepare everything*/
    parent = fork();
    pid = getpid();
    if(parent) {
        printf("This is the parent, pid %d\n.", pid);
        child = wait(&wstatus);
        printf("This is the parent, pid %d, signing off.\n", pid);
    }
    else {
        printf("This is the child, pid %d.\n", pid);
    }

    return 0;
}