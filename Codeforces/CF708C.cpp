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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=4e5+5;

int n;
vector<int>g[maxn];
int rt;
int sz[maxn], mx[maxn][2], ans[maxn], dp[maxn];

void dfs3(int x,int fat = -1){
	for(int u : g[x]){
		if(u == fat)continue;
		if(mx[x][0] == sz[u]){
			dp[u] = max(dp[u], mx[x][1]);
		}else dp[u] = max(dp[u], mx[x][0]);
		if(n - sz[u] <= n/2)dp[u] = max(dp[u], n - sz[u]);
		dp[u] =max(dp[u], dp[x]);
		dfs3(u, x);
	}
}

void dfs2(int x,int fat = -1){
	sz[x] = 1;
	for(int u : g[x]){
		if(u == fat)continue;
		dfs2(u, x);
		sz[x] += sz[u];
		if(sz[u] > n/2)continue;
		if(mx[x][0] <= sz[u]){
			mx[x][1] = mx[x][0];
			mx[x][0] = sz[u];
		}else if(mx[x][1] <= sz[u])mx[x][1] = sz[u];
	}
}

void dfs(int x,int fat = -1){
	sz[x] = 1;
	int iscen = 1;
	for(int u : g[x]){
		if(u == fat)continue;
		dfs(u, x);
		sz[x] += sz[u];
		if(sz[u] > n/2)iscen = 0;
	}
	if(n - sz[x] > n/2)iscen = 0;
	if(iscen)rt = x;
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y), g[y].push_back(x);
	}
	dfs(1);
	dfs2(rt);
	dfs3(rt);
	for(int i=1;i<=n;i++){
		if(i == rt || (n - sz[i] - dp[i]) <= n/2)printf("1 ");
		else printf("0 ");
	}
	puts("");

	return 0;
}


