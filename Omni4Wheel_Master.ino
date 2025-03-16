/*
 * Bismillahirrohmanirrohim
 * Project      : Omni 4 Wheel Master Board Program
 * Author       : Parama Diptya Widayaka, S.ST., M.T.
 * Affiliation  : Universitas Negeri Surabaya
 *                Faculty of Engineering
 *                Department of Electrical Engineering
 *                Microprocessor Laboratory
 * Year         : 2025
 * Program Ver  : 1.0
 * 
 * PIN CONFIGURATION
 * 1. Push Button Up    -> GPIO Pin 12
 * 2. Push Button Down  -> GPIO Pin 15
 * 3. Push Button OK    -> GPIO Pin 27
 * 4. LED BUILTIN       -> GPIO Pin 2
 * 5. Encoder 1A        -> GPIO Pin 36
 * 6. Encoder 1B        -> GPIO Pin 39
 * 7. Encoder 2A        -> GPIO Pin 34
 * 8. Encoder 2B        -> GPIO Pin 35
*/

//Library Definition
#include <SPI.h>
#include <Wire.h>
#include <EEPROM.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//OLED 128x64 Definition
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//Push Button Definition
#define PB_UP   12
#define PB_DOWN 15
#define PB_OK   27
#define PUSH_BUTTON_DOWN_IS_PRESSED digitalRead(PB_DOWN)==LOW
#define PUSH_BUTTON_UP_IS_PRESSED   digitalRead(PB_UP)==LOW
#define PUSH_BUTTON_OK_IS_PRESSED   digitalRead(PB_OK)==LOW

//Motor & Encoder Definition
#define ENCODER1A   36
#define ENCODER1B   39
#define ENCODER2A   34
#define ENCODER2B   35
#define PWM_PIN_1A  23  
#define PWM_PIN_1B  19
#define PWM_PIN_2A  18
#define PWM_PIN_2B  4
#define NUM_OF_MOTORS 2

int VAL_ENC_1A = 0;
int VAL_ENC_1B = 0;
int VAL_ENC_2A = 0;
int VAL_ENC_2B = 0;

int16_t encoder_cnt[NUM_OF_MOTORS];
int16_t encoder_last_cnt[NUM_OF_MOTORS];
int16_t encoder_velocity[NUM_OF_MOTORS];
int16_t encoder_velocity_monitor[NUM_OF_MOTORS];

int frequency = 5000;
int resolution = 8;
int pwmChannel1 = 0;
int pwmChannel2 = 1;

//Hardware Serial Definition
#define RX1 13 
#define TX1 5
#define RX2 16
#define TX2 17
#define MASTER_SERIAL_BAUDRATE 9600

HardwareSerial MasterSerial1(1);
HardwareSerial MasterSerial2(2);

// Variabel Definition
int menu=0, 
    menu_program=0, 
    menu_sensor=0, 
    menu_encoder=0, 
    menu_motor=0, 
    menu_serial=0,
    
    pilih_menu=0, 
    pilih_menu_program=0, 
    pilih_menu_sensor=0, 
    pilih_menu_encoder=0, 
    pilih_menu_motor=0, 
    pilih_menu_serial=0;

char receivedMessage;
int counter=0;

unsigned long currentTime, 
              previousTime = 0;
int interval = 20;

const char startDataIdentifier = '*',
           dataSeparator = ',',
           stopDataIdentifier = '#';

const byte arraySize = 21;

char c;
String bufferDataIn;
bool dataIsComplete;
String bufferDataParsing[arraySize];
byte indexOfData;
int data1, data2, data3, data4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  MasterSerial1.begin(MASTER_SERIAL_BAUDRATE, SERIAL_8N1, RX1, TX1);
  MasterSerial2.begin(MASTER_SERIAL_BAUDRATE, SERIAL_8N1, RX2, TX2);
  
  pinMode(PB_UP,       INPUT_PULLUP);
  pinMode(PB_DOWN,     INPUT_PULLUP);
  pinMode(PB_OK,       INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

  ledcSetup(pwmChannel1, frequency, resolution);
  ledcAttachPin(PWM_PIN_1A, pwmChannel1); pinMode(PWM_PIN_1B, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(ENCODER1A), encoder1_ISR, CHANGE); pinMode(ENCODER1B, INPUT);
  
  ledcSetup(pwmChannel1, frequency, resolution);
  ledcAttachPin(PWM_PIN_2A, pwmChannel2); pinMode(PWM_PIN_2B, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(ENCODER2A), encoder2_ISR, CHANGE); pinMode(ENCODER2B, INPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  robot_boot_screen();
}

void loop() {
//  while (menu==0) {robot_home_screen();}
//  while (menu==1) {robot_program_mode();}
//  while (menu==2) {robot_sensor_check();}
//  while (menu==3) {robot_encoder_check();}
//  while (menu==4) {robot_motor_check();}
//  while (menu==5) {robot_serial_check();}
//  while (menu==6) {robot_about_platform();}

//MasterToSlaveSerial1Test();
//MasterToSlaveSerial2Test();
//SlaveToMasterSerial1Test();
//SlaveToMasterSerial2Test();

SerialDataReceived();

if (dataIsComplete==true){
  DataParsing();

  DataConversion();

  ShowData();

  ResetData();
}
}
