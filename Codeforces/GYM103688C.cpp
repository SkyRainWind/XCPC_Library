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

// dp[i][0/1] 表示考虑到 i 结点，如果 i 作为上升/下降序列，下降序列的max/上升序列的min 
int n,a[maxn];
int dp[maxn][2];
vector<int>g[maxn];

void dfs(int x,int fat){
	dp[x][0] = -inf, dp[x][1] = inf;
//	printf("%d %d %d\n",x,dp[x][0],dp[x][1]);
	
	for(int u : g[x]){
		if(u == fat)continue;
		dfs(u, x);
		
        int mn = inf;
        if(a[u] > a[x])mn = min(mn, dp[u][0]);
        if(dp[u][1] > a[x])mn = min(mn, a[u]);
        dp[x][0] = max(dp[x][0], mn);
        int mx = -inf;
        if(a[u] < a[x])mx = max(mx, dp[u][1]);
        if(dp[u][0] < a[x])mx = max(mx, a[u]);
        dp[x][1] = min(dp[x][1], mx);
	}
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
	}
	dfs(1,0);
	if(dp[1][0] != inf || dp[1][1] != -inf)puts("YES");
	else puts("NO");

	return 0;
}

