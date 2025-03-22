#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<limits.h>

#define max(x, y) x > y ? x: y

struct process
{
	
	int id;

	int starttime;
	int endtime;
	int run;
	int arrivaltime; 	
};
struct process proc[100];
int total;
void firstcomeserved()
{

	int time = 0;
	for(int i = 0; i < total; i++) {
		printf("process %d start at  %d and finished at  %d\n", proc[i].id, max(time, proc[i].arrivaltime), (max(time, proc[i].arrivaltime)) + proc[i].run);
		time = (max(time, proc[i].arrivaltime)) + proc[i].run;
	}
}

void shortjobfirst()
{
	
	int time = 0;
	int count = 0;
	int visited[total];
	for(int i =0; i < total; i++)visited[i] = 0;
	while(count < total) {
		int min = INT_MAX ;
		int mindex;
		for(int i = 0; i < total; i++) {
			if(proc[i].arrivaltime <= time ) {
				if(min > proc[i].run && visited[i] != 1) {
					mindex = i;
					min= proc[i].run;
				}
			}
			else break;
		}
		if(min == INT_MAX && count < total) {
			time++;
			continue;
		}
		
		
		visited[mindex]  = 1;
		count++;
		printf("Process %d started at time %d and finished at time %d\n", proc[mindex].id, max(time, proc[mindex].arrivaltime), (max(time, proc[mindex].arrivaltime)) + proc[mindex].run);
		time += min;

	}
}

int main()
{

	FILE *pFile = fopen("algtest.txt", "r");
	if (pFile == NULL)
	{
		printf("error and can't open file\n");
		exit(-1);
	}
	int i = 0;
	printf("process\tarrival\trun-time\n");
	while (fscanf(pFile, "%d%d%d", &proc[i].id, &proc[i].arrivaltime, &proc[i].run) != EOF)
	{
		printf("%d\t%d\t%d\n", proc[i].id, proc[i].arrivaltime, proc[i].run);
		i++;
	}
	total = i;

	
	printf("first come first served scheduling algorithm \n");
	firstcomeserved();

	printf("shortest job first scheduling algorithm \n");
	shortjobfirst();
	return 0;
}