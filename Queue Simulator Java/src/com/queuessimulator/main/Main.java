package com.queuessimulator.main;

import com.queuessimulator.components.Simulation;

public class Main {
    public static void main(String[] args) {
        try{
            Simulation gen = new Simulation(args[0],args[1]);
            Thread t = new Thread(gen);
            t.start();
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Not enough arguments");
        }
    }
}
