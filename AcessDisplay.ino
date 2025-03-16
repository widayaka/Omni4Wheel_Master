void robot_boot_screen(){
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0,0); display.println(F("Dhurobotic - 2025"));
  display.setCursor(0,10); display.println(F("Omni 4 Wheel Robot"));
  display.setCursor(0,20); display.println(F("By: Parama Diptya W"));
  display.setCursor(0,30); display.println(F("FT - UNESA"));
  display.setCursor(0,40); display.println(F("Microprocessor"));
  display.setCursor(0,50); display.println(F("Laboratory"));

  display.display();
  delay(2000);
  display.clearDisplay();
}

void robot_home_screen(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  switch(pilih_menu){
    case 0: pilih_menu = 1; break;

    // Menu Program Mode
    case 1: display.setTextSize(1);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0,0);   display.println(F(">"));
            display.setCursor(10,0);  display.println(F("Program Mode"));
            display.setCursor(10,10);  display.println(F("Sensor Check"));
            display.setCursor(10,20);  display.println(F("Encoder Check"));
            display.setCursor(10,30);  display.println(F("Motor Check"));
            display.setCursor(10,40);  display.println(F("Serial Check"));
            display.setCursor(10,50);  display.println(F("About Platform"));
            display.display(); 
            while (PUSH_BUTTON_OK_IS_PRESSED) menu=1;
            break;

    // Menu Sensor Check
    case 2: display.setTextSize(1);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0,10);   display.println(F(">"));
            display.setCursor(10,0);  display.println(F("Program Mode"));
            display.setCursor(10,10);  display.println(F("Sensor Check"));
            display.setCursor(10,20);  display.println(F("Encoder Check"));
            display.setCursor(10,30);  display.println(F("Motor Check"));
            display.setCursor(10,40);  display.println(F("Serial Check"));
            display.setCursor(10,50);  display.println(F("About Platform"));
            display.display(); 
            while (PUSH_BUTTON_OK_IS_PRESSED) menu=2;
            break;

    // Menu Encoder Check       
    case 3: display.setTextSize(1);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0,20);   display.println(F(">"));
            display.setCursor(10,0);  display.println(F("Program Mode"));
            display.setCursor(10,10);  display.println(F("Sensor Check"));
            display.setCursor(10,20);  display.println(F("Encoder Check"));
            display.setCursor(10,30);  display.println(F("Motor Check"));
            display.setCursor(10,40);  display.println(F("Serial Check"));
            display.setCursor(10,50);  display.println(F("About Platform"));
            display.display(); 
            while (PUSH_BUTTON_OK_IS_PRESSED) menu=3;
            break;

    // Menu Motor Check
    case 4: display.setTextSize(1);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0,30);   display.println(F(">"));
            display.setCursor(10,0);  display.println(F("Program Mode"));
            display.setCursor(10,10);  display.println(F("Sensor Check"));
            display.setCursor(10,20);  display.println(F("Encoder Check"));
            display.setCursor(10,30);  display.println(F("Motor Check"));
            display.setCursor(10,40);  display.println(F("Serial Check"));
            display.setCursor(10,50);  display.println(F("About Platform"));
            display.display(); 
            while (PUSH_BUTTON_OK_IS_PRESSED) menu=4;
            break;

    // Menu Serial Check
    case 5: display.setTextSize(1);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0,40);   display.println(F(">"));
            display.setCursor(10,0);  display.println(F("Program Mode"));
            display.setCursor(10,10);  display.println(F("Sensor Check"));
            display.setCursor(10,20);  display.println(F("Encoder Check"));
            display.setCursor(10,30);  display.println(F("Motor Check"));
            display.setCursor(10,40);  display.println(F("Serial Check"));
            display.setCursor(10,50);  display.println(F("About Platform"));
            display.display(); 
            while (PUSH_BUTTON_OK_IS_PRESSED) menu=5;
            break;
            
    // Menu About Platform
    case 6: display.setTextSize(1);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0,50);   display.println(F(">"));
            display.setCursor(10,0);  display.println(F("Program Mode"));
            display.setCursor(10,10);  display.println(F("Sensor Check"));
            display.setCursor(10,20);  display.println(F("Encoder Check"));
            display.setCursor(10,30);  display.println(F("Motor Check"));
            display.setCursor(10,40);  display.println(F("Serial Check"));
            display.setCursor(10,50);  display.println(F("About Platform"));
            display.display(); 
            while (PUSH_BUTTON_OK_IS_PRESSED) {menu=6; delay(200); display.clearDisplay();}
            break;
                    
    case 7: pilih_menu = 6; break;
  }
  if (PUSH_BUTTON_DOWN_IS_PRESSED)  {delay(200); display.clearDisplay(); pilih_menu++;}
  if (PUSH_BUTTON_UP_IS_PRESSED)    {delay(200); display.clearDisplay(); pilih_menu--;}
}

