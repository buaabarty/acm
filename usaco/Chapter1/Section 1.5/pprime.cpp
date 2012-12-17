/*
ID:ybojan2
LANG:C++
TASK:pprime
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int length(int x)
{
    int l=0;
    for (;x>0;)
    {
        l++;
        x/=10;
    }
    return l;
}

bool prim(int x)
{
     if (x==2) return true;
     if (x==1) return false;
     for (int i=2;i<=sqrt(x);i++)
     {
         if (x%i==0) return false;
     }
     return true;
}


int main()
{
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");
    
    int a,b,la,lb;
    fin>>a>>b;
    la=length(a);
    lb=length(b);
    if (lb==9) lb=8;
    for (int i=la;i<=lb;i++)
    {
        int num;
        if (i==1){
                  for (int j=2;j<=9;j++)
                      if ((j>=a)&&(j<=b)&&(prim(j))) fout<<j<<endl;
                  }
        if (i==2){
                  for (int j=1;j<=9;j+=2)
                  {
                      num=j*11;
                      if (num>b) break;
                      if (prim(num)&&(num>=a)&&(num<=b)) fout<<num<<endl;
                  }
                  }
        if (i==3){
                  for (int j1=1;j1<=9;j1+=2)
                  {
                      for (int j2=0;j2<=9;j2++)
                      {
                          num=j1*101+j2*10;
                          if (num>b) break;
                          if (prim(num)&&(num>=a)&&(num<=b)) fout<<num<<endl;
                      }
                  }
                  }
        if (i==4){
                  for (int j1=1;j1<=9;j1+=2)
                  {
                      for (int j2=0;j2<=9;j2++)
                      {
                          num=j1*1001+j2*110;
                          if (num>b) break;
                          if (prim(num)&&(num>=a)&&(num<=b)) fout<<num<<endl;
                      }
                  }
                  }
        if (i==5){
                  for (int j1=1;j1<=9;j1+=2)
                  {
                      for (int j2=0;j2<=9;j2++)
                      {
                          for (int j3=0;j3<=9;j3++)
                          {
                              num=j1*10001+j2*1010+j3*100;
                              if (num>b) break;
                              if (prim(num)&&(num>=a)&&(num<=b)) fout<<num<<endl;
                          }
                      }
                  }
                  }
        if (i==6){
                  for (int j1=1;j1<=9;j1+=2)
                  {
                      for (int j2=0;j2<=9;j2++)
                      {
                          for (int j3=0;j3<=9;j3++)
                          {
                              num=j1*100001+j2*10010+j3*1100;
                              if (num>b) break;
                              if (prim(num)&&(num>=a)&&(num<=b)) fout<<num<<endl;
                          }
                      }
                  }
                  }
        if (i==7){
                  for (int j1=1;j1<=9;j1+=2)
                  {
                      for (int j2=0;j2<=9;j2++)
                      {
                          for (int j3=0;j3<=9;j3++)
                          {
                              for (int j4=0;j4<=9;j4++)
                              {
                                  num=j1*1000001+j2*100010+j3*10100+j4*1000;
                                  if (num>b) break;
                                  if (prim(num)&&(num>=a)&&(num<=b)) fout<<num<<endl;
                              }
                          }
                      }
                  }
                  }
        if (i==8){
                  for (int j1=1;j1<=9;j1+=2)
                  {
                      for (int j2=0;j2<=9;j2++)
                      {
                          for (int j3=0;j3<=9;j3++)
                          {
                              for (int j4=0;j4<=9;j4++)
                              {
                                  num=j1*10000001+j2*1000010+j3*100100+j4*11000;
                                  if (num>b) break;
                                  if (prim(num)&&(num>=a)&&(num<=b)) fout<<num<<endl;
                              }
                          }
                      }
                  }
                  }

    }
    return 0;
}
