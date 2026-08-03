#include <DHT.h>//Incluyo la librería del sensor DHT11
#include <Wire.h>
////////////////////////Para la pantalla LCD
#include <LiquidCrystal_I2C.h> // Debe descargar la Libreria que controla el I2C
LiquidCrystal_I2C lcd(0x27, 16, 2); //SI no va, se puede poner 0x20 para probar
//el modulo es de 16 por 2. el protocolo es 0x27. si no va, probar con 0x20
//Pines del módulo I2C
//VCC GND SON LA TENSIÓN Y LA TIERRA
//SDA VA AL A4
//SCL VA AL A5
////////////////////////Configuro pines y variables
int sensor = 4;//Pin 4 para el valor del sensor DHT11
int temp, humedad;//Configuro las variables de temperatura y humedad del DHT11
const int bomba = 8; //Pin 8 para la bomba
const int humedadsuelo = A0; //A0 para la humedad del suelo
DHT dht (sensor, DHT11);//Configuro el modelo de DHT. Es el DHT11
void setup()
{
  Serial.begin(9600);//Arrancamos el puerto serie a 9600
  dht.begin();//Arranco el sensor DHT11
//Configuramos entradas y salidas
  pinMode(humedadsuelo, INPUT);//Configuro humedadsuelo como entrada
  pinMode(bomba, OUTPUT);//Configuro bomba como salida
//Para la pantalla LCD INICIO
lcd.init(); //Inicializamos el LCD
lcd.backlight(); //Activamos la luz de fondo
lcd.clear();//blanqueamos la pantalla
lcd.setCursor(0, 0); //Posicion: columna cero fila cero
lcd.print("####");
lcd.setCursor(5, 0); //Posicion: columna cero fila cinco
lcd.print("SERCAP");
lcd.setCursor(12, 0); //Posicion: columna cero fila once
lcd.print("####");
lcd.setCursor(2, 1); //Posicion: columna cero fila uno
lcd.print("HUERTO SMART");
delay(5000);
}
void loop()
{
//Leo el valor de la humedad y lo introduzco en SensorValue en porcentaje de 0 a 100%
int SensorValue = map(analogRead(humedadsuelo), 0, 1023, 100, 0);
Serial.print("Sensor de Humedad: ");
Serial.print(SensorValue);
Serial.println("%");
//Leo y meto los valores de temperatura y humedad en las variables temp y humedad
humedad = dht.readHumidity();
temp = dht.readTemperature();
/////Puerto serie
//Imprimo por el puerto serie los valores de temperatura y humedad del DHT11
Serial.print("Temperatura: "); Serial.print(temp);
Serial.print("°C Humedad: "); Serial.print(humedad); Serial.println("%");
//Imprimo por el puerto serie el valor de la humedad del suelo
Serial.print("Humedad del suelo: "); Serial.print(SensorValue); Serial.println("%");
delay(500);
//*************************************************************
// Condiciones de riego
// Si la humedad en el suelo es igual o inferior al 50%.
// Si la temperatura es mayor o igual al 30%, entonces el sistema de riego riega.
// En caso de que no se cumpla alguno o ninguno de los 2 requisitos anteriores,
// el sistema de riego no riega
//*************************************************************
if( SensorValue <= 50 && temp >= 30) { // el valor que considero seco y Temp mayor o igual a 30 grados
// Riega durante 2 segundoS y espera a comprobar la humedad otro segundo
Serial.println("La tierra está seca, comienza el riego automático");
lcd.clear();//blanqueamos la pantalla
lcd.setCursor(0, 0); //Posicion: columna cero fila cero
lcd.print("Riego ON");
lcd.setCursor(9, 0); //Posicion: columna cero fila uno
lcd.print("HS:");
lcd.print(SensorValue);
lcd.print("%");
lcd.setCursor(0, 1); //Posicion: columna cero fila cero
lcd.print("DHT:");
lcd.print(temp);
lcd.print("C/");
lcd.print(humedad);
lcd.print("%");
digitalWrite(bomba, HIGH);
delay(2000);
digitalWrite(bomba, LOW);
delay(1000);
}
else{
// Riega durante 2 segundos y espera a comprobar la humedad otro segundo
Serial.println("La tierra está seca, comienza el riego automático");
lcd.clear();//blanqueamos la pantalla
lcd.setCursor(0, 0); //Posicion: columna cero fila cero
lcd.print("Riego OFF");
lcd.setCursor(10, 0); //Posicion: columna cero fila uno
lcd.print("HS:");
lcd.print(SensorValue);
lcd.print("%");
lcd.setCursor(0, 1); //Posicion: columna cero fila cero
lcd.print("DHT:");
lcd.print(temp);
lcd.print("C/");
lcd.print(humedad);
lcd.print("%");
digitalWrite(bomba, LOW);
delay(20);
}
}