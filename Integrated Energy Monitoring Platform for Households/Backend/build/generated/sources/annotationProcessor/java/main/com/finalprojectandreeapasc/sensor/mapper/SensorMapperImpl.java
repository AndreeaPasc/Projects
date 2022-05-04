package com.finalprojectandreeapasc.sensor.mapper;

import com.finalprojectandreeapasc.device.model.Device;
import com.finalprojectandreeapasc.sensor.dto.SensorDTO;
import com.finalprojectandreeapasc.sensor.model.Sensor;
import javax.annotation.processing.Generated;
import org.springframework.stereotype.Component;

@Generated(
    value = "org.mapstruct.ap.MappingProcessor",
    date = "2022-01-05T10:01:53+0200",
    comments = "version: 1.4.2.Final, compiler: IncrementalProcessingEnvironment from gradle-language-java-7.0.2.jar, environment: Java 11.0.13 (Oracle Corporation)"
)
@Component
public class SensorMapperImpl implements SensorMapper {

    @Override
    public SensorDTO toDTO(Sensor sensor) {
        if ( sensor == null ) {
            return null;
        }

        Long id = null;
        String description = null;
        Float maxValue = null;

        id = sensor.getId();
        description = sensor.getDescription();
        maxValue = sensor.getMaxValue();

        Device device = null;

        SensorDTO sensorDTO = new SensorDTO( id, description, maxValue, device );

        return sensorDTO;
    }

    @Override
    public Sensor fromDTO(SensorDTO dto) {
        if ( dto == null ) {
            return null;
        }

        Sensor sensor = new Sensor();

        sensor.setId( dto.getId() );
        sensor.setDescription( dto.getDescription() );
        sensor.setMaxValue( dto.getMaxValue() );

        return sensor;
    }
}
