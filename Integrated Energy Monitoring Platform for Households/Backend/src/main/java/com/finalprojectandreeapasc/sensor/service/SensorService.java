package com.finalprojectandreeapasc.sensor.service;

import com.finalprojectandreeapasc.device.model.Device;
import com.finalprojectandreeapasc.device.repository.DeviceRepository;
import com.finalprojectandreeapasc.sensor.dto.SensorDTO;
import com.finalprojectandreeapasc.sensor.mapper.SensorMapper;
import com.finalprojectandreeapasc.sensor.model.Sensor;
import com.finalprojectandreeapasc.sensor.repository.SensorRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

import javax.persistence.EntityNotFoundException;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;

@Service
@RequiredArgsConstructor
public class SensorService {

    private final SensorRepository sensorRepository;
    private final SensorMapper sensorMapper;
    private final DeviceRepository deviceRepository;

    public Sensor findById(Long id) {
        return sensorRepository.findById(id).orElseThrow(() -> new EntityNotFoundException("The Sensor was not found: " + id));
    }

    public List<SensorDTO> findAll() {
        List<Sensor> sensorList = sensorRepository.findAll();
        return sensorList.stream()
                .map(sensorMapper::toDTO)
                .collect(Collectors.toList());
    }

    public SensorDTO create(SensorDTO sensorDTO) {
        return sensorMapper.toDTO(sensorRepository.save(
                sensorMapper.fromDTO(sensorDTO)
        ));
    }

    public void delete(Long id) {
        sensorRepository.deleteById(id);
        List<Device> devices = deviceRepository.findAll();
        for(Device d: devices){
            if(Objects.equals(d.getSensorId(), id)){
                deviceRepository.deleteById(d.getId());
            }
        }
    }

    public SensorDTO update(Long id, SensorDTO sensorDTO) {
        Sensor actSensor = findById(id);
        actSensor.setId(sensorDTO.getId());
        actSensor.setDescription(sensorDTO.getDescription());
        actSensor.setMaxValue(sensorDTO.getMaxValue());
        return sensorMapper.toDTO(
                sensorRepository.save(actSensor)
        );
    }
}
