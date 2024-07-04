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

int n,k,p;
vector<pii>g[maxn];
ll dp[maxn][105][2], tmp[105][2];
int sz[maxn];

void dfs(int x,int fat=0){
	for(int i=0;i<=k;i++)dp[x][i][0]=dp[x][i][1]=-1e18;
	dp[x][0][0] = dp[x][0][1] = dp[x][1][0] = 0;
	sz[x] = 1;
	
	for(auto it : g[x]){
		int u = it.first, v = it.second;
		if(u == fat)continue;
		
		dfs(u, x);
		for(int i=0;i<=k;i++)tmp[i][0] = tmp[i][1] = -1e18;
		
		for(int i=0;i<=min(sz[x], k);i++)
			for(int j=0;j<=min(sz[u], k-i);j++){
				tmp[i+j][1] = max(tmp[i+j][1], dp[x][i][1] + dp[u][j][0]);
				tmp[i+j][0] = max(tmp[i+j][0], dp[x][i][0] + dp[u][j][0]);
				tmp[i+j][0] = max(tmp[i+j][0], dp[x][i][1] + dp[u][j][1] + v);
			}
		
		sz[x] += sz[u];
		for(int i=0;i<=k;i++)dp[x][i][0] = tmp[i][0], dp[x][i][1] = tmp[i][1];
	}
}

signed main(){
	scanf("%d%d%d",&n,&k,&p);k*=2;
	for(int i=1;i<n;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		g[x].pb(mpr(y,z));
		g[y].pb(mpr(x,z));
	}
	dfs(1);
	ll ans = 0;
	for(int i=0;i<=k;i++)ans = max(ans, max(dp[1][i][0], dp[1][i][1]) + 1ll*i/2*p);
	cout << ans << '\n';

	return 0;
}

