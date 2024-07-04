// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;
#define int ll

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1000005;

int n,m,k;
vector<pii>g[maxn];
int vis[maxn],s,t;
int dis[maxn];

priority_queue<pii>pq;
void dij(){
	memset(dis,0x3f,sizeof dis);
	dis[s] = 0;
	pq.push(mpr(0, s));
	
	while(!pq.empty()){
		pii now = pq.top(); pq.pop();
		int nd = -now.first, u = now.second;
		if(vis[u])continue;
		vis[u] = 1;
		for(pii nowv : g[u]){
			int v = nowv.first, w = nowv.second;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				pq.push(mpr(-dis[v], v));
			}
		}
	}
}

signed main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	s=1,t=n;
	for(int i=1;i<=m;i++){
		int x,y,z;scanf("%lld%lld%lld",&x,&y,&z);
		for(int j=0;j<=k;j++)
			g[x+j*n].pb(mpr(y+j*n,z)), g[y+j*n].pb(mpr(x+j*n,z));
		for(int j=0;j<k;j++){
			int nx = x+j*n, ny = y+(j+1)*n;
			int nxx = y+j*n, nyy = x+(j+1)*n;
			g[nx].emplace_back(ny, 0), g[nxx].emplace_back(nyy, 0);
		}
	}
	dij();

	int ans = 1e18;
	for(int i=0;i<=k;i++)
		ans = min(ans, dis[t+i*n]);
	cout << ans << '\n';

	return 0;
}

