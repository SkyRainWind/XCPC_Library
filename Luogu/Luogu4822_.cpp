// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 50 * 55 + 5;

int n,m,k;
vector<pii>g[maxn];
int vis[maxn];
int dis[maxn];

priority_queue<pii>pq;
void dij(){
	memset(dis,0x3f,sizeof dis);
	dis[1] = 0;
	pq.push(mpr(0, 1));
	
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

vector<pair<int,pii>>vi;
signed main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		vi.pb(mpr(x,mpr(y,z)));
		for(int j=0;j<=k;j++)
			g[x+j*n].pb(mpr(y+j*n,z)), g[y+j*n].pb(mpr(x+j*n,z));
		for(int j=0;j<k;j++){
			int nx = x+j*n, ny = y+(j+1)*n;
			int nxx = y+j*n, nyy = x+(j+1)*n;
			g[nx].pb(mpr(ny,z/2)), g[nxx].emplace_back(nyy, z/2);
		}
	}
	dij();

	int ans = 1e9;
	for(int i=1;i<=k+1;i++)
		ans = min(ans, dis[i*n]);
	cout << ans << '\n';

	return 0;
}

