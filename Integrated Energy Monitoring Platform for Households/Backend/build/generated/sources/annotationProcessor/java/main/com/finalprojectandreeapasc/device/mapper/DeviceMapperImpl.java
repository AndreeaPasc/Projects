package com.finalprojectandreeapasc.device.mapper;

import com.finalprojectandreeapasc.device.dto.DeviceDTO;
import com.finalprojectandreeapasc.device.model.Device;
import javax.annotation.processing.Generated;
import org.springframework.stereotype.Component;

@Generated(
    value = "org.mapstruct.ap.MappingProcessor",
    date = "2022-01-05T10:01:53+0200",
    comments = "version: 1.4.2.Final, compiler: IncrementalProcessingEnvironment from gradle-language-java-7.0.2.jar, environment: Java 11.0.13 (Oracle Corporation)"
)
@Component
public class DeviceMapperImpl implements DeviceMapper {

    @Override
    public DeviceDTO toDTO(Device device) {
        if ( device == null ) {
            return null;
        }

        Long id = null;
        String description = null;
        String location = null;
        Float maxEnergyConsumption = null;
        Float averageEnergyConsumption = null;
        Long userId = null;
        Long sensorId = null;

        id = device.getId();
        description = device.getDescription();
        location = device.getLocation();
        maxEnergyConsumption = device.getMaxEnergyConsumption();
        averageEnergyConsumption = device.getAverageEnergyConsumption();
        userId = device.getUserId();
        sensorId = device.getSensorId();

        DeviceDTO deviceDTO = new DeviceDTO( id, description, location, maxEnergyConsumption, averageEnergyConsumption, userId, sensorId );

        return deviceDTO;
    }

    @Override
    public Device fromDTO(DeviceDTO dto) {
        if ( dto == null ) {
            return null;
        }

        Device device = new Device();

        device.setId( dto.getId() );
        device.setDescription( dto.getDescription() );
        device.setLocation( dto.getLocation() );
        device.setMaxEnergyConsumption( dto.getMaxEnergyConsumption() );
        device.setAverageEnergyConsumption( dto.getAverageEnergyConsumption() );
        device.setUserId( dto.getUserId() );
        device.setSensorId( dto.getSensorId() );

        return device;
    }
}
