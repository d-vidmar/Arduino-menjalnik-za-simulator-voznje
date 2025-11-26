#include "Joystick.h"

// Create Joystick
Joystick_ Joystick;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(13, INPUT_PULLUP);
  Joystick.begin();
}

void loop() {
  int v=analogRead(A0);
  int h=analogRead(A1);
  if(digitalRead(13)==LOW){ //tipka pri strani
    Joystick.setButton(7,true);
  }
  else{
    Joystick.setButton(7,false);
  }
  
  //spremeni vrednosti pogojev tako, da ustrezajo vrednostim "v" in "h" potenciometrov, ko je prestava v določenem položaju
  //vrednosti "v" in "h" za tvoj primer dobiš tako, da odpreš datoteko "menjalnik.ino" in slediš navodilom.
  if(v<460&&h<480){ //R |spremeni pogoj tako, da je izpolnjen, ko je prestava v R položaju; enako velja za druge prestave
    Joystick.setButton(6,true);
    for(int i=0; i<6; i++){
      Joystick.setButton(i,false);
    }
  }
  else if(v<460&&h>480&&h<525){//1
    Joystick.setButton(0,true);
    for(int i=1; i<7; i++){
      Joystick.setButton(i,false);
    }
  }
  else if(v>490&&h>480&&h<525){//2
    Joystick.setButton(1,true);
    for(int i=0; i<7; i++){
      if(i!=1){
        Joystick.setButton(i,false);
      }
    }
  }
  else if(v<460&&h>525&&h<575){//3
    Joystick.setButton(2,true);
    for(int i=0; i<7; i++){
      if(i!=2){
        Joystick.setButton(i,false);
      }
    }
  }
  else if(v>490&&h>525&&h<575){//4
    Joystick.setButton(3,true);
    for(int i=0; i<7; i++){
      if(i!=3){
        Joystick.setButton(i,false);
      }
    }
  }
  else if(v<460&&h>575){//5
    Joystick.setButton(4,true);
    for(int i=0; i<7; i++){
      if(i!=4){
        Joystick.setButton(i,false);
      }
    }
  }
  else if(v>490&&h>575){//6
    Joystick.setButton(5,true);
    for(int i=0; i<7; i++){
      if(i!=5){
        Joystick.setButton(i,false);
      }
    }
  }
  else{ //N
    for(int i=0; i<7; i++){
      Joystick.setButton(i,false);
    }
  }

  delay(50);

}
