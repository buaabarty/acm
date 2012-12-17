/*
ID:ybojan2
LANG:C++
TASK:fence4
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

    ifstream fin("fence4.in");
    ofstream fout("fence4.out");

int ox,oy,n,i,j,cc,x[203],y[203];
bool seen[201];
double e=1e-5;

double abs(double x)
{
       if (x<0) return -x;
       return x;
}

double sqr(double x)
{
       return x*x;
}

bool cross1(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4)
{
     double s1=(x4-x3)*(y1-y3)-(x1-x3)*(y4-y3),s2=(x3-x1)*(y2-y1)-(x2-x1)*(y3-y1),s3=(x2-x1)*(y4-y3)-(x4-x3)*(y2-y1);
     if (s3<0) {
               s1=-s1;
               s2=-s2;
               s3=-s3;
               }
     if ((s1>0)&&(s2>0)&&(s1<s3)&&(s2<s3)) return true;
     else return false;
}

int side(double x1,double y1,double x2,double y2,double x3,double y3)
{
    double t=(x3-x2)*(y1-y2)-(x1-x2)*(y3-y2);
    if (t>e) return 1;
    else if(t<-e) return -1;
    else return 0;
}

void cross2(double x1,double y1,double x2,double y2)
{
     double s1,s2,s3,fx,fy,s,ts,ml,mr,mm;
     int i,oi,l,r,t1,t2;
     ml=1e100;
     mr=1e100;
     mm=1e100;
     oi=0;
     for (int i=1;i<=n;i++)
     {
         s1=(x[i+1]-x[i])*(y1-y[i])-(x1-x[i])*(y[i+1]-y[i]);
         s2=(x[i]-x1)*(y2-y1)-(x2-x1)*(y[i]-y1);
         s3=(x2-x1)*(y[i+1]-y[i])-(x[i+1]-x[i])*(y2-y1);
         if (s3<-e){
                    s1=-s1;
                    s2=-s2;
                    s3=-s3;
                    }
         if ((s1>e)&&(s2>=0)&&(s2<=s3)){
                                        if (abs(s3)>e){
                                                       fx=x1+(x2-x1)*s1/s3;
                                                       fy=y1+(y2-y1)*s1/s3;
                                                       s=sqr(fx-ox)+sqr(fy-oy);
                                                       }
                                        else {
                                             fx=x[i];
                                             fy=y[i];
                                             s=sqr(fx-ox)+sqr(fy-oy);
                                             fx=x[i+1];
                                             fy=y[i+1];
                                             ts=sqr(fx-ox)+sqr(fy-oy);
                                             if (ts<s) s=ts;
                                             }
                                        if ((s2>e)&&(s2<s3-e)){
                                                               if (s<mm){
                                                                         mm=s;
                                                                         oi=i;
                                                                         }
                                                               continue;
                                                               }
                                        if (s2<e){
                                                  l=i-1;
                                                  r=i+1;
                                                  }
                                        else {
                                             l=i;
                                             r=i+2;
                                             }
                                        t1=side(x[l],y[l],x1,y1,x2,y2);
                                        t2=side(x[r],y[r],x1,y1,x2,y2);
                                        if ((t1>0)&&(t2<0)){
                                                            if (s2<mm){
                                                                       mm=s;
                                                                       oi=i; 
                                                                       }
                                                            }
                                        if ((t1>=0)&&(t2>=0)){
                                                              if (s<mr) mr=s;
                                                              }
                                        if ((t1<=0)&&(t2<=0)){
                                                              if (s<ml) ml=s;
                                                              }
                                        }
     }
     if ((mm<mr)||(mm<ml)) seen[oi]=true;
     fout<<oi<<endl;
}

int main()
{
    memset(seen,false,sizeof(seen));
    fin>>n>>ox>>oy;
    for (int i=1;i<=n;i++)
        fin>>x[i]>>y[i];
    x[n+1]=x[1];
    y[n+1]=y[1];
    x[n+2]=x[2];
    y[n+2]=y[2];
    x[0]=x[n];
    y[0]=y[n];
    for (int i=1;i<=n-1;i++)   
        for (int j=i+1;j<=n;j++)
            if (cross1(x[i],y[i],x[i+1],y[i+1],x[j],y[j],x[j+1],y[j+1])){
                                                                         fout<<"NOFENCE"<<endl;
                                                                         return 0;
                                                                         }
    for (int i=1;i<=n;i++)
    {
        cross2(ox,oy,x[i],y[i]);
        cross2(ox,oy,(x[i]+x[i+1])/2,(y[i]+y[i+1])/2);
    }
    cc=0;
    fout<<endl;
    for (int i=1;i<=n;i++)
        if (seen[i]) {
                     fout<<i<<endl;
                     cc++;
                     }
    fout<<cc<<endl;
    for (int i=1;i<=n-2;i++)
        if (seen[i]) fout<<x[i]<<" "<<y[i]<<" "<<x[i+1]<<" "<<y[i+1]<<endl;
    if (seen[n]) fout<<x[1]<<" "<<y[1]<<" "<<x[n]<<" "<<y[n]<<endl;    
    if (seen[n-1]) fout<<x[n-1]<<" "<<y[n-1]<<" "<<x[n]<<" "<<y[n]<<endl;
    return 0;
}
