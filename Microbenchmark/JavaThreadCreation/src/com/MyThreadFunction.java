package com;

import java.util.concurrent.locks.Lock;

public class MyThreadFunction implements Runnable {
    private int thNumber;
    int j = 0;
    public MyThreadFunction(int thNumber){
        this.thNumber = thNumber;
    }

    public void run(){
        j++;
    }
}
