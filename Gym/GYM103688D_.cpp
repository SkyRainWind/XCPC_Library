#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll x1,y1,x2,y2,x3,y3;
bool check(long double a,long double b,long double c,long double d)
{
    if(a*c+b*d<-1e-9)
    {
        //ax+by=a/2*x1+b/2*y1
        long double cc=-b/2*x1+a/2*y1;
        cc=-cc;
        if(cc>0&&-b*x3+a*y3+cc>0||-b*x3+a*y3+cc<0&&cc<0)
        {/*
            cout<<"????"<<(double)cc<<" "<<(double)(-b*x3+a*y3+cc)<<" "<<(double)(-b/2*x1+a/2*y1+cc)<<endl;
            cout<<(double)-b<<" "<<(double)a<<" "<<(double)cc<<endl;
            cout<<(double)a<<" "<<(double)b<<" "<<(double)c<<" "<<(double)d<<endl;
            cout<<x1<<" "<<y1<<" "<<x3<<" "<<y3<<endl;
            cout<<"??"<<(double)(a*c+b*d)<<endl;*/
            return 1;
        }
        else return 0;
    }
    else return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        x1-=x2;
        y1-=y2;
        x3-=x2;
        y3-=y2;
        if(x1>0)
        {
            x1=-x1;
            x3=-x3;
        }
        if(y1>0)
        {
            y1=-y1;
            y3=-y3;
        }
        if(y1>x1)
        {
            swap(x1,y1);
            swap(x3,y3);
        }
        if(x1==0&&y1==-2)
        {
            if(y3<=0)printf("no\n");
            else if(abs(x3)>=2)printf("no\n");
            else printf("yes\n");
            continue;
        }
        swap(x1,y1);
        swap(x3,y3);
        long double xa1,xa2,ya1,ya2;
        {
            long double sn=2/sqrt((long double)(x1*x1+y1*y1));
            long double cs=sqrt((long double)(x1*x1+y1*y1-4))/sqrt((long double)(x1*x1+y1*y1));
            //cs -sn
            //sn cs
            xa1=x1*cs+y1*sn;
            ya1=-x1*sn+y1*cs;
            sn=-sn;
            xa2=x1*cs+y1*sn;
            ya2=-x1*sn+y1*cs;
        }
        long double xb1,xb2,yb1,yb2;
        {
            #define x1 x3
            #define y1 y3
            long double sn=2/sqrt((long double)(x1*x1+y1*y1));
            long double cs=sqrt((long double)(x1*x1+y1*y1-4))/sqrt((long double)(x1*x1+y1*y1));
            //cs -sn
            //sn cs
            xb1=x1*cs+y1*sn;
            yb1=-x1*sn+y1*cs;
            sn=-sn;
            xb2=x1*cs+y1*sn;
            yb2=-x1*sn+y1*cs;
            #undef x1
            #undef y1
        }
        //cout<<"<<"<<(double)xa1<<" "<<(double)ya1<<" "<<(double)xa2<<" "<<(double)ya2<<endl;
        //cout<<"<<"<<(double)xb1<<" "<<(double)yb1<<" "<<(double)xb2<<" "<<(double)yb2<<endl;
        if(check(xa1,ya1,xb2,yb2)||check(xa2,ya2,xb2,yb2)||check(xa1,ya1,xb1,yb1)||check(xa2,ya2,xb1,yb1))printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
