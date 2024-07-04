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
vector<int>g[maxn], id[maxn];
int vis[maxn], vise[maxn], dis[maxn];
int cf[maxn], cyc=0, sp;
vector<int>ans;

void dfs(int x,int fat=0){
	vis[x] = 1;
	for(int i=0;i<g[x].size();i++){
		int u=g[x][i];
		if(vise[id[x][i]])continue;
		
		vise[id[x][i]] = 1;
		if(!vis[u]){
			dis[u] = dis[x]^1;
			dfs(u, x);
		}else{
			if(dis[x]==dis[u]){	// Ææ»· 
				++cyc;
				sp = id[x][i];
				cf[x] ++;
				cf[u] --;
			}else{
				-- cf[x];
				++ cf[u];
			}
		}
	}
}

void dfs0(int x){
	vis[x] = 1;
	for(int i=0;i<g[x].size();i++){
		int u=g[x][i];
		if(vis[u])continue;
		
		dfs0(u);
		if(cf[u] == cyc){
			ans.pb(id[x][i]);
		}
		cf[x] += cf[u];
	}
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
		id[x].pb(i), id[y].pb(i);
	}
	
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
	
	if(!cyc){
		printf("%d\n",m);
		for(int i=1;i<=m;i++)printf("%d ",i);puts("");
		return 0;
	}
	
	memset(vis,0,sizeof vis);
	memset(vise,0,sizeof vise);
	for(int i=1;i<=n;i++)if(!vis[i])dfs0(i);
	if(cyc==1)ans.pb(sp); 
	sort(ans.begin(), ans.end());
	printf("%d\n",ans.size());
	for(int u : ans)printf("%d ",u);puts("");

	return 0;
}

