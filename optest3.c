#include <stdio.h>

#define MAX 10  


void waitingtime(int process[], int n, int b[], int w[]) {
    w[0] = 0;  
    for (int i = 1; i < n; i++) {
        w[i] = b[i - 1] + w[i - 1];  
    }
}


void turnaroundtime(int process[], int n, int b[], int w[], int z[]) {
    for (int i = 0; i < n; i++) {
        z[i] = b[i] + w[i];  
    }
}


void averages(int n, int w[], int z[]) {
    float WT = 0, T = 0;

    for (int i = 0; i < n; i++) {
        WT += w[i];
        T += z[i];
    }

    printf("\naverage wait time = %.3f\n", WT /n);
    printf("average turnaround time = %.3f\n", T /n );
}


void GanttChart(int process[], int n, int b[]) {
    int totalTime = 0;

    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", process[i]);
        totalTime += b[i];
    }
    printf("|\n");

    
    totalTime = 0;
    printf("0");
    for (int i = 0; i < n; i++) {
        totalTime += b[i];
        printf("   %d", totalTime);
    }
    printf("\n");
}

int main() {
    int process[MAX], burstT[MAX], waitingT[MAX], turnaroundT[MAX], n;

    
    printf(" number of processes: ");
    scanf("%d", &n);

  
    printf("enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Burst time of P%d: ", i + 1);
        scanf("%d", &burstT[i]);
        process[i] = i + 1;  
    }

   
    waitingtime(process, n, burstT, waitingT);
    turnaroundtime(process, n, burstT, waitingT, turnaroundT);

   
    GanttChart(process, n, burstT);


    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", process[i], burstT[i], waitingT[i], turnaroundT[i]);
    }

    averages(n, waitingT, turnaroundT);

    return 0;
}

