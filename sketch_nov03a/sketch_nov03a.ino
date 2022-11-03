#include <DHTesp.h>
#include <dhtnew.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>

#define DHTPIN 12
#define DHTTYPE DHT11

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
DHT dht (DHTPIN, DHTTYPE);

byte grau[8] ={ B00001100,            
                B00010010,              
                B00010010,              
                B00001100,            
                B00000000,              
                B00000000,            
                B00000000,            
                B00000000,};    

void setup() {

 lcd.begin(16,2);  
 lcd.clear();                                              
 lcd.createChar(0, grau);              
 dht.begin();
 pinMode(12, OUTPUT);
 Serial.begin(9600);
}

void loop() {
  
  float t = dht.readTemperature();      
  float h = dht.readHumidity();        
  lcd.setCursor(0,0);                  
  lcd.print("Temp: ");                  
  lcd.print(" ");                      
  lcd.setCursor(7,0);                  
  lcd.print(t,1);                      
  lcd.setCursor(12,0);                
  lcd.write((byte)0);                  
  lcd.print("C");                      
 
  lcd.setCursor(0,1);                    
  lcd.print("Umid: ");                  
  lcd.print(" ");                        
  lcd.setCursor(7,1);                    
  lcd.print(h,1);                        
  lcd.setCursor(12,1);                    
  lcd.print("%");     

  Serial.begin(9600);
  char c = Serial.read();
 
  if (c == 'b'){
    digitalWrite(12, LOW);
    Serial.println("ERRO");
  }
  else{
    digitalWrite(12, HIGH);
    Serial.print("Temp: ");
    Serial.println(t);
    Serial.print("Umid: ");
    Serial.println(h);
  }
                
  delay(60000);
  }
