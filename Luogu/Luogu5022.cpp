// by SkyRainWind
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=5005;

int n,m;
vector<int>g[maxn];
map<pii,int>ban;

namespace brute{
	int ans[maxn], acnt=0;
	void dfs(int x,int fat = -1){
		ans[++ acnt] = x;
		pair<int,int>pc[maxn];
		for(int u : g[x]){
			if(u == fat)continue;
			dfs(u, x);
		}
	}
};

namespace solve{
	int vis[maxn],pre[maxn],nxt[maxn];
	int dfn[maxn], dfs_clock=0, cyc[maxn], res[maxn];
	int ans[maxn],acnt=0;
	pii bkpoint;
	void dfs(int x,int fat = -1){
		dfn[x] = ++dfs_clock;
//		printf("dfs %d %d\n",x,fat);
		vis[x] = 1;
		for(int u : g[x]){
			if(u == fat)continue;
			if(vis[u]){bkpoint = mpr(x,u);continue;}
			dfs(u, x);
			pre[u] = x;
		}
	}
	int gg = -1;
	void dfs2(int x,int fat = -1){
		for(int u : g[x]){
			if(u == fat)continue;
			if(ban.count(mpr(x,u)))continue;
			ans[++acnt] = u;
			dfs2(u, x);
		}
	}
	void main(){
		memset(res, 0x3f,sizeof res);
		dfs(1);
		if(dfn[bkpoint.first] > dfn[bkpoint.second])swap(bkpoint.first,bkpoint.second);
		int u = bkpoint.first, v = bkpoint.second;
		while(u != v){
			cyc[v] = 1;
			nxt[pre[v]] = v;
			v = pre[v];
		}
		cyc[u] = 1;
		v = bkpoint.second;

		while(u != v){
			acnt=0;
			memset(vis,0,sizeof vis);
			ban.clear();
			ban[mpr(v, pre[v])] = ban[mpr(pre[v], v)] = 1;
			
			ans[++acnt] = 1;
			
			dfs2(1);
			int win = 1;
			for(int i=1;i<=acnt;i++){
				if(res[i] < ans[i]){win = 0;break;}
				if(res[i] > ans[i])break;
			}
			if(win)memcpy(res, ans, sizeof ans);
			v = pre[v];
		}
		for(int i=1;i<=acnt;i++)printf("%d ",res[i]);
	}
};

signed main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
//	freopen("5022_.in","r",stdin);
//	freopen("5022_.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y), g[y].push_back(x);
	}
	for(int i=1;i<=n;i++)sort(g[i].begin(),g[i].end());
	if(m == n-1){
		brute::dfs(1);
		for(int i=1;i<=brute::acnt;i++)printf("%d ",brute::ans[i]);puts("");
		return 0;
	}
	solve::main();

	return 0;
}


