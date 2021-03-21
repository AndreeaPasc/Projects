#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>

#define NUM_REPETITIONS 1000
#define NUM_THREADS_SWITCH 2

HANDLE thMutex;
HANDLE thMutex2;
clock_t start, end;
double t1 = 0, time1 = 0;
time_t t;

void show(int i) {
	//i++;
	time1 += t1;
}

DWORD WINAPI myThreadFunction(LPVOID data) {
	WaitForSingleObject(thMutex, INFINITE);
	end = clock();
	//printf("start = %d\n", start);
	//printf("Thread %d starts\n", data);
	show((int)data);
	t1 = (double)end -start;
    start = clock();
	//printf("Thread %d stops\n", data);
	ReleaseMutex(thMutex);

 	return 0;
}

int main(int argc, char* argv[]) {

	//THREAD SWITCHING

	HANDLE arrayThread2[NUM_THREADS_SWITCH];
	thMutex = CreateMutex(NULL, FALSE, NULL);
	
	DWORD threadId2;
	FILE* f2;
	f2 = fopen("th_switch_c_2.csv", "w");
	//double time = 0;
	double sum2 = 0;

	// creating threads
	for (int i = 0; i < NUM_REPETITIONS; i++) {
		sum2 = 0;
		for (int j = 0; j < NUM_THREADS_SWITCH; j++) {
			arrayThread2[j] = CreateThread(NULL, 0, myThreadFunction, (void*)(j + 1), 0, &threadId2);
		}

		WaitForMultipleObjects(NUM_THREADS_SWITCH, arrayThread2, TRUE, INFINITE);
		DWORD lpExitCode;

		for (int i = 0; i < NUM_THREADS_SWITCH ; i++)
		{
			CloseHandle(arrayThread2[i]);
		}
		//printf("t = %lf\n", time1);
		//time += t;
		//time += start;
	}
	time1 /= CLOCKS_PER_SEC;
	fprintf(f2, "%lf", time1 / NUM_REPETITIONS);
	fclose(f2);
	printf("\nDONE_SWITCH\n");

	getchar();
	return 0;
}