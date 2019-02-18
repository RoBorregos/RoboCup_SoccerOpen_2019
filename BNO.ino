
//falta ver cuando da 0 el bno si es apuntando al azul o al amarillo
/**
 En tal caso habría que hacer algo así
 int ajuste;
 if(amarillo)
 {
 if(angulo>180)
 ajuste=-180;
 else
 ajuste=180;
 }
 else
 ajuste=0;
 
 */
int anguloActual(){
  int angulo = 0;
  sensors_event_t event; 
  bno.getEvent(&event);
  angulo = ajuste + event.orientation.x;
  return angulo;
}

void dondeGirar(){
  if (anguloPelota() > anguloActual()){
    x = anguloPelota() - anguloActual();
    if(x<180){
      girarDer();
    }
    else{
      girarIzq();
    }
  }else{
    x = anguloActual()-anguloPelota();
    if (x<180){
      girarIzq();
    }else{
      girarDer();
    }
  }
}
