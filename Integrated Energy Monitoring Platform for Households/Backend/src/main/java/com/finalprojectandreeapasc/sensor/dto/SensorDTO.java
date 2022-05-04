package com.finalprojectandreeapasc.sensor.dto;

import com.finalprojectandreeapasc.device.model.Device;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.experimental.SuperBuilder;

@Data
@SuperBuilder
@AllArgsConstructor
public class SensorDTO {
    private Long id;
    private String description;
    private Float maxValue;
    private Device device;
}
