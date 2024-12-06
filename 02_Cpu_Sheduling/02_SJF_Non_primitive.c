#include<stdio.h>
typedef struct processes{
    char name;
    int wt,bt,ct,tat,at,e;
}processes;
void sort(processes p[],int n){
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
int n,s,remain;
float sum_tat=0,sum_wt=0;
int shortest;
printf("Enter the number of processes you want:");
scanf("%d",&n);
remain=n;
processes p[n];
for(int i=0;i<n;i++){
    printf("Enter process name:");
    scanf(" %c",&p[i].name);
    printf("Enter process arrival time:");
    scanf("%d",&p[i].at);
    printf("Enter process burst time:");
    scanf("%d",&p[i].bt);
    p[i].e=0;
}
sort(p,n);
for(int t=0;remain!=0;){
    shortest=9999;
    s=-1;
    for(int i=0;i<n;i++){
        if(p[i].at<=t && p[i].e==0 && p[i].bt<shortest){
            s=i;
            shortest=p[s].bt;
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