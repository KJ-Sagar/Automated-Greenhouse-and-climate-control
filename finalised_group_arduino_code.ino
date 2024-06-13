//* How to use the DHT-11 sensor with Arduino
//   Temperature and humidity sensor and
//   I2C LCD1602
 //  SDA --> A4
 //  SCL --> A5

//Libraries
#include <DHT.h>
//I2C LCD:
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display
  
//Constants
#define DHTPIN 7     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

//Variables
//int chk;
int h;  //Stores humidity value
int t; //Stores temperature value

void setup()
{
    Serial.begin(9600);
   // Serial.println("Temperature and Humidity Sensor Test");
    dht.begin();
    lcd.init(); //initialize the lcd
    lcd.backlight(); //open the backlight
     pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
   pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
}

void loop()
{
    //Read data and store it to variables h (humidity) and t (temperature)
    // Reading temperature or humidity takes about 250 milliseconds!
    h = dht.readHumidity();
    t = dht.readTemperature();
    
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(h);
   Serial.print(" %, Temp: ");
    Serial.print(t);
    Serial.println(" ° Celsius");
        

    //to print live temperature on LCD
    lcd.setCursor(9, 1);
    lcd.print("T:");
    lcd.print(t);
    lcd.print("C");
    
    //to print live humidity anf fan status on LCD  
    lcd.setCursor(9, 0);
    lcd.print("H:");
    lcd.print(h);
    lcd.print("%");
    if (h < 60) {
    digitalWrite(3, LOW);
    lcd.setCursor(0, 1);
    lcd.print("fan:OFF");
    } 
    else {
    digitalWrite(3, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("fan:ON ");
     //lcd.setCursor(0, 6);
    //lcd.print(value);
  }

    int SensorValue = analogRead(A0); //read the input on analog pin 0
    Serial.println(SensorValue); //prints the value read by sensor on the serial monitor:
    //to print live pump status on LCD 
    if (SensorValue < 750) {
      digitalWrite(4, LOW);
      Serial.print("pump:OFF");
      lcd.setCursor(0, 0);
      lcd.print("pump:OFF");
  } else {
    digitalWrite(4, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("pump:ON ");
    Serial.print("pump:ON ");
  }
  delay(1000); //Delay 1 sec.
}