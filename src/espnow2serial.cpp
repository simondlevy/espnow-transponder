/*
   Copyright (C) 2026 Simon D. Levy

   Adapted from: 

     https://RandomNerdTutorials.com/esp-now-two-way-communication-esp32 
     
   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files.  .  The above
   copyright notice and this permission notice shall be included in all copies
   or substantial portions of the Software.
*/


#include <esp_now.h>
#include <WiFi.h>

#include "espnow2serial.h"

static uint8_t _peer_address[6];

static void OnDataRecv(
        const uint8_t * mac, const uint8_t * data, int len)
{
    (void)mac;
    Serial.print("Bytes received: ");
    Serial.println(len);
}

static void reportForever(const char * msg)
{
    Serial.println(msg);
    delay(500);
}

void EspNow2Serial::begin(
        const uint8_t peer_address[6], 
        HardwareSerial * serial,
        const uint32_t baud)
{
    memcpy(_peer_address, peer_address, 6);

    serial->begin(baud);

    WiFi.mode(WIFI_STA);

    if (esp_now_init() != ESP_OK) {
        reportForever("Error initializing ESP-NOW");
    }

    esp_now_peer_info_t peerInfo = {};
    memcpy(peerInfo.peer_addr, _peer_address, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;

    if (esp_now_add_peer(&peerInfo) != ESP_OK){
        reportForever("Failed to add peer");
    }

    // Register for a callback function that will be called when data is received
    esp_now_register_recv_cb(esp_now_recv_cb_t(OnDataRecv));
}

void EspNow2Serial::send(const uint8_t * message, const uint8_t len)
{
    if (!esp_now_send(_peer_address, message, len) == ESP_OK) {
        Serial.println("Error sending the data");
    }
}
