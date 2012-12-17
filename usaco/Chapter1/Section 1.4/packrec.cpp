/*
ID:ybojan2
LANG:C++
TASK:packrec
*/
#include <iostream>
#include <fstream>

using namespace std;

int a[5],b[5],dh[1000],dw[1000],len=0,res=2147483647;

void swap(int &x,int &y)
{
     int tmp=x;
     x=y;
     y=tmp;
}

int max(int x,int y)
{
    return ((x>y)?x:y);
}

void put(int h,int w)
{
     if (h>w) swap(h,w);
     if (h*w<res)
                {
                                  len=1;
                                  dh[len]=h;
                                  dw[len]=w;
                                  res=h*w;
                }
     else if (h*w==res)
                {
                     len++;
                     dh[len]=h;
                     dw[len]=w;
                }
}

void set1(int &h,int &w)
{
     h=max(max(max(a[1],a[2]),a[3]),a[4]);
     w=b[1]+b[2]+b[3]+b[4];
}

void set2(int &h,int &w)
{
     h=b[1]+max(max(a[2],a[3]),a[4]);
     w=max(a[1],b[2]+b[3]+b[4]);
}

void set3(int &h,int &w)
{
     h=max(a[4],b[1]+max(a[2],a[3]));
     w=b[4]+max(a[1],b[2]+b[3]);
}

void set45(int &h,int &w)
{
     h=max(max(a[1]+a[2],a[3]),a[4]);
     w=max(b[1],b[2])+b[3]+b[4];
}

void set6(int &h,int &w)
{
     h=max(a[1]+a[2],a[3]+a[4]);
     w=max(b[2]+b[3],b[1]+b[4]);
     if (((a[1]+a[3]>h)&&(b[1]+b[3]>w))||((a[2]+a[4]>h)&&(b[2]+b[4]>w))) 
     {
                                                                         h=10000;
                                                                         w=10000;
                                                                         }
}

void find()
{
     int h,w;
     set1(h,w);
     put(h,w);
     set2(h,w);
     put(h,w);
     set3(h,w);
     put(h,w);
     set45(h,w);
     put(h,w);
     set6(h,w);
     put(h,w);
}

int main()
{
    ifstream fin("packrec.in");
    ofstream fout("packrec.out");
    
    int x[5],y[5];
    for (int i=1;i<=4;i++)
    {
        fin>>x[i]>>y[i];
    }
    for (int i1=1;i1<=4;i1++)
    {
        a[1]=x[i1];
        b[1]=y[i1];
        for (int i2=1;i2<=4;i2++)
        {
            if (i1==i2) continue;
            a[2]=x[i2];
            b[2]=y[i2];
            for (int i3=1;i3<=4;i3++)
            {
                if ((i3==i1)||(i3==i2)) continue;
                a[3]=x[i3];
                b[3]=y[i3];
                a[4]=x[10-i1-i2-i3];
                b[4]=y[10-i1-i2-i3];
                for (int j1=1;j1<=2;j1++)
                {
                    swap(a[1],b[1]);
                    for (int j2=1;j2<=2;j2++)
                    {
                        swap(a[2],b[2]);
                        for (int j3=1;j3<=2;j3++)
                        {
                            swap(a[3],b[3]);
                            for (int j4=1;j4<=2;j4++)
                            {
                                swap(a[4],b[4]);
                                find();               
                            }
                        }
                    }
                }
            }
        }
    }
    fout<<res<<endl;
    for (int i=1;i<=len;i++)
    {
        for (int j=i+1;j<=len;j++)
        {
            if (dh[i]>dh[j]) 
            {
                             swap(dh[i],dh[j]);
                             swap(dw[i],dw[j]);
            }
        }
    }
    for (int i=1;i<=len;i++)
    {
        if ((dh[i]==dh[i-1])&&(dw[i]=dw[i-1])) continue;
        fout<<dh[i]<<" "<<dw[i]<<endl;
    }
    return 0;
}
