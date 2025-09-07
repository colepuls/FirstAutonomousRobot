#include <Arduino.h>
#include <Servo.h>

Servo rightWheel; // needs to spin backward for right turn
Servo leftWheel; // needs to spin forward for right turn

const int PIN_TRIG = 6;
const int PIN_ECHO = 5;

const float DETECT_DISTANCE_CM = 22.0;

bool motorsAttached = false;

// if wheels are attached, make sure it stays that way
// this prevents motors from dragging on their own
void ensureAttached() 
{
  if (!motorsAttached) 
  {
    rightWheel.attach(9);
    leftWheel.attach(10);
    rightWheel.writeMicroseconds(1500);
    leftWheel.writeMicroseconds(1500);
    delay(50);
    motorsAttached = true;
  }
}

// if wheels are detached, make sure it stays that way
// prevents motors from dragging on its own
void ensureDetached() 
{
  if (motorsAttached) 
  {
    rightWheel.writeMicroseconds(1500);
    leftWheel.writeMicroseconds(1500);
    delay(80);
    rightWheel.detach();
    leftWheel.detach();
    motorsAttached = false;
  }
}

void setup() 
{
  pinMode(PIN_TRIG, OUTPUT); // sender
  pinMode(PIN_ECHO, INPUT); // reciever
  digitalWrite(PIN_TRIG, LOW);
}

float readDistanceCm() 
{
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  unsigned long duration = pulseIn(PIN_ECHO, HIGH, 25000UL);
  if (duration == 0) return 9999;
  return (duration * 0.0343f) / 2.0f; // return distance
}

void forward()
{
  leftWheel.write(180);
  rightWheel.write(0);
}

void turnRight()
{
  leftWheel.write(90);
  rightWheel.write(90);
  delay(100);
  leftWheel.write(180);
  rightWheel.write(180);
  delay(350);
  leftWheel.write(90);
  rightWheel.write(90);
  delay(100);
}

void loop() 
{
  float cm = readDistanceCm();

  if (cm <= DETECT_DISTANCE_CM) 
  {
    ensureAttached();
    turnRight();
  } 
  else if (cm > DETECT_DISTANCE_CM) 
  {
    ensureAttached();
    forward();
  } 
  else 
  {
    if (motorsAttached) 
    {
      rightWheel.write(90);
      leftWheel.write(90);
      ensureDetached();
    }
  }

  delay(60);
}
