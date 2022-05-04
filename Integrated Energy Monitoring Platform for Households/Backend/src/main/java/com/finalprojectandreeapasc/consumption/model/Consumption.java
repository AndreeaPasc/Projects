package com.finalprojectandreeapasc.consumption.model;

import com.finalprojectandreeapasc.sensor.model.Sensor;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.RequiredArgsConstructor;

import javax.persistence.*;
import java.io.Serializable;
import java.sql.Timestamp;

@Entity
@Builder
@AllArgsConstructor
@RequiredArgsConstructor
@Data
public class Consumption {

    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;

    @Column
    private String timestamp;

    @Column
    private Float energyConsumption;

    @Column
    private Long sensorId;
}
