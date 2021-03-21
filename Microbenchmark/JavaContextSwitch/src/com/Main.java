package com;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Main implements Runnable{
    private Object lock;
    public Main(Object lock ){
        this.lock = lock;
    }
    static double start = 0.0;
    static double end = 0.0;
    private static double total = 0.0;

    public void run(){
        synchronized( lock ){
            start = System.currentTimeMillis();
            lock.notify();
        }
    }
    public static void main(String[] args) throws InterruptedException {
        Object lock = new Object();
        int NUM_THREADS = 2;
        int NUM_REPETITIONS = 1000;
        Thread[] myThreads = new Thread[NUM_THREADS];
        for(int i = 0; i < NUM_REPETITIONS; i++) {
            //double start = 0;
            for(int j = 0; j < NUM_THREADS; j++){
                myThreads[j] = new Thread(new Main(lock));
                myThreads[j].start();
                try {
                    synchronized (lock) {
                        lock.wait();
                    }
                    end = System.currentTimeMillis();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                total += end - start;
            }
            for (int j = 0; j < NUM_THREADS; j++){
                myThreads[j].join();
            }
        }
        total = (total / (double) NUM_REPETITIONS) / 1000;
        try {
            FileWriter w3 = new FileWriter("th_switch_java_2.csv", false);
            BufferedWriter bf = new BufferedWriter(w3);
            bf.write(String.valueOf(total));
            bf.newLine();
            bf.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("\nDONE\n");
    }
}


