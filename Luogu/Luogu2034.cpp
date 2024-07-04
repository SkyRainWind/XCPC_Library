// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+ 5;

int n,k;
int a[maxn];
LL dp[maxn], qu[maxn], qu2[maxn];

signed main(){
	scanf("%d%d",&n,&k);
	LL sum = 0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), sum += a[i];
	int hd=1, tl=0;
//	for(int i=1;i<=k;i++)dp[i] = 0, qu[++ tl] = 0, qu2[tl] = i;
	qu[++ tl] = 0;qu2[tl] = 0;
	for(int i=1;i<=n;i++){
		while(hd <= tl && qu[tl] >= qu[hd] + a[i])-- tl;
		dp[i] = qu[hd] + a[i];	// i-k-1 .. i-1
		qu[++ tl] = dp[i];
		qu2[tl] = i;
		while(hd <= tl && i - qu2[hd] >= k+1)++ hd;
	}
//	printf("%lld\n",dp[3]);
	LL r = 1e18;
	for(int i=n-k;i<=n;i++)r = min(r, dp[i]);
	printf("%lld\n",sum - r);

	return 0;
}


