// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5,mod=1e9+7;

int n;
vector<int>g[maxn];
ll dp[maxn][2],vis[maxn];

void dfs(int x,int fat=0){
	vis[x]=1;
	dp[x][0]=dp[x][1]=1;
	
	for(auto u : g[x])if(u!=fat){
		dfs(u, x);
		(dp[x][0] *= dp[u][1]) %= mod;
		(dp[x][1] *= (dp[u][0] + dp[u][1])) %= mod;
	}
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
	}
	ll ans=0;
	for(int i=1;i<=n;i++)if(!vis[i]){
		dfs(i);
		(ans+=dp[i][0]+dp[i][1])%=mod;
	}
	cout<<ans;

	return 0;
}

