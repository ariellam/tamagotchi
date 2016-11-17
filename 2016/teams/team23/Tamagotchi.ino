#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>
#include <stdlib.h>
#include <Wire.h>

int xpos = 0;
int ypos = 10;
char frog[] = {
  0x00, 0x60, 0x90, 0x8C, 0x82, 0x8A, 0x82, 0x84, 0x84, 0x82, 0x8A, 0x42, 0x0C, 0x10, 0xE0, 0x00,
  0x00, 0x00, 0x01, 0x1E, 0x20, 0x40, 0x80, 0x40, 0x40, 0x4C, 0x90, 0x4C, 0x20, 0x1E, 0x01, 0x00,
  0x00, 0x00
};

char fish [] = {
  0x00, 0x00, 0x80, 0x40, 0x60, 0x50, 0x48, 0x58, 0x8C, 0x0A, 0x4A, 0x1A, 0xEC, 0x10, 0x20, 0x40,
  0x20, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x03, 0x05, 0x05, 0x0D, 0xD5, 0xF4, 0x33, 0x10, 0x10, 0x7C,
  0xFB, 0xD0, 0x08, 0x04, 0x09, 0x0E, 0x00, 0x00, 0x58, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01
};

struct stats {
  int hunger;
  int health;
  int happiness;
  int hygiene;
};

void WireInit();
void GameInit() {
  OrbitOledInit();
  OrbitOledClear();
  OrbitOledClearBuffer();
  OrbitOledSetFillPattern(OrbitOledGetStdPattern(iptnSolid));
  OrbitOledSetDrawMode(modOledSet);
  //  OrbitOledSetDrawColor('p');
}

int count = 3;

static void printHello() {
  count++;
  OrbitOledMoveTo(count, 24);
  OrbitOledDrawString("Hello");
  if (count == 128) {
    count = 0;
  }

}
int xdirect = 0;
int ydirect = 0;
int jump = 0;

static void printFrog() {

  if (xpos == 128 - 16) {
    xdirect = 1;
  }
  if (xpos == 0) {
    xdirect = 0;
  }
  if (ypos == 10) {
    ydirect = 1;
  }
  if (ypos == 5) {
    ydirect = 0;
  }


  if((xpos/10)%2 == 0){
    if (ypos > 5 && ydirect == 1) {
      ypos--;
    } else if (ypos < 10 && ydirect == 0) {
      ypos++;
    }
  }else if((xpos/10)%2 == 1){
    ypos == 10;
  }

  if (xpos < 128 - 16 && xdirect == 0) {
    OrbitOledMoveTo(xpos++, ypos);
  }

  else {
    if (xpos > 0 && xdirect == 1) {
      OrbitOledMoveTo(xpos--, ypos);
    }
  }
  OrbitOledPutBmp(16, 17, frog);
  //jump++;
}

static void printFish() {
  OrbitOledMoveTo(24, 0);
  OrbitOledPutBmp(20, 19, fish);
}

void setup() {
  WireInit();
  GameInit();
  Serial.begin(9600);
  delay(100);



}

void loop() {
  printFrog();

  OrbitOledUpdate();
  //  printFish();
  // put your main code here, to run repeatedly:
  OrbitOledUpdate();
  delay(50);
  //  OrbitOledClear();
  Serial.print(ypos);
  Serial.print("\n");
  //Serial.print(jump);
  Serial.print("\n");
}
