
#define RST 12
#define CE 11
#define DC 10
#define DIN 9
#define CLK 8
#include "font.h";
//This function will clear the lcd
void LcdClear(){
  for(int i=0; i<504;i++) LcdWriteData(0x00);
  }


//This function will sen string to the display
void LcdWriteString (char *characters){
  while(*characters) LcdWriteCharacter(*characters++);
  }




//This funtiion will send characte to the display
void LcdWriteCharacter(char character){
   for(int i=0; i<5; i++) LcdWriteData(ASCII[character - 0x20][i]);
  LcdWriteData(0x00);
  }


void LcdWriteData(byte dat){
digitalWrite(DC, HIGH); //DC pin is low for commands
digitalWrite(CE, LOW);
shiftOut(DIN, CLK, MSBFIRST, dat); //transmit serial data
digitalWrite(CE, HIGH);
}

void LcdWriteCmd(byte cmd){
digitalWrite(DC, LOW); //DC pin is low for commands
digitalWrite(CE, LOW);
shiftOut(DIN, CLK, MSBFIRST, cmd); //transmit serial data
digitalWrite(CE, HIGH);
}

// This funtion will help to move vertically and horizontally 
void LcdXY(int x, int y){
  LcdWriteCmd(0x80 | x);  // Column.
  LcdWriteCmd(0x40 | y);  // Row.
  }

void setup()
{
pinMode(RST, OUTPUT);
pinMode(CE, OUTPUT);
pinMode(DC, OUTPUT);
pinMode(DIN, OUTPUT);
pinMode(CLK, OUTPUT);
digitalWrite(RST, LOW);
digitalWrite(RST, HIGH); LcdWriteCmd(0x21); // LCD extended commands

//These are taken from analyzing the data sheet for PCD8544 page 14
//LcdWriteCmd(0xB8); // set LCD Vop (contrast)
LcdWriteCmd(0xBF); // set LCD Vop (contrast) this changed later to make pixels more clear 
LcdWriteCmd(0x04); // set temp coefficent
LcdWriteCmd(0x14); // LCD bias mode 1:40
LcdWriteCmd(0x20); // LCD basic commands
LcdWriteCmd(0x0C); // LCD normal video


//clear LCD
//for(int i=0; i<504;i++) LcdWriteData(0x00);

//LcdWriteData(0x55);
//LcdWriteData(0xAA);

//---This 6 lines print character for my name ----
//LcdWriteCharacter(0x46);
//LcdWriteCharacter(0x41);
//LcdWriteCharacter(0x59);
//LcdWriteCharacter(0x53);
//LcdWriteCharacter(0x41);
//LcdWriteCharacter(0x4c);

//------------------------------

LcdClear();

//Print String
//LcdWriteString("Weclcom");

LcdXY(20,2);
LcdWriteString("Jence BD");
 

}

void loop()
{
//  LcdWriteData(0x55);  //biased upwards
//LcdWriteData(0xAA);    //biased downwards

//LcdWriteData(0xFE); // displays six rows (addressable location)

//----this 6 line dislay random things in loop
//LcdWriteData(0x01);
//LcdWriteData(0x03);
//LcdWriteData(0x08);
//LcdWriteData(0x20);
//LcdWriteData(0x80);
//delay(2);
//-------------
} 
