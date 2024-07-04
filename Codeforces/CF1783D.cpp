// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 305, mod = 998244353;

int n,a[maxn];
unordered_map<int,int>dp[2];

signed main(){
// 	freopen("D.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dp[2&1][a[2]] = 1;
	for(int i=2;i<=n-1;i++){
		dp[i+1&1].clear();
		for(auto pr : dp[i&1]){
			int lstt = pr.first, dpp = pr.second;
//			if(!dp[i+1&1].count(lstt+a[i+1]))dp[i+1&1][lstt + a[i+1]] = 0;
			(dp[i+1&1][lstt + a[i+1]] += dp[i&1][lstt]);
			if(dp[i+1&1][lstt+a[i+1]]>=mod)dp[i+1&1][lstt+a[i+1]]-=mod;
			
			if(lstt == 0)continue;
//			if(!dp[i+1&1].count(a[i+1] - lstt))dp[i+1&1][a[i+1] - lstt] = 0;
			(dp[i+1&1][a[i+1] - lstt] += dp[i&1][lstt]);
			if(dp[i+1&1][a[i+1] - lstt] >= mod)dp[i+1&1][a[i+1] - lstt] -= mod;
		}
	}
//	printf("%d %d\n",dp[3][1],dp[3][5]);
	ll ans=0;
	for(auto pr : dp[n&1])
		(ans += pr.second) %= mod;
	cout<<ans;

	return 0;
}
