#include <iostream>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <mutex>
using namespace std;

#define NUM_THREADS 64
#define NUM_REPETITIONS 1000

std::mutex mtx;
clock_t start, end1;
double t1 = 0, time1 = 0;

void MyThreadFunctio(int data) {
    mtx.lock();    
    end1 = clock();
    //data++;
    time1 += t1;
    t1 = (double)(end1 - start);
    start = clock();
    mtx.unlock();
}

int main()
{
    FILE* f;
    double time = 0;
    f = fopen("th_switch_cpp_64.csv", "w");
    double sum = 0;

    for (int i = 0; i < NUM_REPETITIONS; i++) {
        double thSum = 0;
        std::vector<thread> arrayThreads(NUM_THREADS);

        for (int i = 0; i < NUM_THREADS; i++) {
            arrayThreads[i] = thread(MyThreadFunctio, i);
        }

        for (auto& th : arrayThreads) {
            th.join();
        }

    }
    time1 /= CLOCKS_PER_SEC;
    fprintf(f, "%f", time1 / NUM_REPETITIONS);
    fclose(f);
    printf("\nDONE\n");
    getchar();
    return 0;
}


