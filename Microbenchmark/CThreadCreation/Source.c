#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>

#define NUM_THREADS_CREATE 1
#define NUM_REPETITIONS 1000

void show(int i) {
	i++;
}

DWORD WINAPI myThreadFunction(LPVOID data) {
	show((int) data);
	return 0;
}

int main(int argc, char* argv[]) {

	// THREAD CREATION

	HANDLE arrayThread[NUM_THREADS_CREATE];
	DWORD threadId;
	FILE* f;
	f = fopen("th_create_c_1.csv", "w");
	float sum = 0;
	// creating threads
	for (int i = 0; i < NUM_REPETITIONS; i++) {
		clock_t start = clock();
		for (int j = 0; j < NUM_THREADS_CREATE; j++) {
			arrayThread[j] = CreateThread(NULL, 0, myThreadFunction, (void*)i, 0, &threadId);
		}

		WaitForMultipleObjects(NUM_THREADS_CREATE, arrayThread, TRUE, INFINITE);
		DWORD lpExitCode;

		for (int i = 0; i < NUM_THREADS_CREATE; i++)
		{
			CloseHandle(arrayThread[i]);
		}

		clock_t end = clock();
		double time = (double)(end - start) / CLOCKS_PER_SEC;
		sum += time;
	}
	fprintf(f, "%f", sum / NUM_REPETITIONS);
	fclose(f);
	printf("\nDONE_CREATE\n");

	getchar();
	return 0;
}