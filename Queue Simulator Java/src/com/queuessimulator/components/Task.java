package com.queuessimulator.components;

public class Task {
    private int arrivalTime;
    private int processingPeriod;
    private int ID;

    public Task(int arrivalTime, int processingPeriod, int ID){
        this.arrivalTime = arrivalTime;
        this.processingPeriod = processingPeriod;
        this.ID = ID;
    }

    public void decProcessingPeriod(){
        processingPeriod--;
    }

    public int getArrivalTime() {
        return arrivalTime;
    }

    public int getProcessingPeriod() {
        return processingPeriod;
    }

    public  int getID(){
        return ID;
    }
}
