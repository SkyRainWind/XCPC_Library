// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5 + 5;

map<pair<int,int>,int>mp;
int n,m;
vector<int>g[maxn];
int de[maxn], vis[maxn], res;

void dfs(int x,int fat =-1){
	vis[x] = 1;
	for(int u : g[x]){
		if(u == fat)continue;
//		printf("%d %d %d\n",x,u,vis[u]);
		if(vis[u])++ res;
		else dfs(u,x);
	}
}

signed main(){
//	freopen("zr1154.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		if(x == y)res += 2;
		else{
			if(mp.count(mpr(x, y)))res += 2; 
			else g[x].push_back(y), g[y].push_back(x), mp[mpr(x,y)] = mp[mpr(y,x)] = 1;
		}
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
	printf("%d\n",res /2 );

	return 0;
}

