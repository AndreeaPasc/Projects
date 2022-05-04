package com.finalprojectandreeapasc.sensor.controller;

import com.finalprojectandreeapasc.sensor.dto.SensorDTO;
import com.finalprojectandreeapasc.sensor.service.SensorService;
import lombok.RequiredArgsConstructor;
import org.springframework.web.bind.annotation.*;

import java.util.List;

import static com.finalprojectandreeapasc.UrlMapping.ENTITY;
import static com.finalprojectandreeapasc.UrlMapping.SENSORS;


@RestController
@RequiredArgsConstructor
@RequestMapping(value = SENSORS)
public class SensorController {
    private final SensorService sensorService;

    @GetMapping
    public List<SensorDTO> allSensors() {
        return sensorService.findAll();
    }

    @PostMapping
    public SensorDTO create(@RequestBody SensorDTO sensorDTO) {
        return sensorService.create(sensorDTO);
    }

    @PutMapping(ENTITY)
    public SensorDTO update(@PathVariable Long id, @RequestBody SensorDTO sensorDTO) {
        return sensorService.update(id, sensorDTO);
    }

    @DeleteMapping(ENTITY)
    public void delete(@PathVariable Long id) {
        sensorService.delete(id);
    }
}
