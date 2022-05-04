package com.finalprojectandreeapasc.device.model;

import com.finalprojectandreeapasc.user.model.User;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.RequiredArgsConstructor;
import org.hibernate.annotations.Cascade;

import javax.persistence.*;

@Entity
@Builder
@AllArgsConstructor
@RequiredArgsConstructor
@Data
public class Device {
    private static final long serialVersionUID = 1L;

    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;

    @Column(name = "description")
    private String description;

    @Column(name = "location")
    private String location;

    @Column(name = "max_energy_consumption")
    private Float maxEnergyConsumption;

    @Column(name = "average_energy_consumption")
    private Float averageEnergyConsumption;

    @Column
    private Long userId;

    @Column
    private Long sensorId;
}
