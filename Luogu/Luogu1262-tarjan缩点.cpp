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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 10005;

int n,p,m, cst[maxn], de[maxn];
struct spy{int cs,to;}sp[maxn];
pii ed[maxn];

vector<int>g[maxn], h[maxn];
struct _scc{
	// 存图 g[] 缩点之后在 h[]
	// ed[] 保存原图的 m 个有向边 
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
			}else if(!belong[u])	// 也可写成：if(instack[u]) 
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
	for(int u : g[x]){
		if(!vis[u])dfs(u);
	}
}

signed main(){
//	freopen("1262.in","r",stdin);
	memset(cst, 0x3f, sizeof cst);
	scanf("%d%d",&n,&p);
	for(int i=1;i<=p;i++)scanf("%d%d",&sp[i].to,&sp[i].cs);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y);
		ed[i] = mpr(x, y);
	}
	for(int i=1;i<=p;i++)
		dfs(sp[i].to);
	for(int i=1;i<=n;i++)
		if(!vis[i])return printf("NO\n%d\n",i), 0;
	scc.getscc();
	scc.deal();
	for(int i=1;i<=p;i++)
		cst[scc.belong[sp[i].to]] = min(cst[scc.belong[sp[i].to]], sp[i].cs); 
	int ans = 0;
	for(int i=1;i<=scc.tot;i++)
		if(!de[i])ans += cst[i];
	printf("YES\n%d\n",ans);

	return 0;
}

