// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 1e9+7, maxn = 2e5+5;

int fac[maxn], inv[maxn],inv2;
vector<int>g[maxn];

int pw(int x,int y){
	if(!y)return 1;
	if(y == 1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

int C(int x,int y){
	if(x < y)return 0;
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}

int sz[maxn];

int ans = 0, iv; 
void dfs(int x,int fat=0){
	sz[x] = 1;
	for(int u : g[x])if(u != fat){
		dfs(u, x);
		sz[x] += sz[u];
	}
}

signed main(){
	inv2=pw(2,mod-2);
	fac[0] = inv[0] = 1;
	for(int i=1;i<=maxn-5;i++)fac[i] = 1ll*fac[i-1]*i%mod;
	inv[maxn-5] = pw(fac[maxn-5], mod-2);
	for(int i=maxn-6;i>=1;i--)inv[i] = 1ll*inv[i+1]*(i+1)%mod;
	
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
	}
	
	if(k %2 == 1){
		puts("1");
		return 0;
	}
	
	dfs(1);
	iv = pw(C(n,k), mod-2);
	for(int i=1;i<=n;i++)
		(ans += 1ll * C(sz[i], k/2) * C(n-sz[i], k/2)%mod) %= mod;
	printf("%d\n",(1ll * ans * iv + 1) % mod);
	
	return 0;
}
