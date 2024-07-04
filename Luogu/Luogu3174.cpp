// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 3e5 + 5;

int n,m;
vector<int>g[maxn];
int de[maxn], vis[maxn], dp[maxn], ans = 1, rt;

void dfs(int x,int fat = -1){
	vis[x] = 1;
	int mx = -1, smx = -1;
	for(int u : g[x]){
		if(u == fat)continue;
		dfs(u, x);
		if(dp[u] > mx){
			smx = mx, mx = dp[u];
		}else if(dp[u] > smx)smx = dp[u];
	}
	if(x == rt){
		if(mx==-1){ans=max(ans,1);return ;}
		if(smx==-1){ans=max(ans,mx+1);return ;}
		int tmp=mx+smx+1;
		if(de[x]>=2)tmp+=de[x]-2;
		ans=max(ans,tmp);
		return ;
	}
	
	if(mx == -1){	// leaf
		dp[x] = 1;ans=max(ans,1);
		return ;
	}
	if(smx == -1){	// chain
		dp[x] = mx + 1;
		ans = max(ans, dp[x] + 1);	// + 1 -> father
		return ;
	}
	int tmp = mx + smx + 1;
	if(de[x] >= 3)tmp += de[x]-2;
	ans = max(ans, tmp);
	dp[x] = mx + 1;
	if(de[x] >= 2)dp[x] += de[x]-2;
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y), g[y].push_back(x);
		++ de[x], ++ de[y];
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])rt=i,dfs(i);
	printf("%d\n",ans);

	return 0;
}

