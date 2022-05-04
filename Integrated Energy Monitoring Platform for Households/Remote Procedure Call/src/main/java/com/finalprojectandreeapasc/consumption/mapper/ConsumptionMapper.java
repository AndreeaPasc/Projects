package com.finalprojectandreeapasc.consumption.mapper;

import com.finalprojectandreeapasc.consumption.dto.ConsumptionDTO;
import com.finalprojectandreeapasc.consumption.model.Consumption;
import org.mapstruct.Mapper;

@Mapper(componentModel = "spring")
public interface ConsumptionMapper {

    ConsumptionDTO toDTO(Consumption consumption);
    Consumption fromDTO(ConsumptionDTO consumptionDTO);
}
