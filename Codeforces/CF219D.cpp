// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5 + 5;

int n;
map<pii,int>mp;
vector<int>g[maxn];
int dp[maxn];

void dfs0(int x,int fat=0){
	for(int u : g[x])if(u!=fat){
		if(mp.count(mpr(x, u)) == 0)++ dp[1];
		dfs0(u, x);
	}
}

void dfs(int x,int fat=0){
	for(int u : g[x])if(u!=fat){
		if(mp.count(mpr(x, u)) == 0)dp[u] = dp[x] - 1;
		else dp[u] = dp[x] + 1 ;
		dfs(u, x);
	}
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y), g[y].push_back(x);
		mp[mpr(x,y)] = 1;
	}
	dfs0(1);dfs(1);
	int mn = 1e9;
	for(int i=1;i<=n;i++)
		if(mn > dp[i])mn = dp[i];
	printf("%d\n",mn);
	for(int i=1;i<=n;i++)
		if(dp[i] == mn)printf("%d ",i);

	return 0;
}

