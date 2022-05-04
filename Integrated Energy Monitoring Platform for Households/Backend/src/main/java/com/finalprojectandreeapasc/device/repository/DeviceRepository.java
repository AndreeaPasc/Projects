package com.finalprojectandreeapasc.device.repository;
import com.finalprojectandreeapasc.device.model.Device;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface DeviceRepository extends JpaRepository<Device, Long> {
}