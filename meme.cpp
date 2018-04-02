#include <LiquidCrystalShift.h>
#include <Adafruit_BMP280.h>

LiquidCrystalShift lcd(7, 8, A3);
Adafruit_BMP280 bmp;


void setup() {
    pinMode(4, INPUT); //down button
    pinMode(5, INPUT); //up button
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    lcd.begin(16, 2);

    if (!bmp.begin(0x76)) {
        lcd.clear();
        lcd.print("Sensor needs to");
        lcd.setCursor(0, 1);
        lcd.print("be turned on.");
        while (1) {
            //stay here forever.
        }
    }
}

void checkHeater(float reading, int userSetting){
	if(reading < userSetting){
	digitalWrite(10, HIGH);
	digitalWrite(11,LOW);
	}
	else if (analogVal > temp){
		digitalWrite(11, HIGH);
		digitalWrite(10,LOW);
	}
}

void loop() {
	//this will read the temperature in celsius
	float temp = bmp.readTemperature();
	int userSetting = 23;
	lcd.setCursor(0,0);
	lcd.print("Current Temp: ");
	lcd.print(temp);
	lcd.setCursor(0,1);
	lcd.print("Set Temp: " analogVal);
	lcd.print("userSetting");



	checkHeater(temp, int userSetting)

	if(analogVal>255)
	{
	analogVal=255;
	}
	if(analogVal<-255)
	{
	analogVal=-255;
	}
	if (analogVal<temp)
	{
	digitalWrite(10, HIGH);
	digitalWrite(11,LOW);
	}
	if (analogVal>temp)
	{
	digitalWrite(11, HIGH);
	digitalWrite(10,LOW);
	}
}
