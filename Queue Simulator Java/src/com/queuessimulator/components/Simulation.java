package com.queuessimulator.components;

import com.queuessimulator.main.FileInput;
import com.queuessimulator.main.FileOutput;
import com.queuessimulator.strategy.SelectionPolicy;

import java.util.*;
import java.util.concurrent.BrokenBarrierException;
import java.util.stream.Collectors;

public class Simulation implements Runnable {

    public int timeLimit;
    public int maxArrival;
    public int minArrival;
    public int minService;
    public int maxService;
    public int numberOfServers;
    public int numberOfClients;
    public int ID;
    public SelectionPolicy selectionPolicy = SelectionPolicy.SHORTEST_TIME;

    public FileOutput out;
    public FileInput input;

    // entity responsible with queue management and client distribution
    private Scheduler scheduler;

    // pool of tasks
    private List<Task> generatedTasks = new ArrayList<>();
    private List<Server> servers;

    public Simulation(String input, String output) {
        this.input = new FileInput(input);
        out = new FileOutput(output);
    }

    private void generateNRandomTasks() {
        int arrival, service;
        Random r = new Random();
        for(int i = 0; i < numberOfClients; i++){
            arrival = generateRandom(minArrival, maxArrival);
            service = generateRandom(minService, maxService);

            this.generatedTasks.add(i, new Task(arrival, service, i));
        }

        generatedTasks = generatedTasks.stream().sorted(Comparator.comparing(Task::getArrivalTime)).collect(Collectors.toList());
    }

    private int generateRandom(int min, int max) {
        Random r = new Random();
        return min + r.nextInt((max - min) + 1);
    }
    private boolean checkEnd(){
        if(generatedTasks.size()>0)
            return false;
        for(Server s:servers){
            if(s.getTasks().size()>0)
                return false;
        }
        return true;
    }
    @Override
    public void run() {
        timeLimit = input.getTimeLimit();
        maxArrival = input.getMaxArrival();
        minArrival = input.getMinArrival();
        maxService = input.getMaxService();
        minService = input.getMinService();
        numberOfClients = input.getNumberOfClients();
        numberOfServers = input.getNumberOfServers();
        scheduler = new Scheduler(numberOfServers, numberOfClients);
        scheduler.changeStrategy(selectionPolicy);
        servers = scheduler.getServers();
        generateNRandomTasks();

        int currentTime = 0;
        while(currentTime <= timeLimit){
            Iterator<Task> it = generatedTasks.iterator();
            while(it.hasNext()){
                Task t = it.next();
                if(t.getArrivalTime() == currentTime){
                    scheduler.dispatchTask(t);
                    it.remove();
                }
            }
            try {
                Thread.sleep(100);
                out.setTime(currentTime);
                out.setServers(servers);
                out.setTasks(generatedTasks);
                out.writeFile();
                for(Server s: servers){
                    if(s.getTasks().size()>0)
                        s.getBarrier().await();
                }
                currentTime++;
                if(checkEnd())
                    break;
            } catch (InterruptedException | BrokenBarrierException e) {
                e.printStackTrace();
            }
        }
        out.close();
    }
}