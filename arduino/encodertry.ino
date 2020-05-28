#define leftencoder_pinA 20
#define leftencoder_pinB 21
volatile long leftencoderticks = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  setupencoder();

}
void setupencoder()
{
  pinMode(leftencoder_pinA,INPUT_PULLUP);
  pinMode(leftencoder_pinB,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(leftencoder_pinA),doleftencoder, RISING); 
}

void loop() {
  // put your main code here, to run repeatedly:
  updateencoder();
}
void updateencoder()
{
  Serial.println(leftencoderticks);
}
void doleftencoder()
{
  int leftencoderbset = digitalRead(leftencoder_pinB);
  leftencoderticks -= leftencoderbset ? -1 : +1;
}
