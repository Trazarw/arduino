byte pinIndex = 0;
byte pins[] = {5, 7, 9, 11, 13};
byte x;
byte y;

void setup() {
  configure_output();
  configure_debuggin();
  ford_back_pin_loading();
}

void loop() {
  
  capture_and_log_joystick();

  if(x == 0)
  {
    set_next_pin_on();
  }
  
  if(x == 255)
  {
    set_last_pin_off();
  }

   Serial.print("\n");
   Serial.print("pinIndex :");
   Serial.println(pinIndex);
}

void capture_and_log_joystick()
{
  x = analogRead(A0);  
  y = analogRead(A1);
  
  Serial.print("\n"); 
  Serial.print("X-axis: ");
  Serial.print(x);
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(y);
}

void configure_debuggin()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}

void configure_output()
{
  Serial.begin(9600);
  delay(1);
}

void set_pin_on(byte hpin)
{
  digitalWrite(hpin, HIGH);
  digitalWrite(hpin -1, LOW);
}

void set_pin_off(byte hpin)
{
  digitalWrite(hpin, LOW);
  digitalWrite(hpin + 1, HIGH);
}

void ford_back_pin_loading()
{
  set_pin_on(13);
  set_pin_on(11);
  set_pin_on(9);
  set_pin_on(7);
  set_pin_on(5);
  set_pin_off(5);
  set_pin_off(7);
  set_pin_off(7);
  set_pin_off(9);
  set_pin_off(11);
  set_pin_off(13);
}

byte set_next_pin_on()
{
  set_pin_on(pins[pinIndex]);
  pinIndex +=1;
}

byte set_last_pin_off()
{
  set_pin_off(pins[pinIndex]);
  pinIndex -=1;
}
