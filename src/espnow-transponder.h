/*
  Copyright (C) 2026 Simon D. Levy

  Permission is hereby granted, free of charge, to any person obtaining a
  copy of this software and associated documentation files.  .  The above
  copyright notice and this permission notice shall be included in all copies
  or substantial portions of the Software.
 */

#include <Arduino.h>

class EspNowTransponder {

    public:

        /**
          * Initiate ESPNOW communication with device at specified address,
          * using the specified serial port.
          */
        static void begin(
                const uint8_t peer_address[6],
                HardwareSerial * serial);

        /**
          * Call this in your loop().
          */
          static void step();
};


