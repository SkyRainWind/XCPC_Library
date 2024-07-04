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
struct node{int to;ll v;int id;}; 
vector<node>g[maxn];
ll dis[maxn];
int vis[maxn];
ll d[65];

void insert(ll x){
	for(int i=63;i>=0;i--)if(x&(1ll<<i)){
		if(!d[i]){
			d[i] = x;
			break;
		}
		x ^= d[i];
	}
}

int vise[maxn];
void dfs(int x,ll xo = 0){
	dis[x] = xo;
	vis[x] = 1;
	for(node u :g[x])if(!vise[u.id]){
		vise[u.id] = 1;
		if(!vis[u.to])dfs(u.to,xo ^ u.v);
		else{
			insert(xo ^ dis[u.to] ^ u.v);
		}
	}
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		ll z;scanf("%d%d%lld",&x,&y,&z);
		g[x].pb(node{y, z, i});
		g[y].pb(node{x, z, i});
	}
	dfs(1);
	ll ans = dis[n];
	for(int i=63;i>=0;i--)
		if((ans ^ d[i]) > ans)ans ^= d[i];
	cout << ans;

	return 0;
}

