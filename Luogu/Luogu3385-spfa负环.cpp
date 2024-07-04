// by SkyRainWind
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2e5+5;

int n,m,dis[maxn],vis[maxn],cnt[maxn];
vector<pair<int,int> >g[maxn];

int solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)dis[i] = inf, vis[i] = cnt[i] = 0, g[i].clear();
	
	for(int i=1;i<=m;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		if(z >= 0)g[x].emplace_back(mpr(y,z)), g[y].emplace_back(mpr(x,z));
		else g[x].emplace_back(mpr(y,z));
	}
	
	queue<int>Q;
	Q.push(1);dis[1] = 0;vis[1] = 1;
	while(!Q.empty()){
		int x = Q.front();Q.pop();
		vis[x] = 0;	////////!!!
		for(pair<int,int>now : g[x]){
			int u = now.first, v = now.second;
			if(dis[u] > dis[x] + v){
				dis[u] = dis[x] + v;
				cnt[u] = cnt[x] + 1;
				if(cnt[u] >= n)return 1;
				if(!vis[u]){
					vis[u] = 1;
					Q.push(u);
				}
			}
		}
	}
	return 0;
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)puts(solve() ? "YES" : "NO"); 

	return 0;
}


