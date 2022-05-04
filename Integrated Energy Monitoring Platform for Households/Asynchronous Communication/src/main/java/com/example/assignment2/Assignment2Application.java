package com.example.assignment2;

import com.example.assignment2.fileReader.FileReadeSensorService;
import com.example.assignment2.queue.SendMessageService;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

@SpringBootApplication
public class Assignment2Application {

    public static void main(String[] args) throws Exception {
        List<Float> values = new ArrayList<>();
        FileReadeSensorService fileReadeSensorService = new FileReadeSensorService();
        fileReadeSensorService.getValues(values);
        System.out.println(values);

        SendMessageService sendMessageService = new SendMessageService();
        sendMessageService.sendMessage();
        SpringApplication.run(Assignment2Application.class, args);
    }
}
