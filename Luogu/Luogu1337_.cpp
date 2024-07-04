// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int T = 100000;

mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}

int n;
struct point{
	int x,y,w;
}a[maxn];
double ansx=0, ansy=0, answ = 0;

double gete(double x,double y){
	double r = 0;
	for(int i=1;i<=n;i++){
		double dx = x - a[i].x;
		double dy = y - a[i].y;
		r += sqrt(dx*dx + dy*dy) * a[i].w;
	}
	return r;
}

void sa(){
	double t = 3000;
	while(t > 1e-9){
		double ex = ansx + (rnd(T)*2 - T)*t;
		double ey = ansy + (rnd(T)*2 - T)*t;
		double ew = gete(ex,ey);
		double delt = ew - answ;
		if(delt < 1e-9){
			ansx=ex, ansy=ey, answ=ew;
		}else if(exp(-delt/t) * T > rnd(T))
			ansx=ex, ansy=ey;
		t *= 0.997;
	}
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
		ansx += a[i].x;
		ansy += a[i].y;
	}
	ansx /= n,ansy /= n;
	answ = gete(ansx, ansy);
	sa();sa();
	printf("%.3f %.3f\n",ansx,ansy);

	return 0;
}

