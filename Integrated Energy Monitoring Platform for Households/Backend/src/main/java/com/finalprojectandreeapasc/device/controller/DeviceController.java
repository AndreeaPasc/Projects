package com.finalprojectandreeapasc.device.controller;

import com.finalprojectandreeapasc.device.dto.DeviceDTO;
import com.finalprojectandreeapasc.device.service.DeviceService;
import lombok.RequiredArgsConstructor;
import org.springframework.web.bind.annotation.*;

import java.util.List;

import static com.finalprojectandreeapasc.UrlMapping.DEVICES;
import static com.finalprojectandreeapasc.UrlMapping.ENTITY;

@RestController
@RequiredArgsConstructor
@RequestMapping(value = DEVICES)
public class DeviceController {
    private final DeviceService deviceService;

    @GetMapping
    public List<DeviceDTO> allDevices() {
        return deviceService.findAll();
    }

    @PostMapping
    public DeviceDTO create(@RequestBody DeviceDTO deviceDTO) {
        return deviceService.create(deviceDTO);
    }

    @PutMapping(ENTITY)
    public DeviceDTO update(@PathVariable Long id, @RequestBody DeviceDTO deviceDTO) {
        return deviceService.update(id, deviceDTO);
    }

    @DeleteMapping(ENTITY)
    public void delete(@PathVariable Long id) {
        deviceService.delete(id);
    }
}
