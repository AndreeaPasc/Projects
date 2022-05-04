package com.finalprojectandreeapasc.consumption.controller;

import com.finalprojectandreeapasc.consumption.dto.ConsumptionDTO;
import com.finalprojectandreeapasc.consumption.service.ConsumptionService;
import lombok.RequiredArgsConstructor;
import org.springframework.web.bind.annotation.*;

import java.util.List;

import static com.finalprojectandreeapasc.UrlMapping.CONSUMPTIONS;
import static com.finalprojectandreeapasc.UrlMapping.ENTITY;

@RestController
@RequiredArgsConstructor
@RequestMapping(value = CONSUMPTIONS)
public class ConsumptionController {
    private final ConsumptionService consumptionService;

    @GetMapping
    public List<ConsumptionDTO> allConsumptions() {
        return consumptionService.findAll();
    }

    @DeleteMapping(ENTITY)
    public void delete(@PathVariable Long id) {
        consumptionService.delete(id);
    }

    @PostMapping
    public ConsumptionDTO create(@RequestBody ConsumptionDTO consumptionDTO) {
        return consumptionService.create(consumptionDTO);
    }

    @PutMapping(ENTITY)
    public ConsumptionDTO update(@PathVariable Long id, @RequestBody ConsumptionDTO consumptionDTO) {
        return consumptionService.update(id, consumptionDTO);
    }
}
