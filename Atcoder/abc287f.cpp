// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5005, mod=998244353;

int n;
vector<int>g[maxn];
int sz[maxn];
ll dp[maxn][maxn][2];
ll ndp[maxn][2];

void dfs(int x,int fat=0){
	sz[x] = 1;
	dp[x][0][0] = dp[x][1][1] = 1;
	for(int u : g[x])if(u!=fat){
		dfs(u, x);
		
		for(int j=0;j<=n;j++)ndp[j][0] = ndp[j][1] = 0; 
		for(int j=0;j<=sz[x];j++)
			for(int k=0;k<=sz[u];k++){
				(ndp[j+k][0] += dp[x][j][0] * (dp[u][k][0]+dp[u][k][1])%mod) %= mod;
				(ndp[j+k][1] += dp[x][j][1] * dp[u][k][0]%mod) %= mod;
				if(j+k)(ndp[j+k-1][1] += dp[x][j][1] * dp[u][k][1]%mod) %= mod;
			}
		
		swap(dp[x], ndp);
		sz[x] += sz[u];
	}
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
	}
	
	dfs(1);
	for(int i=1;i<=n;i++){
		ll ans = (dp[1][i][0] + dp[1][i][1]) % mod;
		printf("%lld\n",ans);
	}

	return 0;
}

