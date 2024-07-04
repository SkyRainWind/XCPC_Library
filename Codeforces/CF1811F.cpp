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

int n,m;
vector<int>g[maxn];
vector<int>vd;
vector<int>vis,de;
int r1=0,ff=0;

void dfs1(int x,int st){
	++ r1;
	vis[x] = 1;
	for(int u : g[x])if(!vis[u] && de[u] == 4){
		dfs1(u, st);
	}
	for(int u : g[x])if(u == st)++ ff;
}

void dfs2(int x,int st){
	++ r1;
	vis[x] = 1;
	for(int u : g[x])if(!vis[u] && de[u] == 2){
		dfs2(u, st);
	}
	for(int u : g[x])if(u == st)++ ff;
}

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)g[i].clear();
	
	de.assign(n+1, 0);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
		++ de[x], ++ de[y];
	}
	
	int tn = (int)sqrt(1.0 * n);
	if(tn * tn != n || tn * (tn+1) != m)
		return (void)puts("NO");
	if(tn <= 2)
		return (void)puts("NO");
	
	int d1=0, d2=0;
	
	r1 = 0;
	vd.clear();
	vis.assign(n+1, 0);
	for(int i=1;i<=n;i++)
		if(de[i] == 4)++ d1, vd.pb(i);
		else if(de[i] == 2)++ d2;
	if(!(d1 == tn && d2 == n-tn))
		return (void)puts("NO");
	
	ff = 0;
	dfs1(vd[0],vd[0]);
	if(ff != 2 || r1 != tn)
		return (void)puts("NO");
	for(int u : vd){
		r1 = ff = 0;
		dfs2(u,u);
		if(ff != 2 || r1 != tn)
			return (void)puts("NO");
	}
	return (void)puts("YES");
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

