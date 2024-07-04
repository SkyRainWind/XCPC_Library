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

vector<int>g[maxn];
int dis[maxn], de[maxn], vis[maxn];
priority_queue<pii>pq; 

signed main(){
	memset(dis,0x3f,sizeof dis);
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[y].pb(x);
		++ de[x];
	}
	
	dis[n] = 0;
	pq.push(mpr(-dis[n], n));
	while(!pq.empty()){
		int x = pq.top().second;pq.pop();
		if(vis[x])continue;vis[x] = 1;
		
		for(int u : g[x]){
			if(dis[x]+de[u] < dis[u]){
				dis[u] = dis[x] + de[u];
				pq.push(mpr(-dis[u], u));
			}
			-- de[u];
		}
	}
	printf("%d\n",dis[1]);

	return 0;
}

