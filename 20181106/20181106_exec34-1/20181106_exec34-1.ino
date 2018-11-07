int ROW[8] = {10, 11, 12, 13, A0,A1,A2, A3};
int CEL[8] = {2, 3, 4, 5, 6, 7, 8, 9};
unsigned long tt=0;
int X0[8][8] = {
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {1, 1, 0, 0, 0, 0, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 1}
};

int X1[8][8] = {
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0}
};
int X2[8][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1, 1, 1, 0}
};
int X3[8][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0}
};
int X4[8][8] = {
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0}
};
int X5[8][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0}
};
int X6[8][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0}
};
int X7[8][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0}
};
int X8[8][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0}
};
int X9[8][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0}
};
int XX[8][8] = {
  {1, 0, 0, 0, 0, 0, 0, 1},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {1, 0, 0, 0, 0, 0, 0, 1}
};



void setup() {
  // put your setup code here, to run once:
  for (int i = 2; i <= 18; i++)
  {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(tt<1000)
{
C0();
}
else if(tt<2000)
{
C1();
}
else if(tt<3000)
{
C2();
}
else if(tt<4000)
{
C3();
}
else if(tt<5000)
{
C4();
}
else if(tt<6000)
{
C5();
}
else if(tt<7000)
{
C6();
}
else if(tt<8000)
{
C7();
}
else if(tt<9000)
{
C8();
}
else if(tt<10000)
{
C9();
}
else
{
  tt=0;
  }
tt++;

}

void C0()
{
   for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
     if(X0[i][j]==1)
     {
      digitalWrite(ROW[i],LOW);
      digitalWrite(CEL[j],HIGH);
      
      digitalWrite(CEL[j],LOW);
      digitalWrite(ROW[i],HIGH);
      }
     
    }
  }
}
  void C1()
{
   for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
     if(X1[i][j]==1)
     {
      digitalWrite(ROW[i],LOW);
      digitalWrite(CEL[j],HIGH);
       // delay(1);
      digitalWrite(CEL[j],LOW);
      digitalWrite(ROW[i],HIGH);
      }
     
    }
  }
}

void C2()
{
   for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
     if(X2[i][j]==1)
     {
      digitalWrite(ROW[i],LOW);
      digitalWrite(CEL[j],HIGH);
       // delay(1);
      digitalWrite(CEL[j],LOW);
      digitalWrite(ROW[i],HIGH);
      }
     
    }
  }
}
void C3()
{
   for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
     if(X3[i][j]==1)
     {
      digitalWrite(ROW[i],LOW);
      digitalWrite(CEL[j],HIGH);
       // delay(1);
      digitalWrite(CEL[j],LOW);
      digitalWrite(ROW[i],HIGH);
      }
     
    }
  }
}
  void C4()
{
   for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
     if(X4[i][j]==1)
     {
      digitalWrite(ROW[i],LOW);
      digitalWrite(CEL[j],HIGH);
       // delay(1);
      digitalWrite(CEL[j],LOW);
      digitalWrite(ROW[i],HIGH);
      }
     
    }
  }
}
  void C5()
{
   for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
     if(X5[i][j]==1)
     {
      digitalWrite(ROW[i],LOW);
      digitalWrite(CEL[j],HIGH);
       // delay(1);
      digitalWrite(CEL[j],LOW);
      digitalWrite(ROW[i],HIGH);
      }
     
    }
  }
}
  void C6()
{
   for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
     if(X6[i][j]==1)
     {
      digitalWrite(ROW[i],LOW);
      digitalWrite(CEL[j],HIGH);
       // delay(1);
      digitalWrite(CEL[j],LOW);
      digitalWrite(ROW[i],HIGH);
      }
     
    }
  }
}
  void C7()
{
   for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
     if(X7[i][j]==1)
     {
      digitalWrite(ROW[i],LOW);
      digitalWrite(CEL[j],HIGH);
       // delay(1);
      digitalWrite(CEL[j],LOW);
      digitalWrite(ROW[i],HIGH);
      }
     
    }
  }
}
  void C8()
{
   for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
     if(X8[i][j]==1)
     {
      digitalWrite(ROW[i],LOW);
      digitalWrite(CEL[j],HIGH);
       // delay(1);
      digitalWrite(CEL[j],LOW);
      digitalWrite(ROW[i],HIGH);
      }
     
    }
  }
}
  void C9()
{
   for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
     if(X9[i][j]==1)
     {
      digitalWrite(ROW[i],LOW);
      digitalWrite(CEL[j],HIGH);
       // delay(1);
      digitalWrite(CEL[j],LOW);
      digitalWrite(ROW[i],HIGH);
      }
     
    }
  }
}
