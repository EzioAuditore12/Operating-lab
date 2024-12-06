#include<stdio.h>
typedef struct process{
int pno;
int size;
int block;
}process;
int main()
{
int b;
printf("Enter the number of free blocks you want:");
scanf("%d",&b);
int memory[b];
for(int i=0;i<b;i++){
    scanf("%d",&memory[i]);
}
int n;
printf("Enter the number of processes you want:");
scanf("%d",&n);
process p[n];
for(int i=0;i<n;i++){
    p[i].pno=i+1;
    p[i].block=-1;
    scanf("%d",&p[i].size);
}
for(int i=0;i<n;i++){
    int max=-1;
    int s=-1;
    for(int j=0;j<b;j++){
       if (p[i].size <= memory[j] && memory[j] - p[i].size > max){
            max=memory[j]-p[i].size;
            s=j;
        }
    }
    if(s!=-1){
        memory[s]-=p[i].size;
        p[i].block=s+1;
    }
}
for(int i=0;i<n;i++){   

     if(p[i].block==-1)
            printf("P%d   Not Executed\n",p[i].pno);
        else
            printf("P%d   %d\n",p[i].pno,p[i].block);
}
return 0;
}