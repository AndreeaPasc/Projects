package com.finalprojectandreeapasc.consumption.mapper;

import com.finalprojectandreeapasc.consumption.dto.ConsumptionDTO;
import com.finalprojectandreeapasc.consumption.model.Consumption;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.Mappings;

@Mapper(componentModel = "spring")
public interface ConsumptionMapper {

    ConsumptionDTO toDTO(Consumption consumption);
    Consumption fromDTO(ConsumptionDTO consumptionDTO);
}
