#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
byte ip[] = {192,168,1,2};
EthernetServer server(80);
String HTTP_req;
boolean Line;
char c;

void setup() {
  Ethernet.begin(mac, ip);
  server.begin();
  pinMode(2, OUTPUT);
}

void loop() {
  EthernetClient client = server.available();
  if(client){
    Line = true;
    while(client.connected()){
      if(client.available()){
        c - client.read();
        HTTP_req += c;
        if(c == '\n' && Line){
          client.println("HTTP/1.1 200 OK");
          client.println("Content Type: text/html");
          client.println();
          client.println("<html><head><title>Web Viewer</title></head><body>");
          client.println("<form method = \"get\">");
          ProcessGet(client);
          client.println("</form></body></html>");
          HTTP_req = "";
          client.stop();
        }
        if(c == '\n'){
            Line = true;
        }
        else if(c!= '\r'){
          Line = false;
        }
      }
    }
    delay(5);
  }
}
void ProcessGet(EthernetClient cl){
  if (HTTP_req.indexOf("state=on") > -1){
    digitalWrite(2, HIGH);
    cl.println("<h1>LED IS ON!<h1>");
  }
 else if(HTTP_req.indexOf("state=off") > -1){
  digitalWrite(2, LOW);
  cl.println("LED ID OFF"); 
 }
 else{
 cl.println("LED IS OFF BY DEFAULT");
 }
}