void robot_program_mode(){
  
}

void robot_sensor_check(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  switch(pilih_menu_sensor){
    case 0: pilih_menu_sensor = 1; break;

    // Menu Program Mode
    case 1: display.setTextSize(1);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0,0);   display.println(F(">"));
            display.setCursor(10,0);  display.println(F("MPU6050"));
            display.setCursor(10,10);  display.println(F("BNO055"));
            display.setCursor(10,20);  display.println(F("Exit"));
            display.display(); 
            while (PUSH_BUTTON_OK_IS_PRESSED) menu=1;
            break;

    // Menu Sensor Check
    case 2: display.setTextSize(1);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0,10);   display.println(F(">"));
            display.setCursor(10,0);  display.println(F("MPU6050"));
            display.setCursor(10,10);  display.println(F("BNO055"));
            display.setCursor(10,20);  display.println(F("Exit"));
            display.display(); 
            while (PUSH_BUTTON_OK_IS_PRESSED) menu=2;
            break;

    // Menu Encoder Check       
    case 3: display.setTextSize(1);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0,20);   display.println(F(">"));
            display.setCursor(10,0);  display.println(F("MPU6050"));
            display.setCursor(10,10);  display.println(F("BNO055"));
            display.setCursor(10,20);  display.println(F("Exit"));
            display.display(); 
            while (PUSH_BUTTON_OK_IS_PRESSED) {pilih_menu_sensor = 0; menu=0;}
            break;
                    
    case 4: pilih_menu_sensor = 3; break;
  }
  if (PUSH_BUTTON_DOWN_IS_PRESSED)  {delay(200); display.clearDisplay(); pilih_menu_sensor++;}
  if (PUSH_BUTTON_UP_IS_PRESSED)    {delay(200); display.clearDisplay(); pilih_menu_sensor--;}
}

void robot_encoder_check(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  switch(pilih_menu_encoder){
    case 0: pilih_menu_encoder = 1; break;

    // Menu Program Mode
    case 1: display.setTextSize(1);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0,0);   display.println(F(">"));
            display.setCursor(10,0);  display.println(F("2 Encoder Master"));
            display.setCursor(10,10);  display.println(F("4 Encoder Slave"));
            display.setCursor(10,20);  display.println(F("Exit"));
            display.display(); 
            while (PUSH_BUTTON_OK_IS_PRESSED) menu=1;
            break;

    // Menu Sensor Check
    case 2: display.setTextSize(1);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0,10);   display.println(F(">"));
            display.setCursor(10,0);  display.println(F("2 Encoder Master"));
            display.setCursor(10,10);  display.println(F("4 Encoder Slave"));
            display.setCursor(10,20);  display.println(F("Exit"));
            display.display(); 
            while (PUSH_BUTTON_OK_IS_PRESSED) menu=2;
            break;

    // Menu Encoder Check       
    case 3: display.setTextSize(1);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0,20);   display.println(F(">"));
            display.setCursor(10,0);  display.println(F("2 Encoder Master"));
            display.setCursor(10,10);  display.println(F("4 Encoder Slave"));
            display.setCursor(10,20);  display.println(F("Exit"));
            display.display(); 
            while (PUSH_BUTTON_OK_IS_PRESSED) {pilih_menu_encoder = 0; menu=0;}
            break;
                    
    case 4: pilih_menu_encoder = 3; break;
  }
  if (PUSH_BUTTON_DOWN_IS_PRESSED)  {delay(200); display.clearDisplay(); pilih_menu_encoder++;}
  if (PUSH_BUTTON_UP_IS_PRESSED)    {delay(200); display.clearDisplay(); pilih_menu_encoder--;}
}

