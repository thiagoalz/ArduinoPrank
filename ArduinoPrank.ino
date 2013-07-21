/*
Keyboard and mouse Prank using Arduino Leonardo
 */
 
// Configs
const int delayLevel = 8; //1-10


void setup() {
  Serial.begin(9600);
  
  // initialize control:
  Mouse.begin();
  Keyboard.begin();
}

void loop() {
  startRandSeed();
  
  //Wait to start
  executeDelay(30,90);  
  
  int randPrank = random(1, 2);
  switch (randPrank) {
    case 1:    
      mouseClickPrank(3);
      break;
    case 2:    
      mouseJumpPrank(3,400);
      break;
    case 3:    
      mouseJitterPrank(3,10);
      break;
    case 4:    
      keyboardTypePrank(3);
      break;
    case 5:    
      keyboardHoldKeyPrank(3);
      break;
    default:
      Serial.print("Default");
    } 
}


//////Pranks
void mouseClickPrank(int repeats){
  Serial.println("Click: "+repeats);
  
  for (int i=0; i<repeats; i++){
    mouseClick();    
    executeDelay(5,10);
  }
}

void mouseJumpPrank(int repeats, int distance){
  Serial.print("Jump: "+repeats);
  Serial.println(" "+distance);
  
  for (int i=0; i<repeats; i++){
    jump(distance);    
    executeDelay(5,10);
  }
}

void mouseJitterPrank(int repeats, int duration){
  Serial.print("Jitter: "+repeats);
  Serial.println(" "+duration);
  
  for (int i=0; i<repeats; i++){
    jitter(duration);    
    executeDelay(1,10);
  }
}

void keyboardTypePrank(int repeats){
  Serial.println("keyboardType: "+repeats);

  for (int i=0; i<repeats; i++){
    int randWord = random(1, 5);
    switch (randWord) {
      case 1:    
        Keyboard.print("Warning");
        break;
      case 2:    
        Keyboard.print("Error");
        break;
      case 3:    
        Keyboard.write('T');
        delay(300);
        Keyboard.write('A');
        delay(300);
        Keyboard.write('L');
        delay(300);
        break;
      case 4:    
        Keyboard.print("NULL");
        break;
      default:
        Keyboard.print("Default");   
      }
      
     executeDelay(1,10);
   }
}

void keyboardHoldKeyPrank(int repeats){
  Serial.println("keyboardHoldKey: "+repeats);
  
  char holdKey = KEY_LEFT_CTRL;
  
  for (int i=0; i<repeats; i++){
    int randKey = random(1, 3);
    switch (randKey) {
      case 1:
        Serial.println("Crtl");
        holdKey = KEY_LEFT_CTRL;
        break;
      case 2:
         Serial.println("Shift"); 
        holdKey = KEY_LEFT_SHIFT;
        break;      
      default:
        Keyboard.print("Default");   
      }
    
    Serial.println("Hold Key");  
    Keyboard.press(holdKey);
    delay(20*1000);
    Keyboard.releaseAll();
    Serial.println("Release Key"); 
      
    executeDelay(10,20);
   }
}

/////AUX
void startRandSeed(){
  randomSeed(analogRead(0)+analogRead(1));
}

void executeDelay(int minDelay, int maxDelay){
  long randomDelay = random(minDelay,maxDelay); //generate random number for delay
  long thisDelay = randomDelay * long (delayLevel);
  
  thisDelay = 10;//TEMP TODO:REMOVE
  
  Serial.print("Wating ");Serial.print(thisDelay);Serial.println(" seconds");
  delay(thisDelay*1000);
}

void jump(int howFar){
  int rand1= random(0, howFar);
  int rand2= random(howFar, howFar*2);  
  Mouse.move ( rand1 ,rand2);
  delay (2);
}

void jitter(int duration){
  int i = 0;
  while (i < duration){
    Mouse.move(10,10);
    delay (10);
    Mouse.move(-10, 0);
    delay (10);
    Mouse.move(10,-10);
    delay(10);
    Mouse.move (-10,0);
    delay (10);
    i++;
  } 
}

void mouseClick(){
  int randclick = random(1, 4);
  switch (randclick) {
    case 1:
      Serial.println("L Click");
        Mouse.press(MOUSE_LEFT);
        delay(100);
        Mouse.release(MOUSE_LEFT);
      break;
    case 2:
       Serial.println("DL Click");
        Mouse.press(MOUSE_LEFT);
        delay(100);
        Mouse.release(MOUSE_LEFT);
        delay(100);
        Mouse.press(MOUSE_LEFT);
        delay(100);
        Mouse.release(MOUSE_LEFT);
      break;     
    case 3:
       Serial.println("R Click");
       Mouse.press(MOUSE_RIGHT);
       delay(100);
       Mouse.release(MOUSE_RIGHT);
      break;  
    default:
      Keyboard.print("Default Click");   
   }
}
