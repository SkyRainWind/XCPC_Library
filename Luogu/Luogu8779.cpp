// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, maxn = 2e5+5;
ll INF;

int n,m,q;
vector<pair<int,ll>>g[maxn];
int vis[maxn];
map<int,vector<pii>>query;
int ans[maxn];
ll dis[maxn];

void bfs(int now){
	vector<int>v;
	queue<int>Q;dis[now] = 0;
	Q.push(now);v.pb(now);
	
	while(!Q.empty()){
		int x=Q.front();Q.pop();
		vis[x] = 1;
		for(pair<int,ll> u : g[x]){
			int to = u.first;if(vis[to])continue;
			ll w = u.second;
//			if(dis[x] + w < dis[u]){
			dis[to] = dis[x] + w;
			v.pb(to);
			Q.push(to);
//			}
		}
	}
	
	for(auto it : query[now])
		if(dis[it.first] != INF){ans[it.second] = dis[it.first];}
	for(auto it : v)dis[it] = INF;
}

signed main(){
	memset(dis,0x3f,sizeof dis);
	INF = dis[0];
	memset(ans,-1,sizeof ans);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++){
		int l,r;
		ll x;scanf("%d%d%lld",&l,&r,&x);
		g[l-1].pb(mpr(r, x));
		g[r].pb(mpr(l-1, -x));
	}
	for(int i=1;i<=q;i++){
		int l,r;scanf("%d%d",&l,&r);
		query[l-1].pb(mpr(r, i));
	}
	for(int i=0;i<=n-1;i++)
		if(!vis[i])bfs(i);
	for(int i=1;i<=q;i++)
		if(ans[i] != -1)printf("%lld\n",ans[i]);
		else puts("UNKNOWN");

	return 0;
}

