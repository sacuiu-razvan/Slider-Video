#include <SoftwareSerial.h>

#include <Servo.h> 
Servo rotservo;
Servo tr_servo;

#define BDRpin 3 // buton-dr pin 3
#define BSTpin 4 // buton-st pin 4

int bluetoothTx = 10; // tr bl pe 10 
int bluetoothRx = 11; // rec pe 11
int BDR, BST; 

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  rotservo.attach(9);
  tr_servo.attach(8);  
  Serial.begin(9600);
  pinMode(BDRpin,INPUT_PULLUP);// setare DRpin
  pinMode(BSTpin,INPUT_PULLUP);// setare STpin   

  bluetooth.begin(9600);
}

void loop()
{
  
  BDR = digitalRead(BDRpin);// citire status buton - dreapta (BDR)
  BST = digitalRead(BSTpin);// citire status buton - stanga (BST)
   if(BDR ==LOW)
    {
      tr_servo.write(87);
   }
    if(BST ==LOW)
    {
      tr_servo.write(96);
    }
  if(bluetooth.available()> 0 ) 
  {
    int servopos = bluetooth.read(); 
    Serial.println(servopos); 
   // rotservo.write(servopos);
   // tr_servo.write(87);

    if(servopos<80)
    {
      rotservo.write(servopos);
    }
  //  int servotr = bluetooth.read();
   
   // if (servotr > 80)
  //  {
   //   tr_servo.write(87);
        
      
      
  //  }

  else if (servopos == 87)
    {
           if(BDR ==LOW)
        {
             tr_servo.write(87);
        }
            if(BST ==LOW)
        {
              tr_servo.write(96);
    }
      
      
    }

    else if (servopos == 84)
    {
           if(BDR ==LOW)
        {
             tr_servo.write(84);
        }
            if(BST ==LOW)
        {
              tr_servo.write(98);
    }
      
      
    }

    else if (servopos == 80)
    {
           if(BDR ==LOW)
        {
             tr_servo.write(70);
        }
            if(BST ==LOW)
        {
              tr_servo.write(120);
    }
      
      
    }

    else if(servopos == 90)
    {
       tr_servo.write(90);
    }
   
    
   // tr_servo.write(servopos); 
  }
  delay(60);


}
