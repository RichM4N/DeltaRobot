#include <math.h>

class StepperMotArray {
  private:
    int coil1;
    int coil2;
    int coil3;
    int coil4;
    int coil5;
    int coil6;
    int coil7;
    int coil8;
    int coil9;
    int coil10;
    int coil11;
    int coil12;

    
  public:
    int currentPos1 = 14260;
    int currentPos2 = 14260;
    int currentPos3 = 14260;
    
    StepperMotArray(int coil1, int coil2, int coil3, int coil4, int coil5, int coil6, int coil7, int coil8, int coil9, int coil10, int coil11, int coil12)
    {
      this->coil1 = coil1;
      this->coil2 = coil2;
      this->coil3 = coil3;
      this->coil4 = coil4;
      this->coil5 = coil5;
      this->coil6 = coil6;
      this->coil7 = coil7;
      this->coil8 = coil8;
      this->coil9 = coil9;
      this->coil10 = coil10;
      this->coil11 = coil11;
      this->coil12 = coil12;

      pinMode(coil1, OUTPUT);
      pinMode(coil2, OUTPUT);
      pinMode(coil3, OUTPUT);
      pinMode(coil4, OUTPUT);
      pinMode(coil5, OUTPUT);
      pinMode(coil6, OUTPUT);
      pinMode(coil7, OUTPUT);
      pinMode(coil8, OUTPUT);
      pinMode(coil9, OUTPUT);
      pinMode(coil10, OUTPUT);
      pinMode(coil11, OUTPUT);
      pinMode(coil12, OUTPUT);
      
    }

