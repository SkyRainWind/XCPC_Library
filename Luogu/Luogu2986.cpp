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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e5 + 5;

int n;
int c[maxn];
LL dp[maxn], tot[maxn], r;
vector<pii>g[maxn];
int dep[maxn];

void dfs2(int x,int fat = -1){
	for(pii now : g[x]){
		int u = now.first, v = now.second;
		if(u == fat)continue;
		dp[u] = dp[x] + 1ll * v * (r - 2 * tot[u]);
		dfs2(u, x);
	}
}

void dfs(int x,int fat = -1){
	tot[x] = c[x];
	for(pii now : g[x]){
		int u = now.first, v = now.second;
		if(u == fat)continue;
		dep[u] = dep[x] + v;
		dp[1] += 1ll * c[u] * dep[u];
		dfs(u, x);
		tot[x] += tot[u];
	}
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]), r += c[i];
	for(int i=1;i<=n-1;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		g[x].push_back(mpr(y,z));
		g[y].push_back(mpr(x,z));
	}
	dfs(1);
	dfs2(1);
	LL ans = dp[1];
	for(int i=1;i<=n;i++)ans = min(ans, dp[i]);
	printf("%lld\n",ans);

	return 0;
}


