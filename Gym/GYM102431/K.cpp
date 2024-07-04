// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n;
vector<int>g[maxn];
int sz[maxn], heavy[maxn], cnt=0;
int ans[maxn], fg[maxn], vis[maxn];

void dfs(int x,int fat=0){
	sz[x] = 1;
	for(int u : g[x])if(u!=fat){
		dfs(u, x);
		sz[x] += sz[u];
		if(!heavy[x] || sz[u] > sz[heavy[x]])
			heavy[x] = u;
	}
}

void upd(int x,int keep,int fat){
	int qw = fg[x-1] + fg[x+1];
	if(keep){
		if(qw == 0)++ cnt;
		else if(qw == 2)-- cnt;
	}else{
		if(qw == 0)-- cnt;
		else if(qw == 2)++ cnt;
	}
	fg[x] = keep;
	for(int u : g[x])if(u!=fat && !vis[u]){
		upd(u, keep, x);
	}
}

void dfs2(int x,int keep=1,int fat=0){
	for(int u : g[x])if(u!=fat && u!=heavy[x]){
		dfs2(u, 0, x);
	}
	if(heavy[x])dfs2(heavy[x], 1, x), vis[heavy[x]] = 1;
	
	upd(x, 1, fat);
	if(heavy[x])vis[heavy[x]] = 0;
	ans[x] = cnt;
	
	if(!keep)upd(x, 0, fat);
}

int kase = 0;
void solve(){
	cnt = 0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)g[i].clear(), heavy[i] = fg[i] = ans[i] = vis[i] = 0;
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
	}
	dfs(1);
	dfs2(1, 1);
	printf("Case #%d: ",++kase);
	for(int i=1;i<=n;i++)printf("%d%c",ans[i]," \n"[i==n]);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

