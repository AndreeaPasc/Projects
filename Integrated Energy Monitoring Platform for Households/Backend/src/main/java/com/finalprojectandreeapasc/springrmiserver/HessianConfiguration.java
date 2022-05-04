package com.finalprojectandreeapasc.springrmiserver;

import com.finalprojectandreeapasc.consumption.service.ConsumptionService;
import lombok.RequiredArgsConstructor;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.remoting.caucho.HessianServiceExporter;
import org.springframework.remoting.support.RemoteExporter;

import java.rmi.RemoteException;

@Configuration
@RequiredArgsConstructor
public class HessianConfiguration {

    private final ConsumptionService consumptionService;

    @Bean(name = "/hellohessian")
    RemoteExporter sayHelloServiceHessian() throws RemoteException {
        HessianServiceExporter exporter = new HessianServiceExporter();
        exporter.setService(new ServerAPIImpl(consumptionService));
        exporter.setServiceInterface(ServerAPI.class);
        return exporter;
    }
}