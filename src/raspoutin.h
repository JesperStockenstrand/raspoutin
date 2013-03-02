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

typedef struct { 
     char *bus_name;
     int address;
     int device;
     int connected;
     char data[1];
} i2c_device;

void device_setup(i2c_device *i2cdev); 
void device_read(i2c_device *i2cdev);
void device_write(i2c_device *i2cdev);                   
