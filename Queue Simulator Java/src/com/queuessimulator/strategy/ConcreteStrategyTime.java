package com.queuessimulator.strategy;

import com.queuessimulator.components.Server;
import com.queuessimulator.components.Task;

import java.util.List;

public class ConcreteStrategyTime implements Strategy {

    @Override
    public void addTask(List<Server> servers, Task t) {
        int minWaitingTime = servers.get(0).getWaitingPeriod().intValue();
        int minPosition = 0;
        for(int i = 1; i < servers.size(); i++){
            if(servers.get(i).getWaitingPeriod().intValue() < minWaitingTime){
                minWaitingTime = servers.get(i).getWaitingPeriod().intValue();
                minPosition = i;
            }
        }
        servers.get(minPosition).addTask(t);
        //servers.add(minPosition, servers.get(minPosition));
    }
}
