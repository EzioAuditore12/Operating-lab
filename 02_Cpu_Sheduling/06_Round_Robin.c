#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct processes{
    char name;
    int at,bt,ct,rt,tat,wt;
}processes;
void sort_at(processes p[],int n){
    processes temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].at>p[j].at){
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
}
int main()
{
int n,last_executed_time=0,time=0,time_quantum;
float total_tat=0,total_wt=0;
printf("Enter the number of processes you want:");
scanf("%d",&n);
int remain=n;
processes p[n];
for(int i=0;i<n;i++){
    printf("Enter process name:");
    scanf(" %c",&p[i].name);
    printf("Enter process arrival time:");
    scanf("%d",&p[i].at);
    printf("Enter process burst time:");
    scanf("%d",&p[i].bt);
    p[i].rt=p[i].bt;
}
sort_at(p,n);
printf("Enter time quantum:");
scanf("%d",&time_quantum);
int ready_queue[100];
int front=0,rear=-1;
bool idle=true;
while(remain>0){
    idle=true;
    for(int i=0;i<n;i++){
        if(p[i].at==time && p[i].rt>0){
            rear++;
            ready_queue[rear]=i;
        }
    }
    if(front<=rear){
        int curr=ready_queue[front];
        front++;
        idle=false;
        if(p[curr].rt>time_quantum){
            printf("|%c",p[curr].name);
            time=time+time_quantum;
            p[curr].rt=p[curr].rt-time_quantum;

            for(int i=0;i<n;i++){
                if(p[i].at>last_executed_time && p[i].rt>0){
                    rear++;
                    ready_queue[rear]=i;
                }
            }
            rear++;
            ready_queue[rear]=curr;
        }
        else{
            remain--;
            printf("|%c",p[curr].name);
            time=time+p[curr].rt;
            p[curr].ct=time;
            p[curr].tat=p[curr].ct-p[curr].at;
            total_tat=total_tat+p[curr].tat;
            p[curr].wt=p[curr].tat-p[curr].bt;
            total_wt=total_wt+p[curr].wt;
            p[curr].rt=0;
        }
        last_executed_time=time;
    }
    if(idle){
        printf("*");
        time++;
    }
}
float avg_tat=total_tat/(float)n;
float avg_wt=total_wt/(float)n;
printf("\n");
printf("Average tat is %0.2f\n",avg_tat);
printf("Average wt is %0.2f\n",avg_wt);
return 0;
}