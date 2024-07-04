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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e5+5;

int n,k;
vector<int>g[maxn];
int c[maxn], down[maxn][22], dp[maxn][22];

void dfs2(int x,int fat =-1){
	for(int u : g[x]){
		if(u == fat)continue;
		for(int i=1;i<=k;i++){
			int tt = 0;
			if(i >= 2)tt =down[u][i-2];
			dp[u][i] = dp[x][i-1] - tt + down[u][i];
		}
		dfs2(u, x);
	}
}

void dfs(int x,int fat = -1){
	for(int i=1;i<=k;i++)down[x][i] += c[x];
	for(int u : g[x]){
		if(u == fat)continue;
		dfs(u, x);
		for(int i=1;i<=k;i++)
			down[x][i] += down[u][i-1]; 
	}
}

signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y), g[y].push_back(x);
	}
	for(int i=1;i<=n;i++)scanf("%d",&c[i]), down[i][0] = dp[i][0] = c[i];
	dfs(1);
	for(int i=0;i<=k;i++)dp[1][i] = down[1][i];
	dfs2(1);
	for(int i=1;i<=n;i++)printf("%d\n",dp[i][k]);

	return 0;
}


