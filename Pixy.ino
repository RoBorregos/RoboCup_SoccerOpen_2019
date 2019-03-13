
void xPixy(int obj){

  pixy.ccc.getBlocks();
   int j = -1;
   if (pixy.ccc.numBlocks) {
    for(int i=0;i<pixy.ccc.numBlocks;i++) {
       if(int(pixy.ccc.blocks[i].m_signature)==obj){
       j=i;
      }
    }
    
   switch(j){

    case -1:
    x[obj] = -1;
    altura[obj] = -1;
    ancho[obj] = -1;
    y[obj] = -1;
    
    return x;

    case 0: 
    //Serial.print("Caso 0 - Mayor ÁREA");
     x[obj]= int(pixy.ccc.blocks[j].m_x);
     y[obj]= int(pixy.ccc.blocks[j].m_y);
     altura[obj]= int(pixy.ccc.blocks[j].m_height);
     ancho[obj]= int(pixy.ccc.blocks[j].m_width);
    
    break;

    case 1:
    // Serial.print("Caso 1 - AREA MEDIA ");
    
    x[obj]= int(pixy.ccc.blocks[j].m_x);
     y[obj]= int(pixy.ccc.blocks[j].m_y);
     altura[obj]= int(pixy.ccc.blocks[j].m_height);
     ancho[obj]= int(pixy.ccc.blocks[j].m_width);
     
    

    break; 

    case 2:
    //
    x[obj]= int(pixy.ccc.blocks[j].m_x);
     y[obj]= int(pixy.ccc.blocks[j].m_y);
     altura[obj]= int(pixy.ccc.blocks[j].m_height);
     ancho[obj]= int(pixy.ccc.blocks[j].m_width);
    
 
    break;
  }
  switch (obj){
    case 1:
      d[obj] = 1449 / ancho[obj];
      if(d[obj]>=8){
      ultimaD[obj] = d[obj];
      }else
      d[obj] = -1;
    break;
    case 2: 
    d[obj] = 3000/altura[obj];
    break;
    case 3:
    d[obj] = 3000/ altura[obj];
  }

      
     ultimaX[obj] = x[obj];
     ultimaAltura[obj] = altura[obj];
     ultimoAncho[obj] = ancho[obj];
          ultimaY[obj] = y[4];

angulo[obj] = abs(158-x[obj])*30/158;

}
    if(angulo==360)
    angulo==0;
    
   }else{
    x[obj]= -1;
     y[obj]= -1;
     altura[obj]= -1;
     ancho[obj]= -1;
    return ;
   }
 return;
   
}
