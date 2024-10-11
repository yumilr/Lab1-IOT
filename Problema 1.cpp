// C++ code
//

int ledR = 8;
int ledAZ = 7;
int ledV = 6;
int ledAM = 5;

int button = 13;

int state =0; bool flag = true; int last_but=0; int but=0;

void setup()
{
  pinMode(ledR, OUTPUT);
  pinMode(ledAZ, OUTPUT);
  pinMode(ledV, OUTPUT);
  pinMode(ledAM, OUTPUT);
  
  pinMode(button, INPUT);
  
  off();
}

void off(){
  digitalWrite(ledR, 0);
  digitalWrite(ledAZ, 0);
  digitalWrite(ledV, 0);
  digitalWrite(ledAM, 0);
}

void loop()
{
  but = digitalRead(button); 
  if (but == 1 && last_but == 0)
    flag = !flag;
  last_but = but;
  
  off();
  delay(500);
  secuencia(state);
  
  if(flag)
    state = (state+1)%4;
  else
    state = (state-1+4)%4;
}  
 
void secuencia(int state){

  switch(state){
  case 0:
    digitalWrite(ledR, HIGH);
    break;
  case 1:
    digitalWrite(ledAZ, HIGH);
    break;
  case 2:
    digitalWrite(ledV, HIGH);
    break;
  case 3:
    digitalWrite(ledAM, HIGH);
    break;
  }
}
