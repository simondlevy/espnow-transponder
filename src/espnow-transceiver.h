/*
  Copyright (C) 2026 Simon D. Levy

  Permission is hereby granted, free of charge, to any person obtaining a
  copy of this software and associated documentation files.  .  The above
  copyright notice and this permission notice shall be included in all copies
  or substantial portions of the Software.
 */

#include <Arduino.h>

class EspNowTransceiver {

    public:

        /**
          * Initiate ESPNOW communication with device at specified address.
          */
        static void begin(const uint8_t peer_address[6]);

        /**
          * Send data to the peer device.
          */
        static void send(const uint8_t * data, const uint8_t len);

        /**
          * You should implement this method for your application.
          */
         static void recv(const uint8_t * data, const uint8_t len);
};


