package com.finalprojectandreeapasc.sensor.mapper;

import com.finalprojectandreeapasc.sensor.dto.SensorDTO;
import com.finalprojectandreeapasc.sensor.model.Sensor;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.Mappings;

@Mapper(componentModel = "spring")
public interface SensorMapper {

    SensorDTO toDTO(Sensor sensor);
    Sensor fromDTO(SensorDTO dto);
}