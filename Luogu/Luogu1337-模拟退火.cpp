// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=1e5+5;
const long double eps = 1e-18;
long double dist(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
int n,m[maxn];
double x[maxn],y[maxn];
double nowx=0, nowy=0, ansx=0, ansy=0;
long double nowans = 0, ans = 1e18;
void sa(){
	long double T = 2000;
	while(T > eps){
		double curx = nowx + (rand()*2 - 32767) * T;
		double cury = nowy + (rand()*2 - 32767) * T;
		nowans = 0;
		for(int i=1;i<=n;i++)
			nowans += dist(curx,cury,x[i],y[i]) * m[i];
		if(nowans < ans){
			ans = nowans;
			nowx = ansx = curx;
			nowy = ansy = cury;
		}else{
			if(exp(-(nowans - ans) / T)*32767 > rand()){
				nowx = curx, nowy = cury;
			}
		}
		T *= 0.998;
	}
}
signed main(){
	srand(time(0));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf%lf%d",&x[i],&y[i],&m[i]);
	}
	sa();sa();sa();
	printf("%.3f %.3f\n",ansx, ansy);

	return 0;
}

