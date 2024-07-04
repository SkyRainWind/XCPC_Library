// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e5+5;

int n,m,k;
int suki[maxn];
vector<pii>o[maxn],g[maxn];
int s,t;
int dis[maxn],vis[maxn];

void dijkstra(){
	priority_queue<pii>pq;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0, sizeof vis);
	
	dis[s] = 0;pq.push(mpr(0, s));
	while(!pq.empty()){
		pii now = pq.top(); pq.pop();
		int ds = -now.first, x = now.second;
		if(vis[x])continue;
		vis[x] = 1;
		for(pii nn : g[x]){
			int u = nn.first;
			if(dis[x] + nn.second < dis[u]){
				dis[u] = dis[x] + nn.second;
				pq.push(mpr(-dis[u], u));
			}
		}
	}
}

void solve(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		if(x == y)continue;
		o[x].pb(mpr(y,z));
	}
	for(int i=1;i<=k;i++)scanf("%d",&suki[i]);
	int ans = 1e9;
	for(int cs=0;cs<=16;cs++){
		for(int i=0;i<=n;i++)g[i] = o[i];
		vector<int>s1,s2;
		for(int i=1;i<=k;i++){
			if((suki[i] >> cs) & 1)s1.pb(suki[i]);
			else s2.pb(suki[i]);
		}
		
		s=0, t=n+1;
		for(int it : s1)g[s].pb(mpr(it, 0));
		for(int it : s2)g[it].pb(mpr(t, 0));
		
		dijkstra();
		ans = min(ans, dis[t]);
		for(int it : s2)g[it].pop_back();
		for(int it : s1)g[s].pop_back();
		
		for(int it : s2)g[s].pb(mpr(it, 0));
		for(int it : s1)g[it].pb(mpr(t, 0));
		dijkstra();
		ans = min(ans, dis[t]);
	}
	cout << ans << '\n';
	
	for(int i=1;i<=n;i++)o[i].clear();
}

signed main(){
//	freopen("Luogu5304.in","r",stdin);
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

