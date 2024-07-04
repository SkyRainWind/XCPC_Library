// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;
const double eps = 1e-8;
const double pi = 3.14159265358;

int sgn(double x) {
    if (fabs(x)<eps) return 0;
    if (x<0) return -1;
    return 1;
}

// 感谢板子 
struct Point {
    double x,y;
    Point (){}
    Point (double _x,double _y):x(_x),y(_y){}
    double distance(const Point &b) const{
        return hypot(x-b.x,y-b.y);
    }
    double len(){return hypot(x,y);}
    Point operator +(const Point &b) const{return Point (x+b.x,y+b.y);}
    Point operator -(const Point &b) const{return Point (x-b.x,y-b.y);}
    double operator *(const Point &b)const{return x*b.x+y*b.y;}
    Point operator *(const double &k) const{return Point (x*k,y*k);}
    Point operator /(const double &k) const{return Point (x/k,y/k);}
    double operator ^(const Point &b)const {return x*b.y-y*b.x;}
    double len2(){return x*x+y*y;}	// hypot
    Point trunc(double r){
        double l=len();
        if (!sgn(l)) return *this;
        r/=l;
        return Point(x*r,y*r);
    }
    // 向左/右转 90 
    Point rotleft() {return Point(-y,x);}
    Point rotright(){return Point(y,-x);}
};
struct Line{
    Point s,e;
    double angle(){	// 求倾斜角 [0,2*pi] 
        double k=atan2(e.y-s.y,e.x-s.x);
        if (k<0) k+=2*pi;return k;
    }
    Line(){}
    Line(Point _s,Point _e):s(_s),e(_e){} 
    double length(){return hypot(e.x-s.x,e.y-s.y);}
    Point lineprog(Point p){
        return s+(((e-s)*((e-s)*(p-s)))/(e-s).len2());
    }
    double dispointtoline(Point p){return fabs((p-s)^(e-s))/length();}
};
struct Circle{
    Point p;double r;
    Circle(){}
    Circle(Point _p,double _r):p(_p),r(_r){}
    // 2 点在圆内 1 上 0 外 
    int relation(Point b){
        double dst=b.distance(p);
        if (sgn(dst-r)<0) return 2;
        if (sgn(dst-r)==0) return 1;
        return 0;
    }
    // 2 线与圆相交 1 相切 0 相离 
    int relationline(Line v){
        double dst=v.dispointtoline(p);
        if (sgn(dst-r)<0) return 2;
        if (sgn(dst-r)==0)return 1;
        return 0;
    }
    // 求线与圆的交点 p1,p2 
    int pointcrossline(Line v,Point &p1,Point &p2){
        if (!relationline(v)) return 0;
        Point a=v.lineprog(p);
        double d=v.dispointtoline(p);
        d=sqrt(r*r-d*d);
        if (sgn(d)==0) {p1=p2=a;return 1;}
        p1=a+(v.e-v.s).trunc(d);
        p2=a-(v.e-v.s).trunc(d);
        return 2;
    }
    int tangentline(Point q,Line &u,Line &v){
        int x=relation(q);
        if (x==2) return 0;
        if (x==1) {
            u=Line(q,q+(q-p).rotleft());
            v=Line(q,q+(q-p).rotright());
            return 2;
        }
        double d=p.distance(q),l=r*r/d,h=sqrt(r*r-l*l);
        u=Line(q,p+((q-p).trunc(l)+(q-p).rotleft().trunc(h)));
        v=Line(q,p+((q-p).trunc(l)+(q-p).rotright().trunc(h)));
        return 2;
    }
    void circlewithcircle_s_tangentline1(Circle b,Line &u,Line &v){
        Point mid=(p+b.p)/2,p1,p2;
        tangentline(mid,u,v);
        v.e=v.e-v.s;v.s=Point(0,0);
        v.e=v.e.rotright();
        u.e=u.e-u.s;u.s=Point(0,0);
        u.e=u.e.rotleft();
        swap(u,v);
    }
    void circlewithcircle_s_tangentline2(Circle b,Line &u,Line &v){
        Point mid=(p+b.p)/2;
        tangentline(mid,u,v);
    }
}O1,O2,O3;

void solve(){
	int x1,y1,x2,y2,x3,y3;
	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
	Circle c1 = Circle{Point{x1,y1}, 1};
	Circle c2 = Circle{Point{x2,y2}, 1};
	Circle c3 = Circle{Point{x3,y3}, 1};
	
	Line l[5];
	double a[5];
	c2.circlewithcircle_s_tangentline1(c1,l[1],l[2]);
	c3.circlewithcircle_s_tangentline2(c2,l[3],l[4]);
	
	for(int i=1;i<=4;i++)a[i] = l[i].angle();
	printf("%f %f\n",a[1],a[2]);
	
	int f=1;
	if(a[1] > a[2])a[1] -= 2.0*pi;
	if(a[3] > a[4])a[3] -= 2.0*pi;
	f=0;
	for(int i=-2;i<=2;i+=2){
		double j=pi*i;
		if(a[1]==a[2])break;
		if(a[1]<a[3]+j&&a[3]+j<a[2])f=1;
		if(a[1]<a[4]+j&&a[4]+j<a[2])f=1;
		if(a[1]==a[3]+j&&a[2]==a[4]+j)f=1;
	}
	puts(f ? "yes" : "no");
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

