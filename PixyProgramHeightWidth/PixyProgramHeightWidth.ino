#include <SPI.h>  
#include <Pixy.h>

#define X_CENTER    160L
#define Y_CENTER    100L
#define RCS_MIN_POS     0L
#define RCS_MAX_POS     1000L
#define RCS_CENTER_POS	((RCS_MAX_POS-RCS_MIN_POS)/2)

Pixy pixy;

void setup()
{
  Serial.begin(115200);
  pixy.init();
}

void loop()
{
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32];
  int32_t panError, tiltError;
  
  blocks = pixy.getBlocks();
  
  if (blocks)
  {
    panError = X_CENTER-pixy.blocks[0].x;
    tiltError = pixy.blocks[0].y-Y_CENTER;
    i++;
    
    // do this (print) every 50 frames because printing every
    // frame would bog down the Arduino
    if (i%50==0)
   
    Serial.print("b");
    Serial.print(panError);
    Serial.print(",");
    Serial.print(tiltError);
    pixy.blocks[j].print();
    Serial.println("!");
  }
  
}

