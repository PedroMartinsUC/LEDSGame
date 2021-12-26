int led[] = {2,3,4,5,6,7,8,9,10};
int botao1 = 11;
int botao2 = 12;
static int prevState = LOW;
bool light[9] = {0,0,0,0,0,0,0,0,0};
int count = 0;
bool currentState = false;
 
void setup()
{
  for(int i = 0; i < 9; i++){
    pinMode(led[i], OUTPUT);
  }    
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  Serial.begin(9600);
  
}
 
void loop()
{
  
  
  for(int i = 0; i < 9; i++){
    
    if (count == 9){
      for (int timecount = 0; timecount < 5; timecount++){
        digitalWrite(led[0], HIGH);
        digitalWrite(led[1], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[3], HIGH);
        digitalWrite(led[4], HIGH);
        digitalWrite(led[5], HIGH);
        digitalWrite(led[6], HIGH);
        digitalWrite(led[7], HIGH);
        digitalWrite(led[8], HIGH);
        digitalWrite(led[0], HIGH);
        delay(500);
        digitalWrite(led[0], LOW);
        digitalWrite(led[1], LOW);
        digitalWrite(led[2], LOW);
        digitalWrite(led[3], LOW);
        digitalWrite(led[4], LOW);
        digitalWrite(led[5], LOW);
        digitalWrite(led[6], LOW);
        digitalWrite(led[7], LOW);
        digitalWrite(led[8], LOW);
        digitalWrite(led[9], LOW);
        delay(500);
        count = 0;
             
      }     
    }
    else{
      
      if (light[i] == 1){
        delay(500);
      
      }
      else{
        digitalWrite(led[i], HIGH);
        delay(500);
        int butstate = !digitalRead(botao1);
          if(butstate != prevState){
            light[i] = 1;
            prevState = butstate;
            digitalWrite(led[i], HIGH);
            count = count + 1;
            Serial.print(count);
          }
          
            else{
            digitalWrite(led[i], LOW);
          }
        currentState = prevState;
 
      }
    }
 
  }
  
}
