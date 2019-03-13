
void perseguirPelota(){

  analogWrite(pwm[0], 200); // Frente Der 165
  analogWrite(pwm[1], 188); //Atras derecha 175
  analogWrite(pwm[2], 200);// Atras Izq 210
  analogWrite(pwm[3],188); //mas 20 Frente Der 230  

  //Coordenada X pelota
  xPixy(1);
  xPixy(2);
  lcd.setCursor(12,0);
  lcd.print(d[1]);


  rangos();
  //LCD
  lcd.setCursor(0,0);
  lcd.print(x[1]);


  
//VE PELOTA 
if(x[1]!=-1) {
  
      //ESTA A SU DERECHA
     if (x[1]<rangoD && x[1]>=0){
      
      //SI DISTANCIA ES CORTA SE MUEVE DERECHA
      if(d[1]<=30 && d[1]!=-1){
        mover(3);
        lcd.setCursor(0,1);
        lcd.print("derecha");
      }
      //SI ESTA LEJOS DIAGONAL DERECHA
      else if(d[1]>30){
        mover(7);
        lcd.setCursor(0,1);
        lcd.print("diagonalD");
      }
      //SI ESTA EN SU IZQUIERDA
      }else if (x[1]>rangoI && x[1]<=316){
      //SI DISTANCIA CORTA SE VA IZQ
        if(d[1]<=30 && d[1]!=-1){
   
          mover(4);
          lcd.setCursor(0,1);
          lcd.print("izquierda");
        }
        
      // SI LEJOS SE VA EN DIAGONAL IZQ
      else if(d[1]>30) {
        mover(6);
      
      lcd.setCursor(0,1);
      lcd.print("diagonalI");
      }
    }else if (x[1]<rangoI && x[1]>=rangoD) {
  
      mover(1);
      // patear();
      
      lcd.setCursor(0,1);
      lcd.print("Frente");
    }
    }
    //NO VE PELOTA 
    else if (x[1] == -1 ){
      if (ultimaY[1] <25){
         tienesPelota = true;
         mover(1);
         lcd.setCursor(0,1);
         lcd.print("FirmalaGio");
      }
      else if (ultimaY[1] >= 25){
        mover(2);
        tienesPelota = false;
        lcd.setCursor(0,1);
        lcd.print("Regresando");
        //alinearte al centro?
      }
      
    }
 
}




//PROXIMO CODIGO
/*
else if (p == -1){
  if (CNY>50){
    tienesPelota = true;
    mover(1);
    lcd.setCursor(0,1);
    lcd.print("Metegol");
  }else{
    mover(2);
        tienesPelota = false;
        lcd.setCursor(0,1);
        lcd.print("Regresando");
  }
}
*/

 void rangos(){
  if (d[1]== -1){
    rangoI = 231;
    rangoD = 85;
  }else{
  rangoD = 0.3952*d[1] + 84.624;
  rangoI = -0.3952*d[1] + 231.38;

  }
 }
