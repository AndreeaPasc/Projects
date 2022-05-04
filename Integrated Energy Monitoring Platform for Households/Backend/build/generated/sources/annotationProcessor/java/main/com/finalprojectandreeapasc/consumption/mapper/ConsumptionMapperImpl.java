package com.finalprojectandreeapasc.consumption.mapper;

import com.finalprojectandreeapasc.consumption.dto.ConsumptionDTO;
import com.finalprojectandreeapasc.consumption.model.Consumption;
import javax.annotation.processing.Generated;
import org.springframework.stereotype.Component;

@Generated(
    value = "org.mapstruct.ap.MappingProcessor",
    date = "2022-01-05T10:01:53+0200",
    comments = "version: 1.4.2.Final, compiler: IncrementalProcessingEnvironment from gradle-language-java-7.0.2.jar, environment: Java 11.0.13 (Oracle Corporation)"
)
@Component
public class ConsumptionMapperImpl implements ConsumptionMapper {

    @Override
    public ConsumptionDTO toDTO(Consumption consumption) {
        if ( consumption == null ) {
            return null;
        }

        Long id = null;
        Long sensorId = null;
        String timestamp = null;
        Float energyConsumption = null;

        id = consumption.getId();
        sensorId = consumption.getSensorId();
        timestamp = consumption.getTimestamp();
        energyConsumption = consumption.getEnergyConsumption();

        ConsumptionDTO consumptionDTO = new ConsumptionDTO( id, sensorId, timestamp, energyConsumption );

        return consumptionDTO;
    }

    @Override
    public Consumption fromDTO(ConsumptionDTO consumptionDTO) {
        if ( consumptionDTO == null ) {
            return null;
        }

        Consumption consumption = new Consumption();

        consumption.setId( consumptionDTO.getId() );
        consumption.setTimestamp( consumptionDTO.getTimestamp() );
        consumption.setEnergyConsumption( consumptionDTO.getEnergyConsumption() );
        consumption.setSensorId( consumptionDTO.getSensorId() );

        return consumption;
    }
}
