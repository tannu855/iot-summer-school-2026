#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

#define SERVICE_UUID "12345678-1234-1234-1234-1234567890ab"
#define TEMP_UUID    "12345678-1234-1234-1234-1234567890ac"
#define HUM_UUID     "12345678-1234-1234-1234-1234567890ad"
#define TIME_UUID    "12345678-1234-1234-1234-1234567890ae"

BLECharacteristic *tempChar;
BLECharacteristic *humChar;
BLECharacteristic *timeChar;

void setup() {
  Serial.begin(115200);
  dht.begin();

  BLEDevice::init("ESP32_DHT11");

  BLEServer *server = BLEDevice::createServer();
  BLEService *service = server->createService(SERVICE_UUID);

  tempChar = service->createCharacteristic(TEMP_UUID, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
  humChar = service->createCharacteristic(HUM_UUID, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
  timeChar = service->createCharacteristic(TIME_UUID, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);

  service->start();
  BLEDevice::getAdvertising()->start();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  unsigned long timestamp = millis() / 1000;

  tempChar->setValue(String(temp).c_str());
  humChar->setValue(String(hum).c_str());
  timeChar->setValue(String(timestamp).c_str());

  tempChar->notify();
  humChar->notify();
  timeChar->notify();

  delay(3000);
}
