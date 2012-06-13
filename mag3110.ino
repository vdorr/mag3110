
//June 13 2012
//This program is given to you without any warranty.
//The author disclaims copyright to this source code.

#include <Wire.h>
#include <stdint.h>
#include "MAG3110.h"

#define MAGM_ADDR  MAG3110_I2C_ADDRESS
#define MAG_ADDR MAGM_ADDR


void setup()
{
  Wire.begin();
  Serial.begin(9600);
  delay(100);
  Serial.println(mag3110_detect(MAGM_ADDR) ? "MAG3110 not found :-(" :  "MAG3110 found :-)");
  mag3110_basic_setup(MAGM_ADDR);
}

void loop()
{
  delay(500);
  int16_t x, y, z;
  uint8_t st_reg;
  int rc = mag3110_read_all(MAGM_ADDR, &x, &y, &z, &st_reg);
  Serial.print("x= ");
  Serial.print(x);
  Serial.print(", y= ");
  Serial.print(y);
  Serial.print(", z= ");
  Serial.print(z);
  Serial.println("");
}

#define MAG3110_ALL_AXES_READY ((uint8_t)((1 << MAG3110_ZDR) | (1 << MAG3110_YDR) | (1 << MAG3110_XDR)))

int mag3110_read_all(uint8_t i2c_addr, int16_t* x, int16_t* y, int16_t* z, uint8_t* st_reg_out)
{
  uint8_t st_reg;
  do
  {
    Wire.beginTransmission(i2c_addr);
    Wire.write((uint8_t)MAG3110_DR_STATUS);
    Wire.endTransmission();
    Wire.requestFrom(i2c_addr, (uint8_t)1);
    st_reg = Wire.read();
  } while (Wire.available() && ((st_reg & MAG3110_ALL_AXES_READY) != MAG3110_ALL_AXES_READY));//TODO timeout

  if ( st_reg_out != NULL )
  {
    *st_reg_out = st_reg;
  }

  Wire.beginTransmission(i2c_addr);
  Wire.write((uint8_t)MAG3110_OUT_X_MSB);
  Wire.endTransmission();
  Wire.requestFrom(i2c_addr, (uint8_t)6);

  uint8_t mem[6];
  for (int i = 0; (i < 6) && Wire.available(); i++)
  {
    mem[i^1] = Wire.read();//negate lsb to swap bytes in words
//    Serial.print("0x");
//    Serial.print(mem[i], HEX);
//    Serial.print(", ");
  }
//  Serial.println("");
  *x = ((int16_t*)mem)[0];
  *y = ((int16_t*)mem)[1];
  *z = ((int16_t*)mem)[2];
  return 0;
}

int mag3110_detect(uint8_t i2c_addr)
{
  Wire.beginTransmission(i2c_addr);
  Wire.write((uint8_t)MAG3110_WHO_AM_I);
  Wire.endTransmission();
  Wire.requestFrom((uint8_t)i2c_addr, (uint8_t)1);
  if (Wire.available())
  { 
    uint8_t hello = Wire.read();
    return hello != MAG3110_WHO_AM_I_VALUE;
  }
  return -1;
} 

int mag3110_basic_setup(uint8_t i2c_addr)
{
  Wire.beginTransmission(i2c_addr);
  Wire.write((uint8_t)MAG3110_CTRL_REG2);
  Wire.write((uint8_t)(1 << MAG3110_AUTO_MRST_EN));
  Wire.endTransmission();
  
  delay(15);//??
  
  Wire.beginTransmission(i2c_addr);
  Wire.write((uint8_t)MAG3110_CTRL_REG1);
  Wire.write((uint8_t)(1 << MAG3110_AC));
  Wire.endTransmission();
}

