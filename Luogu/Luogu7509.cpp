// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 998244353, maxn = 2e5+5;

int n,k,a[maxn],p[maxn];
int dp[maxn][22][2], g[maxn][22][2];

ll pw(ll x,int y){
	if(!y)return 1;
	if(y == 1)return x%mod;
	ll mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

signed main(){
//	freopen("Luogu7509.in","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	
	g[0][0][0] = 1;
	for(int i=1;i<=n;i++){
		dp[i][0][0] = 0;
		g[i][0][0] = 1ll * (1-p[i]+mod) * g[i-1][0][0] % mod;
		for(int j=1;j<=min(k, (i+1)/2);j++){
			(dp[i][j][0] += 1ll * (1-p[i]+mod) * (dp[i-1][j][1] + dp[i-1][j][0]) % mod) %= mod;
			(dp[i][j][1] += 1ll * p[i] * (dp[i-1][j-1][0] + 1ll * g[i-1][j-1][0] * a[i] % mod) % mod) %= mod;
			(dp[i][j][1] += 1ll * p[i] * (dp[i-1][j][1] + 1ll * g[i-1][j][1] * a[i] % mod) % mod) %= mod;
			(g[i][j][1] += 1ll * p[i] * (g[i-1][j][1]+g[i-1][j-1][0]) % mod) %= mod;
			(g[i][j][0] += 1ll * (1-p[i]+mod) * (g[i-1][j][1] + g[i-1][j][0]) % mod) %= mod;
		}
	}
	int bs = pw((g[n][k][1] + g[n][k][0])%mod, mod-2);
	cout<<(dp[n][k][1]+dp[n][k][0])%mod;

	return 0;
}

