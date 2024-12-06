#include<stdio.h>
#include<stdlib.h>

typedef struct Processes{
char name;
int at,bt,rt,tat,ct,wt;
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
int shortest;
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
    p[i].rt=p[i].bt;
}
sort(p,n);
for(int t=0;remain!=0;t++){
    shortest=9999;
    s=-1;
    for(int i=0;i<n;i++){
        if(p[i].at<=t && p[i].rt<shortest && p[i].rt!=0){
            s=i;
            shortest=p[s].rt;
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
        sum_tat=sum_tat+p[s].tat;
        p[s].wt=p[s].tat-p[s].bt;
        sum_wt=sum_wt+p[s].wt;
    }
}
float avg_tat=sum_tat/(float)n;
float avg_wt=sum_wt/(float)n;
printf("\n");
printf("Avg tat is : %0.2f\n",avg_tat);
printf("Avg wt is : %0.2f\n",avg_wt);
return 0;
}