package com.queuessimulator.main;
import com.queuessimulator.components.Server;
import com.queuessimulator.components.Task;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class FileOutput {

    private int time;
    private List<Task> tasks = new ArrayList<>();
    private List<Server> servers = new ArrayList<>();
    private BufferedWriter writer;

    public void setTime(int time) {
        this.time = time;
    }

    public void setTasks(List<Task> tasks) {
        this.tasks = tasks;
    }

    public void setServers(List<Server> servers) {
        this.servers = servers;
    }

    public FileOutput(String output) {
        try {
            writer = new BufferedWriter(new FileWriter(output));

            /*for(int i = 0; i < servers.size(); i++){
                if(servers.get(i) == null){
                    writer.write("Queue" + i + "closed");
                    writer.newLine();
                }else{
                    writer.write();
                }
            }*/
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public void writeFile(){
        try{
            writer.write("Time " + time);
            writer.newLine();
            writer.write("Waiting elements: ");
            for(Task t: tasks){
                writer.write("(" + t.getID() + "," + t.getArrivalTime() + "," + t.getProcessingPeriod() + ") ");
            }
            writer.newLine();
            int counter = 1;
            for(Server s: servers){
                writer.write("Queue "+counter+": ");
                for(Task t: s.getTasks()){
                    writer.write("(" + t.getID() + "," + t.getArrivalTime() + "," + t.getProcessingPeriod() + ") ");
                }
                writer.write('\n');
                counter++;
            }
        } catch (IOException e){
            e.printStackTrace();
        }

    }
    public void close(){
        try{
            writer.close();
        }catch (IOException e){
            e.printStackTrace();
        }
    }

/*
    private void writeFile(BufferedWriter writer){
        try {

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

 */
}
