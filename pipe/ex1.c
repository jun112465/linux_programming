#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAXLINE 100

int main(){
    int n, length, fd[2];
    int pid;

    char message[MAXLINE], line[MAXLINE];

    // create pipe
    pipe(fd); 

    if((pid=fork()) == 0){
        // child process
        close(fd[0]);
        sprintf(message, "Hello, from PID : %d\n", getpid());
        length = strlen(message)+1;
        write(fd[1], message, length);
    }else{
        // parent process
        close(fd[1]);
        n = read(fd[0], line, MAXLINE);
        printf("[%d] %s\n", getpid(), line);
    }

    return 0;
}
