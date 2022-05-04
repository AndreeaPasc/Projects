package com.finalprojectandreeapasc.consumption.service;

import com.finalprojectandreeapasc.consumption.dto.ConsumptionDTO;
import com.finalprojectandreeapasc.consumption.mapper.ConsumptionMapper;
import com.finalprojectandreeapasc.consumption.model.Consumption;
import com.finalprojectandreeapasc.consumption.repository.ConsumptionRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

import javax.persistence.EntityNotFoundException;
import java.util.List;
import java.util.stream.Collectors;

@Service
@RequiredArgsConstructor
public class ConsumptionService {

    private final ConsumptionRepository consumptionRepository;
    private final ConsumptionMapper consumptionMapper;

    private Consumption findById(Long id) {
        return consumptionRepository.findById(id).orElseThrow(() -> new EntityNotFoundException("The consumption was not found: " + id));
    }

    public List<ConsumptionDTO> findAll() {
        List<Consumption> consumptionList = consumptionRepository.findAll();
        return consumptionList.stream()
                .map(consumptionMapper::toDTO)
                .collect(Collectors.toList());
    }

    public void delete(Long id) {
        consumptionRepository.deleteById(id);
    }

    public ConsumptionDTO create(ConsumptionDTO consumptionDTO) {
        return consumptionMapper.toDTO(consumptionRepository.save(
                consumptionMapper.fromDTO(consumptionDTO)
        ));
    }

    public ConsumptionDTO update(Long id, ConsumptionDTO consumptionDTO) {
        Consumption actConsumption = findById(id);
        actConsumption.setEnergyConsumption(consumptionDTO.getEnergyConsumption());
        actConsumption.setTimestamp(consumptionDTO.getTimestamp());
        actConsumption.setSensorId(consumptionDTO.getSensorId());
        actConsumption.setId(consumptionDTO.getId());
        return consumptionMapper.toDTO(
                consumptionRepository.save(actConsumption)
        );
    }
}
