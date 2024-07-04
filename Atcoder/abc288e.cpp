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

int n,k,a[maxn],c[maxn],must[maxn];
ll dp[5005][5005];

signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1,x;i<=k;i++){
		scanf("%d",&x);
		must[x] = 1;
	}
	
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j] = 1e18;
	dp[0][0] = 0;
	for(int i=1;i<=n;i++){
		ll cst = 1e18;
		if(!must[i])dp[i][0] = dp[i-1][0];
		for(int j=1;j<=i;j++){
			cst = min(cst, 1ll * c[i - j + 1]);
			dp[i][j] = min(dp[i][j], dp[i-1][j-1] + cst + a[i]);
			if(!must[i])dp[i][j] = min(dp[i][j], dp[i-1][j]);
		}
	}
	ll ans = 1e18;
	for(int i=k;i<=n;i++)ans = min(ans, dp[n][i]);
	cout << ans << '\n';

	return 0;
}

