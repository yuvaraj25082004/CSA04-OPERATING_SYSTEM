#include<stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20], i, j;
    float avwt=0, avtat=0;

    printf("Enter total number of processes(maximum 20): ");
    scanf("%d", &n);

    printf("\nEnter Process Burst Time\n");
    for(i=0; i<n; i++) {
        printf("P[%d]: ", i+1);
        scanf("%d", &bt[i]);
    }

    // waiting time for the first process is 0
    wt[0] = 0;

    // calculating waiting time
    for(i=1; i<n; i++) {
        wt[i] = 0;
        for(j=0; j<i; j++)
            wt[i] += bt[j];
    }

    printf("\nProcess\t Burst Time\t Waiting Time\t Turnaround Time");

    // calculating turnaround time and average waiting and turnaround time
    for(i=0; i<n; i++) {
        tat[i] = bt[i] + wt[i];
        avwt += wt[i]; 
        avtat += tat[i];
        printf("\nP[%d]\t\t %d\t\t %d\t\t %d", i+1, bt[i], wt[i], tat[i]);
    }

    avwt /= n;
    avtat /= n;
    printf("\n\nAverage Waiting Time: %f", avwt);
    printf("\nAverage Turnaround Time: %f\n", avtat);

    return 0;
}