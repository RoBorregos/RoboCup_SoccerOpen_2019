
void dondeGirar(int anguloDes){
  double equis;
  if (anguloDes > anguloActual()){
    equis = anguloDes - anguloActual();
    if(equis<180){
      mover(9);
    }
    else{
      mover(10);

    }
  }else{
    equis = anguloActual()-anguloDes;
    if (equis<180){
      mover(10);
      
    }else{
      mover(9);

    }
  }
}

int pidGiro(int objeto,int otro){



 anguloA=anguloActual();
 
    if (objeto = -1 ){
      anguloD = otro;
    }else{
      xPixy(objeto);
      double anguloD=angulo[objeto];

    }
    
    dondeGirar(anguloD);
    myPID.Compute();
    output = abs(output);
 

  /*  if ( abs(anguloA-anguloD) <10){
      return 0 ; 
    }
     */
     if (output<71){ //75
       output = 71;
     }

    Serial.print(output);
    Serial.print(" ");
    Serial.println(anguloA);
    
    analogWrite(pwm[0],output);
    analogWrite(pwm[1],output);
    analogWrite(pwm[2],output); 
    analogWrite(pwm[3],output);

return 0 ;
}
