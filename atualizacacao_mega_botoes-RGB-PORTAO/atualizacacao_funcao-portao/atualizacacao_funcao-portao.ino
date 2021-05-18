#include <SPI.h>
#include <Ethernet.h>
//#include <SD.h>

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip (192, 168, 0, 13);
IPAddress gateway (192, 168, 0, 1);
IPAddress subnet (255, 255, 255, 0);
EthernetServer server(80);
//File webFile;

int luz1 = 30;
int luz2 = 31;
int luz3 = 32;
int luz4 = 33;
int luz5 = 34;
int luz6 = 35;
int luz7 = 36;
int luz8 = 37;
int abre = 38;
int fecha = 39;
int R = 22;
int G = 24;
int B = 26;

void abreportao()
{
digitalWrite(abre, HIGH);
digitalWrite(fecha, LOW);
delay (20000);
digitalWrite(abre, LOW);
digitalWrite(fecha, LOW);
}

void fechaportao()

{
digitalWrite(abre, LOW);
digitalWrite(fecha, HIGH);
delay(20000);
digitalWrite(abre, LOW);
digitalWrite(fecha, LOW);  
}

void setup()
{
Ethernet.begin(mac, ip);
server.begin();
Serial.begin(9600);
pinMode(luz1, OUTPUT);
pinMode(luz2, OUTPUT);
pinMode(luz3, OUTPUT);
pinMode(luz4, OUTPUT);
pinMode(luz5, OUTPUT);
pinMode(luz6, OUTPUT);
pinMode(luz7, OUTPUT);
pinMode(luz8, OUTPUT);
pinMode(R,OUTPUT);
pinMode(G, OUTPUT);
pinMode(B,OUTPUT);
pinMode(abre, OUTPUT);
pinMode(fecha, OUTPUT);
digitalWrite(luz1, LOW);
digitalWrite(luz2, LOW);
digitalWrite(luz3, LOW);
digitalWrite(luz4, LOW);
digitalWrite(luz5, LOW);
digitalWrite(luz6, LOW);
digitalWrite(luz7, LOW);
digitalWrite(luz8, LOW);
digitalWrite(R, LOW);
digitalWrite(G, LOW);
digitalWrite(B, LOW);
digitalWrite(abre, LOW);
digitalWrite(fecha, LOW);
//Serial.println("Iniciando o cartao sd");
//if (!SD.begin(4))
//{
 // Serial.println("erro sd falhou");
 // return;
 // }


}

