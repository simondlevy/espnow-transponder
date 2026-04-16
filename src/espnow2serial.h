/*
   Copyright (C) 2026 Simon D. Levy

   Adapted from: 

     https://RandomNerdTutorials.com/esp-now-two-way-communication-esp32 

  Permission is hereby granted, free of charge, to any person obtaining a
  copy of this software and associated documentation files.  .  The above
  copyright notice and this permission notice shall be included in all copies
  or substantial portions of the Software.
 */

#include <Arduino.h>

class EspNow2Serial {

    public:

        static void begin(
                const uint8_t peer_address[6], 
                HardwareSerial * serial=&Serial,
                const uint32_t baud=115200);

        static void send(const uint8_t * message, const uint8_t len);
};


