package com.finalprojectandreeapasc;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import java.rmi.RemoteException;

@SpringBootApplication
public class FinalProject {

    public static void main(String[] args) throws RemoteException {

        SpringApplication.run(FinalProject.class, args);

    }
}
