
//June 13 2012
//This program is given to you without any warranty.
//The author disclaims copyright to this source code.

//based on MAG3110FCR1.pdf Document Number: MAG3110 Rev 7, 10/2011

#define MAG3110_I2C_ADDRESS	0x0e

#define MAG3110_DR_STATUS	0x00

#define MAG3110_OUT_X_MSB	0x01
#define MAG3110_OUT_X_LSB	0x02
#define MAG3110_OUT_Y_MSB	0x03
#define MAG3110_OUT_Y_LSB	0x04
#define MAG3110_OUT_Z_MSB	0x05
#define MAG3110_OUT_Z_LSB	0x06

#define MAG3110_WHO_AM_I	0x07
#define MAG3110_SYSMOD		0x08

#define MAG3110_OFF_X_MSB	0x09
#define MAG3110_OFF_X_LSB	0x0a
#define MAG3110_OFF_Y_MSB	0x0b
#define MAG3110_OFF_Y_LSB	0x0c
#define MAG3110_OFF_Z_MSB	0x0d
#define MAG3110_OFF_Z_LSB	0x0e

#define MAG3110_DIE_TEMP	0x0f

#define MAG3110_CTRL_REG1	0x10
#define MAG3110_CTRL_REG2	0x11

//DR_STATUS
#define MAG3110_ZYXOW	7
#define MAG3110_ZOW	6
#define MAG3110_YOW	5
#define MAG3110_XOW	4
#define MAG3110_ZYXDR	3
#define MAG3110_ZDR	2
#define MAG3110_YDR	1
#define MAG3110_XDR	0

//WHO_AM_I
#define MAG3110_WHO_AM_I_VALUE	0xc4

//SYSMOD
#define MAG3110_SYSMOD1		1
#define MAG3110_SYSMOD0		0

//CTRL_REG1
#define MAG3110_DR2	7
#define MAG3110_DR1	6
#define MAG3110_DR0	5
#define MAG3110_OS1	4
#define MAG3110_OS0	3
#define MAG3110_FR	2
#define MAG3110_TM	1
#define MAG3110_AC	0

//CTRL_REG2
#define MAG3110_AUTO_MRST_EN	7
#define MAG3110_RAW		5
#define MAG3110_Mag_RST		4


