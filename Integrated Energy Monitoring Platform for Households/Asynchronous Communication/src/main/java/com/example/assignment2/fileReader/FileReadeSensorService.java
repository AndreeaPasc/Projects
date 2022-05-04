package com.example.assignment2.fileReader;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import com.opencsv.CSVReader;
import lombok.RequiredArgsConstructor;
import lombok.Setter;
import org.springframework.stereotype.Service;

import java.io.FileReader;

@Service
@RequiredArgsConstructor
@Setter
public class FileReadeSensorService {

    public void getValues(List<Float> values){

        try {
            FileReader fileReader = new FileReader("sensor.csv");
            CSVReader csvReader = new CSVReader(fileReader);
            String[] nextRecord;
            while ((nextRecord = csvReader.readNext()) != null) {
                values.add(Float.parseFloat(String.valueOf(nextRecord[0])));
            }
        }
        catch(Exception e){
                e.printStackTrace();
            }
    }

}
