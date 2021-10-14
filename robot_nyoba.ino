
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SoftwareSerial.h> // inclue library software serial

#include <ComponentObject.h>
#include <RangeSensor.h>
#include <SparkFun_VL53L1X.h>
#include <vl53l1x_class.h>
#include <vl53l1_error_codes.h>




Adafruit_PWMServoDriver board2 = Adafruit_PWMServoDriver(0x41);
Adafruit_PWMServoDriver board1 = Adafruit_PWMServoDriver(0x43);
#define MIN_PULSE_WIDTH        650
#define MAX_PULSE_WIDTH        2350
#define DEFAULT_PULSE_WIDTH    1100
#define FREQUENCY              50



SoftwareSerial BlueLED(2, 3); // RX, TX untuk menerima data dari Module Bluetooth




int pos = 0;    // variable to store the servo position


uint8_t servonum = 0;



void setup() {

  pinMode(12, OUTPUT);
  BlueLED.begin(9600); // mengatur boaudrate serial modul bluetooth

  
  Serial.begin (9600);
  //   Serial.println (" Tes Servo 3 Channel");
  board1.begin();
  board2.begin();

  

  board1.setPWMFreq(FREQUENCY);
  board2.setPWMFreq(FREQUENCY);


  board1.setPWM(0, 0, pulseWidth(105)); //
  board1.setPWM(1, 0, pulseWidth(180)); //
  board1.setPWM(2, 0, pulseWidth(180)); //

  board1.setPWM(4, 0, pulseWidth(75)); //
  board1.setPWM(5, 0, pulseWidth(180)); //
  board1.setPWM(6, 0, pulseWidth(180)); //

  board1.setPWM(8, 0, pulseWidth(105)); //
  board1.setPWM(9, 0, pulseWidth(180)); //
  board1.setPWM(10, 0, pulseWidth(180)); //
  // board 2
  board2.setPWM(0, 0, pulseWidth(105)); //
  board2.setPWM(1, 0, pulseWidth(180)); //
  board2.setPWM(2, 0, pulseWidth(180)); //

  board2.setPWM(4, 0, pulseWidth(75)); //
  board2.setPWM(5, 0, pulseWidth(180)); //
  board2.setPWM(6, 0, pulseWidth(180)); //

  board2.setPWM(8, 0, pulseWidth(105)); //
  board2.setPWM(9, 0, pulseWidth(180)); //
  board2.setPWM(10, 0, pulseWidth(180)); //

  delay (2000);



}



void loop() {

if (BlueLED.available()) // jika ada data serial dari modul bluetooth
      {
        char data = BlueLED.read(); // simpan data itu di variable 'data'
        Serial.println(data); // print variable data ke serial monitor
   
        if (data == '1') // jika mendapatkan karakter '1'
          { // maka
           belokkiri();
           Serial.println(data);
           
          }
        else if (data == '0') // namun jika mendapatkan karakter '0'
          { // maka
            belokkanan();
            Serial.println(data);
          }

        else if (data == '3') // namun jika mendapatkan karakter '0'
          { // maka
            maju();
            Serial.println(data);
          }

        else if (data == '2') // namun jika mendapatkan karakter '0'
          { // maka
            mundur();
            Serial.println(data);
          } 
      }

}


  


void belokkiri () {
  // board 1  1a
  board1.setPWM(1, 0, pulseWidth(180));
  board1.setPWM(2, 0, pulseWidth(130)); //

  board1.setPWM(5, 0, pulseWidth(180));
  board1.setPWM(6, 0, pulseWidth(130));

  board1.setPWM(9, 0, pulseWidth(180));
  board1.setPWM(10, 0, pulseWidth(130)); //+ 40


  delay (200);
  // 1b
  board1.setPWM(0, 0, pulseWidth(105)); // kondisi awal 135 -
  board1.setPWM(4, 0, pulseWidth(105)); // kondisi awal 90 +
  board1.setPWM(8, 0, pulseWidth(105)); // kondisi awal 45 -
  delay (200);

  //1c

  board1.setPWM(1, 0, pulseWidth(170)); //
  board1.setPWM(2, 0, pulseWidth(170)); //

  board1.setPWM(5, 0, pulseWidth(170)); //
  board1.setPWM(6, 0, pulseWidth(170)); //

  board1.setPWM(9, 0, pulseWidth(170)); //
  board1.setPWM(10, 0, pulseWidth(170)); //
  delay (200);


  board1.setPWM(0, 0, pulseWidth(75)); //
  board1.setPWM(4, 0, pulseWidth(75)); //
  board1.setPWM(8, 0, pulseWidth(75)); //
  // board 2  2a
  board2.setPWM(1, 0, pulseWidth(180)); //
  board2.setPWM(2, 0, pulseWidth(130)); //

  board2.setPWM(5, 0, pulseWidth(180)); //
  board2.setPWM(6, 0, pulseWidth(130)); //

  board2.setPWM(9, 0, pulseWidth(180)); //
  board2.setPWM(10, 0, pulseWidth(130)); //
  delay (200);


  //2b
  board2.setPWM(0, 0, pulseWidth(105)); //   +
  board2.setPWM(4, 0, pulseWidth(105)); //   -
  board2.setPWM(8, 0, pulseWidth(105)); //  +
  delay (200);
  //2c
  board2.setPWM(1, 0, pulseWidth(170)); //
  board2.setPWM(2, 0, pulseWidth(170)); //

  board2.setPWM(5, 0, pulseWidth(170)); //
  board2.setPWM(6, 0, pulseWidth(170)); //

  board2.setPWM(9, 0, pulseWidth(170)); //
  board2.setPWM(10, 0, pulseWidth(170)); //
  delay (200);
  //2d
  board2.setPWM(0, 0, pulseWidth(75)); //
  board2.setPWM(4, 0, pulseWidth(75)); //
  board2.setPWM(8, 0, pulseWidth(75)); //
  delay (200);

}