void loop ()
{
EthernetClient client = server.available();

if (!client)
{
  return;
 /*boolean currentLineIsBlank = true;
  while (client.connected())
  {
    if (client.available())
          {
      char c = client.read();

          if (c == '\n' && currentLineIsBlank)
          {
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println();
   // webFile = SD.open("teste.html");
   // if (webFile)
   // {
    //  while(webFile.available())
    //  {
     //   client.write(webFile.read());
     //   }
      
    //  }
    //  break;
          }
          if (c == '\n') {
            currentLineIsBlank = true;
            }
            else if (c != '\r')
            {
              currentLineIsBlank = false;
              }*/
 } 
String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  int v1 = LOW;
  int v2 = LOW;
  int v3 = LOW;
  int v4 = LOW;
  int v5 = LOW;
  int v6 = LOW;
  int v7 = LOW;
  int v8 = LOW;
  int v9 = LOW;
  int v10 = LOW;
  int v11 = LOW;
  int v12 = LOW;
  int v13 = LOW;
  
  if (request.indexOf("/luz1=ON") != -1) {
    digitalWrite(luz1, HIGH);
    v1 = HIGH;
  }
  if (request.indexOf("/luz1=OFF") != -1){
    digitalWrite(luz1, LOW);
    v1 = LOW;
    
  }
  
   if (request.indexOf("/luz2=ON") != -1) {
    digitalWrite(luz2, HIGH);
    v2 = HIGH;
  }
  if (request.indexOf("/luz2=OFF") != -1){
    digitalWrite(luz2, LOW);
    v2 = LOW;
    
  }
 
   if (request.indexOf("/luz3=ON") != -1) {
    digitalWrite(luz3, HIGH);
    v3 = HIGH;
  }
  if (request.indexOf("/luz3=OFF") != -1){
    digitalWrite(luz3, LOW);
    v3 = LOW;
    
  }

   if (request.indexOf("/luz4=ON") != -1) {
    digitalWrite(luz4, HIGH);
    v4 = HIGH;
  }
  if (request.indexOf("/luz4=OFF") != -1){
    digitalWrite(luz4, LOW);
    v4 = LOW;
    
  }

   if (request.indexOf("/luz5=ON") != -1) {
    digitalWrite(luz5, HIGH);
    v5 = HIGH;
  }
  if (request.indexOf("/luz5=OFF") != -1){
    digitalWrite(luz5, LOW);
    v5 = LOW;
    
  }
  
   if (request.indexOf("/luz6=ON") != -1) {
    digitalWrite(luz6, HIGH);
    v6 = HIGH;
  }
  if (request.indexOf("/luz6=OFF") != -1){
    digitalWrite(luz6, LOW);
    v6 = LOW;
    
  }

   if (request.indexOf("/luz7=ON") != -1) {
    digitalWrite(luz7, HIGH);
    v7 = HIGH;
  }
  if (request.indexOf("/luz7=OFF") != -1){
    digitalWrite(luz7, LOW);
    v7 = LOW;
    
  }
 
   if (request.indexOf("/luz8=ON") != -1) {
    digitalWrite(luz8, HIGH);
    v8 = HIGH;
  }
  if (request.indexOf("/luz8=OFF") != -1){
    digitalWrite(luz8, LOW);
    v8 = LOW;
    
  }
  if (request.indexOf("/red=ON") != -1)
  {
  digitalWrite(R, HIGH);
  v9 = HIGH;
    
  }
  if (request.indexOf("/red=OFF") != -1)
  {
  digitalWrite(R, LOW);
  v9 = LOW;
    
  }
  
  if (request.indexOf("/green=ON") != -1)
  {
  digitalWrite(G, HIGH);
  v10 = HIGH;
    
  }

  if (request.indexOf("/green=OFF") != -1)
  {
  digitalWrite (G, LOW);
  v10 = LOW;
  
  }

  if (request.indexOf("/blue=ON") != -1)
  {
  digitalWrite (B, HIGH);
  v11 = HIGH;
    
  }

  if (request.indexOf("/blue=OFF")!= -1)
  {
  digitalWrite(B, LOW);
  v11 = LOW;
  
  }

  
  if (request.indexOf("/portao=ON")!= -1)
  {
    abreportao();
  }
  
  if (request.indexOf("/portao=OFF")!= -1)
  {
    fechaportao(); 
  }

client.println("<!DOCTYPE HTML>");
client.println("<html>");
client.println("<meta charset ='utf-8'/>");
client.println("<meta name = 'viewport' content = 'width=device-width, initial-scale=1'>");
client.println("<link href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.1/css/bootstrap.min.css' rel='stylesheet'></link>");
client.println("<div class='jumbotron'>");
client.println("<h1 class='text-center'>Automação</h1>");
client.println("<h2 class='text-center'>Ademir</h2>");
client.println("</div>");
client.println("<div class='col-md-6'>");
client.println("<div class='alert alert-info text-center' role='alert'>Portão</div>");
client.println("<a class='btn btn-danger btn-lg center-block'  href=\"/portao=ON\"> ABRIR </a>");
client.println("<br>");
client.println("<a class='btn btn-success btn-lg center-block' href=\"/portao=OFF\"> FECHAR </a>");
client.println("<br>");
client.println("</div>");
client.println("<div class='col-md-6'>");
client.println("<br>");
client.println("<div class='alert alert-info text-center' role='alert'>luz1</div>");
client.println("<a class='btn btn-danger btn-lg center-block' href=\"/luz1=OFF\"> Desligar </a>");
client.println("<br>");
client.println("<a class='btn btn-success btn-lg center-block' href=\"/luz1=ON\"> Ligar </a>");
client.println("</div>");
client.println("<br>");
client.println("<div class='col-md-6'>");
client.println("<br>");
client.println("<div class='alert alert-info text-center' role='alert'>luz2</div>");
client.println("<a class='btn btn-danger btn-lg center-block' href=\"/luz2=OFF\"> Desligar </a>");
client.println("<br>");
client.println("<a class='btn btn-success btn-lg center-block' href=\"/luz2=ON\"> Ligar </a>");
client.println("</div>");
client.println("<br>");
client.println("<div class='col-md-6'>");
client.println("<br>");
client.println("<div class='alert alert-info text-center' role='alert'>luz3</div>");
client.println("<a class='btn btn-danger btn-lg center-block' href=\"/luz3=OFF\"> Desligar </a>");
client.println("<br>");
client.println("<a class='btn btn-success btn-lg center-block' href=\"/luz3=ON\"> Ligar </a>");
client.println("</div>");
client.println("<br>");
client.println("<div class='col-md-6'>");
client.println("<br>");
client.println("<div class='alert alert-info text-center' role='alert'>luz4</div>");
client.println("<a class='btn btn-danger btn-lg center-block' href=\"/luz4=OFF\"> Desligar </a>");
client.println("<br>");
client.println("<a class='btn btn-success btn-lg center-block' href=\"/luz4=ON\"> Ligar </a>");
client.println("</div>");
client.println("<br>");
client.println("<div class='col-md-6'>");
client.println("<br>");
client.println("<div class='alert alert-info text-center' role='alert'>luz5</div>");
client.println("<a class='btn btn-danger btn-lg center-block' href=\"/luz5=OFF\"> Desligar </a>");
client.println("<br>");
client.println("<a class='btn btn-success btn-lg center-block' href=\"/luz5=ON\"> Ligar </a>");
client.println("</div>");
client.println("<br>");
client.println("<div class='col-md-6'>");
client.println("<br>");
client.println("<div class='alert alert-info text-center' role='alert'>luz6</div>");
client.println("<a class='btn btn-danger btn-lg center-block' href=\"/luz6=OFF\"> Desligar </a>");
client.println("<br>");
client.println("<a class='btn btn-success btn-lg center-block' href=\"/luz6=ON\"> Ligar </a>");
client.println("</div>");
client.println("<br>");
client.println("<div class='col-md-6'>");
client.println("<br>");
client.println("<div class='alert alert-info text-center' role='alert'>luz7</div>");
client.println("<a class='btn btn-danger btn-lg center-block' href=\"/luz7=OFF\"> Desligar </a>");
client.println("<br>");
client.println("<a class='btn btn-success btn-lg center-block' href=\"/luz7=ON\"> Ligar </a>");
client.println("</div>");
client.println("<br>");
client.println("<div class='col-md-6'>");
client.println("<br>");
client.println("<div class='alert alert-info text-center' role='alert'>luz8</div>");
client.println("<a class='btn btn-danger btn-lg center-block' href=\"/luz8=OFF\"> Desligar </a>");
client.println("<br>");
client.println("<a class='btn btn-success btn-lg center-block' href=\"/luz8=ON\"> Ligar </a>");
client.println("</div>");
client.println("<br>");
client.println("<div class='col-md-6'>");
client.println("<br>");
client.println("<div class='alert alert-info text-center' role='alert'>RGB</div>");
client.println("<a class='btn btn-danger btn-lg' href=\"/red=ON\">R-ON</a>");
client.println("<a class='btn btn-danger btn-lg ' href=\"/red=OFF\">R-OFF </a>");
client.println("<a class='btn btn-success btn-lg' href=\"/green=ON\">G-ON</a>");
client.println("<a class='btn btn-success btn-lg' href=\"/green=OFF\">G-OFF</a>");
client.println("<a class='btn btn-primary btn-lg' href=\"/blue=ON\">B-ON</a>");
client.println("<a class='btn btn-primary btn-lg' href=\"/blue=OFF\">B-OFF</a>");
client.println("</div>");
client.println("</html>");
  delay(1);
  Serial.println("Embarcado saiu :");
  Serial.println(""); 
  
 delay(1);
 client.stop();
 }
 
//}


  
//}
