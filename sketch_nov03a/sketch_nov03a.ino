//#include <ESP8266WiFi.h>
#include <DHTesp.h>
#include <dhtnew.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <LiquidCrystal.h>        
/*#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>*/

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

/*IPAddress server_addr(54, 39, 75, 7); // O IP DO SERVIDOR DA CLEVER CLOUD
char user[] = "uxecspw3ghs2piwd";              // Usuario MySQL
char password[] = "skVArLo5KpGeA2Eu4mzL";        //   Senha MySQL
char ssid[] = "NET_5GPires";         //  Nome de rede Wifi
char pass[] = "df389688";     //            Senha Wi-Fi
char INSERT_DATA[] = "INSERT INTO buupqbuquce3aqvjqnrl.Temperatura (ID_SENSOR, Temperatura, Umidade) VALUES (%d,%s, %s)"; 
//   EXEMPLO ACIMA:  "INSERT INTO b3d3z8bggux9ngtdusfw.Temperatura (ID_SENSOR, Temperatura) VALUES (%d,%s)"; 

WiFiClient client;             
MySQL_Connection conn(&client);
MySQL_Cursor* cursor;*/

void setup() {

 lcd.begin(16,2);  
 lcd.clear();                                              
 lcd.createChar(0, grau);              
 dht.begin();
 pinMode(12, OUTPUT);
 Serial.begin(9600);
 //VerificaWiFi();
 
}

void loop() {

  //int id;
  float temp = dht.readTemperature();      
  float h = dht.readHumidity();        
  lcd.setCursor(0,0);                  
  lcd.print("Temp: ");                  
  lcd.print(" ");                      
  lcd.setCursor(7,0);                  
  lcd.print(temp,1);                      
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
  /*AguardaDados();
  Leitura(&id, &temp, &h);*/
  
  Serial.begin(9600);
  digitalWrite(12, HIGH);
  Serial.print("Temp: ");
  Serial.println(temp);
  Serial.print("Umid: ");
  Serial.println(h);
               
  delay(90000);
  /*EnviaDados(id, temp, h);
  Serial.println();*/
  
 }

/*void AguardaDados() {
  
  while (!(Serial.available() > 0)) {}
  
}

void Leitura(int *id, float *temp, float *h) {
  
  char  mensagem[20];
  byte atual, i = 0;
  atual = 255;
  
  if (Serial.available() > 0) {
    
    while (atual != 10) {
      
      if (Serial.available() > 0) {
        
        atual = Serial.read();
        //     Serial.print((char)leitura);
        mensagem[i] = (char)atual;
        i++;
        
      }
      
    }
    
    i = 0;
    *id = atoi(strtok(mensagem, "|"));
    *temp = atof(strtok(NULL, "|"));
    *h = atof(strtok(NULL, "|"));
    
  }
}

void EnviaDados(int id, float temp, float h) {
  
  char query[128];
  char temperatura[10];
  char umidade[10];
  
  VerificaWiFi();
  
  if (conn.connect(server_addr, 3306, user, password)) {
    
    delay(1000);
    MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
    // Save
    
    dtostrf(temp, 1, 1, temperatura);
    sprintf(query, INSERT_DATA, id, temperatura);
    
    dtostrf(h, 1, 1, umidade);
    sprintf(query, INSERT_DATA, id, umidade);
    // Execute the query
    
    cur_mem->execute(query);
    // Note: since there are no results, we do not need to read any data
    // Deleting the cursor also frees up memory used
    
    delete cur_mem;
    Serial.println(); Serial.println("Data recorded."); //
    
  }
  
  else
  
    Serial.println(); Serial.println("Connection failed."); //
  conn.close();
  
}

void VerificaWiFi() {
  
  if (WiFi.status() != WL_CONNECTED) {
    //Serial.println("Sem conexão"); //
    
    WiFi.disconnect();
    delay(1000);
    WiFi.begin(ssid, pass);
    // Serial.println();Serial.println("Conectando ao WiFi."); //
    
    while (WiFi.status() != WL_CONNECTED) {
      
      delay(500);
    }
    // Serial.println();Serial.println("Conectado a rede!"); //
  }
}*/
