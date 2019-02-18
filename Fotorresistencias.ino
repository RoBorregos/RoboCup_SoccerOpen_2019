
void changeAnalog()
{
  for(int i=0;i<3;i++){
  digitalWrite(mhDig[i], mH[mc][i]);
  }
    for(int i=0;i<3;i++){
  digitalWrite(mvDig[i], mV[mc][i]);
  }
  
mc++;
if(mc==8)
mc=0;
}


int readM1()
{
return analogRead(mhAna);
}
int readM2()
{
return analogRead(mvAna);
}

bool lineaBlanca(){
changeAnalog();
if(readM1()<variableLinea || readM2()<variableLinea)
return false;
else
return true;
}

void meterse(){
  int direccionOpuesta=0;
if(dir!=-1)
{
  if(dir%2==0)
  direccionOpuesta=dir-1;
  else
 direccionOpuesta=dir+1;
}
mover(direccionOpuesta);
}
