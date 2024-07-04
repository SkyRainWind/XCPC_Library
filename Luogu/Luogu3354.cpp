// by Balloons
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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=105;

struct node{
	int to, w;
	node(){}
	node(int to,int w) : to(to), w(w){}
};
int n,m;
vector<node>ve[maxn];
int w[maxn], de[maxn], dep[maxn];
int anc[maxn], sz = 0;
int f[maxn][maxn][maxn], g[maxn][maxn][maxn];

void dfs(int x,int fat = -1){
	anc[++ sz] = x;
	for(node nd : ve[x]){
		int u = nd.to, w = nd.w;
		if(u == fat)continue;
		dep[u] = dep[x] + w;
		dfs(u, x);
		for(int i=1;i<=sz;i++){
			int j = anc[i];
			for(int k = m;k>=0;k--){
				f[x][j][k] += f[u][j][0];
				g[x][j][k] += f[u][x][0];
				
				for(int p = 0;p<=k;p++)
					f[x][j][k] = min(f[x][j][k], f[x][j][p] + f[u][j][k - p]);
				for(int p = 1;p<=k;p++)
					g[x][j][k] = min(g[x][j][k], g[x][j][p] + f[u][x][k - p]);
			}
		}
	}
	
	for(int i = 1;i<=sz;i++){
		int j = anc[i];
		for(int p = 0;p<=m;p++)
			if(p == 0)f[x][j][p] += w[x] * (dep[x] - dep[j]);
			else f[x][j][p] = min(f[x][j][p] + w[x] * (dep[x] - dep[j]), g[x][j][p]);
	}
	-- sz;
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int fa;
		scanf("%d%d%d",&w[i],&fa,&de[i]);
		ve[i].push_back(node(fa, de[i]));
		ve[fa].push_back(node(i, de[i]));
	}
	dfs(0);
	printf("%d\n",f[0][0][m]);

	return 0;
}


