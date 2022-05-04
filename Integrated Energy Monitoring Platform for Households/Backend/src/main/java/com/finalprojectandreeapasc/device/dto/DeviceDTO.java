package com.finalprojectandreeapasc.device.dto;

import com.finalprojectandreeapasc.user.model.User;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.experimental.SuperBuilder;

@Data
@SuperBuilder
@AllArgsConstructor
public class DeviceDTO {
    private Long id;
    private String description;
    private String location;
    private Float maxEnergyConsumption;
    private Float averageEnergyConsumption;
    private Long userId;
    private Long sensorId;
}
