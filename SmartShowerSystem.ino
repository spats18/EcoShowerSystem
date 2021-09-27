// Code for Arduino-1
// Including the RadioHead ASK library
#include <RH_ASK.h>
// The RadioHead ASK library needs SPI library to work.
// Including the SPI library
#include<SPI.h>
// The Pressure Mat Sensor sends a signal when a person is standing on the mat.
const int Person_Standing= 3;
// Setting the pinmode and checking the transmitter
void setup()
{
pinMode(Person_Standing, INPUT);
Serial.begin(9600);
if(!T_driver.init())
Serial.println("init failed");
}
// The transmitter transmits the information only when the Person_Standing pin is High.
Void loop()
{
if(digitalRead(Person_Standing) == HIGH)
{
const char *msg= " The person is standing on the mat";
T_driver.send((uint8_t *)msg, strlen(msg));
T_driver.waitPacketSent();
delay(1000);
}
}
// Code for Arduino-2
// Including the RadioHead ASK library
#include <RH_ASK.h>
// The RadioHead ASK library needs SPI library to work.
// Including the SPI library
#include<SPI.h>
//Setting the pin that transmits the information to solenoid valve
const int is_present=3;
// Setting the pinmode and checking the receiver
void setup()
{
29 | P a g e
pinMode(is_present, OUTPUT);
Serial.begin(9600);
if (!R_driver.init())
Serial.println("init failed");
}
// Since the receiver needs to receive the message from the transmitter,
//the buffer size in the transmitter should be exactly same as that of the message.
Void loop()
{
uint8_t buf[33];
uint8_t buflen = sizeof(buf);
// Checking whether the information received is valid or not
if (R_driver.recv(buf, &buflen))
{
int i;
Serial.print("Message: ");
Serial.println((char*)buf);
}
digitalWrite(3,HIGH);
}
