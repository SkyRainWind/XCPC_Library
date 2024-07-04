// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int n,m;
vector<int>g[200005];
int vis[200005];

void dfs(int x){
	vis[x] = 1;
	for(int u : g[x]){
		if(!vis[u])dfs(u);
	}
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		g[x-1].pb(y), g[y].pb(x-1);
	}
	dfs(0);
	if(vis[n])puts("Yes");else puts("No");

	return 0;
}

