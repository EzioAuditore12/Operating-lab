#include<stdio.h>
typedef struct Processes{
    char name;
    int at,bt,wt,ct,tat,priority,rt;
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
int n,remain,s,max_priority;
float tat_sum=0,wt_sum=0;
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
    printf("Enter priority:");
    scanf("%d",&p[i].priority);
    p[i].rt=p[i].bt;
}
sort(p,n);
for(int t=0;remain!=0;t++){
    s=-1;
    max_priority=0;
    for(int i=0;i<n;i++){
        if(p[i].at<=t && p[i].priority>max_priority && p[i].rt!=0){
            s=i;
            max_priority=p[s].priority;
        }
    }
    if(s==-1){
        printf("*");
        continue;
    }
    printf("|%c",p[s].name);
    p[s].rt--;
    if(p[s].rt==0){
        remain--;
        p[s].ct=t+1;
        p[s].tat=p[s].ct-p[s].at;
        tat_sum=tat_sum+p[s].tat;
        p[s].wt=p[s].tat-p[s].bt;
        wt_sum=wt_sum+p[s].wt;
    }
}
float avg_tat=tat_sum/(float)n;
float avg_wt=wt_sum/(float)n;
printf("\n");
printf("Average tat %0.2f\n",avg_tat);
printf("Average wt %0.2f\n",avg_wt);
return 0;
}