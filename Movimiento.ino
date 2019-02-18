//anguloPelota() funciona con respecto al robot
//si es asi el robot intenta llegar de frente a la pelota para usar dribbler/kicker

double dif= anguloAcual()-anguloPelota();
void perseguirPelota(){
  if ((anguloPelota()<=85 && anguloPelota()>=0) || (anguloPelota()>=275 && anguloPelota<=360))
  {
  if(dif<3 && dif>-3)
  {
   dir=1;
  }
  else
  {
    if(anguloPelota()>3 && anguloPelota()<40)
    {
      dir=7;
    }
    else if (anguloPelota()>40 && anguloPelota()<85)
    {
      dir=3
    }
    else if (anguloPelota()<358 && anguloPelota()>320)
    {
      dir=6;
    }
    else if(anguloPelota()<320 && anguloPelota()>275)
    {
      dir=4;
    }
  }
  mover(dir);
}
else
{
  dondeGirar();
}

}
/**
 1: Hacia el Frente
 2: Atrás
 3: Derecha
 4: Izquierda
 5: diagonal derecha hacia atras
 6: diagonal izquierda hacia delante
 7: diagonal derecha hacia delante
 8: diagonal izquierda hacia atrás
*/
void mover(int direccion) 
{
  switch (direccion)
  {
    case 1: //hacia el frente
    for(int i = 0; i < 8; i++){
        if(i % 2 == 0)
          digitalWrite(motores[i], HIGH);
        else
          digitalWrite(motores[i], LOW);         
}
    break;
    case 2: //hacia atrás
    for(int i = 0; i < 8; i++){
        if(i % 2 == 0)
          digitalWrite(motores[i], LOW);
        else
          digitalWrite(motores[i], HIGH);         
}
    break;
        case 3: //hacia la derecha
    for(int i = 0; i < 8; i++){
        if(i ==0||i==3||i==4||i==7)
          digitalWrite(motores[i], HIGH);
        else
          digitalWrite(motores[i], LOW);         
}
    break;
        case 4: //hacia la izquierda
    for(int i = 0; i < 8; i++){
        if(i ==0||i==3||i==4||i==7)
          digitalWrite(motores[i], LOW);
        else
          digitalWrite(motores[i], HIGH);         
}
    break;
        case 5: //diagonal derecha hacia atras
    for(int i = 0; i < 8; i++){
        if(i==3||i==7)
          digitalWrite(motores[i], HIGH);
        else
          digitalWrite(motores[i], LOW);         
}
    break;
        case 6: //diagonal izquierda hacia delante
    for(int i = 0; i < 8; i++){
        if(i==2||i==6)
          digitalWrite(motores[i], HIGH);
        else
          digitalWrite(motores[i], LOW);         
}
    break;
            case 7: //diagonal derecha hacia delante
    for(int i = 0; i < 8; i++){
        if(i==0||i==4)
          digitalWrite(motores[i], HIGH);
        else
          digitalWrite(motores[i], LOW);         
}
    break;
            case 8: //diagonal izquierda hacia atras
    for(int i = 0; i < 8; i++){
        if(i==1||i==5)
          digitalWrite(motores[i], HIGH);
        else
          digitalWrite(motores[i], LOW);         
}
    break;
}

  }
void girarDer()
{
      for(int i = 0; i < 8; i++){
        if(i==7||i==5 || i==2 || i==0)
          digitalWrite(motores[i], HIGH);
        else
          digitalWrite(motores[i], LOW);         
}
}
void girarIzq()
{
      for(int i = 0; i < 8; i++){
        if(i==7||i==5 || i==2 || i==0)
          digitalWrite(motores[i], LOW);
        else
          digitalWrite(motores[i], HIGH);         
}
}
