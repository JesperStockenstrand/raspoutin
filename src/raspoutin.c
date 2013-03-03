/* rasp_ut_in - Used together with schematics at http://raspify.stockenstrand.com  
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

#include <stdio.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>

#include "raspoutin.h"

int device_setup(i2c_device *i2cdev) {
    if (((*i2cdev).device = open((*i2cdev).bus_name, O_RDWR)) < 0) {
        fprintf(stderr, "Failed to open the %s\n", (*i2cdev).bus_name);
        (*i2cdev).connected = 0;
        return FAILED_TO_OPEN_THE_I2C_BUS;
    }
	
    if (ioctl((*i2cdev).device, I2C_SLAVE, (*i2cdev).address) < 0) {
        fprintf(stderr, "Failed to acquire bus access and/or talk to slave.\n");
        (*i2cdev).connected = 0;
        return FAILED_TO_AQUIRE_BUS_ACCESS_AND_OR_TALK_TO_SLAVE;
    }
    (*i2cdev).connected = 1;
    return SETUP_OK;
}

int device_read(i2c_device *i2cdev) {
    if (read((*i2cdev).device, (*i2cdev).data, 1) != 1) {
        fprintf(stderr, "Error reading from i2c\n");
        (*i2cdev).connected = 0;
        return FAILED_TO_READ_FROM_THE_I2C_BUS;
    }
    return READ_OK;
}

int device_write(i2c_device *i2cdev) {
    if (write((*i2cdev).device, (*i2cdev).data, 1) != 1) {
        fprintf(stderr, "Failed to write to the i2c bus.\n");
        (*i2cdev).connected = 0;
        return FAILED_TO_WRITE_TO_THE_I2C_BUS;
    }
    return WRITE_OK;
}
