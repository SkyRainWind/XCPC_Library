// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn= 2500+5;
const double eps = 1e-6;

int K,n;
int s[maxn], p[maxn], r[maxn];
double w[maxn], dp[maxn][maxn];
vector<int>g[maxn];
int sz[maxn], dfn[maxn], dfs_clock, seq[maxn], fa[maxn];

void dfs(int x,int fat = -1){
	dfn[x] = dfs_clock;
	seq[dfs_clock++] = x;
	fa[x] = fat;
	sz[x] = 1;
	for(int u : g[x])if(u != fat){
		dfs(u, x);
		sz[x] += sz[u];
	}
}

void upd(double &x,double y){x = max(x, y);}
int check(double lim){	// K+1
	// >= 0 : lim ะกมห , 1
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=K+1;j++)dp[i][j] = -inf;
	}
	dp[0][0] = 0;
	for(int i=1;i<=n;i++)w[dfn[i]] = p[i] - lim * s[i];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=K;j++)if(dp[i][j] != -inf){
			upd(dp[i+1][j+1], dp[i][j] + w[i]);
			upd(dp[i+sz[seq[i]]][j], dp[i][j]);
		}
	for(int i=1;i<=n+1;i++)if(dp[i][K+1] > eps){return 1;}
	return 0;
}

signed main(){
	scanf("%d%d",&K,&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&s[i],&p[i],&r[i]);
		g[i].push_back(r[i]), g[r[i]].push_back(i);
	}
	dfs(0);
	double l=0, r=1e9, ans;
	while(fabs(r-l) > eps){
		double mid = (l+r)/2.0;
		if(check(mid))l = ans = mid;
		else r = mid;
	}
	printf("%.3f\n",ans);

	return 0;
}


