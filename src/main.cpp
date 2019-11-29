#include <Arduino.h>
#include <microBox.h>
#include <joUtils.h>
#include "../include/settings.h" // #define BAUD 9600
char historyBuf[100];
char hostname[] = "ioBash";

PARAM_ENTRY Params[]=
{
  {"hostname", hostname, PARTYPE_STRING | PARTYPE_RW, sizeof(hostname), NULL, NULL, 0}, 
  {NULL, NULL}
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUD); //115200);
  
  microbox.begin(&Params[0], hostname, true, historyBuf, 100);
  joutils.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  microbox.cmdParser();
}