// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5e5+5;

int n;
vector<pii>g[maxn];
int fa[maxn][21], dis[maxn][21];
int dfn[maxn], dfs_clock, dep[maxn];
int k,spe[maxn],stk[maxn],tp;
int isimp[maxn], rt=0;
ll dp[maxn];
vector<pii>h[maxn];

struct vt{
	void dfs(int x,int fat=0){
		fa[x][0] = fat;
		dfn[x] = ++dfs_clock;
		dep[x] = dep[fat] + 1;
		for(auto u : g[x])if(u.first != fat){
			dis[u.first][0] = u.second;
			dfs(u.first, x);
		}
	}
	
	int getlca(int x,int y){
		if(dep[x] < dep[y])swap(x, y);
		for(int i=19;i>=0;i--)
			if(dep[fa[x][i]] >= dep[y])x = fa[x][i];
		if(x == y)return x;
		for(int i=19;i>=0;i--)
			if(fa[x][i] != fa[y][i])x = fa[x][i], y = fa[y][i];
		return fa[x][0];
	}
	
	int getv(int x,int y){
		if(dep[x] < dep[y])swap(x, y);
		int r = 2e9;
		for(int i=19;i>=0;i--)
			if(dep[fa[x][i]] >= dep[y])r = min(r, dis[x][i]), x = fa[x][i];
		return r;
	}
	
	void link(int x,int y){
		if(x == y)return ;
		int v = getv(x, y);
		h[x].pb(mpr(y, v)), h[y].pb(mpr(x, v));
	}
	
	void buildvt(){
		sort(spe+1,spe+k+1,[&](int a,int b){
			return dfn[a] < dfn[b];
		});
		stk[tp = 1] = spe[1];
		for(int i=2;i<=k;i++){
			int lc = getlca(spe[i], stk[tp]);
			if(lc != stk[tp]){
				while(dfn[lc] < dfn[stk[tp-1]]){
					link(stk[tp],stk[tp-1]);
					-- tp;
				}
				if(lc != stk[tp-1]){
					link(lc, stk[tp]);
					stk[tp] = lc;
				}else link(lc, stk[tp --]);
			}
			stk[++ tp] = spe[i];
		}
		for(int i=1;i<tp;i++)link(stk[i], stk[i+1]);
		rt = stk[1];
		link(1, rt);	// 特殊情况，可以删去 
	}
}vt; 

void getdp(int x,int fat=0){
	dp[x] = 0;
	for(auto it : h[x])if(it.first != fat){
		getdp(it.first, x);
		if(isimp[it.first])
			dp[x] += it.second;
		else
			dp[x] += min(dp[it.first], 1ll * it.second);
	}
	h[x].clear();
}

signed main(){
//	freopen("2495.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		g[x].pb(mpr(y,z)), g[y].pb(mpr(x,z));
	}
	vt.dfs(1);
	for(int j=1;j<=19;j++)
		for(int i=1;i<=n;i++)
			fa[i][j] = fa[fa[i][j-1]][j-1],
			dis[i][j] = min(dis[i][j-1], dis[fa[i][j-1]][j-1]);
			
	int m;scanf("%d",&m);
	while(m --){
		scanf("%d",&k);
		for(int i=1;i<=k;i++)scanf("%d",&spe[i]), isimp[spe[i]] = 1;
		vt.buildvt();
		getdp(1);
		printf("%lld\n",dp[1]);
		
		for(int i=1;i<=k;i++)isimp[spe[i]] = 0;
	}

	return 0;
}

