raspoutin
=========
(RASPberry pi OUTput INput)
C library for easy access of i2c I/O expanders on the i2c bus.

Usage:

#include "raspoutin.h"

i2c_device mydevice = {
    .bus_name  = "/dev/i2c-0", 
    .address = 0x24, 
    .device = 0, 
    .connected = -1, 
    .data = "0"
};

int main() {
    int read_data;
    if (mydevice.connected == -1) { device_setup(&mydevice); }
    if (mydevice.connected == 0) { return 0; }
    if (mydevice.connected == 1) {
        mydevice.data = 127;
        device.write(&mydevice);
        device_read(&mydevice);
        read_data = mydevice.data;
    }
    return 0;
}
        
