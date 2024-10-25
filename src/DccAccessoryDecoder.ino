#include <NmraDcc.h>                                    // DCC message decoder (https://github.com/mrrwa/NmraDcc.git)
#include <Arduino.h>

#ifndef DCC_PIN                                         // If DCC_PIN not externally defined
    #define DCC_PIN 2                                   // Define it to default value
#endif

// DCC decoder
NmraDcc dccInterface;                                   // DCC interface class
uint16_t lastDccAddress = 0;                            // Last DCC address received
uint8_t lastDccDirection = 0;                           // Last DCC direction received
uint8_t lastDccOutputPower = 0;                         // Last DCC output power received

//  ---- DCC routines ----

// This function is called whenever a normal DCC Turnout Packet is received and we're in Output Addressing Mode
void notifyDccAccTurnoutOutput(uint16_t addr, uint8_t direction, uint8_t outputPower) {
    //printInfo("notifyDccAccTurnoutBoard addr=%d, direction=%d, outputPower=%x\n", addr, direction, outputPower);
    // Define received address
    if (addr != lastDccAddress || direction != lastDccDirection || outputPower != lastDccOutputPower ) {
        // Save last DCC parameters as multiple messages will be received, and remaining identical to be ignored
        lastDccAddress = addr;
        lastDccDirection = direction;
        lastDccOutputPower = outputPower;
        // Send address <space> direction <space> outputPower <CR> <LF>
        Serial.print(addr);
        Serial.print(" ");
        Serial.print(direction);
        Serial.print(" ");
        Serial.println(outputPower);
    }
}

void setup() {
    Serial.begin(74880);                                 // Set serial speed
    dccInterface.pin(DCC_PIN, 0);                        // DCC decoder pin
    dccInterface.init(MAN_ID_DIY, 10, CV29_ACCESSORY_DECODER | CV29_OUTPUT_ADDRESS_MODE, 0);
}

void loop() {
    dccInterface.process();                             // Run DCC loop
}