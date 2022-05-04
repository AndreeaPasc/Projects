package com.finalprojectandreeapasc.springrmiserver;

import com.finalprojectandreeapasc.consumption.dto.ConsumptionDTO;
import com.finalprojectandreeapasc.consumption.service.ConsumptionService;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Component;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.*;

@Component
@RequiredArgsConstructor
public class ServerAPIImpl implements ServerAPI{

   private final ConsumptionService consumptionService;

    @Override
    public List<ConsumptionDTO> allConsumptions() throws RemoteException, ClassNotFoundException {

        return consumptionService.findAll();

    }
}
