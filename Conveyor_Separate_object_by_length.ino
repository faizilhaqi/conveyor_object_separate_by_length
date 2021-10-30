int sensbaca1,sensbaca2;
bool sens1,sens2;
float waktu1,waktu2,panjang,kecepatan;
bool waktu1_on,waktu2_on;
long count1,count2;


//set servo--------------------------
#include <Servo.h>
Servo servo1;
Servo servo2;
//-----------------------------------

const float jarak=100; //---------jarak kedua sensor dalam milimeter

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
servo1.attach(9);
servo2.attach(10);
}
//-----------------------------------

void loop() { 
  
//---------- set nilai baca sens1 dan sens2----------
sensbaca1=analogRead(A0);//membaca nilai sens1 dalam analog
sensbaca2=analogRead(A1);//membaca nilai sens2 dalam analog
Serial.print("s1= ");Serial.print(sensbaca1);
Serial.print(" s2= ");Serial.print(sensbaca2);
if (sensbaca1>600){
sens1=true;
}else{
sens1=false;  
}
if (sensbaca2>500){
sens2=true;
}else{
sens2=false;  
}

//---------------------------------------------------
//---------------------------------------------------

Serial.print(" c1= "),Serial.print(count1);
Serial.print(" c2= "),Serial.print(count2);
Serial.print(" sens1= ");Serial.print(sens1);
Serial.print(" sens2= ");Serial.print(sens2);

//-----------waktu baca kecepatan---------------
//----------------------------------------------
  if (sens1==true){
    if(waktu1_on==false){
      waktu1_on=true;
    }
  }
  
  if (sens2==true){
    if (waktu1_on==true){
      waktu1_on=false;
      }
  }
    
  if (waktu1_on==true){
    count1++;
    }
  if (waktu1_on==false){
    if(count1!=0){
      waktu1= count1;//----------ambil waktu kecepatan dalam milisecond
    }
    count1=0; 
    }
//-----------waktu baca panjang------------------
//-----------------------------------------------

if (sens1==true){
  waktu2_on=true;
  }else{
    waktu2_on=false;
  }

  if(waktu2_on==true){
    count2++;
  }else{
      if(count2!=0){
        waktu2 = float(count2)/1000;  //-------ambil waktu panjang second
      }count2=0;
  }

//-------mendapatkan nilai waktu1-----------------
//------------------------------------------------
 Serial.print(" waktu= ");Serial.print(waktu1);
//------------------------------------------------

 //mendapatkan nilai kecepatan
 kecepatan = jarak/waktu1;
 Serial.print(" v= ");Serial.print(kecepatan);//----kecepatan dalam m/s
 
//-----------------------------------------------
//-------------get panjang-----------------------

//mendapatkan nilai waktu2
 Serial.print(" t= ");Serial.print(waktu2);
 
//mendapatkan nilai panjang
 panjang = kecepatan*waktu2;//----panjang dalam meter
 Serial.print(" p= ");Serial.println(panjang);
 delay(1);

 //kondisi seleksi object------------------------
 //kondisi 1
 if(panjang<0.05){
  servo1.write(180);
  servo2.write(180);
 }else if(panjang<0.12){
  servo1.write(110);
  servo2.write(180);
 }else if(panjang<0.16){
  servo1.write(180);
  servo2.write(110);
 }else{
  servo1.write(180);
  servo2.write(180);  
 }
 //---------------------------------------------
 //---------------------------------------------
 
}
