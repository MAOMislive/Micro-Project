#define BLYNK_TEMPLATE_NAME "MicroProjectRoof"
#define BLYNK_TEMPLATE_ID "Your_Template_ID_Here"  // Define an arbitrary template ID

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char authPerson1[] = "x3P0t5qhWV82fzUaWHlj5aCxt6Yrwxe-";
char authPerson2[] = "VOwxdT9RwlYSn1SB_jKyHccj-flYfjMF";

char ssid[] = "One Virus Found";        // Your WiFi SSID
char pass[] = "mfaho499";    // Your WiFi password

char currentAuth[] = "x3P0t5qhWV82fzUaWHlj5aCxt6Yrwxe-"; // Current authentication token

void setup() {
  Serial.begin(115200);

  Blynk.begin(currentAuth, ssid, pass);
}

void loop() {
  Blynk.run();
}

BLYNK_WRITE(V0) {
  // Function triggered when data is received from the Terminal widget (V0)
  String command = param.asStr(); // Get the received command as a string
  Serial.println("Received command: " + command);

  if (command == "person1") {
    strncpy(currentAuth, authPerson1, sizeof(currentAuth)); // Set authentication token to person 1's token
    Blynk.config(currentAuth); // Reconfigure Blynk with the new authentication token
    Serial.println("Switched to person 1's authentication token");
    delay(15000); // Delay for 15 seconds
    Blynk.virtualWrite(V1, "Provide the Password to unlock: "); // Write to V1 pin
  } else if (command == "person2") {
    strncpy(currentAuth, authPerson2, sizeof(currentAuth)); // Set authentication token to person 2's token
    Blynk.config(currentAuth); // Reconfigure Blynk with the new authentication token
    Serial.println("Switched to person 2's authentication token");
    delay(15000); // Delay for 15 seconds
    Blynk.virtualWrite(V1, "Provide the Password to unlock: "); // Write to V1 pin
  } else {
//    Serial.println("Invalid command");
  }
}
