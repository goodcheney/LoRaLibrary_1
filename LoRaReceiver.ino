#include <SPI.h>
#include <LoRa.h>


//Receiver LoRa packets and forward it 
void receivepacket() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    int i = 0;
    
    uint8_t  message[50];

    while (LoRa.available()&&i<50)
    {
      message[i]=LoRa.read();
      i++;
    }
  
     // print RSSI of packet
     
       Serial.print((char *)message);
  
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(433.3E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  LoRa.setFrequency(433300000);
  LoRa.setSpreadingFactor(7);
  LoRa.setSignalBandwidth(125E3);
  LoRa.setCodingRate4(5);
}

void loop() {
receivepacket();
}
