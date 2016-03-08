#include <SPI.h>
#include <Ethernet.h>
#include <Twitter.h>
 
// Alter IP address to suit your own network!
byte mac[] = {   0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // create MAC address for ethernet shield
byte ip[] = {   192, 168, 0, 8}; // choose your own IP for ethernet shield
Twitter twitter("aaaaaa"); // replace aaaaaaa with your token
 
void setup()
{
  delay(1000);
  
  if (!Ethernet.begin(mac))  // Try to connect using DHCP
    Ethernet.begin(mac, ip); // Try to connect using a Static IP address.
  delay(100);
  
  Serial.begin(9600);
  delay(100);
  
  Serial.print(F("Connected to IP address: "));  // Print out the IP address.
  for (int i = 0; i < 4; i++)
    {
      Serial.print(Ethernet.localIP()[i], DEC);
      Serial.print("."); 
    }
  Serial.println();
  Serial.println();
}
 
void tweet(char msg[])
{
  Serial.println("connecting ...");
  if (twitter.post(msg))
  {
    // Specify &Serial to output received response to Serial.
    // If no output is required, you can just omit the argument, e.g.
    // int status = twitter.wait();
    int status = twitter.wait(&Serial);
    if (status == 200)
    {
      Serial.println("OK.");
    } 
    else
    {
      Serial.print("failed : code ");
      Serial.println(status);
    }
  } 
  else
  {
    Serial.println("connection failed.");
  }
}
 
void loop()
{
  delay(1000);
  tweet("Purple monkey dishwasher");
  do{} while(1>0); // endless loop
}
