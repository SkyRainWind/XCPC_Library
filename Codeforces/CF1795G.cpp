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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e5+5;

int n,m,a[maxn],de[maxn];
vector<int>g[maxn];

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), g[i].clear(), de[i] = 0;
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
		de[x] ++, de[y] ++;
	}
	queue<int>Q;
	for(int i=1;i<=n;i++){
		de[i] -= a[i];
		if(de[i] == 0)Q.push(i), de[i] = -1;
	}
	
	vector<pii>ed;
	while(!Q.empty()){
		int u = Q.front(); Q.pop();
		for(int v : g[u])if(de[v] >= 0){
			ed.emplace_back(v, u);	// v->u
			if(!--de[v]){
				Q.push(v);
				de[v] = -1;
			}
		}
	}
//	reverse(ed.begin(), ed.end());
	
	vector<ull>S(n+1);
	ll ans = 1ll*n*(n+1) / 2;
	for(int l=1;l<=n;l+=64){
		int r = min(n, l+63);
		for(int i=l;i<=r;i++){
			S[i] = 1ull << (i-l); 
		}
		for(pii e : ed){
			int u=e.first, v=e.second;
			S[u] |= S[v];
		}
		
		for(int i=1;i<=n;i++)ans -= __builtin_popcountll(S[i]), S[i] = 0;
	}
	cout << ans << '\n';
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

