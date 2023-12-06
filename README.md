### ESP32 LED Control System

This Arduino sketch empowers an ESP32 microcontroller to control LEDs interactively. Use buttons to toggle LEDs and send serial commands for more flexibility.
## Instructions:

    Upload the sketch to your ESP32 board using the Arduino IDE.
    Connect LEDs (LEDV2, LEDV3, LEDV4) to respective pins.
    Connect buttons (BTNS2, BTNS3, BTNS4) with pull-up resistors.

## Control Commands:

    Press BTNS2, BTNS3, BTNS4 to toggle LEDV2, LEDV3, LEDV4.
    Send serial commands ('1', '2', '3') to toggle corresponding LEDs.
    Send '8' to invert all LEDs, '9' to turn off all, '0' to turn on all, and 'a' to query LED states.
    Explore more commands with 'c'.
