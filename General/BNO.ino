
int anguloActual(){
  int angulo = 0;
  sensors_event_t event; 
  bno.getEvent(&event);
  angulo = event.orientation.x;
  return angulo;
}
