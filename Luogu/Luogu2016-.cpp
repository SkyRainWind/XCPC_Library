// by Balloons
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=1505;

// dp[i][0/1][0/1] i 结点 不放/放人 子节点放/不放人 
// dp[i][1][0] = sum{min(dp[u][0][1], dp[u][0][0])} + 1
// 枚举 v 
// dp[i][1][1] = min(dp[v][1][0],dp[v][1][1]) + sum{u!=v|min(dp[u][1][0],dp[u][1][1],dp[u][0][1],dp[u][0][0])} + 1
// dp[i][0][0] = sum(dp[u][0][1])
// dp[i][0][1] = min(dp[v][1][0],dp[v][1][1]) + sum(u!=v|min(dp[u][1][0],dp[u][1][1],dp[u][0][1])) 

int dp[maxn][2][2];
vector<int>g[maxn]; 
int cur[maxn],cur2[maxn],n;

void ckmn(int &a,int b){a = min(a,b);}

void dfs(int x,int fat = -1){
	if(~fat && g[x].size() == 1){
		dp[x][1][0] = dp[x][1][1] = 1; dp[x][0][1] = 0;
		return ;	
	}
	for(int i=0;i<g[x].size();i++){
		int u = g[x][i];if(u == fat)continue;
		dfs(u, x);
	}
	dp[x][1][0] = 1;dp[x][1][1] = 1;dp[x][0][1] = 0;
	for(int u : g[x]){
		if(u == fat)continue;
		if(x == 167)printf("%d %d %d %d\n",u,dp[u][0][1], dp[u][1][1], dp[u][1][0]);
		dp[x][1][0] += dp[u][0][1];
		dp[x][1][1] += min(dp[u][1][0], dp[u][1][1]); 
		dp[x][0][1] += min(dp[u][1][0], dp[u][1][1]);
	}
}

signed main(){
	freopen("2016.in","r",stdin);
	scanf("%lld",&n);
	memset(dp, 0x3f ,sizeof dp);
	for(int i=1;i<=n;i++){
		int nu,x;scanf("%lld%lld",&x,&nu);++ x;
		while(nu --){
			int v;scanf("%lld",&v);++ v;
			g[x].push_back(v); g[v].push_back(x);
		}
	}
//	return 0;
	dfs(1);
	for(int i=1;i<=200;i++)printf("%d %d %d %d\n",i,dp[i][1][1], dp[i][1][0], dp[i][0][1]);
	int i=500;printf("%d %d %d %d\n",i,dp[i][1][1], dp[i][1][0], dp[i][0][1]);
//	printf("%d\n",dp[2][1][0]);
	ckmn(dp[1][1][1], min(dp[1][1][0], dp[1][0][1]));
	printf("%lld\n",dp[1][1][1]);
	
	return 0;
}

