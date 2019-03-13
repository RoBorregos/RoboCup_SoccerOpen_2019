

int readM1()
{
return analogRead(mhAna);
}
int readM2()
{
return analogRead(mvAna);
}


void changeAnalogM(){
     if(MC>7){MC=0;delay(200);}
    digitalWrite(H1, MH[MC][0]);
    digitalWrite(H2, MH[MC][1]);
    digitalWrite(H3, MH[MC][2]);
    digitalWrite(V1, MV[MC][0]);
    digitalWrite(V2, MV[MC][1]);
    digitalWrite(V3, MV[MC][2]);
    MC++;
}

void inicializar(){
    for(int i=0;i<8;i++){
      changeAnalogM();
      inicial1[i]=readM1();
      inicial2[i]=readM2();
      }
  }

int lineablanca(int tmp[],int x){
    
    for(int i=0;i<8;i++){
      changeAnalogM();
      if(x==1){
        if(readM1()-tmp[i]>90){
          if(i==4 || i==2 || i==6 || i==1)
          return 1;//frente
          else
          return 3;//derecha
        }else{
            if(readM2()-tmp[i]>90){
          if(i==4 || i==2 || i==6 || i==1)
          return 4;//="IZQUIERDA";
          else
          return 2;//tmp1="ATRAS";  
          
          }
         }
  
        }
      }
      return 0;
    }
 
