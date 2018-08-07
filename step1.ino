int program_pin = 12;
int enable_pin = 13;

void setup()
{
  Serial1.begin(115200);
  Serial.begin(115200);
  pinMode(enable_pin, OUTPUT);
  pinMode(program_pin, OUTPUT);
  digitalWrite(program_pin, LOW);
  digitalWrite(enable_pin,HIGH);
}

void loop()
{
  while(Serial1.available()){
    Serial.write((uint8_t)Serial1.read());
  }

  if(Serial.available()){
    while(Serial.available()){
      Serial1.write((uint8_t)Serial.read());
    }
  }
}
