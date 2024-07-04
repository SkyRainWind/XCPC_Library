// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5, inv2 = 499122177, mod = 998244353;

int exgcd(int a,int b,int &x,int &y){
	if(!b){
		x=1, y=0;
		return a;
	}
	int ret = exgcd(b,a%b,x,y);
	int t = x;
	x = y;
	y = t - a/b*y;
	return ret;
}

int count(int a,int b,int x,int y){	// ax+by=C
	int minx = x - x/b*b, yy = y + x/b*a;
	int miny = y - y/a*a, xx = x + y/a*b;
	if(xx < minx)return 0;
	return (xx - minx) / b + 1;
}

int n,a[maxn];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
	int ans = 0;
	for(int l=1,r;l<=n;l=r+1){
		int r1 = a[n] / (a[n] / l), r2 = (a[n]-1) / ((a[n]-1) / l) + 1;
		r = min(min(r1, r2), n);
		int x1 = a[n] / r, x2 = (a[n]-1) / r + 1;
		printf("? %d %d\n",x1,x2);
		int x, y;
		int gd = exgcd(x1, x2, x, y);
		x *= gd, y *= gd;
		
		int rr = count(x1, x2, x, y);
		(ans += 1ll*rr*(r-l+1)%mod*(l+r)%mod*inv2%mod) %= mod;
	}
	printf("%d\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

