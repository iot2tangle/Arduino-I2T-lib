#ifndef ARDUINO_I2T_LIB_H_
#define ARDUINO_I2T_LIB_H_

#include <stdint.h>

void print_init_msg();
void init_WiFi(const char*, const char*);
void init_HTTP(const char*, int);
void init_sensors();
char* generate_json();
void send_HTTP(const char*);

#endif
