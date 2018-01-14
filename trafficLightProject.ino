int r_mtr_n = 2; //dc motor
int r_mtr_p = 4;//dc motor
int l_mtr_p = 5;//dc motor
int l_mtr_n = 7; //dc motor

int b_light =0; //green
int f_light = 1;//yellow
int  light = 2; //red

int E1=3; //enable speed 1 >> 3 aurduino
int E2=2; // enable speed 9

int incomingByte = 0; // assign pin for bluetooth module

void setup(){
pinMode(r_mtr_n, OUTPUT); //setup
pinMode(r_mtr_p, OUTPUT);
pinMode(l_mtr_p, OUTPUT);
pinMode(l_mtr_n, OUTPUT);

pinMode(b_light, OUTPUT);
pinMode(f_light, OUTPUT);
pinMode(light, OUTPUT);

pinMode(E1, OUTPUT);
pinMode(E2, OUTPUT);

digitalWrite(r_mtr_n, LOW);
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, LOW);

digitalWrite(b_light, LOW);
digitalWrite(f_light, LOW);
digitalWrite(light, LOW);

analogWrite(E1,0);
analogWrite(E2,0);

Serial.begin(9600); // realtime connection
Serial.println("start");
}

void Forward()
{
  digitalWrite(r_mtr_n, HIGH);
  digitalWrite(r_mtr_p, LOW);
  digitalWrite(l_mtr_p, LOW);
  digitalWrite(l_mtr_n, HIGH);
}

void Backward()
{
  digitalWrite(r_mtr_n, LOW);
  digitalWrite(r_mtr_p, HIGH);
  digitalWrite(l_mtr_p, HIGH);
  digitalWrite(l_mtr_n, LOW);
}

void Right_Forward()
{
  digitalWrite(r_mtr_n, HIGH);
  digitalWrite(r_mtr_p, LOW);
  digitalWrite(l_mtr_p, LOW);
  digitalWrite(l_mtr_n, LOW);
}

void Right_Backward(){
  digitalWrite(r_mtr_n, LOW);
  digitalWrite(r_mtr_p, HIGH);
  digitalWrite(l_mtr_p, LOW);
  digitalWrite(l_mtr_n, LOW);
  }
  

void Left_Forward()
{
 digitalWrite(r_mtr_n,LOW);
  digitalWrite(r_mtr_p, LOW);
  digitalWrite(l_mtr_p, LOW);
  digitalWrite(l_mtr_n, HIGH);
}

void Left_Backward()
{
  digitalWrite(r_mtr_n, LOW);
  digitalWrite(r_mtr_p, LOW);
  digitalWrite(l_mtr_p, HIGH);
  digitalWrite(l_mtr_n,LOW);
}

void Stop()
{
  digitalWrite(r_mtr_n, LOW);
  digitalWrite(r_mtr_p, LOW);
  digitalWrite(l_mtr_p, LOW);
  digitalWrite(l_mtr_n, LOW);

}

void loop(){
if (Serial.available() > 0) { // hyfdel sha8al >0
incomingByte = Serial.read();
//green
digitalWrite(b_light,HIGH);
analogWrite(E1,255);
analogWrite(E2,255);
Forward();
delay(1000);
Backward();
delay(1000);
Right_Forward();
delay(1100);
Right_Backward();
delay(1000);
Left_Forward();
delay(1000);
Left_Backward();
delay(1000);
digitalWrite(b_light,LOW);
//yellow
digitalWrite(f_light,HIGH);
analogWrite(E1,150);
analogWrite(E2,150);
Forward();
delay(1000);
Backward();
delay(1000);
Right_Forward();
delay(1100);
Right_Backward();
delay(1000);
Left_Forward();
delay(1000);
Left_Backward();
delay(1000);
digitalWrite(f_light,LOW);
//RED
digitalWrite(light,HIGH);
analogWrite(E1,0);
analogWrite(E2,0);
Stop();
digitalWrite(light,LOW);
}
}
