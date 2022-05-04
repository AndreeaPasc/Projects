package com.finalprojectandreeapasc.websocket.service;

import com.finalprojectandreeapasc.consumption.dto.ConsumptionDTO;
import com.finalprojectandreeapasc.consumption.service.ConsumptionService;
import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;
import com.rabbitmq.client.ConnectionFactory;
import com.rabbitmq.client.DeliverCallback;
import lombok.RequiredArgsConstructor;
import org.json.JSONException;
import org.json.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Configurable;
import org.springframework.messaging.simp.SimpMessagingTemplate;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

@Service
@RequiredArgsConstructor
@Configurable
@Transactional
public class RespondService {

    private final ConsumptionService consumptionService;
    private final List<Double> measurements = new ArrayList<>();
    private final List<Double> times = new ArrayList<>();
    private final List<Long> ids = new ArrayList<>();
    @Autowired
    private final SimpMessagingTemplate simpMessageSendingOperations;

    public void getMessageQueue() throws Exception{
        String uri = System.getenv("CLOUDAMQP_URL");
        if (uri == null) uri = "amqps://yqddfxvk:0I52bcn_0niZ93SdYoxMnBdav-HlIDsf@rat.rmq2.cloudamqp.com/yqddfxvk";

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

        DeliverCallback deliverCallback = (consumerTag, delivery) -> {

            String message = new String(delivery.getBody(), "UTF-8");

            JSONObject obj1;
            try {
                obj1 = new JSONObject(message);
                DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
                consumptionService.create(ConsumptionDTO.builder()
                        .energyConsumption(Float.valueOf(obj1.getString("measurement_value")))
                        .timestamp(dateFormat.format(new Date(obj1.getLong("timestamp"))))
                        .sensorId(obj1.getLong("sensor_id"))
                        .build());

                Double measure1 = obj1.getDouble("measurement_value");
                Double time1 = obj1.getDouble("timestamp");
                Long id1 = obj1.getLong("sensor_id");
                measurements.add(measure1);
                times.add(time1);
                ids.add(id1);
            } catch (JSONException e) {
                e.printStackTrace();
            }

            peak(measurements, times);

            System.out.println(" [x] Received '" + message + "'");
        };
        channel.basicConsume(queue, true, deliverCallback, consumerTag -> { });
    }

    public void peak(List<Double> measurements, List<Double> times){

        Integer i = measurements.size();

        if(measurements.size() >= 2 && times.size()>=2){

            Double peak = (measurements.get(i-1) - measurements.get(i-2))/(times.get(i-1) - times.get(i-2));

            System.out.println(peak);
            if(peak > 0.002) {
                System.out.println("Peak exceeded");
                simpMessageSendingOperations.convertAndSend("/measures/message", "Exceeded value for sensor");
            }
        }
    }
}
