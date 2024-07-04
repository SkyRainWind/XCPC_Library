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
vector<int>g[maxn],rg[maxn];
int vis[maxn],dis[maxn];
int vis1[maxn],dis1[maxn];
void bfs(){
	queue<int>Q;
	Q.push(1);
	dis[1] = 0, vis[1] = 1;
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		for(int u : g[x]){
			if(!vis[u]){
				dis[u] = dis[x] + 1;
				vis[u] = 1;
				Q.push(u);
			}
		}
	}
}
void bfs1(){
	queue<int>Q;
	Q.push(1);
	dis1[1] = 0, vis1[1] = 1;
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		for(int u : rg[x]){
			if(!vis1[u]){
				dis1[u] = dis1[x] + 1;
				vis1[u] = 1;
				Q.push(u); 
			}
		}
	}
}
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)g[i].clear(), rg[i].clear(), vis[i] = vis1[i] = 0;
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), rg[y].pb(x);
	}
	bfs();bfs1();
	int ans = 0;
	for(int x=1;x<=n;x++){
		for(int u : g[x]){
			if(vis[x] && vis1[u]){
				ans = __gcd(ans, dis[x] + dis1[u] + 1);
			}
		}
	}
	if(!ans)return puts("No"), void();
	while(ans%2 == 0)ans /= 2;
	while(ans%5 == 0)ans /= 5;
	if(ans == 1)puts("Yes");
	else puts("No"); 
}

signed main(){
	int te;
	scanf("%d",&te);
	while(te --)solve();

	return 0;
}

