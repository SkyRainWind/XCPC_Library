// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 998244353, inv2 = 499122177, maxn = 3e5+5;

int n,k;
int a[maxn];
int dp[maxn];
vector<int>g[maxn];
int fa[maxn]; 

ll pw(ll x,int y){
	if(!y)return 1;
	if(y == 1)return x%mod;
	ll mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

int sz[maxn];
pii ed[maxn];
void dfs(int x,int fat=0){
	if(a[x])dp[x] = 1, ++ sz[x];
	fa[x] = fat;
	for(int u : g[x])if(u!=fat){
		dfs(u, x);
		sz[x] += sz[u];
	}
}

signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++){
		int x;scanf("%d",&x);
		a[x] = 1;
	}
	for(int i=1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);
		ed[i] = mpr(x, y);
		g[x].push_back(y), g[y].push_back(x);
	}
	dfs(1);
	ll ans = 0;
	for(int i=1;i<=n-1;i++){
		int u = ed[i].first, v = ed[i].second;
		if(fa[u] == v)swap(u, v);
		int puv = 1ll * dp[u] * (1-dp[v]+mod) % mod;
		int pvu = 1ll * dp[v] * (1-dp[u]+mod) % mod;

		ll delt = 0;
		(delt += mod-1ll*puv*sz[v]%mod*(k-sz[v])%mod) %= mod;
		(delt += mod-1ll*pvu*sz[v]%mod*(k-sz[v])%mod) %= mod;
		(delt += 1ll*puv*(sz[v]+1)%mod*(k-sz[v]-1)%mod)%=mod;
		(delt += 1ll*pvu*(sz[v]-1)%mod*(k-sz[v]+1)%mod)%=mod;
		(ans += (1ll * sz[v] * (k-sz[v]) % mod + 1ll*delt*inv2%mod)%mod) %= mod;
		
		dp[u] = dp[v] = 1ll * (dp[u] + dp[v]) * inv2%mod;
	}
	cout<<1ll*ans*pw(1ll*k*(k-1)/2%mod, mod-2)%mod;

	return 0;
}

