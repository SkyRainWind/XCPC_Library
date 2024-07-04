// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 505;

int n,m;
int a[505][505];
vector<pii>g[505];
int ed,vis[maxn][maxn];
ll w[505];
ll dis[maxn][maxn];
struct node{
	int cs;
	ll dis;
	int now;
};

bool operator < (node a,node b){
	if(a.cs != b.cs)return a.cs > b.cs;
	return a.dis>b.dis;
}

void dijkstra(){
	memset(dis,0x3f,sizeof dis);
	priority_queue<node>pq;
	pq.push(node{0,0,1});
	dis[1][0] = 0;
	
	while(!pq.empty()){
		node now = pq.top();pq.pop();
		int u = now.now, cs =now.cs;
		if(vis[u][cs])continue;
		vis[u][cs] = 1;
		
		for(auto v : g[u]){
			if(cs+1 <= n-1 && dis[u][cs] + v.second < dis[v.first][cs+1]){
				dis[v.first][cs + 1] = dis[u][cs] + v.second;
				pq.push(node{cs+1, dis[v.first][cs+1], v.first});
			}
		}
	}
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		g[x].pb(mpr(y,z));
		g[y].pb(mpr(x,z));
	}
	
	dijkstra();
	int qu;scanf("%d",&qu);
	for(int i=1;i<=qu;i++){
		scanf("%d",&ed);
		for(int j=1;j<=n-1;j++){
			scanf("%lld",&w[j]);
		}
		for(int j=2;j<=n-1;j++)w[j] += w[j-1];
		ll ans = 1e18;
		for(int j=1;j<=n-1;j++)
			ans = min(ans, dis[ed][j] + w[j]);
		printf("%lld\n",ans);
	}
	
	return 0;
}

