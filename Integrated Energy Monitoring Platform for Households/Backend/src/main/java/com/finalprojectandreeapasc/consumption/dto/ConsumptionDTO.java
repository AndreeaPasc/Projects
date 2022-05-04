package com.finalprojectandreeapasc.consumption.dto;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.experimental.SuperBuilder;

import java.io.Serializable;

@Data
@SuperBuilder
@AllArgsConstructor
public class ConsumptionDTO implements Serializable {
    private static final long serialVersionUID = 1L;

    private Long id;
    private Long sensorId;
    private String timestamp;
    private Float energyConsumption;
}
