#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <sys/timeb.h>

#define NUM_REPETITIONS 1000000

int main(int argc, char* argv[]){
	FILE* f3;
	FILE *f4;
	
	f3 = fopen("alloc_static_c.csv", "w");

	clock_t start = clock();
	for (int i = 0; i < NUM_REPETITIONS; i++) {
		int a[1000];
	}
	clock_t end = clock();
	//printf("%d %d\n", start, end);
	double time = (double)(end - start) / (double) CLOCKS_PER_SEC;
	//printf("%.10f\n", time/ NUM_REPETITIONS);
	fprintf(f3, "%.10f", time / NUM_REPETITIONS);

	f4 = fopen("alloc_dynamic_c.csv", "w");
	clock_t start1 = clock();
	for (int i = 0; i < NUM_REPETITIONS; i++) {
		int* b = (int*)malloc(sizeof(int) * 1000);
	}
	clock_t end1 = clock();
	double time2 = ((double)(end1 - start1) / (double) CLOCKS_PER_SEC);
	//printf("%.10f", time2 / NUM_REPETITIONS);
	fprintf(f4, "%.10f", time2 / NUM_REPETITIONS);
	printf("\nDONE\n");
	fclose(f3);
	fclose(f4);
	getchar();
	return 0;
}