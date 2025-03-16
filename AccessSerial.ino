// Serial Test via Serial Monitor
void SerialMonitorTest(){
  while (Serial.available()>0){
    receivedMessage = Serial.read();
    if (receivedMessage == 'a'){digitalWrite(LED_BUILTIN, HIGH);}
    else if (receivedMessage == 'b'){digitalWrite(LED_BUILTIN, LOW);}
  }
  while (PUSH_BUTTON_OK_IS_PRESSED) menu=0;
}

//Serial Test sending data from Master to Slave using UART 1
void MasterToSlaveSerial1Test(){
  MasterSerial1.println(String(counter));
  Serial.println("Master 1 Sent: " + String(counter)); counter++; delay(100);
}

//Serial Test sending data from Slave to Master using UART 1
void SlaveToMasterSerial1Test(){
  if (MasterSerial1.available()){
    String message = MasterSerial1.readStringUntil('\n');
    Serial.println("Master 1 Received: " + message);
  }
}

//Serial Test sending data from Master to Slave using UART 2
void MasterToSlaveSerial2Test(){
  MasterSerial2.println(String(counter));
  Serial.println("Master 2 Sent: " + String(counter));
  counter++;
  delay(100);
}

//Serial Test sending data from Slave to Master using UART 2
void SlaveToMasterSerial2Test(){
  if (MasterSerial2.available()){
    String message = MasterSerial2.readStringUntil('\n');
    Serial.println("Master 2 Received: " + message);
  }
}

//=====================================================================================================================================================//
void SerialDataReceived(){
  while (MasterSerial2.available()){                          //Open serial connection using MasterSerial2 (UART2)
    c = MasterSerial2.read();                                 //Read serial data and save the data to 'c' variable
    if (c==startDataIdentifier){                              //Checking the data to read '*' character
      bufferDataIn = startDataIdentifier;                     //Saving the data '*' character to bufferDataIn variable
      bufferDataIn += MasterSerial2.readStringUntil('#');     //Updating the data in bufferDataIn variable until read '#' character 
      dataIsComplete = true;                                  //Changee the boolean state of dataIsComplete variable
      bufferDataIn += stopDataIdentifier;                     //Updating the data in bufferDataIn variable until read '#' character
      Serial.print(bufferDataIn); Serial.print("\t");         //Show the data received to serial monitor
      break;                                                  //exit from if loop
    }
  }
}

void DataParsing(){
  for (int i=0;i<bufferDataIn.length();i++){
    if (bufferDataIn[i]==startDataIdentifier){
      bufferDataParsing[indexOfData] = "";
    }

    else if (bufferDataIn[i]!=dataSeparator){
      bufferDataParsing[indexOfData] += bufferDataIn[i];
    }

    else{
      indexOfData++;
      bufferDataParsing[indexOfData]="";
    }
  }
}

void DataConversion(){
  data1=bufferDataParsing[0].toInt();
  data2=bufferDataParsing[1].toInt();
  data3=bufferDataParsing[2].toInt();
  data4=bufferDataParsing[3].toInt();
}

void ShowData(){
  Serial.print("Data1 = "); Serial.print(data1); Serial.print("\t");
  Serial.print("Data2 = "); Serial.print(data2); Serial.print("\t");
  Serial.print("Data3 = "); Serial.print(data3); Serial.print("\t");
  Serial.print("Data4 = "); Serial.println(data4);
}

void ResetData(){
  c = 0;
  bufferDataIn="";
  dataIsComplete = false;
  indexOfData=0;
}
//=====================================================================================================================================================//
