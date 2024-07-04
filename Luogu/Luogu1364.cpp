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
int sz[maxn],w[maxn];
ll f[maxn];
vector<int>g[maxn];

void dfs(int x,int dep = 0){
	sz[x] = w[x];
	for(int u : g[x]){
		dfs(u, dep+1);
		sz[x] += sz[u];
	}
	f[1] += 1ll * w[x] * dep;
}

void getdp(int x){
	for(int u : g[x]){
		f[u] = f[x] + sz[1] - 2ll * sz[u];
		getdp(u);
	}
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int u,v;scanf("%d%d%d",&w[i],&u,&v);
		if(u)g[i].pb(u);
		if(v)g[i].pb(v);
	}
	dfs(1);
	getdp(1);
	ll ans = 1e18;
	for(int i=1;i<=n;i++)ans = min(ans, f[i]);
	printf("%lld\n",ans);

	return 0;
}

