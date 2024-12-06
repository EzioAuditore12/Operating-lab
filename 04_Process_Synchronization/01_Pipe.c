#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int fd[2];
    if(pipe(fd)==-1){
        printf("Pipe creation failed");
        exit(0);
    }
    pid_t pid;
    char write_msg[100];
    char read_msg[100];
    pid=fork();
    if(pid==0){
        printf("entered child process:\n");
        close(fd[0]);//close reading end
        fgets(write_msg,sizeof(write_msg),stdin);
        write(fd[1],write_msg,strlen(write_msg)+1);
        close(fd[1]);
    }
    if(pid>0){
        printf("Entered parent process:\n");
        close(fd[1]);
        read(fd[0],read_msg,sizeof(read_msg));
        printf("Parent recieved message: %s\n",read_msg);
    }
}