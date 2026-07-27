void setup(){
  pinMode(2, OUTPUT); // Asignamos el pin 2 del Arduino como salida.
  pinMode(5, OUTPUT); // Asignamos el pin 5 del Arduino como salida.
  pinMode(4, OUTPUT); // Asignamos el pin 4 del Arduino como salida.
  pinMode(6, OUTPUT); // Asignamos el pin 6 del Arduino como salida.
}

void loop(){
  digitalWrite(2,HIGH); // Asigna el Pin 2 a nivel alto (5V).
  analogWrite(5,50); // Asigna el Pin 5 con modulación de ancho de pulso PWM.
  digitalWrite(4,LOW); // Asigna el Pin 4 a nivel bajo (0V).
  analogWrite(6,50); // Asigna el Pin 6 con modulación de ancho de pulso PWM.
  delay(2000); // Tiempo de espera a 2 segundos.
  
  digitalWrite(2,LOW);
  analogWrite(5,50);
  digitalWrite(4,HIGH);
  analogWrite(6,50);
  delay(2000);

  digitalWrite(2,LOW);
  analogWrite(5,50);
  digitalWrite(4,HIGH);
  analogWrite(6,50);
  delay(2000);
  
  digitalWrite(2,HIGH);
  analogWrite(5,50);
  digitalWrite(4,HIGH);
  analogWrite(6,50);
  delay(2000);
}
