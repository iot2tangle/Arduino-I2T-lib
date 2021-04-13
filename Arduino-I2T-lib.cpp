#include <Arduino.h>


void print_init_msg()
{
	delay(3000);
	Serial.println("Hi");
}

void init_WiFi(const char* a, const char* b)
{
	Serial.println("Init WiFi");
}

void init_HTTP(const char* c, int d)
{
	Serial.println("Init HTTP");
}

void init_sensors()
{
	Serial.println("Init sensors");
}

char* generate_json()
{
	char* json = "{JSON}";
	return json;
}

void send_HTTP(const char* e)
{
	Serial.println("Send HTTP");
}
