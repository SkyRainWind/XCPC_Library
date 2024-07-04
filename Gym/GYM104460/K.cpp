// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<ll,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e6+5;

int n,m,k,e[maxn],d[maxn];
vector<pii>g[maxn];
int vis[maxn];
ll dis[maxn];

void dijkstra(){
	for(int i=1;i<=n;i++)dis[i] = 1e18, vis[i] = 0;
	
	priority_queue<pii>pq;
	for(int i=1;i<=k;i++)
		pq.push(mpr(0,e[i])), dis[e[i]] = d[e[i]] = 0;
	while(!pq.empty()){
		pii now = pq.top(); pq.pop();
		if(vis[now.second])continue;
		if(d[now.second]){
			-- d[now.second];
			continue;
		}
		vis[now.second] = 1;
		dis[now.second] = -now.first;
		if(now.second == 1)break;
//		printf("hh %d\n",now.second);
		for(auto it : g[now.second]){
			if(dis[it.first] > dis[now.second] + it.second){
				pq.push(mpr(-(dis[now.second] + it.second), it.first));
			}
		}
	}
}

void solve(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)scanf("%d",&e[i]);
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	for(int i=1,x,y,w;i<=m;i++){
		scanf("%d%d%d",&x,&y,&w);
		g[x].pb(mpr(y,w)), g[y].pb(mpr(x,w));
	}
	
	dijkstra();
	if(dis[1] == (ll)1e18)puts("-1");
	else printf("%lld\n",dis[1]);
	
	for(int i=1;i<=n;i++)g[i].clear();
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

