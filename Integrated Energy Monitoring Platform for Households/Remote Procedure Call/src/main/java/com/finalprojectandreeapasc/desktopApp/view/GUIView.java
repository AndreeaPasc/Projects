package com.finalprojectandreeapasc.desktopApp.view;

import javax.swing.*;
import java.awt.event.ActionListener;

import static javax.swing.BoxLayout.Y_AXIS;

public class GUIView extends JFrame{

    private JButton historicalEnCons;
    private JButton baseline;
    private JButton setProgram1;
    private JButton setProgram2;
    private JButton setProgram3;

    public void initializeGui(){
        setSize(300,300);
        setLocationRelativeTo(null);
        setLayout(new BoxLayout(getContentPane(), Y_AXIS));
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        historicalEnCons = new JButton("Historical Energy Consumption");
        baseline = new JButton("Baseline(h)");
        setProgram1 = new JButton("Optimal Start time for Program 1: 3 hours");
        setProgram2 = new JButton("Optimal Start time for Program 2: 5 hours");
        setProgram3 = new JButton("Optimal Start time for Program 3: 8 hours");

        add(historicalEnCons);
        add(baseline);
        add(setProgram1);
        add(setProgram2);
        add(setProgram3);
        setVisible();
    }


    public void setHistoricalEnConsListener(ActionListener listener) {
        historicalEnCons.addActionListener(listener);
    }

    public void setBaselineListener(ActionListener registerButtonListener) {
        baseline.addActionListener(registerButtonListener);
    }

    public void setProgram1(ActionListener registerButtonListener) {
        setProgram1.addActionListener(registerButtonListener);
    }

    public void setProgram2(ActionListener registerButtonListener) {
        setProgram2.addActionListener(registerButtonListener);
    }

    public void setProgram3(ActionListener registerButtonListener) {
        setProgram3.addActionListener(registerButtonListener);
    }

    public void setVisible(){
        this.setVisible(true);
    }
}
