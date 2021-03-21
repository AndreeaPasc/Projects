package com;
import java.io.*;
import java.text.DecimalFormat;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        File f = new File("th_create_java_1.csv");
        DecimalFormat df = new DecimalFormat();
        df.setMaximumFractionDigits(10);
        float sum = 0;
        int NUM_THREADS = 1;
        BufferedWriter bf = null;
        int NUM_REPETITIONS = 1000;
        Thread[] myThreads = new Thread[NUM_THREADS];
        for(int i = 0; i < NUM_REPETITIONS; i++) {
            double start = System.currentTimeMillis();
            for(int j = 0; j < NUM_THREADS; j++){
                myThreads[j] = new Thread(new MyThreadFunction(j));
                myThreads[j].start();
            }
            for (int j = 0; j < NUM_THREADS; j++){
                myThreads[j].join();
            }
            double stop = System.currentTimeMillis();
            //System.out.println("start = " + start + "\nstop = " + stop);
            double time = (stop - start) / 1000.0;
            sum += time;
        }
        sum = sum / (float) NUM_REPETITIONS;
        try {
            BufferedWriter writer = new BufferedWriter(new OutputStreamWriter( new FileOutputStream(f)));
            writer.write(String.valueOf(df.format(sum)));
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("\nDONE\n");
    }
}


