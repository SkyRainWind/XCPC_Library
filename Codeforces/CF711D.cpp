// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5, mod = 1e9+7;

int n;
vector<pii>g[maxn];
int vis[maxn], gg = -1, pre[maxn], sz=0, r0;
pii cyc;

int pw(ll x,ll y){
	if(!y)return 1;
	if(y == 1)return x;
	int mid=pw(x,y/2);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

void dfs(int x,int pr = 0,int lste = 0){
//	printf("%d %d\n",x,pr);
	vis[x] = 1;
	pre[x] = pr;
	++ sz;
	for(auto u : g[x]){
//	printf("%d %d\n",x,u.first);
	if(u.second != lste){
		if(vis[u.first] && gg==-1){
			gg = u.first;
			
			int v = x;
//			debug();
			while(v != u.first){
//				printf("! %d\n",v);
				++ r0;
				v = pre[v];
			}
			continue;
		}
//		printf("to: %d %d\n",u.first,x);
		if(!vis[u.first])dfs(u.first, x, u.second);
//		if(~gg)return ;
	}
}
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		g[i].pb(mpr(x, i)), g[x].pb(mpr(i, i));
	}
	int ans = 1;
	for(int i=1;i<=n;i++)if(!vis[i]){
		gg = -1;
		sz = 0;
		r0 = 1;
		dfs(i);
//		printf("hh %d %d\n",sz,r0);
		int res = 1ll * pw(2, sz-r0) * (pw(2, r0) - 2 + mod)% mod;
		ans = 1ll* ans * res % mod;
	}
	cout << ans << '\n';

	return 0;
}

