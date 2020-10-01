
#define BLYNK_PRINT Serial

#include <SPI.h>                // Library for SPI

#include <Ethernet.h>        // Library for Ethernet

#include <BlynkSimpleEthernet.h>    // Library for Blynk

 

// You should get Auth Token in the Blynk App.

// Go to the Project Settings (nut icon).

char auth[] = "52861cfcce7c48a097fb3cbb190c5fdc";

 

#define W5100_CS  10

#define SDCARD_CS 4

#define red 11                 // Digital Pin for Red

#define green 10            // Digital Pin for Green

#define blue 9                // Digital Pin for Blue

 

/* The setup() function is called when a sketch starts. It is used to initialize variables, pin modes, start using libraries, etc. This function will only run once, after each power up or reset of the Arduino board. */

 

void setup()

{

  // Debug console

  Serial.begin(9600);           // Baud Rate

 

  pinMode(SDCARD_CS, OUTPUT);

  digitalWrite(SDCARD_CS, HIGH); // Deselect the SD card

 

  Blynk.begin(auth);

  // You can also specify server:

  //Blynk.begin(auth, "blynk-cloud.com", 80);

  //Blynk.begin(auth, IPAddress(192,168,1,100), 8080);

 

  // Setup notification button on pin 2

}

 

BLYNK_WRITE(V1)  // Run this function when V1 button pressed.

    {

    int x = param[0].asInt();   

   

        while(x==1)               // When both values are equal

    {

        x = param.asInt();     // Initialize x

        int i=0,j=0,k=0;          // Store values in variables

           

            // Function to output PWM Signal

 

           analogWrite(red, 255);  //  Pin 11 is HIGH

           analogWrite(green, 255);  // Pin 10 is HIGH

           analogWrite(blue, 255);       // Pin 9 is HIGH

       

        for(int j=0;j<20;j++)

        {

           analogWrite(red, 0);       // Pin 11 is LOW

           analogWrite(green, 255);   // Pin 10 is HIGH

           analogWrite(blue, 255);     // Pin 9 is LOW

        delay(100);                       // Wait for 100 ms

           analogWrite(red, 255);      // Pin 11 is HIGH

           analogWrite(green, 0);      // Pin 10 is HIGH

           analogWrite(blue, 255);    // Pin 9 is HIGH

        delay(100);                      // Wait for 100 ms

           analogWrite(red, 255);     // Pin 11 is HIGH

           analogWrite(green, 255);  // Pin 10 is HIGH

           analogWrite(blue, 0);        // Pin 9 is LOW

        delay(100);                      // Wait for 100 ms

           x = param.asInt();           

            if(x==0)                           // When x value equals 0

            break;

        }

       

        analogWrite(red, 255);       // Red is HIGH

        analogWrite(green, 255);   // Green is HIGH

        analogWrite(blue, 255);     // Blue is HIGH

       

        for(int z=0;z<10;z++)

        {

        for(i=0;i<=180;i++)

        {

                analogWrite(red, 180-i);  // Variations for Red

                delay(2);                          // Wait for 2 ms

        }

        analogWrite(red, 255);            // Red is HIGH

        for(j=0;j<255;j++)

        {

                analogWrite(green, 255-j); 

                 delay(2);                             // Wait for 2 ms

        }

        analogWrite(green, 255);        // Green is HIGH

        for(k=0;k<255;k++)           

        {

                analogWrite(blue, 255-k);   

                 delay(2);                            // Wait for 2 ms

        }

        analogWrite(blue, 255);             // Blue is HIGH

        x = param.asInt();

        if(x==0)                                  // when x value equals 0

        break;

       

        }

       

        analogWrite(red, 255);           // Red is HIGH

        analogWrite(green, 255);       // Green is HIGH

        analogWrite(blue, 255);         // Blue is HIGH

            for(int z=0;z<5;z++)

        {

 

        for(j=0;j<255;j++)

        {

                analogWrite(green, 255-j); 

                 delay(20);                      // Wait for 20 ms

        }

        for(k=0;k<255;k++)

        {

                analogWrite(blue, 255-k);

                 delay(20);                     // Wait for 20 ms

        }

       

            for(i=0;i<=180;i++)

        {

                analogWrite(red, 180-i);

                delay(20);                     // Wait for 20 ms

        }

        analogWrite(red,180);          // Red is HIGH

        x = param.asInt();

        if(x==0)                            // When x values equals 0

        break;

        }

    if(x==0)                           // When x values equals 0

    break;

    }

        analogWrite(red, 255);    // Red HIGH

        analogWrite(green, 255);  // Green HIGH

        analogWrite(blue, 255);    // Blue HIGH

    }

/* The loop() function executes the program repeatedly until Specified. */

 

void loop()

{

  Blynk.run();

}
