#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <sys/timeb.h>
#include <ctime>
#include <chrono>

#define NUM_REPETITIONS 1000000

int main(int argc, char* argv[]) {
	FILE* f3;
	FILE* f4;
	std::chrono::duration<double, std::milli> time, time2;
	f3 = fopen("alloc_static_cpp.csv", "w");

	auto start = std::chrono::steady_clock::now();
	for (int i = 0; i < NUM_REPETITIONS; i++) {
		int a[1000];
	}
	auto end = std::chrono::steady_clock::now();
	//printf("%d %d\n", start, end);
	time = (end - start) / 1000;
	//printf("%.10f\n", time / NUM_REPETITIONS);
	fprintf(f3, "%.10f", time / NUM_REPETITIONS);
	f4 = fopen("alloc_dynamic_cpp.csv", "w");
	auto start2 = std::chrono::steady_clock::now();
	for (int i = 0; i < NUM_REPETITIONS; i++) {
		int* b = (int*)malloc(sizeof(int) * 1000);
	}
	auto end2 = std::chrono::steady_clock::now();
	time2 = (end2 - start2) / 1000;
	//printf("%.10f", time2 / NUM_REPETITIONS);
	fprintf(f4, "%.10f", time2 / NUM_REPETITIONS);
	printf("\nDONE\n");
	fclose(f3);
	fclose(f4);
	getchar();
	return 0;
}