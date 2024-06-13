//Libraries
#include <DHT.h>
//I2C LCD:
//#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display
  
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
   // lcd.init(); //initialize the lcd
   // lcd.backlight(); //open the backlight
     pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
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
        
// set the cursor to (0,0):
// print from 0 to 9:

  //  lcd.setCursor(0, 8);
  //  lcd.println("Now Temperature ");
    
   // lcd.setCursor(9, 1);
   // lcd.print("T:");
   // lcd.print(t);
//lcd.print("C");

  //  lcd.setCursor(8, 0);
   // lcd.println("2020 ");
     
   // lcd.setCursor(9, 0);
   // lcd.print("H:");
   // lcd.print(h);
   // lcd.print("%");


     int value = analogRead(A0);
  Serial.println(value);
  if (h < 65) {
    digitalWrite(2, LOW);
   // lcd.setCursor(0, 0);
    Serial.print("fan: Off ");
   //  lcd.setCursor(0, 6);
   // lcd.print(value);
   delay(1000);
  } else {
    digitalWrite(2, HIGH);
   // lcd.setCursor(0, 0);
    Serial.print("fan:On");
    // lcd.setCursor(0, 6);
    //lcd.print(value);
  delay(1000); //Delay 1 sec.
  }
  Serial.print("\n");
}