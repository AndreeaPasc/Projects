package com.finalprojectandreeapasc.consumption.controller;
import com.finalprojectandreeapasc.consumption.dto.ConsumptionDTO;
import com.finalprojectandreeapasc.consumption.service.ConsumptionService;
import com.finalprojectandreeapasc.UrlMapping;
import lombok.RequiredArgsConstructor;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequiredArgsConstructor
@RequestMapping(value = UrlMapping.CONSUMPTIONS)
public class ConsumptionController {
    private final ConsumptionService consumptionService;

    @GetMapping
    public List<ConsumptionDTO> allConsumptions() {
        return consumptionService.findAll();
    }

    @DeleteMapping(UrlMapping.ENTITY)
    public void delete(@PathVariable Long id) {
        consumptionService.delete(id);
    }

    @PostMapping
    public ConsumptionDTO create(@RequestBody ConsumptionDTO consumptionDTO) {
        return consumptionService.create(consumptionDTO);
    }

    @PutMapping(UrlMapping.ENTITY)
    public ConsumptionDTO update(@PathVariable Long id, @RequestBody ConsumptionDTO consumptionDTO) {
        return consumptionService.update(id, consumptionDTO);
    }
}
