package com.finalprojectandreeapasc.consumption.repository;

import com.finalprojectandreeapasc.consumption.model.Consumption;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface ConsumptionRepository extends JpaRepository<Consumption, Long> {
}
