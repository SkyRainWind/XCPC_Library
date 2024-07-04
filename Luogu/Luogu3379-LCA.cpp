// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=5e5+5;

int n,m,s;
vector<int>g[maxn];
int fa[maxn][23], dep[maxn];

void dfs(int x,int fat = 0){
	fa[x][0] = fat;
	for(int u : g[x]){
		if(u == fat)continue;
		dep[u] = dep[x] + 1;
		dfs(u, x);
	}
}

int getlca(int x,int y){
	if(dep[x] < dep[y])swap(x, y);
	int tp = 20;
	while(tp>=0 && dep[x] != dep[y]){
		if(dep[fa[x][tp]] >= dep[y])x = fa[x][tp];
		-- tp;
	}
	if(x == y)return x;
	tp = 20;
	while(tp >= 0){
		while(fa[x][tp] != fa[y][tp])x = fa[x][tp], y = fa[y][tp];
		-- tp;
	}
	return fa[x][0];
}

signed main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y); g[y].push_back(x);
	}
	dep[s] = 1;
	dfs(s);
	for(int j = 1;j<=20;j++)
		for(int i=1;i<=n;i++)
			fa[i][j] = fa[fa[i][j-1]][j-1];
	while(m --){
		int x,y;scanf("%d%d",&x,&y);
		printf("%d\n",getlca(x, y));
	}

	return 0;
}


