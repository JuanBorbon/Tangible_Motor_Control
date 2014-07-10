import processing.serial.*;
Serial myPort;

void setup (){
  println(Serial.list());
  myPort = new Serial(this, Serial.list() [0], 9600); // the number in the [] brackets may change. change it to 1 if 0 doesn't work
}


void draw(){ // Reads the keyboard input and sends the corresponding value to the arduino
  if (keyPressed){
    if (key == 'w' || key == 'W'){
      myPort.write(119);
    }
    if (key == 's' || key == 'S'){
      myPort.clear();
      myPort.write(115);
    }
    if (key == 'a' || key == 'A'){
      myPort.write(97);
    }
    if (key == 'd' || key == 'D'){
      myPort.write(100);
    }
    if (key == 'f' || key == 'F'){
      myPort.write(50);
    }

  }   
  myPort.clear();

}
