package com.finalprojectandreeapasc.desktopApp.controller;

import com.finalprojectandreeapasc.consumption.dto.ConsumptionDTO;
import com.finalprojectandreeapasc.consumption.service.ConsumptionService;
import com.finalprojectandreeapasc.desktopApp.view.GUIView;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.CategoryPlot;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.chart.renderer.category.BarRenderer;
import org.jfree.data.category.CategoryDataset;
import org.jfree.data.category.DefaultCategoryDataset;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class GUIController extends JFrame{

    private final GUIView guiView;
    private List<ConsumptionDTO> consumptionList;

    public GUIController(List<ConsumptionDTO> consumptionList) {
        this.guiView = new GUIView();
        this.consumptionList = consumptionList;
    }

    public void initializeButtons(GUIView guiView){
        guiView.setHistoricalEnConsListener(new HistoricalEnConsListener());
        guiView.setBaselineListener(new BaselineConsListener());
        guiView.setProgram1(new Program1Listener());
        guiView.setProgram2(new Program2Listener());
        guiView.setProgram3(new Program3Listener());
    }

    private class HistoricalEnConsListener implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent e){
            chartController(
                    "Energy Consumption", createDataset(), "Days", "Energy Consumption");
        }
    }

    private class BaselineConsListener implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent e){
            chartController(
                    "Baseline", createDataset1(), "Hours", "Predicted Energy Consumption");
        }
    }

    private class Program1Listener implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
            chartController(
                    "Baseline", createDataset2(3), "Hours", "Time start for optimal Energy Consumption");
        }
    }

    private class Program2Listener implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
            chartController(
                    "Baseline", createDataset2(5), "Hours", "Time start for optimal Energy Consumption");
        }
    }

    private class Program3Listener implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
            chartController(
                    "Baseline", createDataset2(8), "Hours", "Time start for optimal Energy Consumption");
        }
    }

    private void chartController(String chartTitle, CategoryDataset dataset, String categoryAxisLabel, String valueAxisLabel) {
        JFreeChart barChart = ChartFactory.createBarChart(
                chartTitle,
                categoryAxisLabel,
                valueAxisLabel,
                dataset,
                PlotOrientation.VERTICAL,
                true, true, false);

        ChartPanel chartPanel = new ChartPanel( barChart );
        chartPanel.setPreferredSize(new java.awt.Dimension( 1000 , 1000 ) );
        setContentPane( chartPanel );
        setVisible(true);
    }

    private CategoryDataset createDataset( ) {
        final DefaultCategoryDataset dataset =
                new DefaultCategoryDataset( );

        String day;
        String hour;

        for(ConsumptionDTO c: consumptionList){
            day = c.getTimestamp().substring(0, 10);
            hour = c.getTimestamp().substring(11, 13);
            dataset.addValue(c.getEnergyConsumption(), day, String.valueOf(Integer.parseInt(hour) + 1));
        }

        return dataset;
    }

    private CategoryDataset createDataset1( ) {
        final DefaultCategoryDataset dataset =
                new DefaultCategoryDataset( );

        String day;
        String hour;

        List<Float> baseline = new ArrayList<>();

        for(int i = 0; i < 24; i++){
            baseline.add(0f);
        }

        System.out.println(baseline.size());

        List<String> hours = new ArrayList<>();
        List<String> days = new ArrayList<>();

        for(ConsumptionDTO c: consumptionList){
            day = c.getTimestamp().substring(0, 10);
            hour = c.getTimestamp().substring(11, 13);
            days.add(day);
            hours.add(hour);
        }

        hours = hours.stream().distinct().sorted().collect(Collectors.toList());
        days = days.stream().distinct().sorted().collect(Collectors.toList());

        System.out.println(hours);
        System.out.println(days);

        for(ConsumptionDTO c: consumptionList){
            hour = c.getTimestamp().substring(11, 13);
            computeBaseline(baseline, hour, c);
        }

        for(int i = 0; i < 24; i++){
            baseline.set(i, (float) 1/7 * baseline.get(i));
        }

        System.out.println(baseline);

        int i = 0;
        for(String h: hours){
            dataset.addValue(baseline.get(i), String.valueOf(Integer.parseInt(h) + 1), String.valueOf(Integer.parseInt(h) + 1));
            i++;
        }

        return dataset;
    }

    private CategoryDataset createDataset2(Integer duration ) {
        final DefaultCategoryDataset dataset =
                new DefaultCategoryDataset( );

        String day;
        String hour;

        List<Float> baseline = new ArrayList<>();

        for(int i = 0; i < 24; i++){
            baseline.add(0f);
        }

        System.out.println(baseline.size());

        List<String> hours = new ArrayList<>();
        List<String> days = new ArrayList<>();

        for(ConsumptionDTO c: consumptionList){
            day = c.getTimestamp().substring(0, 10);
            hour = c.getTimestamp().substring(11, 13);
            days.add(day);
            hours.add(hour);
        }

        hours = hours.stream().distinct().sorted().collect(Collectors.toList());
        days = days.stream().distinct().sorted().collect(Collectors.toList());

        System.out.println(hours);
        System.out.println(days);

        for(ConsumptionDTO c: consumptionList){
            hour = c.getTimestamp().substring(11, 13);
            computeBaseline(baseline, hour, c);
        }

        for(int i = 0; i < 24; i++){
            baseline.set(i, (float) 1/7 * baseline.get(i) + 20f);
        }

        System.out.println(baseline);

        float maxBaseline = 0f;
        int maxBaselineHour = 0;

        for(int i = 0; i < 24; i++){
            maxBaseline = Math.max(maxBaseline, baseline.get(i));
            maxBaselineHour = i;
        }

        System.out.println(maxBaseline);
        System.out.println(maxBaselineHour);

        for(int i = maxBaselineHour; i < maxBaselineHour + duration; i++){
            if(i >= 24) {
                int newHour = i - 24;
                dataset.addValue(baseline.get(newHour), String.valueOf(newHour), String.valueOf(newHour));
            } else {
                dataset.addValue(baseline.get(i), String.valueOf(i), String.valueOf(i));
            }
        }

        return dataset;
    }



    private void computeBaseline(List<Float> baseline, String hour, ConsumptionDTO c){

        switch(hour){
            case "00":
                baseline.set(0, baseline.get(0) + c.getEnergyConsumption());
                break;
            case "01":
                baseline.set(1, baseline.get(1) + c.getEnergyConsumption());
                break;
            case "02":
                baseline.set(2, baseline.get(2) + c.getEnergyConsumption());
                break;
            case "03":
                baseline.set(3, baseline.get(3) + c.getEnergyConsumption());
                break;
            case "04":
                baseline.set(4, baseline.get(4) + c.getEnergyConsumption());
                break;
            case "05":
                baseline.set(5, baseline.get(5) + c.getEnergyConsumption());
                break;
            case "06":
                baseline.set(6, baseline.get(6) + c.getEnergyConsumption());
                break;
            case "07":
                baseline.set(7, baseline.get(7) + c.getEnergyConsumption());
                break;
            case "08":
                baseline.set(8, baseline.get(8) + c.getEnergyConsumption());
                break;
            case "09":
                baseline.set(9, baseline.get(9) + c.getEnergyConsumption());
                break;
            case "10":
                baseline.set(10, baseline.get(10) + c.getEnergyConsumption());
                break;
            case "11":
                baseline.set(11, baseline.get(11) + c.getEnergyConsumption());
                break;
            case "12":
                baseline.set(12, baseline.get(12) + c.getEnergyConsumption());
                break;
            case "13":
                baseline.set(13, baseline.get(13) + c.getEnergyConsumption());
                break;
            case "14":
                baseline.set(14, baseline.get(14) + c.getEnergyConsumption());
                break;
            case "15":
                baseline.set(15, baseline.get(15) + c.getEnergyConsumption());
                break;
            case "16":
                baseline.set(16, baseline.get(16) + c.getEnergyConsumption());
                break;
            case "17":
                baseline.set(17, baseline.get(17) + c.getEnergyConsumption());
                break;
            case "18":
                baseline.set(18, baseline.get(18) + c.getEnergyConsumption());
                break;
            case "19":
                baseline.set(19, baseline.get(19) + c.getEnergyConsumption());
                break;
            case "20":
                baseline.set(20, baseline.get(20) + c.getEnergyConsumption());
                break;
            case "21":
                baseline.set(21, baseline.get(21) + c.getEnergyConsumption());
                break;
            case "22":
                baseline.set(22, baseline.get(22) + c.getEnergyConsumption());
                break;
            case "23":
                baseline.set(23, baseline.get(23) + c.getEnergyConsumption());
                break;
            default: break;
        }
    }
}
