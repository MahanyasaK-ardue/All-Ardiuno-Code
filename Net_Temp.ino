#include <SPI.h> //Serial Peripheral Interface
#include <Ethernet.h> //Ethernet Sheild

int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T1, T2, T3;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
// Variable declaration
byte mac[] = {
   0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
  //MAC Address
byte ip[] = {
    192,168,1,2};
    // IP Address
EthernetServer server =  EthernetServer(80);
// EthernetServer declared toserver
int led = 7; // LED attached to pin 7
void setup() {
pinMode(led, OUTPUT); // Led set as an output
Serial.begin(9600);
Ethernet.begin(mac, ip);
server.begin();
Serial.println("Server address:"); // Print server address
// (Arduino shield)
Serial.println(Ethernet.localIP());
}

void loop() {
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T1 = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T2 = T1 - 273.15;
  T3 = (T2 * 9.0)/ 5.0 + 32.0; 
  Serial.print("Temperature: "); 
  Serial.print(T3);
  Serial.println(" F"); 
  Serial.println(" ");
  delay(500);
// Temperature converted from voltage
  EthernetClient client = server.available();
  if(client){
    boolean b = true;
    String buffer = "";
    while(client.connected()){
      if(client.available()){
        char c = client.read();
        if(c == '\n' && b){
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.println("<head><title>Device Readings Web Veiwer</title><style>");
          client.println("body{background-color: white;}");
          client.println(".temp1{ border: 3px solid blue; float: left; top: 340px;  left: 10px;}");
          client.println(".temp2{ border: 3px solid blue; float: right; top: 340px; right: 10px;}");
          client.println(".temp3{ border: 3px solid blue; float: center; top: 340px; right: 10px; left: 10px;}");
          client.println("</style></head>");
          client.println("<body><center><h1>Temperature Using Thermistor</h1><div class='temp3' style='width: 40%; height: 40%'><h3>Temperature In Kelvin</h3><br><br><br>");
          client.println(T1);
          client.print(" k");
          client.println("</div><div class='temp2' style='width: 27%; height: 40%'><h3>Temperature In Celsius</h3><br><br><br>");
          client.println(T2);
          client.print(" C");
          client.println("</div><div class='temp1' style='width: 27%; height: 40%'><h3>Temperature In Fahrenheit</h3><br><br><br>");
          client.println(T3);
          client.print(" F");
          client.println("</div>");
          client.println("</center></body></html>");
          // Web html
          break;
        }
        if(c == '\n'){
          b = true;
          buffer = "";
        }
        else if (c != '\r'){// Command from webpage 
          }
        }
        else{
          b = false;
        }
      }
    }
       delay(300000);
//     Refresh after 5 min
   client.stop();
   // Break statement
   }
