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
vector<int>g[2005];
int o[2005][2005], vis[2005][2005];

void dfs(int x,int f){
	vis[f][x] = 1;
	for(int u : g[x])if(!vis[f][u])dfs(u,f);
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y);
		o[x][y] = 1;
	}
	for(int i=1;i<=n;i++)o[i][i] = 1;
	for(int i=1;i<=n;i++)dfs(i,i);
	int ans = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(vis[i][j] && !o[i][j])++ ans;
	printf("%d\n",ans);

	return 0;
}

