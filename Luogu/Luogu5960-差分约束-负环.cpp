// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5005;

int n,m;
vector<pii>g[maxn];
int dis[maxn];
int len[maxn],vis[maxn];

int spfa(){
	memset(dis,0x3f,sizeof dis);
	queue<int>Q;
	Q.push(0);dis[0] = 0;vis[0] = 1;
	while(!Q.empty()){
		int u = Q.front();Q.pop();vis[u] = 0;
		for(auto now : g[u]){
			int v = now.first, w = now.second;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				if(!vis[v]){
					vis[v] = 1;
					++ len[v];
					if(len[v] == n+1)return 0;
					Q.push(v);
				}
			}
		}
	}
	return 1;
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		// i j c --> x_i-x_j <= c
		// x_i <= x_j+c
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		g[b].pb(mpr(a, c));
	}
	for(int i=1;i<=n;i++)
		g[0].pb(mpr(i, 0));
	int ret = spfa();
	if(!ret)return puts("NO"), 0;
	for(int i=1;i<=n;i++)
		printf("%d ",dis[i]);

	return 0;
}

