#include <stdio.h>
#include <assert.h>
#include "batteryManagement.h"

int checkChargeRate(float chargeRate)
{
   if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  else{
    return 1;
  }
}
int checkTemperature(float temperature)
{
  if(temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return 0;
  } 
  else{
    return 1;
  }
}
int checkSoc(float soc)
{
  if(soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
    return 0;
  } 
  else{
    return 1;
  }
}
int batteryIsOk(float temperature, float soc, float chargeRate) {
   int batteryStatus=1;
   batteryStatus &= checkChargeRate(chargeRate);
   batteryStatus &= checkTemperature(temperature);
   batteryStatus &= checkSoc(soc);
  if(batteryStatus){
      return 1;
  }
  else{
    return 0;
  }
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
