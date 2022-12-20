# 2022/2023 Exam Case Study

A small airport facility makes use of hand-held battery-powered devices to enable airport and airline staff to track checked luggage as it moves through the facility. To facilitate this process, bar-codes are placed at each location of interest, as well as on the printed luggage tags affixed to each bag at check-in. Baggage handlers are required to scan the nearest location bar code before scanning one or more bags.

To scan a bar-code, the device is pointed so that the bar code reader faces the bar-code, and the button is pressed. For each bag scanned, the handheld devices attempt to wirelessly send an appropriately formatted XML message to a central server located within the airport. Because the wireless connectivity in some areas of the airport is poor, devices make use of internal real-time clocks (RTC) to timestamp the scanned information, and are able to store information for up to 1000 bags. If a device is “full”, it can be connected to the server via TTL-level RS232 to transmit the XML messages.

Each hand-held device consists of: an ESP-01s (with WiFi-enabled firmware based on the ESP8266 RTOS SDK), a button, a buzzer, a bar-code reader, and a real-time clock. The latter two both communicate with the ESP-01s via I2C, while the button and buzzer are connected to GPIO pins.

A successful baggage tag scan is indicated by a short beep (300 milliseconds), a successful location tag scan is indicated by a double short beep (300 milliseconds on , 300 milliseconds off, 300 milliseconds on), an unsuccessful scan is indicated by a long beep (900 milliseconds), and a full device is indicated by a double long beep (900 milliseconds on 300 milliseconds off 900 milliseconds on)

## Ai Response

It sounds like the hand-held devices are being used to track the movement of luggage through the airport facility by scanning barcode on luggage tags and location tags. The devices are equipped with WiFi to transmit the scanned information to a central server, but they also have the ability to store the information locally if the WiFi connectivity is poor. They also have an internal real-time clock to timestamp the scanned information. The devices use different beep patterns to indicate the status of the scan, such as a successful scan or a full device.

## Q: Identify two operational concerns or ethical concerns pertaining to implementing the system.

There are a few operational and ethical concerns that may arise when implementing the system described in the previous question:

1. Data security and privacy: The system involves collecting and storing personal information, such as passenger names and luggage details, on a central server. This information could potentially be accessed by unauthorized individuals if proper security measures are not in place. It is important to ensure that the system is designed with data security and privacy in mind, including measures such as encryption and secure access controls.

1. Reliability and accuracy of tracking: The system relies on the accuracy and reliability of the hand-held devices for tracking luggage. If the devices malfunction or are not used correctly, it could lead to incorrect or missing tracking information. It is important to ensure that the devices are regularly maintained and that airport and airline staff are trained on how to use them correctly.

1. Fairness and transparency: The system may raise concerns about fairness and transparency, as it could potentially be used to unfairly track and monitor passengers or baggage. It is important to ensure that the system is used in a transparent and fair manner, with clear policies in place to govern its use and any potential abuses.

## what are the possible tasks for implementing the system ?

what are the possible tasks functions for implementing the system in the FreeRTOS kernel
