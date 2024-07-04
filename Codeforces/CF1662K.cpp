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
const double eps = 1e-7;

struct point{double x,y;}p[5],q[5];

point operator +(point a,point b){return point{a.x+b.x,a.y+b.y};}
point operator -(point a,point b){return point{a.x-b.x,a.y-b.y};}
point operator /(point a,double k){return point{a.x/k,a.y/k};}
point operator *(point a,double k){return point{a.x*k,a.y*k};}

pair<double,double>pd;
double res=1e9;
int tt;

double sq(double x){return x*x;}
double f5(double x,double y){
	double r=0.0;
	for(int i=1;i<=3;i++)r += sqrt(sq(x-q[i].x) + sq(y-q[i].y));
	return r;
}

double f4(double p){
	double l=-1e4, r=1e4;
	int c=0;
	while(++c<=tt&&r-l > eps){
//		printf("%.6f %.6f\n",l,r);
		double lmid = (l*2+r) / 3.0;
		double rmid = (l+2*r) / 3.0;
//		printf(" -> %.6f %.6f\n",lmid,rmid);
		double lr = f5(p,lmid), rr = f5(p,rmid);
		if(lr < rr)r = rmid;
		else l = lmid;
//		printf("    -> %.6f %.6f\n",l,r);
	}
	return f5(p,l);
}

double dis(point a,point b){
	return sqrt(sq(a.x - b.x) + sq(a.y - b.y));
}

double f3(){
	point ans = q[1];
	double t = 1;
	while(t > eps){
		point d;
		for(int i=1;i<=3;i++){
			point delt = q[i] - ans;
			double dist = sqrt(sq(delt.x) + sq(delt.y));
			if(dist > eps)
				d = d + delt / dist;
		}
		ans = ans + d * t;
		t *= 0.99;
	}
	return dis(q[1],ans) + dis(q[2],ans) + dis(q[3],ans);
}

double f2(double x,double y){
	double r = 0.0; 
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++)q[j] = p[j];
		q[i] = point{x,y};
		r = max(r, f3());
	}
	res = min(res, r);
	return r;
}

double f1(double x){
	double l=-1e4, r=1e4;
	int c=0;
	while(++c<=tt&&r-l > eps){
		double lmid = (l*2+r) / 3.0;
		double rmid = (l+2*r) / 3.0;
		double lr = f2(x,lmid), rr = f2(x,rmid);
		if(lr < rr)r = rmid;
		else l = lmid;
	}
	return f2(x,l);
}

signed main(){
	for(int i=1;i<=3;i++)
		scanf("%lf%lf",&p[i].x,&p[i].y);
	
	double l=-1e4, r=1e4;
	int c=0;
	tt=50;
	while(r-l > eps&&++c<=tt){
		double lmid = (l*2+r) / 3.0;
		double rmid = (l+2*r) / 3.0;
		double lr = f1(lmid), rr = f1(rmid);
		if(lr < rr)r = rmid;
		else l = lmid;
	}
	tt=100;
	f1(l);
	printf("%.9f\n",res);

	return 0;
}

