#include "forkhelp.h"

int main(int argc, char *argv[]) {
    char **args;
    pid_t parent;
    int wstatus, child;
    if(argc == 2) {
        args = &(argv[1]);
    }
    else {
        fprintf(stderr, "usage: tryit command\n");
        return 0;
    }
    
    /*forks and sets the status to parent*/
    parent = fork();

    if(parent) {
        /*wait for the child, and check the status of the wait*/
        child = wait(&wstatus);
        if(child == -1 || !WIFEXITED(wstatus)) {
            perror("wait failed");
            exit(-57);
        }
        if(!WEXITSTATUS(wstatus)) {
            printf("Process %d succeeded.\n", parent);
        }
        else {
            printf("Process %d exited with an error code.\n", parent);
        }
    }
    else {
        /*exec, if it fails perror why it didn't*/
        execvp(argv[1], args);
        perror(args[0]);
        exit(-32);
    }


    return 0;
}