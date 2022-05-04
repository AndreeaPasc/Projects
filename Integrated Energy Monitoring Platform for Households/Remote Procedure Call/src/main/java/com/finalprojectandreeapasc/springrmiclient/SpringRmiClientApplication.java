package com.finalprojectandreeapasc.springrmiclient;
import com.finalprojectandreeapasc.consumption.dto.ConsumptionDTO;
import com.finalprojectandreeapasc.desktopApp.controller.GUIController;
import com.finalprojectandreeapasc.desktopApp.view.GUIView;
import com.finalprojectandreeapasc.springrmiserver.ServerAPI;
import lombok.Getter;
import lombok.RequiredArgsConstructor;
import lombok.Setter;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ConfigurableApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.remoting.caucho.HessianProxyFactoryBean;

import java.rmi.Naming;
import java.rmi.RemoteException;
import java.util.ArrayList;
import java.util.List;

@SpringBootApplication
@RequiredArgsConstructor
@Getter
@Setter
public class SpringRmiClientApplication {

	@Bean
	public HessianProxyFactoryBean hessianInvoker() {
		HessianProxyFactoryBean invoker = new HessianProxyFactoryBean();
		//invoker.setServiceUrl("http://localhost:8087/hellohessian");
		invoker.setServiceUrl("https://ds2020-30431-pasc-andreea-1-be.herokuapp.com/hellohessian");
		invoker.setServiceInterface(ServerAPI.class);
		return invoker;
	}

	public static void main(String[] args) throws RemoteException, ClassNotFoundException {

		ConfigurableApplicationContext context = SpringApplication.run(SpringRmiClientApplication.class, args);
		List<ConsumptionDTO> consumptionDTOList;
		ServerAPI server = context.getBean(ServerAPI.class);

		consumptionDTOList = server.allConsumptions();
		System.out.println(consumptionDTOList);
		System.setProperty("java.awt.headless", "false");

		GUIView guiView = new GUIView();
		guiView.initializeGui();

		GUIController guiController = new GUIController(consumptionDTOList);
		guiController.initializeButtons(guiView);
	}
}
