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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 200005;

int n,m,e;
vector<int>g[maxn];
int vis[maxn], mtch[maxn], pp[maxn], bride[maxn];

int dfs(int x,int to){
	for(int u : g[x])if(vis[u] != to){
		vis[u] = to;
		if(mtch[u] == 0 || dfs(mtch[u], to)){
			mtch[u] = x;
			return 1;
		}
	}
	return 0;
}

signed main(){
	scanf("%d%d%d",&n,&m,&e);
	for(int i=1;i<=e;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[v].push_back(u);
	}
	int ans = 0;
	for(int i=1;i<=m;i++)
		if(dfs(i, i))++ ans;
	printf("%d\n",ans);
//	for(int i=1;i<=n;i++)printf("%d ",mtch[i]);

	return 0;
}

