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

int n,k,c;
int dep[maxn], f[maxn], g[maxn];
vector<int>gr[maxn];
int sf[maxn], sg[maxn];

void dfs(int x,int fat=0){
	dep[x] = dep[fat] + 1;
	int r=0,sr=0;
	for(int u : gr[x])if(u != fat){
		dfs(u, x);
		if(r < f[u]+1){sr=r, r=f[u]+1;}
		else if(sr < f[u]+1){sr = f[u]+1;}
	}
	f[x] = r, sf[x] = sr;
}

void dfs2(int x,int fat=0){
	for(int u : gr[x])if(u!=fat){
		if(f[u]+1 == g[x]){
			g[u] = max(f[u], sg[x]+1);
			if(g[u] == f[u])sg[u] = max(sf[u], sg[x] + 1);
			else sg[u] = f[u];
		}else{
			g[u] = g[x]+1;
			sg[u] = max({f[u], sf[u], sg[x]+1});
		}
		dfs2(u, x);
	}
}

void solve(){
	scanf("%d%d%d",&n,&k,&c);
	for(int i=1;i<=n;i++)gr[i].clear(), f[i] = g[i] = dep[i] = 0;
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		gr[x].pb(y),gr[y].pb(x);
	}
	dfs(1);
	g[1] = f[1], sg[1] = sf[1];
	dfs2(1);
	ll ans = 0;
	for(int i=1;i<=n;i++)
		ans = max(ans, 1ll*k*g[i] - 1ll*c*(dep[i] - 1));
	printf("%lld\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

