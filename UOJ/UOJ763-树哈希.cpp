// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e6+5;

int n;
vector<int>g[maxn];

struct thash{
	typedef unsigned long long ull;
	const ull mask = std::chrono::steady_clock::now().time_since_epoch().count();
	set<ull>S;
	ull hs[maxn];

	ull shift(ull x) {
		x ^= mask;x ^= x << 13;x ^= x >> 7;x ^= x << 17;x ^= mask;
		return x;
	}
	
	void dfs(int x,int fat=0){
		hs[x] = 1;
		for(int u : g[x])if(u != fat){
			dfs(u, x);
			hs[x] += shift(hs[u]);
		}
		S.insert(hs[x]);
	}
	
	void solve(){
		dfs(1);
		cout << S.size() << '\n';
	}
}th;

signed main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
	}
	th.solve();

	return 0;
}

