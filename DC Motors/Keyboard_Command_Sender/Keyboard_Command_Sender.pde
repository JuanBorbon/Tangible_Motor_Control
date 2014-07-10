import processing.serial.*;
Serial myPort;

void setup (){
  println(Serial.list());
  myPort = new Serial(this, Serial.list() [0], 9600); // the number in the [] brackets may change

}


void draw(){ // Reads the keyboard input and sends the corresponding value to the arduino
  if (keyPressed){

    if (key == 'A' || key == 'a'){
      myPort.write(3);
    }
    if (key == 'W' || key == 'w'){
      myPort.write(1);
    }
    if (key == 's' || key == 'S'){
      myPort.write(2);
    }

    if (key == 'd' || key == 'D'){
      myPort.write(3);
    }

    if (key == CODED){
      if (keyCode == UP){
        myPort.write(5);
      }
      else if (keyCode == DOWN){
        myPort.write(6);
      }
      else if (keyCode == LEFT){
        myPort.write(7);
      }
      else {
        myPort.write(8);
      }
    }
}
  myPort.clear();

}
