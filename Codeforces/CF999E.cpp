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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5005;

int n,m,s;
vector<int>g[maxn], h[maxn];
pii ed[maxn];
int de[maxn];

struct _scc{
	int dfn[maxn], low[maxn], dfs_clock;
	int stk[maxn], tp = 0, belong[maxn], tot=0, sz[maxn];
	// belong[i] i 属于哪个强连通块 tot 块数（新的n）sz 每个块的大小 
	_scc(){memset(dfn,0,sizeof dfn);}
	
	void tarjan(int x){
		dfn[x] = low[x] = ++ dfs_clock; 
		stk[++ tp] = x;
		for(int u : g[x]){
			if(!dfn[u]){
				tarjan(u);
				low[x] = min(low[x], low[u]);
			}else if(!belong[u])
				low[x] = min(low[x], dfn[u]); 
		}
		if(low[x] == dfn[x]){
			belong[x] = ++tot;
			++sz[tot];
			while(stk[tp] != x){
				++sz[tot];
				belong[stk[tp]] = tot;
				-- tp;
			}
			-- tp;
		}
	}
	
	void getscc(){
		for(int i=1;i<=n;i++)
			if(!dfn[i])tarjan(i);
	}
	
	void deal(){	// 缩点 
		for(int i=1;i<=m;i++){
			int x = ed[i].first, y = ed[i].second;
			if(belong[x] != belong[y])
				h[belong[x]].push_back(belong[y]),
				++ de[belong[y]];
		}
	}
};
struct _scc scc;
int vis[maxn];

void dfs(int x){
	vis[x] = 1;
	for(int u : h[x])if(!vis[u]){
		dfs(u);
	}
}

signed main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v);
		ed[i] = mpr(u, v);
	}
	scc.getscc();
	scc.deal();
	s = scc.belong[s];
	dfs(s);
	int res = 0;
	for(int i=1;i<=scc.tot;i++)if(!vis[i] && de[i] == 0)++ res;
	printf("%d\n",res);

	return 0;
}

