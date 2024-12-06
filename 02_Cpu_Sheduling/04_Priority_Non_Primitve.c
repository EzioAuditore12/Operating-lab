#include<stdio.h>
typedef struct Processes{
char name;
int at,bt,priority,tat,ct,wt,e;
}Processes;

void sort(Processes p[],int n){
    Processes temp;
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
int n,s,remain;
float sum_tat=0,sum_wt=0;
int max_priority;
printf("Enter the number of processes you want:");
scanf("%d",&n);
remain=n;
Processes p[n];
for(int i=0;i<n;i++){
    printf("Enter process name:");
    scanf(" %c",&p[i].name);
    printf("Enter process arrival time:");
    scanf("%d",&p[i].at);
    printf("Enter process burst time:");
    scanf("%d",&p[i].bt);
    printf("Enter priority");
    scanf("%d",&p[i].priority);
    p[i].e=0;
}
sort(p,n);
for(int t=0;remain!=0;){
    s=-1;
    max_priority=0;
    for(int i=0;i<n;i++){
        if(p[i].at<=t && p[i].priority>max_priority && p[i].e==0){
            s=i;
            max_priority=p[s].priority;
        }
    }
    if(s==-1){
        printf("*");
        t++;
        continue;
    }
    printf("|%c",p[s].name);
    remain--;
    t=t+p[s].bt;
    p[s].e=1;
     p[s].ct=t;
    p[s].tat=p[s].ct-p[s].at;
    sum_tat=sum_tat+p[s].tat;
    p[s].wt=p[s].tat-p[s].bt;
    sum_wt=sum_wt+p[s].wt;
}
float avg_tat=sum_tat/(float)n;
float avg_wt=sum_wt/(float)n;
printf("\n");
printf("Avg tat is : %0.2f\n",avg_tat);
printf("Avg wt is : %0.2f\n",avg_wt);
return 0;
}