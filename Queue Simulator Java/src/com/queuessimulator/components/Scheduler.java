package com.queuessimulator.components;

import com.queuessimulator.main.FileOutput;
import com.queuessimulator.strategy.ConcreteStrategyQueue;
import com.queuessimulator.strategy.ConcreteStrategyTime;
import com.queuessimulator.strategy.SelectionPolicy;
import com.queuessimulator.strategy.Strategy;
import java.util.ArrayList;
import java.util.List;

public class Scheduler{
    private List<Server> servers = new ArrayList<>();
    private List<Thread> threads = new ArrayList<>();
    private int maxNoServers;
    private int maxTasksPerServer;
    private Strategy strategy;


    public Scheduler(int maxNoServers, int maxTasksPerServer){
        for(int i = 0; i < maxNoServers; i++){
            Server s = new Server();
            servers.add(s);
        }

        for (Server s : servers) {
            threads.add(new Thread(s));
        }
    }

    public void changeStrategy(SelectionPolicy policy){

        if(policy.equals(SelectionPolicy.SHORTEST_QUEUE)){
            strategy = new ConcreteStrategyQueue();
        }
        if(policy.equals(SelectionPolicy.SHORTEST_TIME)){
            strategy = new ConcreteStrategyTime();
        }
    }

    public void dispatchTask(Task t){
        strategy.addTask(servers, t);
        for(Server s : servers){
            if(s.getTasks().size() > 0){
                if(threads.get(servers.indexOf(s)).getState() == Thread.State.TERMINATED){
                    threads.set(servers.indexOf(s),new Thread(s));
                }
                if(threads.get(servers.indexOf(s)).getState() == Thread.State.NEW){
                    threads.get(servers.indexOf(s)).start();
                }
            }
        }
    }

    public List<Server> getServers(){
        return servers;
    }
}
