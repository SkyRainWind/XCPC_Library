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
#define int LL

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5 + 5;

int n,k;
int dp[maxn], a[maxn];
int qu1[maxn], qu2[maxn], hd=1, tl = 0, sum[maxn];

signed main(){
//	freopen("2627_2.in","r",stdin);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]), sum[i] = sum[i-1] + a[i];
	int ans = 0;
	for(int i=1;i<=n;i++){
		dp[i] = qu1[hd] + sum[i - 1];
		if(i <= k+1)dp[i] = max(dp[i], sum[i-1]);
//		printf("%d %d %d\n",i,dp[i],qu2[hd]);
		ans = max(ans, dp[i]);
		while(hd <= tl && qu1[tl] <= dp[i] - sum[i])-- tl;
		qu1[++ tl] = dp[i] - sum[i], qu2[tl] = i;
		while(hd <= tl && qu2[hd] < (i+1)-k-1)++ hd;
	}
//	printf("%d %d\n",qu2[hd],qu1[hd]);
	ans = max(ans, qu1[hd] + sum[n]);
	printf("%lld\n",ans);

	return 0;
}


