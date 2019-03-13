//0 izquierda, 1 derecha, 2atraz izquierda, 3 atras derecha
void ultraI (){
   digitalWrite(ultraT[0], LOW);
  delayMicroseconds(2);
  digitalWrite(ultraT[0], HIGH);
   delayMicroseconds(10);
  digitalWrite(ultraT[0], LOW);
  tiempo[0] = pulseIn(ultraE[0], HIGH);
  distancia[0] = tiempo[0] / 58;
  if (distancia [0]<0 || distancia[0]>200){
    distancia[0] = 0;
  }
  
  lcd.setCursor(8,0);
  lcd.print(distancia[0]);
 // Serial.print(distancia[0]);
  
  // Serial.println(distancia[0]);
}

void  ultraD (){
   digitalWrite(ultraT[1], LOW);
  delayMicroseconds(2);
  digitalWrite(ultraT[1], HIGH);
   delayMicroseconds(10);
  digitalWrite(ultraT[1], LOW);
  tiempo[1] = pulseIn(ultraE[1], HIGH);
  distancia[1] = tiempo[1] / 58;
  if (distancia [1]<0 || distancia[1]>200){
    distancia[1] = 0;
  }
    lcd.setCursor(8,1);
  lcd.print(distancia[1]);
  
 // Serial.println(distancia[1]);

}

void ultraAI (){
   digitalWrite(ultraT[2], LOW);
  delayMicroseconds(2);
  digitalWrite(ultraT[2], HIGH);
   delayMicroseconds(10);
  digitalWrite(ultraT[2], LOW);
  tiempo[2] = pulseIn(ultraE[2], HIGH);
  distancia[2] = tiempo[2] / 58;
  if (distancia [2]<0 || distancia[2]>200){
    distancia[2] = 0;
  }
  
  lcd.setCursor(11,1);
  lcd.print(distancia[2]);
  Serial.print(distancia[2]);
  
  // Serial.println(distancia[0]);
}

void ultraAD (){
   digitalWrite(ultraT[3], LOW);
  delayMicroseconds(2);
  digitalWrite(ultraT[3], HIGH);
   delayMicroseconds(10);
  digitalWrite(ultraT[3], LOW);
  tiempo[3] = pulseIn(ultraE[3], HIGH);
  distancia[3] = tiempo[3] / 58;
  if (distancia [3]<0 || distancia[3]>200){
    distancia[3] = 0;
  }
  
  lcd.setCursor(11,0);
  lcd.print(distancia[3]);
  Serial.print(distancia[3]);
  
  // Serial.println(distancia[0]);
}



void ultrasonicosGeneral(){
  //SALIO POR IZQ
  if (distancia[0]>25 && distancia [1]<25){
    salida = false; 
  }
  //SALIO POR DERECHA
  else if (distancia[0]<25 && distancia[1]>25){
    salida = true;
  }
}

void acomodarse(){
    //MOVER DERECHA 
    
  if (distancia[0]>25 && distancia [1]>25){
    if (salida == true){
      mover(4);
    }else{
      mover(3);
    }
  }else{
    mover(11);
  }
  
}
