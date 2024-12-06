#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
pid_t p;
p=fork();
if(p==0){
    printf("It is a child process %d\n" ,getpid());
}
else if(p>1){
    printf("It is a parent process %d\n",getpid());
}
else{
    printf("not a parent not a child\n");
}
return 0;
}