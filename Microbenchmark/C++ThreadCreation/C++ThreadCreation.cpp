#include <iostream>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <mutex>
using namespace std;

#define NUM_THREADS 1
#define NUM_REPETITIONS 1000

clock_t start;
int n = 10;

void MyThreadFunction(int data) {
    data++;
}

int main()
{
    FILE* f;
    double time;
    f = fopen("th_create_cpp_1.csv", "w");
    double sum = 0;
    for (int i = 0; i < NUM_REPETITIONS; i++) {
        double thSum = 0;
        std::vector<thread> arrayThreads(NUM_THREADS);

        clock_t start = clock();
        for (int i = 0; i < NUM_THREADS; i++) {
            arrayThreads[i] = thread(MyThreadFunction, i);
        }

        for (auto& th : arrayThreads) {
            th.join();
        }
        clock_t end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        sum += time;
    }
    fprintf(f, "%f", sum / NUM_REPETITIONS);
    fclose(f);
    printf("\nDONE\n");
    getchar();
    return 0;
}


