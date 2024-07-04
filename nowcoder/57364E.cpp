// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;
typedef double db;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e5+5;
const db eps = 1e-12,pi=3.141592653897;

db rad = 0;

int sgn(db x) {
    if (fabs(x)<eps) return 0;
    if (x<0) return -1;
    return 1;
}

// 感谢板子 
struct Point {
    db x,y;
    Point (){}
    Point (db _x,db _y):x(_x),y(_y){}
    db distance(const Point &b) const{
        return hypot(x-b.x,y-b.y);
    }
    db len(){return hypot(x,y);}
    Point operator +(const Point &b) const{return Point (x+b.x,y+b.y);}
    Point operator -(const Point &b) const{return Point (x-b.x,y-b.y);}
    db operator *(const Point &b)const{return x*b.x+y*b.y;}
    Point operator *(const db &k) const{return Point (x*k,y*k);}
    Point operator /(const db &k) const{return Point (x/k,y/k);}
    db operator ^(const Point &b)const {return x*b.y-y*b.x;}
    db len2(){return x*x+y*y;}	// hypot
    Point trunc(db r){
        db l=len();
        if (!sgn(l)) return *this;
        r/=l;
        return Point(x*r,y*r);
    }
    // 向左/右转 90 
    Point rotleft() {return Point(-y,x);}
    Point rotright(){return Point(y,-x);}
};
struct Circle{
    Point p;db r;
    Circle(){}
    Circle(Point _p,db _r):p(_p),r(_r){}
};
int n;

Point rot(pii now,db cs,db sn){	// 逆时针旋转 th 
	db x1 = now.first*cs - now.second*sn;
	db y1 = now.first*sn + now.second*cs;
	return Point{x1,y1};
}
pair<pii,int>a[200005];

db getans(db rad){
	db l,r,u,d;
    db cs=cos(rad),sn=sin(rad);
	l=d=1e12, r=u=-1e12;
	for(int i=1;i<=n;i++){
		Point now = rot(a[i].first,cs,sn);
		l = min(l, now.x - a[i].second);
		r = max(r, now.x + a[i].second);
		u = max(u, now.y + a[i].second);
		d = min(d, now.y - a[i].second);
	}
	return max(r-l, u-d);
}

int rnd(int x){return rand()%x;}

db ans = 0, res=1e18,br;

void sa(int now){
    
    mt19937 rnd(random_device{}());
    uniform_real_distribution<double> dist(0, 1);
	int T = 1000;
	db t = 10000;
	int cnt=0;
	while(t > 1e-8){
		db nrad = rad + (dist(rnd) - 0.5) * pi / 2 * t;
		db nans = getans(nrad);
        res = min(res, nans);
		db delt = nans - ans;
		if(delt < 0)br=rad=nrad;
		if(exp(-delt/t) > dist(rnd))rad = nrad,ans=nans;
		t *= 0.998;
	}
}

signed main(){
    
    mt19937 rnd(random_device{}());
    uniform_real_distribution<double> dist(0, 1);
    srand(time(0));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].first.first,&a[i].first.second,&a[i].second);
	
	rad=br =  (dist(rnd) - 0.5) * pi/ 2;
	res = ans=getans(rad);
	
	for(int i=1;i<=1;i++)sa(i);
    rad=br;
	for(int i=1;i<=5000;i++){
		double nrad = rad + (dist(rnd) - 0.5) * pi / 2 / 1000000;
		double nans = getans(nrad);
		if(nans < res)res = nans, rad = nrad;
	}
	printf("%.9f\n",res);

	return 0;
}

