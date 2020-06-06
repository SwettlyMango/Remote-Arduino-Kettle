#include <Servo.h>
#include <IRremote.h>

Servo servo;

long button0 = 16593103;
long button1 = 16582903;
long button2 = 16615543;
long button3 = 16599223;
long button4 = 16591063;
long button5 = 16623703;
long button6 = 16607383;
long button7 = 16586983;
long button8 = 16619623;
long button9 = 16603303;

int RECV_PIN = 3; 
long get; 

IRrecv irrecv(RECV_PIN); // receiver object
decode_results results; 


void setup()
{
  irrecv.enableIRIn();
  pinMode(A0, INPUT);
  pinMode(3, INPUT);
  pinMode(6, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  servo.attach(5);
}

void loop()
{
  int tmp = -40 + 0.488155 * (analogRead(A0) - 20);
  if (irrecv.decode(&results)){ 
    get = results.value; 
    // 100 degrees centigrade
    if(get == button0) {
      analogWrite(6, 255);
    }
    // 10 degrees centigrade
    if(get == button1) {
      analogWrite(6, 25.5);
    }
    // 20 degrees centigrade
    if(get == button2) {
      analogWrite(6, 51);
    }
     // 30 degrees centigrade
    if(get == button3) {
      analogWrite(6, 102);
    }
    // 40 degrees centigrade
    if(get == button4) {
      analogWrite(6, 127.5);
    }
    // 50 degrees centigrade
    if(get == button5) {
      analogWrite(6, 153);
    }
    // 60 degrees centigrade
    if(get == button6) {
      analogWrite(6, 178.5);
    }
    // 70 degrees centigrade
    if(get == button7) {
      analogWrite(6, 204);
    }
    // 80 degrees centigrade
    if(get == button8) {
      analogWrite(6, 229);
    }
    // 90 degrees centigrade
    if(get == button9) {
      analogWrite(6, 255);
    }
    //Heater Shutdown (LED)
    if(get == buttonoff) {
      analogWrite(6, 0);
    }
    
    irrecv.resume(); // tell the receiver that the data has been processed
  }
  if (tmp > 99) {
    servo.write(140);
  } else {
    servo.write(0);
  }
  if (tmp <= 10) {
    analogWrite(11, 0);
    analogWrite(10, 255);
    analogWrite(9, 255);
  } else if (tmp <=40) {
    analogWrite(11, 0);
    analogWrite(10, 255);
    analogWrite(9, 0);
  } else if (tmp <= 90) {
    analogWrite(11, 255);
    analogWrite(10, 255);
    analogWrite(9, 0);
  } else  {
    analogWrite(11, 255);
    analogWrite(10, 0);
    analogWrite(9, 0);
  }
  delay(10);
}
