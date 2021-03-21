package com.queuessimulator.components;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.atomic.AtomicInteger;

public class Server implements Runnable {

    private BlockingQueue<Task> tasks;
    private AtomicInteger waitingPeriod;
    private volatile CyclicBarrier managerBarrier;

    public Server() {
        tasks = new ArrayBlockingQueue<Task>(1000);
        waitingPeriod = new AtomicInteger();
        managerBarrier = new CyclicBarrier(2);
    }

    public AtomicInteger getWaitingPeriod() {
        return waitingPeriod;
    }

    public CyclicBarrier getBarrier() {
        return managerBarrier;
    }

    public void addTask(Task newTask) {
        tasks.add(newTask);
        waitingPeriod.addAndGet(newTask.getProcessingPeriod());
    }

    @Override
    public void run() {
        try {
            while (true) {
                managerBarrier.await();
                if (tasks.size() > 0) {
                    tasks.peek().decProcessingPeriod();
                    waitingPeriod.addAndGet(-1);
                    if (tasks.peek().getProcessingPeriod() == 0) {
                        tasks.take();
                    }
                    if (tasks.size() == 0) {
                        break;
                    }
                } else {
                    break;
                }
            }
        } catch (InterruptedException | BrokenBarrierException e) {
            // Probably got stuck waiting after finishing the simulation,bail out
        }
    }
    public BlockingQueue<Task> getTasks() {
        return tasks;
    }
}

