// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 998244353;

int n;
int dp[2005][2005];

void solve(){
	scanf("%d",&n);
	int ans = 0;
	for(int i=1;i<=n;i++)
		(ans += 1ll * dp[n][i] * (n-i)%mod) %= mod;
	printf("%d\n",ans);
}

signed main(){
	// 1 3 1
	dp[1][1] = 1;
	for(int i=2;i<=2000;i++){
		int s=0;
		for(int j=1;j<=i;j++)
			dp[i][j] = (dp[i-1][j-1] + 1ll*dp[i-1][j]*(i-1)%mod) % mod,
			s += dp[i][j];
//		if(i<=10)printf("%d %d\n",i,s);
	}
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

