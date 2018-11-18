#include <WiFi.h>
#include <DNSServer.h>
#include <WiFiManager.h>

void configModeCallback (WiFiManager *myWiFiManager) {  
//  Serial.println("Entered config mode");
  Serial.println("Entrou no modo de configuração");
  Serial.println(WiFi.softAPIP()); //imprime o IP do AP
  Serial.println(myWiFiManager->getConfigPortalSSID()); //imprime o SSID criado da rede

}

//callback que indica que salvamos uma nova rede para se conectar (modo estação)
void saveConfigCallback () {
//  Serial.println("Should save config");
  Serial.println("Configuração salva");
  Serial.println(WiFi.softAPIP()); //imprime o IP do AP
}

void setup()
{
  Serial.begin(9600);

  WiFiManager wifiManager;

  wifiManager.setAPCallback(configModeCallback);
  wifiManager.setSaveConfigCallback(saveConfigCallback);

  wifiManager.autoConnect("ESP_CASA", "123456");
}

void loop()
{
  // put your main code here, to run repeatedly:
}
