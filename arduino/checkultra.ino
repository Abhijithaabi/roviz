const int echo = 33 , trig = 32;
long duration,cm;


void setup() {
  Serial.begin(115200);
  setultra();
  

}
void setultra()
{
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}
void loop() {
  updateultra();
  delay(200);

}
void updateultra()
{
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  cm = mstocm(duration);
  Serial.print("distance = ");
  Serial.print("\t");
  Serial.print(cm);
  Serial.print("\n");
}
long mstocm(long ms)
{
  return ms/(29/2);
}