void belokkanan () {
  // board 1  1a
  board1.setPWM(1, 0, pulseWidth(180));
  board1.setPWM(2, 0, pulseWidth(130)); //

  board1.setPWM(5, 0, pulseWidth(180));
  board1.setPWM(6, 0, pulseWidth(130));

  board1.setPWM(9, 0, pulseWidth(180));
  board1.setPWM(10, 0, pulseWidth(130)); //+ 40


  delay (200);
  // 1b
  board1.setPWM(0, 0, pulseWidth(75)); // kondisi awal 135 -
  board1.setPWM(4, 0, pulseWidth(75)); // kondisi awal 90 +
  board1.setPWM(8, 0, pulseWidth(75)); // kondisi awal 45 -
  delay (200);

  //1c

  board1.setPWM(1, 0, pulseWidth(170)); //
  board1.setPWM(2, 0, pulseWidth(170)); //

  board1.setPWM(5, 0, pulseWidth(170)); //
  board1.setPWM(6, 0, pulseWidth(170)); //

  board1.setPWM(9, 0, pulseWidth(170)); //
  board1.setPWM(10, 0, pulseWidth(170)); //
  delay (200);



  board1.setPWM(0, 0, pulseWidth(105)); //
  board1.setPWM(4, 0, pulseWidth(105)); //
  board1.setPWM(8, 0, pulseWidth(105)); //
  // board 2  2a
  board2.setPWM(1, 0, pulseWidth(180)); //
  board2.setPWM(2, 0, pulseWidth(130)); //

  board2.setPWM(5, 0, pulseWidth(180)); //
  board2.setPWM(6, 0, pulseWidth(130)); //

  board2.setPWM(9, 0, pulseWidth(180)); //
  board2.setPWM(10, 0, pulseWidth(130)); //
  delay (200);


  //2b
  board2.setPWM(0, 0, pulseWidth(75)); //   +
  board2.setPWM(4, 0, pulseWidth(75)); //   -
  board2.setPWM(8, 0, pulseWidth(75)); //  +
  delay (200);
  //2c
  board2.setPWM(1, 0, pulseWidth(170)); //
  board2.setPWM(2, 0, pulseWidth(170)); //

  board2.setPWM(5, 0, pulseWidth(170)); //
  board2.setPWM(6, 0, pulseWidth(170)); //

  board2.setPWM(9, 0, pulseWidth(170)); //
  board2.setPWM(10, 0, pulseWidth(170)); //
  delay (200);
  //2d
  board2.setPWM(0, 0, pulseWidth(105)); //
  board2.setPWM(4, 0, pulseWidth(105)); //
  board2.setPWM(8, 0, pulseWidth(105)); //
  delay (200);
}



