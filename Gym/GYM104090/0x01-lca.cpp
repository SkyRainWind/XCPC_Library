// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5e5+5;

int n,m,rt;
vector<int>g[maxn];
int dep[maxn], fa[maxn][25];

void dfs(int x,int fat=0){
	dep[x] = dep[fat] + 1;
	fa[x][0] = fat;
	for(int i=0;i<g[x].size();i++){
		int u = g[x][i];
		if(u==fat)continue;
		dfs(u, x);
	}
}

int getlca(int x,int y){
	if(dep[x] < dep[y])swap(x, y);
	for(int j=20;j>=0;j--)
		if(dep[fa[x][j]] >= dep[y])x = fa[x][j];
	if(x == y)return x;
	for(int j=20;j>=0;j--)
		if(fa[x][j] != fa[y][j])x = fa[x][j], y = fa[y][j];
	return fa[x][0];
}

signed main(){
	scanf("%d%d%d",&n,&m,&rt);
	for(int i=1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
	}
	dfs(rt,0);
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n;i++)
			fa[i][j] = fa[fa[i][j-1]][j-1];
	
	while(m --){
		int x,y;scanf("%d%d",&x,&y);
		if(x == y){
			printf("%d\n",x);
			continue;
		}
		printf("%d\n",getlca(x,y));
	}

	return 0;
}

