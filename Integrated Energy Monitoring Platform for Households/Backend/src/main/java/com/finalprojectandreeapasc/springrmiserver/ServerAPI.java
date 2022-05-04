package com.finalprojectandreeapasc.springrmiserver;

import com.finalprojectandreeapasc.consumption.dto.ConsumptionDTO;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.List;

public interface ServerAPI extends Remote {

    public List<ConsumptionDTO> allConsumptions() throws RemoteException, ClassNotFoundException;

}