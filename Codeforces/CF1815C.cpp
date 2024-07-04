// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1505;

int n,m;
vector<int>g[maxn];

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		if(x != 1)g[y].pb(x);
	}
	
	queue<int>Q;
	vector<int>dis(n+1, inf), vis(n+1, 0);
	dis[1] = 0;Q.push(1);
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		if(vis[u])continue;
		vis[u] = 1;
		
		for(int v : g[u]){
			if(dis[v] > dis[u] + 1){
				dis[v] = dis[u] + 1;
				Q.push(v);
			}
		}
	}
	
	for(int i=1;i<=n;i++)
		if(dis[i] == inf)return (void)puts("INFINITE");
	
	puts("FINITE");
	int mx = 0;
	vector<vector<int> >v(n + 1);
	for(int i=1;i<=n;i++){
		v[dis[i]].pb(i);
		mx = max(mx, dis[i]);
	}
	
	vector<int>ans;
	for(int i=mx;i>=0;i--){
		for(int j=i;j<=mx;j++){
			for(auto it : v[j])ans.pb(it);
		}
	}
	printf("%d\n",ans.size());
	for(auto u : ans)printf("%d ",u);
	puts("");
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

