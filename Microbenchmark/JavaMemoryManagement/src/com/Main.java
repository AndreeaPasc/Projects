package com;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        double time = 0.0;
        int NUM_REPETITIONS = 1000000;
        double start = System.currentTimeMillis();
        for(int i = 0; i < NUM_REPETITIONS; i++){
            int[] a = new int[1000];
        }
        double stop = System.currentTimeMillis();
        time = (stop - start) / 1000000;
        //System.out.println(time / 1000);

        try {
            FileWriter w3 = new FileWriter("alloc_dynamic_java.csv", false);
            BufferedWriter bf = new BufferedWriter(w3);
            bf.write(String.valueOf(time / 1000));
            bf.newLine();
            bf.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