void robot_motor_check(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  switch(pilih_menu_motor){
    case 0: pilih_menu_motor = 1; break;

    // Menu Program Mode
    case 1: display.setTextSize(1);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0,0);   display.println(F(">"));
            display.setCursor(10,0);  display.println(F("2 Motor Master"));
            display.setCursor(10,10);  display.println(F("4 Motor Slave"));
            display.setCursor(10,20);  display.println(F("Exit"));
            display.display(); 
            while (PUSH_BUTTON_OK_IS_PRESSED) menu=1;
            break;

    // Menu Sensor Check
    case 2: display.setTextSize(1);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0,10);   display.println(F(">"));
            display.setCursor(10,0);  display.println(F("2 Motor Master"));
            display.setCursor(10,10);  display.println(F("4 Motor Slave"));
            display.setCursor(10,20);  display.println(F("Exit"));
            display.display(); 
            while (PUSH_BUTTON_OK_IS_PRESSED) menu=2;
            break;

    // Menu Encoder Check       
    case 3: display.setTextSize(1);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0,20);   display.println(F(">"));
            display.setCursor(10,0);  display.println(F("2 Motor Master"));
            display.setCursor(10,10);  display.println(F("4 Motor Slave"));
            display.setCursor(10,20);  display.println(F("Exit"));
            display.display(); 
            while (PUSH_BUTTON_OK_IS_PRESSED) {pilih_menu_motor = 0; menu=0;}
            break;
                    
    case 4: pilih_menu_motor = 3; break;
  }
  if (PUSH_BUTTON_DOWN_IS_PRESSED)  {delay(200); display.clearDisplay(); pilih_menu_motor++;}
  if (PUSH_BUTTON_UP_IS_PRESSED)    {delay(200); display.clearDisplay(); pilih_menu_motor--;}
}

void robot_serial_check(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  switch(pilih_menu_serial){
    case 0: pilih_menu_serial = 1; break;

    // Menu Program Mode
    case 1: display.setTextSize(1);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0,0);   display.println(F(">"));
            display.setCursor(10,0);  display.println(F("Serial Monitor"));
            display.setCursor(10,10);  display.println(F("Master to Slave"));
            display.setCursor(10,20);  display.println(F("Slave to Master"));
            display.setCursor(10,30);  display.println(F("Biderictional Data"));
            display.setCursor(10,40);  display.println(F("Exit"));
            display.display(); 
            while (PUSH_BUTTON_OK_IS_PRESSED) menu_serial=7;
            break;

    case 2: display.setTextSize(1);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0,10);   display.println(F(">"));
            display.setCursor(10,0);  display.println(F("Serial Monitor"));
            display.setCursor(10,10);  display.println(F("Master to Slave"));
            display.setCursor(10,20);  display.println(F("Slave to Master"));
            display.setCursor(10,30);  display.println(F("Biderictional Data"));
            display.setCursor(10,40);  display.println(F("Exit"));
            display.display(); 
            while (PUSH_BUTTON_OK_IS_PRESSED) menu=1;
            break;
            
    case 3: display.setTextSize(1);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0,20);   display.println(F(">"));
            display.setCursor(10,0);  display.println(F("Serial Monitor"));
            display.setCursor(10,10);  display.println(F("Master to Slave"));
            display.setCursor(10,20);  display.println(F("Slave to Master"));
            display.setCursor(10,30);  display.println(F("Biderictional Data"));
            display.setCursor(10,40);  display.println(F("Exit"));
            display.display(); 
            while (PUSH_BUTTON_OK_IS_PRESSED) menu=1;
            break;

    case 4: display.setTextSize(1);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0,30);   display.println(F(">"));
            display.setCursor(10,0);  display.println(F("Serial Monitor"));
            display.setCursor(10,10);  display.println(F("Master to Slave"));
            display.setCursor(10,20);  display.println(F("Slave to Master"));
            display.setCursor(10,30);  display.println(F("Biderictional Data"));
            display.setCursor(10,40);  display.println(F("Exit"));
            display.display(); 
            while (PUSH_BUTTON_OK_IS_PRESSED) menu=1;
            break;

    case 5: display.setTextSize(1);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0,40);   display.println(F(">"));
            display.setCursor(10,0);  display.println(F("Serial Monitor"));
            display.setCursor(10,10);  display.println(F("Master to Slave"));
            display.setCursor(10,20);  display.println(F("Slave to Master"));
            display.setCursor(10,30);  display.println(F("Biderictional Data"));
            display.setCursor(10,40);  display.println(F("Exit"));
            display.display(); 
            while (PUSH_BUTTON_OK_IS_PRESSED) {pilih_menu_serial = 0; menu=0;}
            break;
    
    case 6: pilih_menu_serial = 5; break;
  }
  if (PUSH_BUTTON_DOWN_IS_PRESSED)  {delay(200); display.clearDisplay(); pilih_menu_serial++;}
  if (PUSH_BUTTON_UP_IS_PRESSED)    {delay(200); display.clearDisplay(); pilih_menu_serial--;}
}

void robot_about_platform(){
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);    display.println(F("Omni 4 Wheel Robot"));
  display.setCursor(0,10);   display.println(F("Version: 1.0"));
  display.setCursor(0,20);   display.println(F("Year: 2025"));
  display.setCursor(0,30);   display.println(F("Author: Widayaka"));
  display.setCursor(0,40);   display.println(F("Microprocessor"));
  display.setCursor(0,50);   display.println(F("Library"));
  display.display();

  while (digitalRead(PB_OK)==LOW) {menu=0; delay(200); display.clearDisplay();}
}
