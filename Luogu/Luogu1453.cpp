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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=1e5 + 5;

int n,p[maxn];
vector<int>g[maxn];
int vis[maxn], rt, prt, dp[maxn][2];

void dfs(int x,int fat = -1){
	vis[x] = 1;
	for(int u : g[x]){
		if(u == fat)continue;
		if(vis[u]){rt = u;prt = x;continue;}
		dfs(u, x);
	}
}

void upd(int x,int fat = -1){
	dp[x][0] = 0, dp[x][1] = p[x];
	for(int u : g[x]){
		if(u == fat || (x == rt && u == prt))continue;
		if(u == rt){
			dp[x][1] = -inf;
			continue;
		}
		upd(u, x);
		dp[x][1] += dp[u][0];
		dp[x][0] += max(dp[u][0], dp[u][1]);
	}
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++){
		int x,y;scanf("%d%d",&x,&y);
		++ x, ++ y;
		g[x].push_back(y), g[y].push_back(x);
	}
	double kf;scanf("%lf",&kf);
	dfs(1);
	upd(rt);
	int t1 = max(dp[rt][0], dp[rt][1]);
	swap(rt, prt);
	upd(rt);
	int ans = max(t1, max(dp[rt][0], dp[rt][1]));
	printf("%.1f\n",kf * ans);

	return 0;
}


