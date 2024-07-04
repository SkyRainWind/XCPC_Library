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

int xa,ya,xb,yb,xc,yc,a,b;

double calc(int x1,int y1,int x2,int y2,int v){
	return (abs(x1-x2) + abs(y1-y2)) * 1. / v;
}

void solve(){
	scanf("%d%d",&a,&b);
	scanf("%d%d",&xa,&ya);
	scanf("%d%d",&xb,&yb);
	scanf("%d%d",&xc,&yc);
	double ans = calc(xa,ya,xc,yc,a);
	int l = min(xa,xb), r = max(xa,xb), u = max(ya,yb), d = min(ya,yb);
	int xd = max(l, min(r,xc)), yd = max(d, min(u,yc));
	double t1 = calc(xa,ya,xd,yd,a), t2 = calc(xb,yb,xd,yd,b);
	if(t1 < t2)ans = min(ans, calc(xb,yb,xc,yc,b));
	else{
		double nw = (abs(xb-xa)+abs(yb-ya)-t2*(a+b)) *1. / (a+b) + t2;
		ans = min(ans, nw + (abs(xc-xa) + abs(yc-ya) - a*nw) * 1./ b);
	}
	printf("%.9f\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

