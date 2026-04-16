/*
   Copyright (C) 2026 Simon D. Levy

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files.  .  The above
   copyright notice and this permission notice shall be included in all copies
   or substantial portions of the Software.
*/

#include <espnow-transponder.h>

// Change this to the MAC address of the other ESP32
static const uint8_t PEER_ADDRESS[] = {0x00,0x00,0x00,0x00,0x00,0x00};

void setup()
{
    Serial.begin(115200);

    EspNowTransponder::begin(PEER_ADDRESS, &Serial);
}

void loop()
{
    EspNowTransponder::step();

    delay(100);
}
