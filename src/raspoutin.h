/* raspoutin - Used together with schematics at http://raspify.stockenstrand.com  
 * Copyright (C) 2013 Jesper Stockenstrand
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.	
 */
 
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#define SETUP_OK 0
#define READ_OK 0
#define WRITE_OK 0
#define FAILED_TO_OPEN_THE_I2C_BUS 1
#define FAILED_TO_AQUIRE_BUS_ACCESS_AND_OR_TALK_TO_SLAVE 2
#define FAILED_TO_WRITE_TO_THE_I2C_BUS 3
#define FAILED_TO_READ_FROM_THE_I2C_BUS 4

typedef struct { 
     char *bus_name;
     int address;
     int device;
     int connected;
     char data[1];
} i2c_device;

int device_setup(i2c_device *i2cdev); 
int device_read(i2c_device *i2cdev);
int device_write(i2c_device *i2cdev);                   
