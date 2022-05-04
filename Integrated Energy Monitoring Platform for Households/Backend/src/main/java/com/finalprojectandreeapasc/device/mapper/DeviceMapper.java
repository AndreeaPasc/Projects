package com.finalprojectandreeapasc.device.mapper;

import com.finalprojectandreeapasc.device.dto.DeviceDTO;
import com.finalprojectandreeapasc.device.model.Device;
import org.mapstruct.*;

import java.util.stream.Collectors;

@Mapper(componentModel = "spring")
public interface DeviceMapper {

    DeviceDTO toDTO(Device device);
    Device fromDTO(DeviceDTO dto);
}