void mundur () {
  // board 1  1a
  board1.setPWM(1, 0, pulseWidth(180));
  board1.setPWM(2, 0, pulseWidth(130)); //

  board1.setPWM(5, 0, pulseWidth(180));
  board1.setPWM(6, 0, pulseWidth(130));

  board1.setPWM(9, 0, pulseWidth(180));
  board1.setPWM(10, 0, pulseWidth(130)); //+ 40


  delay (200);
  // 1b
  board1.setPWM(0, 0, pulseWidth(105)); // kondisi awal 135 -
  board1.setPWM(4, 0, pulseWidth(75)); // kondisi awal 90 +
  board1.setPWM(8, 0, pulseWidth(105)); // kondisi awal 45 -
  delay (200);

  //1c

  board1.setPWM(1, 0, pulseWidth(170)); //
  board1.setPWM(2, 0, pulseWidth(170)); //

  board1.setPWM(5, 0, pulseWidth(170)); //
  board1.setPWM(6, 0, pulseWidth(170)); //

  board1.setPWM(9, 0, pulseWidth(170)); //
  board1.setPWM(10, 0, pulseWidth(170)); //
  delay (200);



  board1.setPWM(0, 0, pulseWidth(75)); //
  board1.setPWM(4, 0, pulseWidth(105)); //
  board1.setPWM(8, 0, pulseWidth(75)); //
  // board 2  2a
  board2.setPWM(1, 0, pulseWidth(180)); //
  board2.setPWM(2, 0, pulseWidth(130)); //

  board2.setPWM(5, 0, pulseWidth(180)); //
  board2.setPWM(6, 0, pulseWidth(130)); //

  board2.setPWM(9, 0, pulseWidth(180)); //
  board2.setPWM(10, 0, pulseWidth(130)); //
  delay (200);


  //2b
  board2.setPWM(0, 0, pulseWidth(75)); //   +
  board2.setPWM(4, 0, pulseWidth(105)); //   -
  board2.setPWM(8, 0, pulseWidth(75)); //  +
  delay (200);
  //2c
  board2.setPWM(1, 0, pulseWidth(170)); //
  board2.setPWM(2, 0, pulseWidth(170)); //

  board2.setPWM(5, 0, pulseWidth(170)); //
  board2.setPWM(6, 0, pulseWidth(170)); //

  board2.setPWM(9, 0, pulseWidth(170)); //
  board2.setPWM(10, 0, pulseWidth(170)); //
  delay (200);
  //2d
  board2.setPWM(0, 0, pulseWidth(105)); //
  board2.setPWM(4, 0, pulseWidth(75)); //
  board2.setPWM(8, 0, pulseWidth(105)); //
  delay (200);

}


void maju () {

  // board 1  1a
  board1.setPWM(1, 0, pulseWidth(180));
  board1.setPWM(2, 0, pulseWidth(150)); //

  board1.setPWM(5, 0, pulseWidth(180));
  board1.setPWM(6, 0, pulseWidth(150));

  board1.setPWM(9, 0, pulseWidth(180));
  board1.setPWM(10, 0, pulseWidth(150));


  delay (200);
  // 1b
  board1.setPWM(0, 0, pulseWidth(76)); // kondisi awal 135 -
  board1.setPWM(4, 0, pulseWidth(105)); // kondisi awal 90 +
  board1.setPWM(8, 0, pulseWidth(73)); // kondisi awal 45 -
  delay (200);

  //1c
  board1.setPWM(1, 0, pulseWidth(160)); //
  board1.setPWM(2, 0, pulseWidth(160)); //

  board1.setPWM(5, 0, pulseWidth(160)); //
  board1.setPWM(6, 0, pulseWidth(160)); //

  board1.setPWM(9, 0, pulseWidth(160)); //
  board1.setPWM(10, 0, pulseWidth(160)); //
  delay (200);



  board1.setPWM(0, 0, pulseWidth(120)); //
  board1.setPWM(4, 0, pulseWidth(75)); //
  board1.setPWM(8, 0, pulseWidth(113)); //
  delay  (200);

  // board 2  2a
  board2.setPWM(1, 0, pulseWidth(180)); //
  board2.setPWM(2, 0, pulseWidth(150)); //

  board2.setPWM(5, 0, pulseWidth(180)); //
  board2.setPWM(6, 0, pulseWidth(150)); //

  board2.setPWM(9, 0, pulseWidth(180)); //
  board2.setPWM(10, 0, pulseWidth(150)); //
  delay (200);


  //2b
  board2.setPWM(0, 0, pulseWidth(113)); //   +
  board2.setPWM(4, 0, pulseWidth(75)); //   -
  board2.setPWM(8, 0, pulseWidth(105)); //  +
  delay (200);
  //2c
  board2.setPWM(1, 0, pulseWidth(170)); //
  board2.setPWM(2, 0, pulseWidth(170)); //

  board2.setPWM(5, 0, pulseWidth(170)); //
  board2.setPWM(6, 0, pulseWidth(170)); //

  board2.setPWM(9, 0, pulseWidth(170)); //
  board2.setPWM(10, 0, pulseWidth(170)); //
  delay (200);
  //2d
  board2.setPWM(0, 0, pulseWidth(75)); //
  board2.setPWM(4, 0, pulseWidth(105)); //
  board2.setPWM(8, 0, pulseWidth(75)); //
  delay (200);

}

int pulseWidth(int angle)
{
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  Serial.println (analog_value);
  return analog_value;
}
