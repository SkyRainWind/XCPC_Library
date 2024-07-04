// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e9, INF = 0x3f3f3f3f, maxn= 2e5 + 5;

int n;
int a[maxn];
pair<int,int>p1[maxn], p2[maxn];

signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	
	int now = 1;
	LL sl = a[1], sr = a[2];
	p1[2] = mpr(sl, sr);
	for(int i=3;i<=n-2;i++){	// sl = a[1..now] sr = a[now+1..i]
		sr += a[i];
		while(now+1 < i && abs(sl - sr) > abs(sl + a[now+1] - (sr - a[now+1])))
			sl += a[now+1], sr -= a[now+1], ++ now;
		p1[i] = mpr(sl, sr);
	}
	now = n;
	sl = a[n-1], sr = a[n];
	p2[n-2] = mpr(sl, sr);
	for(int i = n-2;i>=3;i--){
		sl += a[i];
		while(now-1 > i && abs(sl - sr) > abs(sl - a[now-1] - (sr + a[now-1])))
			sl -= a[now-1], sr += a[now-1], -- now;
		p2[i-1] = mpr(sl, sr);
	}
	
	int ans = 2e9;
	for(int i=2;i<=n-2;i++){
		int tt[] = {p1[i].first, p1[i].second, p2[i].first, p2[i].second};
		sort(tt, tt+4);
		ans = min(ans, tt[3] - tt[0]);
	}
	printf("%lld\n",ans);

	return 0;
}


