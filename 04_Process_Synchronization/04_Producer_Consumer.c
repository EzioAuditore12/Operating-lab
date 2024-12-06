#include<stdio.h>
#include<stdlib.h>
int mutex=1;
int empty=10;
int full=0;
int x=0;
void Producer(){
    mutex=0;
    empty--;
    full++;
    x++;
    printf("Item produced %d\n",x);
    mutex=1;
}
void Consumer(){
    mutex=0;
    empty++;
    full--;
    printf("Item consumed %d\n",x);
    x--;
    mutex=1;
}
int main()
{
int n;
for(int i=1;i>0;i++){
printf("Enter your choice:\n1:Proucer\n2:Consumer\n3:Exit\n");
scanf("%d",&n);
if(n==1){
    if(mutex==1 && empty!=0){
        Producer();
    }
    else{
        printf("Buffer is full");
    }
}
if(n==2){
    if(mutex==1 && full!=0){
        Consumer();
    }
    else{
        printf("Buffer is empty");
    }
}
if(n==3){
    exit(0);
}
}
return 0;
}