  string message;
  void verMensaje (){
    
if(Serial3.available() > 0){ // Checks whether data is comming from the serial port
    message = Serial3.read(); // Reads the data from the serial port
 }
  }
