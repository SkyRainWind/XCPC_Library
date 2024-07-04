// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

vector<int>g[maxn];

int pre[maxn],on[maxn],vis[maxn];
pii lp;

struct thash{
	typedef unsigned long long ull;
	const ull mask = std::chrono::steady_clock::now().time_since_epoch().count();
	ull hs[maxn];

	ull shift(ull x) {
		x ^= mask;x ^= x << 13;x ^= x >> 7;x ^= x << 17;x ^= mask;
		return x;
	}
	
	void dfs(int x,int fat=0){
		hs[x] = 1;
		for(int u : g[x])if(u != fat && !on[u]){
			dfs(u, x);
			hs[x] += shift(hs[u]);
		}
	}
}th;

void dfs(int x,int fat=0){
	vis[x] = 1;
	pre[x] = fat;
	for(int u : g[x])if(u!=fat){
		if(vis[u]){
			lp = mpr(u,x);
			continue;
		}
		dfs(u, x);
	}
}

void solve(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)g[i].clear(),vis[i]=on[i]=0;
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
	}
	if(m == n-1){
		puts("YES");
		return ;
	}
	if(m > n){
		puts("NO");
		return ;
	}
	dfs(1);
	vector<int>all;
	
	on[lp.second] = 1, all.pb(lp.second);
	for(int i=lp.first;i!=lp.second;i=pre[i])on[i] = 1, all.pb(i);
	
	set<ull>S;
	vector<ull>T;
	for(auto it : all){
		th.dfs(it,it);
		S.insert(th.hs[it]);
		T.pb(th.hs[it]);
	}
	int fg=1;
	for(int i=2;i<T.size();i++){
		if(T[i] != T[i-2])fg=0;
	}
	if(S.size() == 1 || (fg && T.size()%2 == 0))puts("YES");
	else puts("NO");
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