   void wavestep(int steps1, int steps2, int steps3)
   {

    currentPos1 = currentPos1 - steps1;
    currentPos2 = currentPos2 - steps2;
    currentPos3 = currentPos3 - steps3;

    
    int j = 1;
    int k = 1;
    int l = 1;
    int dir1 = 1;
    int dir2 = 1;
    int dir3 = 1;
    int stepLength1;
    int stepLength2;
    int stepLength3;
    int stepIndicator1 = 0;
    int stepIndicator2 = 0;
    int stepIndicator3 = 0;
    int currentStep1 = 0;
    int currentStep2 = 0;
    int currentStep3 = 0;
    if(steps1 < 0)
    {
      dir1 = 0;
      steps1 = -1*steps1;
    }
    if(steps2 < 0)
    {
      dir2 = 0;
      steps2 = -1*steps2;
    }
    if(steps3 < 0)
    {
      dir3 = 0;
      steps3 = -1*steps3;
    }

    
    //STEPS1 BIGGEST//////////////////////////////////
    //////////////////////////////////////////////////
    if(steps1 >= steps2 && steps1 >= steps3)
    {
      
      stepLength2 = steps1/steps2;
      stepLength3 = steps1/steps3;

      if(steps2 == 0)
      {
        stepLength2 = steps1;
      }
      if(steps3 == 0)
      {
        stepLength3 = steps1;
      }
      
      k = stepLength2;
      l = stepLength3;
      
      while(j <= steps1)
      {
        
        currentStep1 = (j-1)%4;
        if(dir1 == 1)
        {
        switch(currentStep1)
        {
          case 0:
          digitalWrite(coil1, HIGH);
          digitalWrite(coil2, LOW);
          digitalWrite(coil3, LOW);
          digitalWrite(coil4, LOW);
          break;
        case 1:
          digitalWrite(coil1, LOW);
          digitalWrite(coil2, HIGH);
          digitalWrite(coil3, LOW);
          digitalWrite(coil4, LOW);
          break;
        case 2:
          digitalWrite(coil1, LOW);
          digitalWrite(coil2, LOW);
          digitalWrite(coil3, HIGH);
          digitalWrite(coil4, LOW);
          break;
        case 3:
          digitalWrite(coil1, LOW);
          digitalWrite(coil2, LOW);
          digitalWrite(coil3, LOW);
          digitalWrite(coil4, HIGH);
          break;
        }
        }else if(dir1 == 0)
        {
          switch(currentStep1)
        {
          case 3:
          digitalWrite(coil1, HIGH);
          digitalWrite(coil2, LOW);
          digitalWrite(coil3, LOW);
          digitalWrite(coil4, LOW);
          break;
        case 2:
          digitalWrite(coil1, LOW);
          digitalWrite(coil2, HIGH);
          digitalWrite(coil3, LOW);
          digitalWrite(coil4, LOW);
          break;
        case 1:
          digitalWrite(coil1, LOW);
          digitalWrite(coil2, LOW);
          digitalWrite(coil3, HIGH);
          digitalWrite(coil4, LOW);
          break;
        case 0:
          digitalWrite(coil1, LOW);
          digitalWrite(coil2, LOW);
          digitalWrite(coil3, LOW);
          digitalWrite(coil4, HIGH);
          break;
        }
        }

        
        if(k <= j+1)
        {
          currentStep2 = stepIndicator2%4;
          if(dir2 == 1)
          {
          switch(currentStep2)
          {
            case 0:
            digitalWrite(coil5, HIGH);
            digitalWrite(coil6, LOW);
            digitalWrite(coil7, LOW);
            digitalWrite(coil8, LOW);
            break;
          case 1:
            digitalWrite(coil5, LOW);
            digitalWrite(coil6, HIGH);
            digitalWrite(coil7, LOW);
            digitalWrite(coil8, LOW);
            break;
          case 2:
            digitalWrite(coil5, LOW);
            digitalWrite(coil6, LOW);
            digitalWrite(coil7, HIGH);
            digitalWrite(coil8, LOW);
            break;
          case 3:
            digitalWrite(coil5, LOW);
            digitalWrite(coil6, LOW);
            digitalWrite(coil7, LOW);
            digitalWrite(coil8, HIGH);
            break;
          }
          }else if(dir2 == 0)
          {
            switch(currentStep2)
          {
            case 3:
            digitalWrite(coil5, HIGH);
            digitalWrite(coil6, LOW);
            digitalWrite(coil7, LOW);
            digitalWrite(coil8, LOW);
            break;
          case 2:
            digitalWrite(coil5, LOW);
            digitalWrite(coil6, HIGH);
            digitalWrite(coil7, LOW);
            digitalWrite(coil8, LOW);
            break;
          case 1:
            digitalWrite(coil5, LOW);
            digitalWrite(coil6, LOW);
            digitalWrite(coil7, HIGH);
            digitalWrite(coil8, LOW);
            break;
          case 0:
            digitalWrite(coil5, LOW);
            digitalWrite(coil6, LOW);
            digitalWrite(coil7, LOW);
            digitalWrite(coil8, HIGH);
            break;
          }
          }
          stepIndicator2 = stepIndicator2 + 1;
          k = k + stepLength2;
        }


        if(l <= j+1)
        {
          currentStep3 = stepIndicator3%4;
          if(dir3 == 1)
          {
          switch(currentStep3)
          {
            case 0:
            digitalWrite(coil9, HIGH);
            digitalWrite(coil10, LOW);
            digitalWrite(coil11, LOW);
            digitalWrite(coil12, LOW);
            break;
          case 1:
            digitalWrite(coil9, LOW);
            digitalWrite(coil10, HIGH);
            digitalWrite(coil11, LOW);
            digitalWrite(coil12, LOW);
            break;
          case 2:
            digitalWrite(coil9, LOW);
            digitalWrite(coil10, LOW);
            digitalWrite(coil11, HIGH);
            digitalWrite(coil12, LOW);
            break;
          case 3:
            digitalWrite(coil9, LOW);
            digitalWrite(coil10, LOW);
            digitalWrite(coil11, LOW);
            digitalWrite(coil12, HIGH);
            break;
          }
          }else if(dir3 == 0)
          {
            switch(currentStep3)
          {
            case 3:
            digitalWrite(coil9, HIGH);
            digitalWrite(coil10, LOW);
            digitalWrite(coil11, LOW);
            digitalWrite(coil12, LOW);
            break;
          case 2:
            digitalWrite(coil9, LOW);
            digitalWrite(coil10, HIGH);
            digitalWrite(coil11, LOW);
            digitalWrite(coil12, LOW);
            break;
          case 1:
            digitalWrite(coil9, LOW);
            digitalWrite(coil10, LOW);
            digitalWrite(coil11, HIGH);
            digitalWrite(coil12, LOW);
            break;
          case 0:
            digitalWrite(coil9, LOW);
            digitalWrite(coil10, LOW);
            digitalWrite(coil11, LOW);
            digitalWrite(coil12, HIGH);
            break;
          }
          }
          stepIndicator3 = stepIndicator3 + 1;
          l = l + stepLength3;
        }

        j = j + 1;
        delay(2);
      }
    //STEPS2 BIGGEST//////////////////////////////////
    ////////////////////////////////////////////////// 
    }else if(steps2 >= steps1 && steps2 >= steps3)
    {
      stepLength1 = steps2/steps1;
      stepLength3 = steps2/steps3;

      if(steps1 == 0)
      {
        stepLength1 = steps2;
      }
      if(steps3 == 0)
      {
        stepLength3 = steps2;
      }
      
      j = stepLength1;
      l = stepLength3;
      
      while(k <= steps2)
      {
        currentStep2 = (k-1)%4;
        
        if(dir2 == 1)
        {
        switch(currentStep2)
        {
          case 0:
          digitalWrite(coil5, HIGH);
          digitalWrite(coil6, LOW);
          digitalWrite(coil7, LOW);
          digitalWrite(coil8, LOW);
          break;
        case 1:
          digitalWrite(coil5, LOW);
          digitalWrite(coil6, HIGH);
          digitalWrite(coil7, LOW);
          digitalWrite(coil8, LOW);
          break;
        case 2:
          digitalWrite(coil5, LOW);
          digitalWrite(coil6, LOW);
          digitalWrite(coil7, HIGH);
          digitalWrite(coil8, LOW);
          break;
        case 3:
          digitalWrite(coil5, LOW);
          digitalWrite(coil6, LOW);
          digitalWrite(coil7, LOW);
          digitalWrite(coil8, HIGH);
          break;
        }
        }else if(dir2 == 0)
        {
          
          switch(currentStep2)
        {
          case 3:
          digitalWrite(coil5, HIGH);
          digitalWrite(coil6, LOW);
          digitalWrite(coil7, LOW);
          digitalWrite(coil8, LOW);
          break;
        case 2:
          digitalWrite(coil5, LOW);
          digitalWrite(coil6, HIGH);
          digitalWrite(coil7, LOW);
          digitalWrite(coil8, LOW);
          break;
        case 1:
          digitalWrite(coil5, LOW);
          digitalWrite(coil6, LOW);
          digitalWrite(coil7, HIGH);
          digitalWrite(coil8, LOW);
          break;
        case 0:
          digitalWrite(coil5, LOW);
          digitalWrite(coil6, LOW);
          digitalWrite(coil7, LOW);
          digitalWrite(coil8, HIGH);
          break;
        }
        }

        if(j <= k+1)
        {
          currentStep1 = stepIndicator1%4;
          if(dir1 == 1)
          {
          switch(currentStep1)
          {
            case 0:
            digitalWrite(coil1, HIGH);
            digitalWrite(coil2, LOW);
            digitalWrite(coil3, LOW);
            digitalWrite(coil4, LOW);
            break;
          case 1:
            digitalWrite(coil1, LOW);
            digitalWrite(coil2, HIGH);
            digitalWrite(coil3, LOW);
            digitalWrite(coil4, LOW);
            break;
          case 2:
            digitalWrite(coil1, LOW);
            digitalWrite(coil2, LOW);
            digitalWrite(coil3, HIGH);
            digitalWrite(coil4, LOW);
            break;
          case 3:
            digitalWrite(coil1, LOW);
            digitalWrite(coil2, LOW);
            digitalWrite(coil3, LOW);
            digitalWrite(coil4, HIGH);
            break;
          }
          }else if(dir1 == 0)
          {
            switch(currentStep1)
          {
            case 3:
            digitalWrite(coil1, HIGH);
            digitalWrite(coil2, LOW);
            digitalWrite(coil3, LOW);
            digitalWrite(coil4, LOW);
            break;
          case 2:
            digitalWrite(coil1, LOW);
            digitalWrite(coil2, HIGH);
            digitalWrite(coil3, LOW);
            digitalWrite(coil4, LOW);
            break;
          case 1:
            digitalWrite(coil1, LOW);
            digitalWrite(coil2, LOW);
            digitalWrite(coil3, HIGH);
            digitalWrite(coil4, LOW);
            break;
          case 0:
            digitalWrite(coil1, LOW);
            digitalWrite(coil2, LOW);
            digitalWrite(coil3, LOW);
            digitalWrite(coil4, HIGH);
            break;
          }
          }
          stepIndicator1 = stepIndicator1 + 1;
          j = j + stepLength1;
        }


        if(l <= k+1)
        {
          currentStep3 = stepIndicator3%4;
          if(dir3 == 1)
          {
          switch(currentStep3)
          {
            case 0:
            digitalWrite(coil9, HIGH);
            digitalWrite(coil10, LOW);
            digitalWrite(coil11, LOW);
            digitalWrite(coil12, LOW);
            break;
          case 1:
            digitalWrite(coil9, LOW);
            digitalWrite(coil10, HIGH);
            digitalWrite(coil11, LOW);
            digitalWrite(coil12, LOW);
            break;
          case 2:
            digitalWrite(coil9, LOW);
            digitalWrite(coil10, LOW);
            digitalWrite(coil11, HIGH);
            digitalWrite(coil12, LOW);
            break;
          case 3:
            digitalWrite(coil9, LOW);
            digitalWrite(coil10, LOW);
            digitalWrite(coil11, LOW);
            digitalWrite(coil12, HIGH);
            break;
          }
          }else if(dir3 == 0)
          {
            switch(currentStep3)
          {
            case 3:
            digitalWrite(coil9, HIGH);
            digitalWrite(coil10, LOW);
            digitalWrite(coil11, LOW);
            digitalWrite(coil12, LOW);
            break;
          case 2:
            digitalWrite(coil9, LOW);
            digitalWrite(coil10, HIGH);
            digitalWrite(coil11, LOW);
            digitalWrite(coil12, LOW);
            break;
          case 1:
            digitalWrite(coil9, LOW);
            digitalWrite(coil10, LOW);
            digitalWrite(coil11, HIGH);
            digitalWrite(coil12, LOW);
            break;
          case 0:
            digitalWrite(coil9, LOW);
            digitalWrite(coil10, LOW);
            digitalWrite(coil11, LOW);
            digitalWrite(coil12, HIGH);
            break;
          }
          }
          stepIndicator3 = stepIndicator3 + 1;
          l = l + stepLength3;
        }
        k = k + 1;
        delay(2);
      }
    //STEPS3 BIGGEST//////////////////////////////////
    ////////////////////////////////////////////////// 
    }else if(steps3 >= steps1 && steps3 >= steps2)
    {

      stepLength1 = steps3/steps1;
      stepLength2 = steps3/steps2;

      if(steps2 == 0)
      {
        stepLength2 = steps3;
      }
      if(steps1 == 0)
      {
        stepLength1 = steps3;
      }

      j = stepLength1;
      k = stepLength2;
      
      while(l <= steps3)
      {
        currentStep3 = (l-1)%4;
        if(dir3 == 1)
        {
        switch(currentStep3)
        {
          case 0:
          digitalWrite(coil9, HIGH);
          digitalWrite(coil10, LOW);
          digitalWrite(coil11, LOW);
          digitalWrite(coil12, LOW);
          break;
        case 1:
          digitalWrite(coil9, LOW);
          digitalWrite(coil10, HIGH);
          digitalWrite(coil11, LOW);
          digitalWrite(coil12, LOW);
          break;
        case 2:
          digitalWrite(coil9, LOW);
          digitalWrite(coil10, LOW);
          digitalWrite(coil11, HIGH);
          digitalWrite(coil12, LOW);
          break;
        case 3:
          digitalWrite(coil9, LOW);
          digitalWrite(coil10, LOW);
          digitalWrite(coil11, LOW);
          digitalWrite(coil12, HIGH);
          break;
        }
        }else if(dir3 == 0)
        {
          switch(currentStep3)
        {
          case 3:
          digitalWrite(coil9, HIGH);
          digitalWrite(coil10, LOW);
          digitalWrite(coil11, LOW);
          digitalWrite(coil12, LOW);
          break;
        case 2:
          digitalWrite(coil9, LOW);
          digitalWrite(coil10, HIGH);
          digitalWrite(coil11, LOW);
          digitalWrite(coil12, LOW);
          break;
        case 1:
          digitalWrite(coil9, LOW);
          digitalWrite(coil10, LOW);
          digitalWrite(coil11, HIGH);
          digitalWrite(coil12, LOW);
          break;
        case 0:
          digitalWrite(coil9, LOW);
          digitalWrite(coil10, LOW);
          digitalWrite(coil11, LOW);
          digitalWrite(coil12, HIGH);
          break;
        }
        }

        if(j <= l+1)
        {
          currentStep1 = stepIndicator1%4;
          if(dir1 == 1)
          {
          switch(currentStep1)
          {
            case 0:
            digitalWrite(coil1, HIGH);
            digitalWrite(coil2, LOW);
            digitalWrite(coil3, LOW);
            digitalWrite(coil4, LOW);
            break;
          case 1:
            digitalWrite(coil1, LOW);
            digitalWrite(coil2, HIGH);
            digitalWrite(coil3, LOW);
            digitalWrite(coil4, LOW);
            break;
          case 2:
            digitalWrite(coil1, LOW);
            digitalWrite(coil2, LOW);
            digitalWrite(coil3, HIGH);
            digitalWrite(coil4, LOW);
            break;
          case 3:
            digitalWrite(coil1, LOW);
            digitalWrite(coil2, LOW);
            digitalWrite(coil3, LOW);
            digitalWrite(coil4, HIGH);
            break;
          }
          }else if(dir1 == 0)
          {
            switch(currentStep1)
          {
            case 3:
            digitalWrite(coil1, HIGH);
            digitalWrite(coil2, LOW);
            digitalWrite(coil3, LOW);
            digitalWrite(coil4, LOW);
            break;
          case 2:
            digitalWrite(coil1, LOW);
            digitalWrite(coil2, HIGH);
            digitalWrite(coil3, LOW);
            digitalWrite(coil4, LOW);
            break;
          case 1:
            digitalWrite(coil1, LOW);
            digitalWrite(coil2, LOW);
            digitalWrite(coil3, HIGH);
            digitalWrite(coil4, LOW);
            break;
          case 0:
            digitalWrite(coil1, LOW);
            digitalWrite(coil2, LOW);
            digitalWrite(coil3, LOW);
            digitalWrite(coil4, HIGH);
            break;
          }
          }
          stepIndicator1 = stepIndicator1 + 1;
          j = j + stepLength1;
        }


        if(k <= l+1)
        {
          currentStep2 = stepIndicator2%4;
          if(dir2 == 1)
          {
          switch(currentStep2)
          {
            case 0:
            digitalWrite(coil5, HIGH);
            digitalWrite(coil6, LOW);
            digitalWrite(coil7, LOW);
            digitalWrite(coil8, LOW);
            break;
          case 1:
            digitalWrite(coil5, LOW);
            digitalWrite(coil6, HIGH);
            digitalWrite(coil7, LOW);
            digitalWrite(coil8, LOW);
            break;
          case 2:
            digitalWrite(coil5, LOW);
            digitalWrite(coil6, LOW);
            digitalWrite(coil7, HIGH);
            digitalWrite(coil8, LOW);
            break;
          case 3:
            digitalWrite(coil5, LOW);
            digitalWrite(coil6, LOW);
            digitalWrite(coil7, LOW);
            digitalWrite(coil8, HIGH);
            break;
          }
          }else if(dir2 == 0)
          {
            switch(currentStep2)
          {
            case 3:
            digitalWrite(coil5, HIGH);
            digitalWrite(coil6, LOW);
            digitalWrite(coil7, LOW);
            digitalWrite(coil8, LOW);
            break;
          case 2:
            digitalWrite(coil5, LOW);
            digitalWrite(coil6, HIGH);
            digitalWrite(coil7, LOW);
            digitalWrite(coil8, LOW);
            break;
          case 1:
            digitalWrite(coil5, LOW);
            digitalWrite(coil6, LOW);
            digitalWrite(coil7, HIGH);
            digitalWrite(coil8, LOW);
            break;
          case 0:
            digitalWrite(coil5, LOW);
            digitalWrite(coil6, LOW);
            digitalWrite(coil7, LOW);
            digitalWrite(coil8, HIGH);
            break;
          }
          }
          stepIndicator2 = stepIndicator2 + 1;
          k = k + stepLength2;
        }
        l = l + 1;
        delay(2);
      }
        
      }
      
    }
    
   };


