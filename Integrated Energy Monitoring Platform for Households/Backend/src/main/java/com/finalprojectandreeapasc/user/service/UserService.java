package com.finalprojectandreeapasc.user.service;

import com.finalprojectandreeapasc.consumption.model.Consumption;
import com.finalprojectandreeapasc.consumption.repository.ConsumptionRepository;
import com.finalprojectandreeapasc.device.dto.DeviceDTO;
import com.finalprojectandreeapasc.device.model.Device;
import com.finalprojectandreeapasc.device.repository.DeviceRepository;
import com.finalprojectandreeapasc.device.service.DeviceService;
import com.finalprojectandreeapasc.sensor.model.Sensor;
import com.finalprojectandreeapasc.sensor.repository.SensorRepository;
import com.finalprojectandreeapasc.user.dto.UserListDTO;
import com.finalprojectandreeapasc.user.dto.UserMinimalDTO;
import com.finalprojectandreeapasc.user.mapper.UserMapper;
import com.finalprojectandreeapasc.user.model.ERole;
import com.finalprojectandreeapasc.user.model.Role;
import com.finalprojectandreeapasc.user.model.User;
import org.springframework.security.crypto.password.*;
import com.finalprojectandreeapasc.user.repository.UserRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

import javax.persistence.EntityNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;
import static java.util.stream.Collectors.toList;

@Service
@RequiredArgsConstructor
public class UserService {

    private final UserRepository userRepository;
    private final UserMapper userMapper;
    private final PasswordEncoder encoder;
    private final DeviceRepository deviceRepository;
    private final ConsumptionRepository consumptionRepository;
    private final SensorRepository sensorRepository;

    public List<UserMinimalDTO> allUsersMinimal() {
        return userRepository.findAll()
                .stream().map(userMapper::userMinimalFromUser)
                .collect(toList());
    }

    public List<UserListDTO> allUsersForList() {
        return userRepository.findAll()
                .stream().map(userMapper::userListDtoFromUser)
                .collect(toList());
    }

    public User findById(Long id) {
        return userRepository.findById(id)
                .orElseThrow(() -> new EntityNotFoundException("User not found: " + id));
    }

    public List<UserMinimalDTO> findAll() {
        return userRepository.findAll().stream()
                .map(userMapper::toDTO)
                .collect(Collectors.toList());
    }

    public UserMinimalDTO create(UserMinimalDTO item) {
        User saveUser = userMapper.fromDTO(item);
        saveUser.setPassword(encoder.encode(item.getPassword()));
        UserMinimalDTO userDto = userMapper.toDTO(saveUser);
        return userMapper.toDTO(userRepository.save(
                userMapper.fromDTO(userDto)
        ));
    }

    public UserMinimalDTO update(Long id, UserMinimalDTO user) {
        User actUser = findById(id);
        actUser.setUsername(user.getName());
        actUser.setEmail(user.getEmail());
        actUser.setAge(user.getAge());
        actUser.setAddress(user.getAddress());
//        actUser.setRoles(user.getRoles().stream()
//                .map(role -> Role.builder().name(ERole.valueOf(role)).build())
//                .collect(Collectors.toSet()));
        return userMapper.toDTO(
                userRepository.save(actUser)
        );
    }

    public void delete(Long id){

        userRepository.deleteById(id);
        List<Device> devices = deviceRepository.findAll();
        for(Device d: devices){
            if(Objects.equals(d.getUserId(), id)){
                deviceRepository.deleteById(d.getId());
            }
        }
    }

    public UserMinimalDTO get(Long id) {
        return userMapper.toDTO(findById(id));
    }

    public List<Device> getDevices(Long id){
        List<Device> devices = deviceRepository.findAll();
        List<Device> retDevice = new ArrayList<>();

        for(Device d: devices){
            if(Objects.equals(d.getUserId(), id))
                retDevice.add(d);
        }
        return retDevice;
    }

    public List<Consumption> getConsumption(Long id){
        List<Consumption> consumptions = consumptionRepository.findAll();
        List<Device> devices = deviceRepository.findAll();
        System.out.println(devices);
        List<Long> sensorsId = new ArrayList<>();
        for(Device d: devices){
            if(Objects.equals(d.getUserId(), id))
                sensorsId.add(d.getSensorId());
        }
        List<Consumption> retConsumption = new ArrayList<>();
        for (Consumption c : consumptions) {
            for (Long i : sensorsId) {
                if (Objects.equals(c.getSensorId(), i)) {
                    retConsumption.add(c);
                }
            }
        }
        return retConsumption;
    }
}
