// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;
int n;double L,R;
double a[222];
double f(double x){
	double t = 1, r = 0;
	for(int i=n+1;i>=1;i--){
		r += a[i] * t;
		t *= x;
	}
	return r;
}
signed main(){
	scanf("%d%lf%lf",&n,&L,&R);
	for(int i=1;i<=n+1;i++)scanf("%lf",&a[i]);
	while(R-L > 1e-6){
		double lmid = L+(R-L)/3.0;
		double rmid = R-(R-L)/3.0;
		if(f(lmid) > f(rmid))R = rmid;
		else L = lmid;
	}
	printf("%.5f\n",L);

	return 0;
}

