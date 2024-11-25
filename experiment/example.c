#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum) {
    int rem_bt[n];
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];
    int t = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) { 
            if (rem_bt[i] > 0) {
                done = 0;
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                    // printf("\nTask %d is completed \n",i+1);
                }
            }
        }
        if (done == 1)
            break;
    }
    printf("Process No. \t Burst Time \t Waiting Time\n");
    for (int i = 0; i < n; i++)
        printf("%d \t\t %d \t\t %d\n", i + 1, bt[i], wt[i]);
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {5, 6, 8};
    int wt[n];
    int quantum = 4;
    findWaitingTime(processes, n, burst_time, wt, quantum);
    return 0;
}