package com.queuessimulator.strategy;

import com.queuessimulator.components.Server;
import com.queuessimulator.components.Task;

import java.util.List;

public class ConcreteStrategyQueue implements Strategy{

    @Override
    public void addTask(List<Server> servers, Task t) {
        int minQue= servers.get(0).getTasks().size();
        int minPosition = 0;
        for(int i = 1; i < servers.size(); i++){
            if(servers.get(i).getTasks().size() < minQue){
                minQue = servers.get(i).getTasks().size();
                minPosition = i;
            }
        }
        servers.get(minPosition).addTask(t);
        servers.add(minPosition, servers.get(minPosition));
    }
}
