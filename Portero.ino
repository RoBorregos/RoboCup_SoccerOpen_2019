int atacar=2; //2=amarilla, 3=azul
#include <PID_v1.h>
#include <Wire.h> 
#include <Pixy2.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2); 
Pixy2 pixy;

//PID
double anguloA,output,anguloD;

double Kp=0.9,Ki=0.05,Kd=0; // 0.05 0.009
PID myPID(&anguloA, &output, &anguloD, Kp, Ki, Kd, DIRECT);
bool pidB=true;

//ULTRASONICOS
int ultraT[4]={24,27,23,28}; 
int ultraE[4]={26,25,22,29}; 
int tiempo[4];
int distancia[4];
boolean salida; 
   int as = 0;

//MULTIPLEXORES

int MC=0;
int IV[]={38,40,42,44,46,48,50,52};
int IH[]={37,39,41,43,45,47,49,51};
byte MH[8][3]={{LOW,LOW,LOW},{HIGH,LOW,LOW},{LOW,HIGH,LOW},{HIGH,HIGH,LOW},{LOW,LOW,HIGH},{LOW,LOW,LOW},{LOW,HIGH,HIGH},{HIGH,HIGH,HIGH}};
byte MV[8][3]={{LOW,LOW,LOW},{HIGH,LOW,LOW},{LOW,HIGH,LOW},{HIGH,HIGH,LOW},{LOW,LOW,HIGH},{HIGH,LOW,HIGH},{LOW,HIGH,HIGH},{HIGH,HIGH,HIGH}};
int H1=32,H2=34,H3=36,HA=2,V1=35,V2=33,V3=31,VA=15;
int inicial1[8];
int inicial2[8];
bool fotoresistencias[]={0,0,0,0};

//FOTORRESISTENCIAS MULTIPLEXOR
int mhDig[3]= {35,33,31}; 
int mvDig[3]= {32,34,36};
int mhAna=15;
int mvAna=2;

//PIXY


boolean tienesPelota =false;
int rangoI;
int rangoD;
double ultimaD[4]={};
int angulo[4]={};
int x[4]={};
int y[4]={};
int ancho[4]={};
int altura[4]={};
int ultimaX[4]={};
int ultimaY[4]={0,100};
int ultimaAltura[4]={};
int ultimoAncho[4]={};

double d[4];
//BOTONES
int boton1=29;
int boton2=2;

//CNY 70
int CNY = 0;

//MOTORES
int motores[8] = {9, 10, 13, 11, 3, 19, 17, 18};
/*
 Frente Izq delante 
 Frente der delante
 Atras Derecha Atras
 atras Izq
 */
int pwm[4] = {8, 6, 5, 12};

//DRIBBLER
int dribbler[2]={16,30}; //+,-
int dribblerpwm =10;

//BNO
Adafruit_BNO055 bno = Adafruit_BNO055(55);

//SER DELANTERO
int tiempoActual = 0;
int ultimoTiempo = 0;


//Declaracion del BNO

void setup(){

  delay(1000);
  inicializar();

  Serial.begin(9600);
  
//LCD
  lcd.init();
  lcd.backlight();

//PIXY
  pixy.init();
  
//BNO 
  bno.begin();
  bno.setExtCrystalUse(true);

//MOTORES
  for(int i = 0; i < 8; i++){
    pinMode(motores[i], OUTPUT);
  }

  for(int i = 0; i < 4; i++){
    pinMode(pwm[i], OUTPUT);
  }
  
  
//PWM
  analogWrite(pwm[0], 120); // Frente Izq 165
  analogWrite(pwm[1], 120); //Atras derecha 175
  analogWrite(pwm[2],120);// Atras Izq 210
  analogWrite(pwm[3],120); //mas 20 Frente Der 230  

//SOLENOIDE
  pinMode(7,OUTPUT);
  digitalWrite(7,HIGH);

//PID
    myPID.SetMode(AUTOMATIC);
    myPID.SetOutputLimits(-200, 200);
    myPID.SetTunings(Kp, Ki, Kd);
    myPID.SetSampleTime(1);

//Ultrasoncios
    for(int i=0;i<=3;i++)
{
  Serial.println("hola");
  pinMode(ultraT[i],OUTPUT);
  pinMode(ultraE[i],INPUT);
}
//pinMode(52,OUTPUT);
//pinMode(53,OUTPUT);
//MUX
for (int i=0;i<3;i++){
  pinMode(mhDig[i], OUTPUT);
}
for (int i=0;i<3;i++){
  pinMode(mvDig[i], OUTPUT);
}


}
//2 amarilla
void loop(){
/*ultraI();
ultraD();
ultraAI();
ultraAD();
*/
xPixy(atacar);
int neu;
int deseado;
if(anguloActual()>180)
{
  deseado=anguloActual()+angulo[atacar];
  deseado=deseado%360;
}
else 
{
  deseado=anguloActual()-angulo[atacar];
  if(deseado<0)
  deseado=360+deseado;
}
Serial.print("atacar");
Serial.println(angulo[atacar]);

Serial.print("actual");
Serial.println(anguloActual());

Serial.print("deseado");
Serial.println(deseado);
if(deseado-10<=0)
{
   neu=360+deseado-10;
}
else 
neu=deseado-10;

  if(!(anguloActual()>neu || anguloActual()<(deseado+10)%360))
{
analogWrite(pwm[0], 80); // Frente Izq 165
  analogWrite(pwm[1], 80); //Atras derecha 175
  analogWrite(pwm[2],80);// Atras Izq 210
  analogWrite(pwm[3],80); //mas 20 Frente Der 230  

dondeGirar(deseado);
lcd.setCursor(8,1);
lcd.print(deseado);
}
else
mover(11);
}
