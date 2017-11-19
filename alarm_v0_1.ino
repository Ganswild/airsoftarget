const int buttonPin = 8; 
int buttonState = 0; 
int alarm = 0; // счетчик попаданий
int in_data; // режим игры 1, 5, 10, 20, 40, 80, 100
int mode; // колличество попаданий

void setup() {  
Serial.begin (9600); 
pinMode(buttonPin, INPUT); 

for ( int y = 2; y < 8; y++) //включаем светодиоды 
{
  pinMode(y, OUTPUT);
  digitalWrite(y, HIGH);
}
  Serial.println("Выберете режим: ");
  Serial.println("1 - 1 перезапуск 10 сек");
  Serial.println("2 - 5 перезапуск 20 сек");
  Serial.println("3 - 10 перезапуск 30 сек");
  Serial.println("4 - 20 перезапуск 40 сек");
  Serial.println("5 - 40 перезапуск 50 сек");
  Serial.println("6 - 80 перезапуск 60 сек");
  Serial.println("7 - 100 перезапуск 70 сек");
} 

void loop() { 
buttonState = digitalRead(buttonPin); 
if (Serial.available() > 0) 
{ 
  in_data = Serial.read()- '0'; 
  Serial.println(in_data);
   
switch (in_data) { 
  case 1: Serial.println("Выбран режим на 1 попадание!");  Serial.print(" Удачи в бою =)"); in_data = 1; mode = 1;  break; 
  case 2: Serial.println("Выбран режим на 5 попаданий!");  Serial.print(" Удачи в бою =)"); in_data = 1; mode = 5;  break; 
  case 3: Serial.println("Выбран режим на 10 попаданий!"); Serial.print(" Удачи в бою =)"); in_data = 1; mode = 10; break; 
  case 4: Serial.println("Выбран режим на 20 попаданий!"); Serial.print(" Удачи в бою =)"); in_data = 1; mode = 20; break; 
  case 5: Serial.println("Выбран режим на 40 попаданий!"); Serial.print(" Удачи в бою =)"); in_data = 1; mode = 40; break; 
  case 6: Serial.println("Выбран режим на 80 попаданий!"); Serial.print(" Удачи в бою =)"); in_data = 1; mode = 80; break; 
  case 7: Serial.println("Выбран режим на 100 попаданий! Ололо, бесмертный пони =)"); Serial.println("Удачи в бою =)"); in_data = 1; mode = 100; break; 
  } 
} 

if (buttonState == HIGH && in_data == 1)
{ 
  Serial.print("Попадание: "); Serial.println(alarm); alarm++; delay(200); 
if (alarm == mode) {
  Serial.println("Вы мертвы =( "); 
  alarm = 0;
  } 
for (int i = 1; buttonState == HIGH; i--)
{
  //Serial.print(i);
  if (i == 0) break;
  digitalWrite(7, LOW);
  delay(200);
  digitalWrite(7, HIGH);
  }
} 
}

