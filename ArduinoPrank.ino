/*
Keyboard and mouse Prank using Arduino Leonardo
 */
 
// Configs
const int delayLevel = 5; //1-10


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
  
  int randPrank = random(3, 4);//TEMP TODO:FIX
  switch (randPrank) {
    case 1:    
      mouseClickPrank(3);
      break;
    case 2:    
      mouseJumpPrank(3,100, 50);
      break;
    case 3:    
      mouseWheelPrank(3);
      break;
    case 4:    
      mouseJitterPrank(3,10);
      break;
    case 5:    
      keyboardTypePrank(3);
      break;
    case 6:    
      keyboardHoldKeyPrank(3);
      break;
    default:
      Serial.print("Default Prank");
    } 
}


//////Pranks
void mouseClickPrank(int repeats){
  Serial.print("Click: "); Serial.println(repeats);
  
  for (int i=0; i<repeats; i++){
    mouseClick();    
    executeDelay(5,10);
  }
}

void mouseJumpPrank(int repeats, int distance, int chanceToClick){
  Serial.print("Jump: "); Serial.println(repeats);
  
  for (int i=0; i<repeats; i++){
   jump(distance);
   delay(200);
   jump(distance); 

   int randClick = random(0,100);
   if ( randClick < chanceToClick){
     mouseClick(); 
   }
   
   executeDelay(5,10);
  }
}

void mouseJitterPrank(int repeats, int duration){
  Serial.print("Jitter: "); Serial.println(repeats);
  
  for (int i=0; i<repeats; i++){
    jitter(duration);    
    executeDelay(1,10);
  }
}

void mouseWheelPrank(int repeats){
  Serial.print("Wheel: "); Serial.println(repeats);
  
  for (int i=0; i<repeats; i++){
    moveWheel();    
    executeDelay(5,10);
  }
}

void keyboardTypePrank(int repeats){
  Serial.println("keyboardType: "); Serial.println(repeats);

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
  Serial.println("keyboardHoldKey: "); Serial.println(repeats);
  
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
  Serial.println("Jump");
  
  int rand1= random(0, howFar);
  int rand2= random(howFar, (howFar*2));  
  Mouse.move ( rand1 ,rand2, 0);
  delay (2);
}

void moveWheel(){
  Mouse.move ( 0 ,0, -20);
  delay (150);
  Mouse.move ( 0 ,0, 20);
  delay (150);
  Mouse.move ( 0 ,0, -50);
  
  Mouse.click();
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
        Mouse.click();
      break;
    case 2:
       Serial.println("DL Click");
        Mouse.click();
        delay(100);
        Mouse.click();
      break;     
    case 3:
       Serial.println("R Click");
       Mouse.click(MOUSE_RIGHT);      
      break;  
    default:
      Keyboard.print("Default Click");   
   }
}
