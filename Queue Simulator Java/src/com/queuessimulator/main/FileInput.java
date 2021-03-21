package com.queuessimulator.main;

import java.io.BufferedReader;
import java.io.FileReader;

public class FileInput {

    private int timeLimit;
    private int maxArrival;
    private int minArrival;
    private int minService;
    private int maxService;
    private int numberOfServers;
    private int numberOfClients;

    public FileInput(String input) {
        BufferedReader reader;
        try {
            reader = new BufferedReader(new FileReader(input));
            numberOfClients = Integer.parseInt(reader.readLine());
            numberOfServers = Integer.parseInt(reader.readLine());
            timeLimit = Integer.parseInt(reader.readLine());
            String[] arrival = reader.readLine().split(",");
            minArrival = Integer.parseInt(arrival[0]);
            maxArrival = Integer.parseInt(arrival[1]);
            String[] service = reader.readLine().split(",");
            minService = Integer.parseInt(service[0]);
            maxService = Integer.parseInt(service[1]);
        }catch (Exception e) {
            e.printStackTrace();
        }
    }
    /*
    private void parseFile(BufferedReader reader){
        try {

        } catch (Exception e){
            e.printStackTrace();
        }
    }
    */

    public int getTimeLimit() {
        return timeLimit;
    }

    public int getMaxArrival() {
        return maxArrival;
    }

    public int getMinArrival() {
        return minArrival;
    }

    public int getMinService() {
        return minService;
    }

    public int getMaxService() {
        return maxService;
    }

    public int getNumberOfServers() {
        return numberOfServers;
    }

    public int getNumberOfClients() {
        return numberOfClients;
    }

}
