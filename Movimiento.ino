void mover(int direccion) 
{
  switch (direccion)
  {
    case 1: //hacia el frente
    for(int i = 0; i < 8; i++){
        if(i==0 || i==2 || i==5 || i==7)
          digitalWrite(motores[i], HIGH);
        else
          digitalWrite(motores[i], LOW);         
}
    break;
    case 2: //hacia atrás
    for(int i = 0; i < 8; i++){
        if(i==0 || i==2 || i==5 || i==7)
          digitalWrite(motores[i], LOW);
        else
          digitalWrite(motores[i], HIGH);         
}
    break;
        case 3: //hacia la derecha
    for(int i = 0; i < 8; i++){
        if(i ==0||i==3||i==5||i==6)
          digitalWrite(motores[i], HIGH);
        else
          digitalWrite(motores[i], LOW);         
}
    break;
        case 4: //hacia la izquierda
    for(int i = 0; i < 8; i++){
        if(i ==0||i==3||i==5||i==6)
          digitalWrite(motores[i], LOW);
        else
          digitalWrite(motores[i], HIGH);         
}
    break;
        case 5: //diagonal derecha hacia atras
    for(int i = 0; i < 8; i++){
        if(i==3||i==6)
          digitalWrite(motores[i], HIGH);
        else
          digitalWrite(motores[i], LOW);         
}
    break;
        case 6: //diagonal izquierda hacia delante
    for(int i = 0; i < 8; i++){
        if(i==2||i==7)
          digitalWrite(motores[i], HIGH);
        else
          digitalWrite(motores[i], LOW);         
}
    break;
            case 7: //diagonal derecha hacia delante
    for(int i = 0; i < 8; i++){
        if(i==0||i==5)
          digitalWrite(motores[i], HIGH);
        else
          digitalWrite(motores[i], LOW);         
}
    break;
            case 8: //diagonal izquierda hacia atras
    for(int i = 0; i < 8; i++){
        if(i==1||i==4)
          digitalWrite(motores[i], HIGH);
        else
          digitalWrite(motores[i], LOW);         
}
    break;

            case 9: //Girar Derecha
     for(int i = 0; i<8;i++){
      if (i ==0||i==3||i==4||i==7)
       digitalWrite(motores[i],HIGH);
       else
       digitalWrite(motores[i],LOW);
     }
     break;
             case 10: //Girar izq
     for(int i = 0; i<8;i++){
      if (i ==0||i==3||i==4||i==7)
       digitalWrite(motores[i],LOW);
       else
       digitalWrite(motores[i],HIGH);
     }
     break;

           case 11: //Detener
     for(int i = 0; i<8;i++){
       digitalWrite(motores[i],LOW);
     }
     break;
}

  }
