#include <Arduino.h>
#include <WiFi101.h>

char json[1024];
char s_name[12][64], d[12][64];

void print_init_msg()
{
	delay(3000);
	Serial.println("Hi");
	
	// Init Json static chars
	strcpy(s_name[0],"InternalTemperature"); 
    strcpy(s_name[1],"Temperature");
    strcpy(s_name[2],"Humidity");
    strcpy(s_name[3],"Pressure");
    strcpy(s_name[4],"SoundLevel");
    strcpy(s_name[5],"Light");
    strcpy(s_name[6],"X");
    strcpy(s_name[7],"Y");
    strcpy(s_name[8],"Z");
    strcpy(s_name[9],"X");
    strcpy(s_name[10],"Y");
    strcpy(s_name[11],"Z");
    
    strcpy(d[0] , "2"); 
    strcpy(d[1] , "54");
    strcpy(d[2] , "23");
    strcpy(d[3] , "234");
    strcpy(d[4] , "23");
    strcpy(d[5] , "32");
    strcpy(d[6] , "0,2");
    strcpy(d[7] , "2.4");
    strcpy(d[8] , "823");
    strcpy(d[9] , "4");
    strcpy(d[10] , "6");
    strcpy(d[11] , "69");
	
}

void init_WiFi(const char* ssid, const char* pass)
{
	int status = WL_IDLE_STATUS;
	
    // check for the presence of the shield:
  	if (WiFi.status() == WL_NO_SHIELD) {
    	Serial.println("WiFi shield not present");
    	// don't continue:
    	while (true);
  	}

	  // attempt to connect to WiFi network:
	while (status != WL_CONNECTED) {
		Serial.print("Attempting to connect to SSID: \"");
		Serial.print(ssid); Serial.println("\" ...");
		// Connect to WPA/WPA2 network. Change this line if using open or WEP network:
		status = WiFi.begin(ssid, pass);

		// wait 10 seconds for connection:
		delay(10000);
	}
	Serial.println("Connected to wifi");

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
    int i, aux;

    strcpy(json, "{\"iot2tangle\":[");
	
    aux = 0;
    strcat(json, "{\"sensor\":\"Internal\",\"data\":[");
    for (i=0;i<1;i++)
	{
			if (aux != i) strcat(json, ",");
			strcat(json, "{\"");
			strcat(json, s_name[i+0]);
			strcat(json, "\":\"");
			strcat(json, d[i+0]);
			strcat(json, "\"}");
    }
    strcat(json, "]}");
	
//    if (check_bme280())
    if (true)
    {
		aux = 0;
		strcat(json, ",{\"sensor\":\"Environmental\",\"data\":[");
		for (i=0;i<3;i++)
		{
			if (aux != i) strcat(json, ",");
			strcat(json, "{\"");
			strcat(json, s_name[i+1]);
			strcat(json, "\":\"");
			strcat(json, d[i+1]);
			strcat(json, "\"}");
		}
		strcat(json, "]}");
    }
	
//    if (check_acoustic())
    if (true)
    {
		aux = 0;
		strcat(json, ",{\"sensor\":\"Acoustic\",\"data\":[");
		for (i=0;i<1;i++)
		{
			if (aux != i) strcat(json, ",");
			strcat(json, "{\"");
			strcat(json, s_name[i+4]);
			strcat(json, "\":\"");
			strcat(json, d[i+4]);
			strcat(json, "\"}");
		}
		strcat(json, "]}");
    }
	
//    if (check_bh1750())
    if (true)
    {
		aux = 0;
		strcat(json, ",{\"sensor\":\"Light\",\"data\":[");
		for (i=0;i<1;i++)
		{
			if (aux != i) strcat(json, ",");
			strcat(json, "{\"");
			strcat(json, s_name[i+5]);
			strcat(json, "\":\"");
			strcat(json, d[i+5]);
			strcat(json, "\"}");
		}
		strcat(json, "]}");
    }
	
//    if (check_mpu6050())
    if (true)
    {
		aux = 0;
		strcat(json, ",{\"sensor\":\"Acelerometer\",\"data\":[");
		for (i=0;i<3;i++)
		{
			if (aux != i) strcat(json, ",");
			strcat(json, "{\"");
			strcat(json, s_name[i+6]);
			strcat(json, "\":\"");
			strcat(json, d[i+6]);
			strcat(json, "\"}");
		}
	strcat(json, "]}");
    }

//    if (check_mpu6050())
    if (true)
    {
		aux = 0;
		strcat(json, ",{\"sensor\":\"Gyroscope\",\"data\":[");
		for (i=0;i<3;i++)
		{
			if (aux != i) strcat(json, ",");
			strcat(json, "{\"");
			strcat(json, s_name[i+9]);
			strcat(json, "\":\"");
			strcat(json, d[i+9]);
			strcat(json, "\"}");
		}
		strcat(json, "]}");
    }

	strcat(json, "],\"device\": \"");
	strcat(json, "123123");
	strcat(json, "\",\"timestamp\": \"0\"}");	
	
	Serial.println(json);

	return json;
}

void send_HTTP(const char* e)
{
	Serial.println("Send HTTP");
}