StepperMotArray delta = StepperMotArray(2,3,4,5,6,7,8,9,14,15,16,17);
int a;
int b;
int c;
float R = 10;

int move1;
int move2;
int move3;

void setup() {
  Serial.begin(115200);
  
  pinMode(18, INPUT);
  pinMode(19, INPUT);
  pinMode(20, INPUT);
  while(digitalRead(18) == 1 || digitalRead(19) == 1 || digitalRead(20) == 1)
  {
    Serial.println("setup");
    a = digitalRead(18) * 32;
    b = digitalRead(19) * 32;
    c = digitalRead(20) * 32;
    delta.wavestep(-1*a,-1*b,-1*c);
  }
  delta.currentPos1 = 14260;
  delta.currentPos2 = 14260;
  delta.currentPos3 = 14260;
  delay(1000);

}



int calculateHeight1(float angle, float radius, float height)
{
  height = height - 4;
  angle = angle*2*M_PI/360;
  float xp = cos(angle)*radius + cos(2.617993878)*2;
  float yp = sin(angle)*radius + sin(2.617993878)*2;
  float x1 = cos(2.617993878)*R;
  float y1 = sin(2.617993878)*R;
  float a = sqrt( ((x1-xp)*(x1-xp)) + ((y1-yp)*(y1-yp)) ); 
  int out = (int) ((height + sqrt(400 - (a*a)))*2038/M_PI);
  return out;
}

