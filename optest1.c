#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int PID;
    int arrivaltime;
    int bursttime;
    int priority;
} Process;

void readFile(const char *filename, Process **processes, int *Count) {
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Error ", filename);
        exit(1);
    }

    
    fscanf(file, "%d", Count); 
    *processes = (Process *)malloc(*Count * sizeof(Process));

   
    char top[100];
    fgets(top, sizeof(top), file);

    // Read the process data
    for (int i = 0; i < *Count; i++) {
        fscanf(file, "%d %d %d %d", 
               &(*processes)[i].PID, 
               &(*processes)[i].arrivaltime, 
               &(*processes)[i].bursttime, 
               &(*processes)[i].priority);
    }

    fclose(file);
}

void print(Process *processes, int Count) {
    printf("PID\tarrival time\tburst time\ttriority\n");
    for (int i = 0; i < Count; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", 
               processes[i].PID, 
               processes[i].arrivaltime, 
               processes[i].bursttime, 
               processes[i].priority);
    }
}

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        printf("usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Process *processes = NULL;
    int Count = 0;


    readFile(argv[1], &processes, &Count);

   
    print(processes, Count);

    
    free(processes);

    return 0;
}