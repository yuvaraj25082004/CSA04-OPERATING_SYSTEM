#include <stdio.h>

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
    int completionTime;
    int isCompleted;
};

int main() {
    int n, i, j, currentTime = 0, totalWaitingTime = 0, totalTurnaroundTime = 0;
    float averageWaitingTime, averageTurnaroundTime;
    struct Process proc[50], temp;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input process details
    for (i = 0; i < n; i++) {
        proc[i].pid = i+1;
        printf("Enter arrival time, burst time and priority for process %d: ", proc[i].pid);
        scanf("%d %d %d", &proc[i].arrivalTime, &proc[i].burstTime, &proc[i].priority);
        proc[i].isCompleted = 0;
    }

    // Sort processes by arrival time
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (proc[i].arrivalTime > proc[j].arrivalTime) {
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }

    // Schedule processes using Priority algorithm
    for (i = 0; i < n; i++) {
        int highestPriority = -1, selectedProcessIndex = -1;
        for (j = 0; j < n; j++) {
            if (proc[j].arrivalTime <= currentTime && proc[j].isCompleted == 0) {
                if (proc[j].priority > highestPriority) {
                    highestPriority = proc[j].priority;
                    selectedProcessIndex = j;
                }
            }
        }
        if (selectedProcessIndex == -1) {
            currentTime++;
            i--;
            continue;
        }
        proc[selectedProcessIndex].completionTime = currentTime + proc[selectedProcessIndex].burstTime;
        proc[selectedProcessIndex].turnaroundTime = proc[selectedProcessIndex].completionTime - proc[selectedProcessIndex].arrivalTime;
        proc[selectedProcessIndex].waitingTime = proc[selectedProcessIndex].turnaroundTime - proc[selectedProcessIndex].burstTime;
        totalWaitingTime += proc[selectedProcessIndex].waitingTime;
        totalTurnaroundTime += proc[selectedProcessIndex].turnaroundTime;
        proc[selectedProcessIndex].isCompleted = 1;
        currentTime = proc[selectedProcessIndex].completionTime;
    }

    // Calculate average waiting time and average turnaround time
    averageWaitingTime = (float)totalWaitingTime / n;
    averageTurnaroundTime = (float)totalTurnaroundTime / n;

    // Display process details and scheduling results
    printf("\nProcess\tArrival\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].arrivalTime, proc[i].burstTime, proc[i].priority, proc[i].completionTime, proc[i].turnaroundTime, proc[i].waitingTime);
    }
    printf("Average waiting time: %.2f\n", averageWaitingTime);
    printf("Average turnaround time: %.2f\n", averageTurnaroundTime);

    return 0;
}