#include <ShiftOutX.h>
#include <ShiftPinNo.h>
//#include <NewTone.h>

//**********************//
//  Name    : shiftOutX, Hello World                                
//  Author  : Juan Hernandez 
//  Date    : 02 Jan 2011    
//  Modified:                                  
//  Version : 1.0                                             
//  Notes   : Code for using four 74HC595 Shift Registers           //
//          : with shiftOutX class                           
//**********************

//_latchPin connected to ST_CP of 74HC595
//_dataPin connected to DS of 74HC595
//_clockPin connected to SH_CP of 74HC595
//_bitOrder is the order in which the bits are send to the register
//values are the constants MSBFIRST for most significant bits first
//or LSBFIRST for least significant bit first, the way I see it is 
//do you want Q0 to be shPin1 or do you want Q7 to be shPin1, 
//Q0 and Q7 are pin on the 74HC595 shift register.
//number of registers is how many registers you have in series
//so if you have 2 you will shift 16 bits or 24 and 32 if you
//have 3 or 4 registers
//this is how you input the parameters to the class constructor
//shiftOutX(_latchPin, _dataPin, _clockPin, _bitOrder, _NofRegisters);
shiftOutX regOne(4, 12, 13, MSBFIRST, 3); 
#define SRCLR 10
//_bitString is the class member that holds the string of ones and zeros
//it is just a 4 byte unsigned integer and though all these members are 
//public I just use the functions to modify them but you can modify them 
//as you like.
//so to access it you would do it like this
//regOne._bitString = xx;

int valor;

const int buzzer1 = 9;
const int boton1 = 2;

void setup() {
 pinMode(boton1,INPUT_PULLUP);
  pinMode (buzzer1,OUTPUT);
 pinMode(SRCLR, OUTPUT);
 digitalWrite(SRCLR,LOW);

}


void loop() {  
digitalWrite(SRCLR,HIGH);



//patron2('r',500);
/*

 delay(100); 
 patron1('g',100);
 patron1('r',100);
 patron1('b',100);
 */


  color('r', 1);
  color('r', 2);
  color('r', 3);
  color('r', 4);
  color('r', 5);
  color('r', 6);

  delay(500);
  color('g', 1);
  color('g', 2);
  color('g', 3);
  color('g', 4);
  color('g', 5);
  color('g', 6);

  
  delay(500);
  color('b', 1);
  color('b', 2);
  color('b', 3);
  color('b', 4);
  color('b', 5);
  color('b', 6);

  delay(500);



//  regOne.pinOff(shPin1);
//  regOne.pinOn(shPin2);
//  regOne.pinOff(shPin3);
//  delay(1000);
//  
//  regOne.pinOn(shPin1);
//  regOne.pinOn(shPin3);
//  regOne.pinOn(shPin2);
//  delay(1000);
//
//  regOne.pinOff(shPin6);
//  regOne.pinOff(shPin4);
//  regOne.pinOn(shPin5);
//  delay(1000);
//
//  regOne.pinOff(shPin8);
//  regOne.pinOn(shPin9);
//  regOne.pinOff(shPin7);
//
//  regOne.pinOff(shPin12);
//  regOne.pinOn(shPin10);
//  regOne.pinOn(shPin11);
//
//  regOne.pinOff(shPin13);
//  regOne.pinOn(shPin15);
//  regOne.pinOn(shPin14);
//
//  regOne.pinOff(shPin16);
//  regOne.pinOn(shPin17);
//  regOne.pinOn(shPin18);
//
//  regOne.pinOn(shPin19);
//  regOne.pinOn(shPin20);
//  regOne.pinOn(shPin21);
//  regOne.pinOn(shPin22);
//  regOne.pinOn(shPin23);
//  regOne.pinOn(shPin24);
}

void color(char color, int numberModule){
  int i = (numberModule*3)-3;
  long arrNumber[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};
  if (color == 'b'){
    regOne.pinOff(arrNumber[i]);
    regOne.pinOn(arrNumber[i+1]);
    regOne.pinOn(arrNumber[i+2]);
    
    }
  if (color == 'r'){
    regOne.pinOn(arrNumber[i]);
    regOne.pinOff(arrNumber[i+1]);
    regOne.pinOn(arrNumber[i+2]);
    
    }
  if(color == 'g'){
    regOne.pinOn(arrNumber[i]);
    regOne.pinOn(arrNumber[i+1]);
    regOne.pinOff(arrNumber[i+2]);
    }
    
  if(color == 'a'){
    regOne.pinOn(arrNumber[i]);
    regOne.pinOn(arrNumber[i+1]);
    regOne.pinOn(arrNumber[i+2]);
    }
  if(color == 'w'){
    regOne.pinOff(arrNumber[i]);
    regOne.pinOff(arrNumber[i+1]);
    regOne.pinOff(arrNumber[i+2]);
    
    }
}

void patron2(char colorv, int velocidad){
  color(colorv,1);
  color('a',2);
  color('a',3);
  color('a',4);
  color('a',5);
  color('a',6);
  delay(velocidad);

  color(colorv,3);
  color('a',2);
  color('a',1);
  color('a',4);
  color('a',5);
  color('a',6);
  delay(velocidad);

  color(colorv,5);
  color('a',2);
  color('a',3);
  color('a',4);
  color('a',1);
  color('a',6);
  delay(velocidad);

  color(colorv,6);
  color('a',2);
  color('a',3);
  color('a',4);
  color('a',5);
  color('a',1);
  delay(velocidad);

  color(colorv,4);
  color('a',2);
  color('a',3);
  color('a',1);
  color('a',5);
  color('a',6);
  delay(velocidad);

  color(colorv,2);
  color('a',1);
  color('a',3);
  color('a',4);
  color('a',5);
  color('a',6);
  delay(velocidad);
}
void patron1(char colorv, int velocidad){
  color(colorv,1);
  color('a',2);
  color('a',3);
  color('a',4);
  color('a',5);
  color('a',6);
  delay(velocidad);

  color(colorv,2);
  color('a',1);
  color('a',3);
  color('a',4);
  color('a',5);
  color('a',6);
  delay(velocidad);

  color(colorv,3);
  color('a',1);
  color('a',2);
  color('a',4);
  color('a',5);
  color('a',6);
  delay(velocidad);

  color(colorv,4);
  color('a',1);
  color('a',2);
  color('a',3);
  color('a',5);
  color('a',6);
  delay(velocidad);

  color(colorv,5);
  color('a',2);
  color('a',3);
  color('a',4);
  color('a',1);
  color('a',6);
  delay(velocidad);

  color(colorv,6);
  color('a',2);
  color('a',3);
  color('a',4);
  color('a',5);
  color('a',1);
  delay(velocidad);
}