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

int n,k;
int c[maxn],ans[maxn];
vector<int>g[maxn];
map<int,int>res[maxn];
vector<int>del[maxn];
int fa[maxn][21],dep[maxn];
vector<int>qw;

void dfs(int x,int fat=0){
	fa[x][0] = fat;
	dep[x] = dep[fat] + 1;
	for(int u : g[x])if(u!=fat){
		dfs(u,x);
	}
}

void dfs2(int x,int fat=0){
	for(int u : g[x])if(u!=fat){
		dfs2(u,x);
	}
	if(dep[x] > k){
		int v = x;
		for(int j : qw)
			if(k & (1<<j))v = fa[v][j];
		del[v].pb(x);
	}
}

void dfs3(int x,int fat=0){
	res[x][c[x]] ++;
	for(int u : g[x])if(u!=fat){
		dfs3(u,x);
		if(res[x].size() < res[u].size())swap(res[x], res[u]);
		for(auto v : res[u])res[x][v.first] += v.second;
		res[u].clear();
	}
	
	ans[x] = res[x].size();
	for(int v : del[x]){
		res[x][c[v]] --;
		if(res[x][c[v]] == 0)res[x].erase(c[v]);
	}
}

signed main(){
	scanf("%d%d",&n,&k);
	for(int i=19;i>=0;i--)
		if(k&(1<<i))qw.pb(i);
		
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
	}
	dfs(1);
	for(int j=1;j<=19;j++)
		for(int i=1;i<=n;i++)
			fa[i][j] = fa[fa[i][j-1]][j-1];
	dfs2(1);
	dfs3(1);
	
	int qu;scanf("%d",&qu);
	while(qu--){int x;scanf("%d",&x);printf("%d\n",ans[x]);}

	return 0;
}

