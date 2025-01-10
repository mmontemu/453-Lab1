#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#define READ END 0
#define WRITE END 1
int main(int argc, char *argv[]) {
    int pipe_1[2];
    pid_t child1, child2, write_file;
    if ( pipe(pipe_1) ) {
        perror("error creating pipe");
        exit(-1);
    }
    write_file = open("./outfile", O_WRONLY | O_CREAT | O_TRUNC,  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
    if ( ! (child1 = fork()) ) {
        /* child one stuff */
        /* dup appropriate pipe ends */
        if ( -1 == dup2(one[WRITE_END],STDOUT_FILENO) ) {
            perror("dup2");
            exit(-1);
        }
        /* clean up */
        close(pipe_1[READ_END]);
        close(pipe_1[WRITE_END]);
        /* do the exec */
        execl("/bin/ls","ls",NULL);
        perror("/bin/ls");
        exit(-1);
    }
    if ( ! (child2 = fork()) ) {
        /* child two stuff */
        if ( -1 == dup2(pipe_1[READ_END],STDIN_FILENO) ) {
            perror("dup2");
            exit(-1);
        }

        if ( -1 == dup2(write_file ,STDOUT_FILENO) ) {
            perror("dup2");
            exit(-1);
        }
        /* clean up */
        close(pipe_1[READ_END]);
        close(pipe_1[WRITE_END]);
        /* do the exec */
        execl("/bin/sort","sort","-r",NULL);
        perror("/bin/sort");
        exit(-1);
    }
    /* parent stuff */
    /* clean up */
    close(pipe_1[READ_END]);
    close(pipe_1[WRITE_END]);
    close(write_file);
    if ( −1 == wait(NULL) ) { /* wait for one child */
        perror("wait");
    }
    if ( −1 == wait(NULL) ) { /* wait for the second child */
        perror("wait");
    }
    exit(0);
}