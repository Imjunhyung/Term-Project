#include <Adafruit_NeoPixel.h>

#define pin1 5 // 네오픽셀 Out을 연결한 핀 번호
#define pin2 6
#define pin3 9
#define pin4 10
#define pin5 11

#define time1 700
#define time2 900
#define time3 1300
#define NUMPIXELS 18

int trig=2;
int echo=4;
Adafruit_NeoPixel pix1(18, pin1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pix2(18, pin2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pix3(NUMPIXELS, pin3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pix4(NUMPIXELS, pin4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pix5(NUMPIXELS, pin5, NEO_GRB + NEO_KHZ800);


void setup() 
{
        pix1.begin(); // 네오픽셀을 활성화
        pix1.show();  // 네오픽셀 소자가 빛을 보여주도록 설정하는 함수
        pix2.begin();
        pix2.show();
        pix3.begin();
        pix3.show();
        pix4.begin();
        pix4.show();
        pix5.begin();
        pix5.show();
        pinMode(trig,OUTPUT);
        pinMode(echo,INPUT);
}

//pix_1의 n0부터n1을 br밝기, rgb 설정
void pix11(int n0,int n1,int br,int r,int g,int b)
{
  for(int k=n0;k<=n1;k++)
  {
    pix1.setBrightness(br);
    pix1.setPixelColor(k,r,g,b);
  }
  return;
}

void pix22(int n0,int n1,int br,int r,int g,int b)
{
  for(int k=n0;k<=n1;k++)
  {
    pix2.setBrightness(br);
    pix2.setPixelColor(k,r,g,b);
  }
  return;
}

void pix33(int n0,int n1,int br,int r,int g,int b)
{
  for(int k=n0;k<=n1;k++)
  {
    pix3.setBrightness(br);
    pix3.setPixelColor(k,r,g,b);
  }
  return;
}

void pix44(int n0,int n1,int br,int r,int g,int b)
{
  for(int k=n0;k<=n1;k++)
  {
    pix4.setBrightness(br);
    pix4.setPixelColor(k,r,g,b);
  }
  return;
}

void pix55(int n0,int n1,int br,int r,int g,int b)
{
  for(int k=n0;k<=n1;k++)
  {
    pix5.setBrightness(br);
    pix5.setPixelColor(k,r,g,b);
  }
  return;
}

void off1()
{
  pix1.clear();
  pix1.show();
  return;
}

void off2()
{
  pix2.clear();
  pix2.show();
  return;
}


void off3()
{
  pix3.clear();
  pix3.show();
  return;
}

void off4()
{
  pix4.clear();
  pix4.show();
  return;
}

void off5()
{
  pix5.clear();
  pix5.show();
  return;
}

//갈색pix22(0,17,50,200,50,19);
//연두색pix22(0,17,50,0,255,0);
void loop()
{
  for(int k=0;k<=4;k++)
  {
    long dur, dist;
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    dur=pulseIn(echo,HIGH);
    dist=dur/58;

    if(dist<=10)
    {
      pix33(0,k,17,0,255,0);
      pix3.show();
      delay(time1);
    }
    else
    {
      if(k==0)
      {
        k=0;
      }
      else
      {
        k--;
      }
    }
  }
  for(int k=4;k<=5;k++)
  {
    long dur, dist;
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    dur=pulseIn(echo,HIGH);
    dist=dur/58;

    if(dist<=10)
    {
      pix22(4,k,17,0,255,0);
      pix44(4,k,17,0,255,0);
      pix2.show();
      pix4.show();
      delay(time1);
    }
    else
    {
      if(k==4)
      {
        k=4;
      }
      else
      {
        k--;
      }
    }
  }

  for(int k=5;k<=6;k++)
  {
    long dur, dist;
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    dur=pulseIn(echo,HIGH);
    dist=dur/58;

    if(dist<=10)
    {
      pix11(5,k,17,0,255,0);
      pix55(5,k,17,0,255,0);
      pix1.show();
      pix5.show();
      delay(time1);
    }
    else
    {
      if(k==5)
      {
        k=5;
      }
      else
      {
        k--;
      }
    }
  }
  //pix11(5,6,17,0,255,0);
  //pix55(5,6,17,0,255,0);
  //pix1.show();
  //pix5.show();
  delay(100);
  
//새싹끝-----------------------------

  int i;
  i=0;
  while(i<10)
  {
    long dur, dist;
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    dur=pulseIn(echo,HIGH);
    dist=dur/58;
    if(dist<=10)
    {
      off1();
      off2();
      off3();
      off4();
      off5();
      i=100;
    }
    else
   {
      i=0;
    }
  }
  
  for(int k=0;k<=5;k++)
  {
    long dur, dist;
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    dur=pulseIn(echo,HIGH);
    dist=dur/58;

    if(dist<=10)
    {
      pix33(0,k,17,190,50,20);
      pix3.show();
      delay(time1);
    }
    else
    {
      if(k==0)
      {
        k=0;
      }
      else
      {
        k--;
      }
    }
  }
  
  

//나뭇닢 생성-------------------------
  for(int k=5;k<6;k++){
  long dur,dist;
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  dur=pulseIn(echo,HIGH);
  dist=dur/58;
  if(dist<=10){
  pix33(k,k,17,0,255,0);
  pix3.show();
  delay(time3);}
  else
    {
      if(k==5)
      {
        k=5;
      }
      else
      {
        k--;
      }
    }}
  for(int k=5;k<6;k++){
  long dur,dist;
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  dur=pulseIn(echo,HIGH);
  dist=dur/58;
  if(dist<=10){
  pix33(k+1,k+1,17,0,255,0);
  pix44(k+1,k+1,17,0,255,0);
  pix22(k+1,k+1,17,0,255,0);
  pix3.show();
  pix4.show();
  pix2.show();
  delay(time3);}
  else
    {
      if(k==5)
      {
        k=5;
      }
      else
      {
        k--;
      }
    }}

  for(int k=5;k<6;k++){
  long dur,dist;
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  dur=pulseIn(echo,HIGH);
  dist=dur/58;
  if(dist<=10){
  pix33(k+2,k+2,17,0,255,0);
  pix44(k+2,k+2,17,0,255,0);
  pix55(k+2,k+2,17,0,255,0);
  pix11(k+2,k+2,17,0,255,0);
  pix22(k+2,k+2,17,0,255,0);
  pix1.show();
  pix2.show();
  pix3.show();
  pix4.show();
  pix5.show();
  delay(time3);}
  else
    {
      if(k==5)
      {
        k=5;
      }
      else
      {
        k--;
      }
    }}
for(int k=5;k<6;k++){
  long dur,dist;
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  dur=pulseIn(echo,HIGH);
  dist=dur/58;
  if(dist<=10){
  pix33(k+3,k+3,17,0,255,0);
  pix44(k+3,k+3,17,0,255,0);
  pix22(k+3,k+3,17,0,255,0);
  pix3.show();
  pix4.show();
  pix2.show();
  delay(time3);}
   else
    {
      if(k==5)
      {
        k=5;
      }
      else
      {
        k--;
      }
    }}
 for(int k=5;k<6;k++){
  long dur,dist;
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  dur=pulseIn(echo,HIGH);
  dist=dur/58;
  if(dist<=10){
  pix33(k+4,k+4,17,0,255,0);
  pix3.show();
  delay(time1);
  delay(time3);}
    else
    {
      if(k==5)
      {
        k=5;
      }
      else
      {
        k--;
      }
    }}
  

//나무완성--------------------------이제 길이늘리기
for(int k=4;k<=10;k++)
  {
    long dur, dist;
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    dur=pulseIn(echo,HIGH);
    dist=dur/58;
    if(dist<=10)
    {
    pix1.clear();
    pix2.clear();
    pix3.clear();
    pix4.clear();
    pix5.clear();
    pix11(k+3,k+3,17,0,255,0);
    
    pix22(k+2,k+4,17,0,255,0);
    pix33(0,k,17,190,50,20);
    pix33(k+1,k+5,17,0,255,0);
    
    pix44(k+2,k+4,17,0,255,0);
    pix55(k+3,k+3,17,0,255,0);
    pix1.show();
    pix2.show();
    pix3.show();
    pix4.show();
    pix5.show();
    delay(time3);
    pix1.clear();
    pix2.clear();
    pix3.clear();
    pix4.clear();
    pix5.clear();
    off1();
    off2();
    off3();
    off4();
    off5();
    }
    else
    {
      if(k==4)
      {
        k=4;
      }
      else
      {
        k--;
      }
    }
  
    } 
  }
