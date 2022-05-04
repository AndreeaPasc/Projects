package com.finalprojectandreeapasc;
import com.finalprojectandreeapasc.consumption.model.Consumption;
import com.finalprojectandreeapasc.consumption.repository.ConsumptionRepository;
import com.finalprojectandreeapasc.device.model.Device;
import com.finalprojectandreeapasc.device.repository.DeviceRepository;
import com.finalprojectandreeapasc.security.dto.SignupRequest;
import com.finalprojectandreeapasc.sensor.model.Sensor;
import com.finalprojectandreeapasc.sensor.repository.SensorRepository;
import com.finalprojectandreeapasc.user.model.ERole;
import com.finalprojectandreeapasc.user.model.Role;
import com.finalprojectandreeapasc.user.model.User;
import com.finalprojectandreeapasc.user.repository.RoleRepository;
import com.finalprojectandreeapasc.user.repository.UserRepository;
import com.finalprojectandreeapasc.websocket.service.RespondService;
import lombok.RequiredArgsConstructor;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.boot.context.event.ApplicationReadyEvent;
import org.springframework.context.ApplicationListener;
import org.springframework.stereotype.Component;
import com.finalprojectandreeapasc.security.*;

import java.sql.Timestamp;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.time.Instant;
import java.util.Calendar;
import java.util.List;
import java.util.Random;
import java.util.Set;

@Component
@RequiredArgsConstructor
public class Bootstrapper implements ApplicationListener<ApplicationReadyEvent> {

    private final RoleRepository roleRepository;
    private final UserRepository userRepository;
    private final AuthService authService;
    private final RespondService respondService;
    private final SensorRepository sensorRepository;
    private final DeviceRepository deviceRepository;
    private final ConsumptionRepository consumptionRepository;

    @Value("${app.bootstrap}")
    private Boolean bootstrap;

    @Override
    public void onApplicationEvent(ApplicationReadyEvent event) {
        if (bootstrap) {
            userRepository.deleteAll();
            roleRepository.deleteAll();
            deviceRepository.deleteAll();
            sensorRepository.deleteAll();
            consumptionRepository.deleteAll();
            for (ERole value : ERole.values()) {
                roleRepository.save(
                        Role.builder()
                                .name(value)
                                .build()
                );
            }
            authService.register(SignupRequest.builder()
                    .email("admin@email.com")
                    .username("admin")
                    .password("WooHoo1!")
                    .roles(Set.of("ADMIN"))
                    .build());
            authService.register(SignupRequest.builder()
                    .email("user1@email.com")
                    .username("user1")
                    .password("WooHoo1!")
                    .roles(Set.of("CUSTOMER"))
                    .build());

            authService.register(SignupRequest.builder()
                    .email("user2@email.com")
                    .username("user2")
                    .password("WooHoo1!")
                    .roles(Set.of("CUSTOMER"))
                    .build());

            List<User> users = userRepository.findAll();
            users.get(0).setAddress("Address1");
            users.get(0).setAge(22);

            users.get(1).setAddress("Address2");
            users.get(1).setAge(22);

            users.get(2).setAddress("Address3");
            users.get(2).setAge(22);

            userRepository.save(users.get(0));
            userRepository.save(users.get(1));
            userRepository.save(users.get(2));

            sensorRepository.save(Sensor.builder()
                    .description("Smoke sensor")
                    .maxValue(0.002f)
                    .build());

            sensorRepository.save(Sensor.builder()
                    .description("Gas sensor")
                    .maxValue(0.002f)
                    .build());

            List<Sensor> sensors = sensorRepository.findAll();

            deviceRepository.save(Device.builder()
                    .userId(users.get(1).getId())
                    .sensorId(sensors.get(0).getId())
                    .averageEnergyConsumption(10.0f)
                    .description("Smoke")
                    .location("living room")
                    .maxEnergyConsumption(20.0f)
                    .build());

            deviceRepository.save(Device.builder()
                    .userId(users.get(2).getId())
                    .sensorId(sensors.get(1).getId())
                    .averageEnergyConsumption(10.0f)
                    .description("Gas")
                    .location("living room")
                    .maxEnergyConsumption(20.0f)
                    .build());

/*            deviceRepository.save(Device.builder()
                    .userId(2L)
                    .sensorId(6L)
                    .averageEnergyConsumption(10.0f)
                    .description("Humidity")
                    .location("living room")
                    .maxEnergyConsumption(20.0f)
                    .build());*/

            /*
            sensorRepository.save(Sensor.builder()
                    .description("Humidity sensor")
                    .maxValue(10.0f)
                    .build());

            */

            Instant instant = Instant.now();
            Timestamp ts = Timestamp.from(instant);
            DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
            Calendar cal = Calendar.getInstance();
            System.out.println("Current Date Time : " + dateFormat.format(cal.getTime()));

            for(int i = 1; i < 8; i++){
                cal = Calendar.getInstance();
                cal.add(Calendar.DATE, -i);
                for(int j = 1; j < 25; j++) {
                    cal.set(Calendar.HOUR_OF_DAY, j);
                    Random rand = new Random();
                    float enConsumption = rand.nextFloat() * 10;
                    consumptionRepository.save(Consumption.builder()
                            .energyConsumption(enConsumption)
                            .timestamp(dateFormat.format(cal.getTime()))
                            .sensorId(sensors.get(1).getId())
                            .build());
                }
            }


            try {
                respondService.getMessageQueue();
            } catch (Exception e) {
                e.printStackTrace();
            }

            //System.out.println(userService.getConsumption(5L));
        }
    }
}