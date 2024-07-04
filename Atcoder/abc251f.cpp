// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n,m;
vector<int>g[maxn];
int vis[maxn];
vector<pii>ans1,ans2;
queue<int>Q;

void dfs(int x){
	vis[x] = 1;
	for(int u : g[x])if(!vis[u]){
		ans1.push_back(mpr(x, u));
		dfs(u);
	}
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y), g[y].push_back(x);
	}
	dfs(1);
	memset(vis,0,sizeof vis);
	Q.push(1);vis[1] = 1;
	while(!Q.empty()){
		int x = Q.front();Q.pop();
		for(int u : g[x])if(!vis[u]){
			ans2.push_back(mpr(x, u));
			vis[u] = 1;
			Q.push(u);
		}
	}
	for(auto u : ans1)printf("%d %d\n",u.first,u.second);
	for(auto u : ans2)printf("%d %d\n",u.first,u.second);

	return 0;
}