int calculateHeight2(float angle, float radius, float height)
{
  height = height - 4;
  angle = angle*2*M_PI/360;
  float xp = cos(angle)*radius + cos(4.7123889804)*2;
  float yp = sin(angle)*radius + sin(4.7123889804)*2;
  float x1 = cos(4.7123889804)*R;
  float y1 = sin(4.7123889804)*R;
  float a = sqrt( (x1-xp)*(x1-xp) + (y1-yp)*(y1-yp) ); 
  int out = (int) ((height + sqrt(400 - (a*a)))*2038/M_PI);
  return out;
}

int calculateHeight3(float angle, float radius, float height)
{
  height = height - 4;
  angle = angle*2*M_PI/360;
  float xp = cos(angle)*radius + cos(0.5235987756)*2;
  float yp = sin(angle)*radius + sin(0.5235987756)*2;
  float x1 = cos(0.5235987756)*R;
  float y1 = sin(0.5235987756)*R;
  float a = sqrt( (x1-xp)*(x1-xp) + (y1-yp)*(y1-yp) ); 
  int out = (int) ((height + sqrt(400 - (a*a)))*2038/M_PI);
  return out;
}

void loop() {
    delay(1000);
    move1 = delta.currentPos1 - calculateHeight1(150, 5, 5);
    move2 = delta.currentPos2 - calculateHeight2(150, 5, 5);
    move3 = delta.currentPos3 - calculateHeight3(150, 5, 5);
    Serial.print("move1: ");
    Serial.println(delta.currentPos1);
    delta.wavestep(move1,move2,move3);
    delay(1000);
    move1 = delta.currentPos1 - calculateHeight1(270, 5, 5);
    move2 = delta.currentPos2 - calculateHeight2(270, 5, 5);
    move3 = delta.currentPos3 - calculateHeight3(270, 5, 5);
    Serial.print("move2: ");
    Serial.println(delta.currentPos1);
    delta.wavestep(move1,move2,move3);
    delay(1000);
    move1 = delta.currentPos1 - calculateHeight1(30, 5, 5);
    move2 = delta.currentPos2 - calculateHeight2(30, 5, 5);
    move3 = delta.currentPos3 - calculateHeight3(30, 5, 5);
    Serial.print("move3: ");
    Serial.println(delta.currentPos1);
    delta.wavestep(move1,move2,move3);
    
}
