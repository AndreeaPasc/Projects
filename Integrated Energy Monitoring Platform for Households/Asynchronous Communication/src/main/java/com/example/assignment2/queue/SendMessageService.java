package com.example.assignment2.queue;

import com.example.assignment2.fileReader.FileReadeSensorService;
import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;
import com.rabbitmq.client.ConnectionFactory;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.sql.Timestamp;
import java.time.Instant;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.TimeUnit;

public class SendMessageService {

    public void sendMessage() throws Exception {

        File file = new File("sensorId.txt");
        BufferedReader br
                = new BufferedReader(new FileReader(file));
        String st;
        st = br.readLine();
        System.out.println(st);

        String uri = System.getenv("CLOUDAMQP_URL");
        if (uri == null) uri = "amqps://btbwliru:Y4eLEz5tkodKMxX_EWQBj6k21VRGxurT@rattlesnake.rmq.cloudamqp.com/btbwliru";

        ConnectionFactory factory = new ConnectionFactory();
        factory.setUri(uri);

        //Recommended settings
        factory.setConnectionTimeout(30000);

        Connection connection = factory.newConnection();
        Channel channel = connection.createChannel();

        String queue = "hello";     //queue name
        boolean durable = false;    //durable - RabbitMQ will never lose the queue if a crash occurs
        boolean exclusive = false;  //exclusive - if queue only will be used by one connection
        boolean autoDelete = false; //autodelete - queue is deleted when last consumer unsubscribes

        channel.queueDeclare(queue, durable, exclusive, autoDelete, null);
        String message1 = "Hello CloudAMQP!";

        String exchangeName = "";
        String routingKey = "hello";

        List<Float> values = new ArrayList<>();
        FileReadeSensorService fileReadeSensorService = new FileReadeSensorService();
        fileReadeSensorService.getValues(values);

        JSONObject obj = new JSONObject();

        for(Float f: values) {
            obj.put("timestamp", Timestamp.from(Instant.now()).getTime());
            obj.put("sensor_id", st); // citit din fisier id ul
            obj.put("measurement_value", f);

            channel.basicPublish(exchangeName, routingKey, null, obj.toString().getBytes());
            System.out.println(" [x] Sent '" + message1 + obj);

            TimeUnit.SECONDS.sleep(5);
        }
    }
}
