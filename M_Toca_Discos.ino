int pin2=9;    //Entrada 2 del L293D M1
int pin7=10;   //Entrada 7 del L293D M1
int pin10=6;   //Entrada 10 del L293D M2
int pin15=11;  //Entrada 15 del L293D M2
int Y=A0;      //Entrada analógica potenciómetro
int valorY;    //Variable que recoge el valor del Eje 
int pwm1;      //Variable del PWM 1 M1
#include <Wire.h>    // SDA pin A4 SDL pin A5             
#include <LiquidCrystal_I2C.h>    
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup()
{
  Serial.begin(9600);
  pinMode(pin2,OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin10,OUTPUT);
  pinMode(pin15, OUTPUT);
  lcd.begin(16,2);// Indicamos medidas de LCD   
  lcd.setCursor(0,0); 
  lcd.print("Velocidad Giro");
   
}

void loop()
{
  valorY=analogRead(Y);
  Serial.println("Entrada analogica");
  Serial.println(valorY);
  delay (50);
  Serial.println("Salida digital");
  Serial.println(pwm1);
  delay (50);
  pwm1 = map(valorY, 0, 1019, 50, 80); //mapeamos pasando de la entrada analogica a los valores de la salida, Regulamos los pulsos para el motor DC
  analogWrite(pin2,pwm1);//Sacamos el PWM de las dos salidas usando analogWrite(pin,valor)
  lcd.setCursor(0,1); 
  lcd.print(pwm1);
}


