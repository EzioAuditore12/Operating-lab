/*
2. SJF NP (Shortest Job First Non-Preemptive):
 - The process with the shortest CPU burst time is selected for execution next.
 - Non-preemptive means the current process runs to completion before the CPU is allocated to the
next process.
*/
#include<stdio.h>

typedef struct processes {
    char name;
    int arrival_time;
    int burst_time;
    int e; 
} processes;

void sortAt(processes process[], int n) {
    processes temp;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(process[i].arrival_time > process[j].arrival_time) {
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }
}

void printTable(processes process[], int n) {
    printf("Process Name  Arrival Time  Burst Time\n");
    for(int i = 0; i < n; i++) {
        printf("%c\t\t%d\t\t%d\n", process[i].name, process[i].arrival_time, process[i].burst_time);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    processes process[n];
    for(int i = 0; i < n; i++) {
        printf("Enter process name: ");
        scanf(" %c", &process[i].name);
        printf("Enter arrival time for %c: ", process[i].name);
        scanf("%d", &process[i].arrival_time);
        printf("Enter burst time for %c: ", process[i].name);
        scanf("%d", &process[i].burst_time);
        process[i].e = 0;  
    }

    printf("\nEntered details:\n");
    printTable(process, n);

    sortAt(process, n);  

    int completed = 0;
    float total_time = 0;
    float waiting_time[n], turnaround_time[n], completion_time[n];

    char gantt_chart[n];
    int gantt_time[n];

    while (completed < n) {
        int min_burst_time = 9999;
        int shortest = -1;

        for(int i = 0; i < n; i++) {
            if(process[i].arrival_time <= total_time && process[i].e == 0 && process[i].burst_time < min_burst_time) {
                min_burst_time = process[i].burst_time;
                shortest = i;
            }
        }

        if(shortest == -1) {
            total_time++;  
            continue;
        }

        process[shortest].e = 1;
        completion_time[shortest] = total_time + process[shortest].burst_time;  
        turnaround_time[shortest] = completion_time[shortest] - process[shortest].arrival_time;  
        waiting_time[shortest] = turnaround_time[shortest] - process[shortest].burst_time;  

        total_time += process[shortest].burst_time;  

        gantt_chart[completed] = process[shortest].name;
        gantt_time[completed] = total_time;

        completed++;
    }

    printf("\nGantt Chart:\n");
    for(int i = 0; i < completed; i++) {
        printf(" %c ", gantt_chart[i]);
        if (i != completed - 1)
            printf("->");
    }
    printf("\n");

    printf("Time: 0");
    for(int i = 0; i < completed; i++) {
        printf("   %d", gantt_time[i]);
    }
    printf("\n");

    printf("\nProcess Name  Arrival Time  Burst Time  Completion Time  Turnaround Time  Waiting Time\n");
    float total_waiting_time = 0.0, total_turnaround_time = 0.0;
    for(int i = 0; i < n; i++) {
        printf("%c\t\t%d\t\t%d\t\t%.0f\t\t%.0f\t\t%.0f\n", 
            process[i].name, process[i].arrival_time, process[i].burst_time, 
            completion_time[i], turnaround_time[i], waiting_time[i]);

        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);

    return 0;
}
