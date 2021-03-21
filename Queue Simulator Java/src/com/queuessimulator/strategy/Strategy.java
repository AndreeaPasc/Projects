package com.queuessimulator.strategy;

import com.queuessimulator.components.Server;
import com.queuessimulator.components.Task;

import java.util.List;

public interface Strategy {
    public void addTask(List<Server> servers, Task t);
}
