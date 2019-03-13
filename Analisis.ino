void portero1 () {
//  ultraI();
  ultraD();
  ultraAI();
  ultraAD();
  analogWrite(pwm[0], 165); // Frente Der 165
  analogWrite(pwm[1], 175); //Atras derecha 175
  analogWrite(pwm[2], 210);// Atras Izq 210
  analogWrite(pwm[3],230); //mas 20 Frente Der 230  
  
  ultrasonicosGeneral();
  
  xPixy(1);
 
 // acomodarse();
 
//DENTRO DE PORTERIA
if (distancia[0]<25 && distancia[1]<25){
  //VEO PELOTA
  if (x[1] != -1 ){
    lcd.setCursor(12,0);
    lcd.print("VEOP");
    if (x[1]<110 && x[1]>0){
         lcd.setCursor(12,0);
         lcd.print("VEOD");
         mover(3);
    }else if (x[1]<316 && x[1]>200){
      lcd.setCursor(12,0);
      lcd.print("VEOI");
      mover(4); 
    }else if (x[1]>= 110 && x[1]<=200){
      mover(11);
    }
    //NO VES PELOTA
  }else{
    mover(11);
  }
  //FUERA DE PORTERIA
}else{

//TODO FUERA
  if (distancia[0]>25 && distancia[1]>25){
    acomodarse();
    //PARTE IZQ FUERA
  } else if (distancia[0]>25 && distancia[1]<25  ){
    if (x[1]<130 && x[1]>0){
      mover(3);
    }else{
      mover(11);
    }
   
    }
    //PARTE DERECHA FUERA
    else if (distancia[0]<25 && distancia[1]>25){
      if (x[1]>200 && x[1]<316){
        mover(4);
      }else{
      mover(11);
      }
    }
}

if(distancia[0]<7 && distancia[1]<7){
  mover(1);
  delay(50); 
}


 //DENTRO DE PORTERIA 
if(distancia[0]<20 && distancia[1]<20)
  {
  if(x[1]<=115 && x[1]>0 && distancia[1]<20){
     mover(3); 
  }

  else if(x[1]>=200 && x[1]<=316 && distancia[0]<20){
  mover (4);
  }
  //FUERA DE PORTERIA
  else {
    //Esquina lado izq fuera
    if (distancia[0]>20 && distancia[1]<20){
      
    }
  mover(11); 
  }

}
/*
//VES PELOTA
if (x != -1 ){
  lcd.setCursor(12,0);
  lcd.print("VEOP");
  //PELOTA ESTA EN DERECHA
  if (x<120 && x>0  && distancia[1]<20){
    lcd.setCursor(12,0);
  lcd.print("VEOD");
    mover(3);
    //PELOTA ESTA EN IZQUIERDA
  }else if (x<316 && x>190  && distancia[0]<20){
    lcd.setCursor(12,0);
  lcd.print("VEOI");
    mover(4); 
  }else if (x>= 120 && x<=190 && distancia[0]<20 && distancia[1]<20){
    mover(11);
  }

}
//NO VES PELOTA
else{
  lcd.setCursor(12,0);
  lcd.print("NVE");
   acomodarse();
}
*/
}
