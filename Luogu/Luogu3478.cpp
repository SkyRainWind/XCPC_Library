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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e6 + 5;

int n;
vector<int>g[maxn];
int dep[maxn], sz[maxn];
LL dp[maxn];

void dfs2(int x,int fat = -1){
	for(int u : g[x]){
		if(u == fat)continue;
		dp[u] = dp[x] - sz[u] + (n - sz[u]);
		dfs2(u, x);
	}
}

void dfs(int x,int fat = -1){
	sz[x] = 1;
	for(int u : g[x]){
		if(u == fat)continue;
		dep[u] = dep[x] + 1;
		dfs(u, x);
		sz[x] += sz[u];
	}
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y), g[y].push_back(x);
	}
	dfs(1);
	for(int i=1;i<=n;i++)dp[1] += dep[i];
	dfs2(1);
	LL ans = 0, ansi;
	for(int i=1;i<=n;i++)ans = max(ans, dp[i]), ans == dp[i] ? (ansi = i) : 1;
	printf("%lld\n",ansi);

	return 0;
}


