# RubberDuckyArduinoUno

You need this program:
  - Windows: https://ww1.microchip.com/downloads/aemDocuments/documents/DEV/ProductDocuments/SoftwareTools/JRE-Flip-Installer-3.4.7.112.exe
  
Once you have the software installed on your computer. You will need to install the appropriate drivers, 
to do this, go to the path of the program we just installed, a folder in the back, contains a file called "usb". 
Once located, we go to the device manager, and connect our Arduino Uno in Bootloader mode bypassing the pins until the led of the arduino static. 
These pins are next to the reset. Once the led is static, remove the jumper. And open Flip. Click on the chip icon next to the usb cable. 
And we select our microcontroller model. In my case it is the ATmega16u2. Then we select the usb icon and in the dropdown we select USB. 
Once inside we click on open, and the arduino will be connected correctly. 
To flash a file simply click on File at the top, and in the dropdown we click on Load HEX File. 
To flash uncheck the blank check option and to finish, click on run. Disconnect and reconnect and that's it. 
We will have the fimware changed!
