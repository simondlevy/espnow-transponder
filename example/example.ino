/*
   Copyright (C) 2026 Simon D. Levy

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files.  .  The above
   copyright notice and this permission notice shall be included in all copies
   or substantial portions of the Software.
*/

#include <espnow-transceiver.h>

// Change this to the MAC address of the other ESP32
static const uint8_t PEER_ADDRESS[] = {0x00,0x00,0x00,0x00,0x00,0x00};

void EspNowTransceiver::recv(const uint8_t * message, const uint8_t len)
{
    Serial.print("Bytes received: ");
    Serial.println(len);
}

void setup()
{
    Serial.begin(115200);

    EspNowTransceiver::begin(PEER_ADDRESS);
}

void loop()
{
    const uint8_t vals[10] = {};

    EspNowTransceiver::send(vals, 10);

    delay(100);
}
