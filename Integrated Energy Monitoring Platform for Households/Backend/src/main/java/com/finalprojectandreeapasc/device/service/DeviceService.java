package com.finalprojectandreeapasc.device.service;

import com.finalprojectandreeapasc.device.dto.DeviceDTO;
import com.finalprojectandreeapasc.device.mapper.DeviceMapper;
import com.finalprojectandreeapasc.device.model.Device;
import com.finalprojectandreeapasc.device.repository.DeviceRepository;
import com.finalprojectandreeapasc.sensor.model.Sensor;
import com.finalprojectandreeapasc.sensor.repository.SensorRepository;
import com.finalprojectandreeapasc.sensor.service.SensorService;
import com.finalprojectandreeapasc.user.model.User;
import com.finalprojectandreeapasc.user.repository.UserRepository;
import com.finalprojectandreeapasc.user.service.UserService;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

import javax.persistence.EntityNotFoundException;
import java.util.List;
import java.util.stream.Collectors;

@Service
@RequiredArgsConstructor
public class DeviceService {
    private final DeviceRepository deviceRepository;
    private final DeviceMapper deviceMapper;
    private final UserService userService;
    private final UserRepository userRepository;
    private final SensorRepository sensorRepository;
    private final SensorService sensorService;

    private Device findById(Long id) {
        return deviceRepository.findById(id).orElseThrow(() -> new EntityNotFoundException("The device was not found: " + id));
    }

    public List<DeviceDTO> findAll() {
        List<Device> deviceList = deviceRepository.findAll();
        return deviceList.stream()
                .map(deviceMapper::toDTO)
                .collect(Collectors.toList());
    }

    public DeviceDTO create(DeviceDTO deviceDTO) {
        return deviceMapper.toDTO(deviceRepository.save(
                deviceMapper.fromDTO(deviceDTO)
        ));
    }

    public void delete(Long id) {
        deviceRepository.deleteById(id);
    }

    public DeviceDTO update(Long id, DeviceDTO deviceDTO) {
        Device actDevice = findById(id);
        actDevice.setId(deviceDTO.getId());
        actDevice.setAverageEnergyConsumption(deviceDTO.getAverageEnergyConsumption());
        actDevice.setDescription(deviceDTO.getDescription());
        actDevice.setLocation(deviceDTO.getLocation());
        actDevice.setMaxEnergyConsumption(deviceDTO.getMaxEnergyConsumption());
        actDevice.setSensorId(addSensorToDevice(id, deviceDTO.getSensorId()).getSensorId());
        actDevice.setUserId(addUserToDevice(id, deviceDTO.getUserId()).getUserId());
        return deviceMapper.toDTO(
                deviceRepository.save(actDevice)
        );
    }

    public DeviceDTO addUserToDevice(Long id, Long userId){
        User user = userService.findById(userId);
        Device device = findById(id);

        if(user!=null){
            device.setUserId(userId);
        }
        return deviceMapper.toDTO(
                deviceRepository.save(device));
    }

    public DeviceDTO addSensorToDevice(Long id, Long sensorId){
        Sensor sensor = sensorService.findById(sensorId);
        Device device = findById(id);

        if(sensor!=null){
            device.setSensorId(sensorId);
        }
        return deviceMapper.toDTO(
                deviceRepository.save(device));
    }
}
