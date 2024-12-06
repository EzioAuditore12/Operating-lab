/*
II.Round Robin Sheduling
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct data{
    char name;
    int bt, at, st, cmp, wt, tat;
} process;


process rq[10000];
int b = -1;
int f = 0;

void enqueue(process p){
    if(f==9999) return;
    rq[f++] = p;
}

process dequeue(){
    process fal;
    fal.bt = -1;
    ++b;
    if(b==9999 || b == -1) return fal;
    return rq[b];
}

int isCompleted(){
    return (b == f);
}

void process_printer(process pq[], int n){
    printf("\nProcess name\tBurst time\tArrival time\tStart Time\tCompleted Time\tTurn Around time\tWeighting Time\n");
    for(int i=0;i<n;i++){
        printf("%c\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", pq[i].name, pq[i].bt, pq[i].at, pq[i].st, pq[i].cmp, pq[i].tat, pq[i].wt);
    }
}

int index_finder(process my_p[], int n, process top){
    int pi = 0;
    for(int i=0;i<n;i++){
        if(my_p[i].name == top.name){
            pi = i;break;
        }
    }
    return pi;
}

void timeSetter(process my_p[], int n, process top, int time){
    if(top.bt == 0){
        int pi = index_finder(my_p, n, top);
        my_p[pi].cmp = time;
        my_p[pi].tat = time  - my_p[pi].at;
        my_p[pi].wt = my_p[pi].tat - my_p[pi].bt;
    }
}

process *roundRobin(int gant_size, process my_p[], int n, int tq){
    process *gant_chart = malloc(sizeof(process) * gant_size);

    // gi = gant_chart index
    int time = -1, gi = 0;

    int temp_tq = 0;

    int pi = 0;
    process top, current_process;
    int cur_ar_time = -1;
    int i = 0;

    while(!isCompleted()){
        time++;
        
        // process arrived, then enqueue
        if(time == my_p[pi].at){
            current_process = my_p[pi];
            enqueue(current_process);
            pi++;
        }

        if(top.bt == 0 || temp_tq == 0 && f!=0){
            top = dequeue();

            if(top.at > cur_ar_time){
                i = index_finder(my_p, n, top);
                my_p[i].st = time;
                cur_ar_time = top.at;
            }

            if(top.bt == -1){
                continue; // if no process in queue yet
            }
            temp_tq = tq;
        }
        
        if(temp_tq > 0){
            temp_tq--;
            
            if(top.bt > 0){
                top.bt--;
                // printf("\nTime: %d, ID: %c, bt: %d\n", time, top.name, top.bt);
                timeSetter(my_p, n, top, time+1);
            }
        }
        if(top.bt==0 || temp_tq == 0 && f!=0 ){
            gant_chart[gi++] = top;
            if(top.bt != 0)
            enqueue(top);
        }

        
    }

    return gant_chart;

}

void print_gant(process gant_chart[], int gant_size, int tq){
    printf("\n\nGantchart: \n");
    for(int i=0;isalpha(gant_chart[i].name);i++){
        printf("%c, ", gant_chart[i].name);
    }
}

int main(){
    int n;
    int gant_size = 0;
    printf("Enter number of process: ");
    scanf("%d",&n);

    process my_p[n];
    int tq = 3;
    printf("Enter number of TQ: ");
    scanf("%d",&tq);
    printf("Enter processes data\n");
    
   

    for(int i=0;i<n;i++){
        printf("Enter name: ");
        scanf(" %c", &my_p[i].name);

        printf("Enter arrival time: ");
        scanf("%d", &my_p[i].at);

        printf("Enter Burst time: ");
        scanf("%d", &my_p[i].bt);

        gant_size += my_p[i].bt;
    }

    process *gant_chart = roundRobin(gant_size, my_p, n, tq);

    print_gant(gant_chart, gant_size, tq);

    process_printer(my_p, n);

    float avgW = 0, avgT = 0;

    for(int i=0;i<n;i++){
        avgT += my_p[i].tat;
        avgW += my_p[i].wt;
    }

    printf("Average weight: %f\nAverage Tat: %f", avgW/n,avgT/n);
}