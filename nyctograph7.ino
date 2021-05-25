/*  Nyctograph
 *  Roni Bandini
 *  May 2021
 */

// LCD SDA, SCL A4 A5
// D12 Yellow printer D11 Green printer
// D5, D6, D7 to Rotary Encodejr
// D8 y D9 Leds

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"

#include "letters.h"

#define TX_PIN 12 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 11 // Arduino receive   GREEN WIRE   labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);     // Pass addr to printer constructor

LiquidCrystal_I2C lcd(0x3F,16,2);  

#define outputA 6
#define outputB 7
#define buttonA 5
#define ledA 8
#define ledB 9

int counter = 0; 
int index=0;
int aState;
int aLastState; 
int alphaPrint=0; 

static char letters[27] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char phrase[16]="";

void message(String myString)
{
        lcd.clear();
        lcd.print("Nyctograph");
        lcd.setCursor(0, 1);
        lcd.print(myString);
  }

 void setup() { 
  
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   pinMode(buttonA,INPUT_PULLUP);

   pinMode (ledA,OUTPUT);
   pinMode (ledB,OUTPUT);

   digitalWrite(ledB, HIGH);
   
   Serial.begin (9600);
   Serial.print("Started");

   mySerial.begin(19200);
   printer.begin();  
   
   lcd.init();
   lcd.backlight();
   lcd.print("Nyctograph 1.0");
   lcd.setCursor(0, 1);
   lcd.print("Roni Bandini");
   delay(2000); 
   
   digitalWrite(ledB, LOW);
     
  lcd.clear();

// debug printing
if (alphaPrint==1){
  
  counter=1;

  digitalWrite(ledB, HIGH);
  
  while (counter<25){
   
   lcd.clear();
   lcd.print(counter);
   lcd.setCursor(0, 1);
   lcd.print("Nyctograph");
   delay(2000); 

   
   
      if (counter==1){
        printer.printBitmap(104, 104, a);  
        printer.println(F("")); 
      }

      if (counter==2){
        printer.printBitmap(104, 104, b);  
        printer.println(F("")); 
      }

      if (counter==3){
        printer.printBitmap(104, 104, c);  
        printer.println(F("")); 
      }

      if (counter==4){
        printer.printBitmap(104, 104, d);  
        printer.println(F("")); 
      }

      if (counter==5){
        printer.printBitmap(104, 104, e);  
        printer.println(F("")); 
      }

      if (counter==6){
        printer.printBitmap(104, 104, f);  
        printer.println(F("")); 
      }

     if (counter==7){
        printer.printBitmap(104, 104, g);  
        printer.println(F("")); 
      }

      if (counter==8){
        printer.printBitmap(104, 104, h);  
        printer.println(F("")); 
      }

      if (counter==9){
        printer.printBitmap(104, 104, i);  
        printer.println(F("")); 
      }

      if (counter==10){
        printer.printBitmap(104, 104, j);  
        printer.println(F("")); 
      }

       if (counter==11){
        printer.printBitmap(104, 104, k);  
        printer.println(F("")); 
      }

      if (counter==12){
        printer.printBitmap(104, 104, l);  
        printer.println(F("")); 
      }

       if (counter==13){
        printer.printBitmap(104, 104, m);  
        printer.println(F("")); 
      }

     if (counter==14){
        printer.printBitmap(104, 104, n);  
        printer.println(F("")); 
      }

     if (counter==15){
        printer.printBitmap(104, 104, o);  
        printer.println(F("")); 
      }

    if (counter==16){
        printer.printBitmap(104, 104, p);  
        printer.println(F("")); 
      }


   if (counter==17){
        printer.printBitmap(104, 104, q);  
        printer.println(F("")); 
      }

   if (counter==18){
        printer.printBitmap(104, 104, r);  
        printer.println(F("")); 
      }

    if (counter==19){
        printer.printBitmap(104, 104, s);  
        printer.println(F("")); 
      }

          if (counter==20){
        printer.printBitmap(104, 104, u);  
        printer.println(F("")); 
      }

      if (counter==21){
        printer.printBitmap(104, 104, v);  
        printer.println(F("")); 
      }

      if (counter==22){
        printer.printBitmap(104, 104, w);  
        printer.println(F("")); 
      }


      if (counter==23){
        printer.printBitmap(104, 104, x);  
        printer.println(F("")); 
      }

     if (counter==24){
        printer.printBitmap(104, 104, y);  
        printer.println(F("")); 
      }

        counter++;
    } // while

    digitalWrite(ledB, LOW);

  } // alpha print

   // init state
   aLastState = digitalRead(outputA);   
 } 

 void loop() { 
  
   aState = digitalRead(outputA);  
   
   if (aState != aLastState){     

     // iterate letters array
     if (digitalRead(outputB) != aState) { 
       counter ++;
       if (counter>26) counter=26;
     } else {
       counter --;
       if (counter<0) counter=0;
     }
     
   } 
   aLastState = aState;

        
     // print letter on screen
     lcd.setCursor(0, 0); 
     lcd.print("Enter a word");
     lcd.setCursor(index, 1);    
      
     if (counter==0){
        lcd.print("*");
        Serial.print("-");    
        }
      else {
        lcd.print(letters[counter]);}

   int buttonValue = digitalRead(buttonA);

   Serial.println(counter);

   if (buttonValue==LOW){

      // assign letter to phrase array
      phrase[index]=counter;
      
      index=index+1;     
      counter=0; 
      
      if (index>15){

        // end of line, print        
        
        

       int myIndex=0;

       
     while (myIndex<16){

      digitalWrite(ledA, HIGH);
      
      if (phrase[myIndex]==1){

          printer.printBitmap(104, 104, a);  
          printer.println(F("")); 

          message("Printing A");
        
      }

      if (phrase[myIndex]==2){
        printer.printBitmap(104, 104, b);  
        printer.println(F("")); 

        message("Printing B");
        
      }

      if (phrase[myIndex]==3){
        printer.printBitmap(104, 104, c);  
        printer.println(F("")); 

        message("Printing C");
      }

      if (phrase[myIndex]==4){
        printer.printBitmap(104, 104, d);  
        printer.println(F("")); 

        message("Printing D");
      }

      if (phrase[myIndex]==5){
        printer.printBitmap(104, 104, e);  
        printer.println(F("")); 

        message("Printing E");
      }

      if (phrase[myIndex]==6){
        printer.printBitmap(104, 104, f);  
        printer.println(F("")); 

        message("Printing F");
      }

     if (phrase[myIndex]==7){
        printer.printBitmap(104, 104, g);  
        printer.println(F("")); 

        message("Printing G");
      }

      if (phrase[myIndex]==8){
        printer.printBitmap(104, 104, h);  
        printer.println(F("")); 

        message("Printing H");
      }

      if (phrase[myIndex]==9){
        printer.printBitmap(104, 104, i);  
        printer.println(F("")); 
        message("Printing I");
      }

      if (phrase[myIndex]==10){
        printer.printBitmap(104, 104, j);  
        printer.println(F("")); 
        message("Printing J");
      }

       if (phrase[myIndex]==11){
        printer.printBitmap(104, 104, k);  
        printer.println(F("")); 
        message("Printing K");
      }

      if (phrase[myIndex]==12){
        printer.printBitmap(104, 104, l);  
        printer.println(F("")); 
        message("Printing L");
      }

       if (phrase[myIndex]==13){
        printer.printBitmap(104, 104, m);  
        printer.println(F("")); 
        message("Printing M");
      }

     if (phrase[myIndex]==14){
        printer.printBitmap(104, 104, n);  
        printer.println(F("")); 
        message("Printing N");
      }

     if (phrase[myIndex]==15){
        printer.printBitmap(104, 104, o);  
        printer.println(F("")); 
        message("Printing O");
      }

    if (phrase[myIndex]==16){
        printer.printBitmap(104, 104, p);  
        printer.println(F("")); 
        message("Printing P");
      }


   if (phrase[myIndex]==17){
        printer.printBitmap(104, 104, q);  
        printer.println(F("")); 
        message("Printing Q");
      }

   if (phrase[myIndex]==18){
        printer.printBitmap(104, 104, r);  
        printer.println(F("")); 
        message("Printing R");
      }

    if (phrase[myIndex]==17){
        printer.printBitmap(104, 104, s);  
        printer.println(F("")); 
        message("Printing S");
      }

    if (phrase[myIndex]==18){
        printer.printBitmap(104, 104, t);  
        printer.println(F("")); 
        message("Printing T");
      }

      if (phrase[myIndex]==19){
        printer.printBitmap(104, 104, u);  
        printer.println(F(""));
        message("Printing U");
      }

      if (phrase[myIndex]==20){
        printer.printBitmap(104, 104, v);  
        printer.println(F("")); 
        message("Printing V");
      }

      if (phrase[myIndex]==21){
        printer.printBitmap(104, 104, w);  
        printer.println(F("")); 
        message("Printing W");
      }


      if (phrase[myIndex]==22){
        printer.printBitmap(104, 104, x);  
        printer.println(F("")); 
        message("Printing X");
      }

     if (phrase[myIndex]==23){
        printer.printBitmap(104, 104, y);  
        printer.println(F(""));
        message("Printing Y"); 
      }

     if (phrase[myIndex]==24){
        printer.printBitmap(104, 104, z);  
        printer.println(F("")); 
        message("Printing Z");
      }

      digitalWrite(ledA, LOW);
      delay(500);
      
      myIndex++;
      } // while

      

      lcd.clear();
      index=0;

      lcd.clear();
      lcd.print("Enter a word");

      
    } // end of line
        
      delay(500);
    }
   
 }
