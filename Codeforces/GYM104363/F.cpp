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

int n;
vector<int>g[maxn];
int dep[maxn],mx = 0;
int dp[maxn];

void dfs(int x,int fat=0){
	if(g[x].size()==0)return ;
	dep[x] = dep[fat] + 1;
	mx = max(mx, dep[x]);
	int rr=0, rs=0;
	for(int u : g[x]){
		dfs(u, x);
		rr = max(rr, dp[u] + 1);
		rs += dp[u] + 1;
	}
	dp[x] = rs - 1;
}

signed main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		int x;scanf("%d",&x);
		g[x].pb(i);
	}
	dfs(1);
	// printf("%d\n",dp[3]);
	printf("%d\n", dp[1]);

	return 0;
}
