// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2505;
const double eps = 1e-6;

int K,n;
vector<int>g[maxn];
int s[maxn], p[maxn];
double w[maxn], f[maxn], dp[maxn][maxn];	// dp[i][j] i 点 一共选了 j 个的最大权值 
int sz[maxn];

void dfs(int x,int fat = -1){
	sz[x] = 1;
	dp[x][1] = w[x];
	for(int u : g[x]){
		if(u == fat)continue;
		dfs(u, x);
		for(int j=1;j<=K+1;j++)f[j] = -1e9;
		for(int j = 1;j <= min(sz[x], K + 1);j++)
			for(int k = 0; k<= min(sz[u], K + 1-j);k++){
				f[j + k] = max(f[j + k], dp[x][j] + dp[u][k]);
			}
		memcpy(dp[x], f, sizeof dp[x]);
		sz[x] += sz[u];
	}
}

int check(double lim){
	for(int i=0;i<=n;i++){
		for(int j=1;j<=K+1;j++)
			dp[i][j] = -1e9;
		dp[i][0] = 0;
	}
	w[0] = 0;
	for(int i=1;i<=n;i++)w[i] = 1.0 * p[i] - lim * s[i];
	dfs(0);
	printf("!! %f\n",dp[0][K+1]);
//	printf("?? %f\n",dp[1][K]);
	return dp[0][K+1] > -eps;
}

signed main(){
	freopen("4322.in", "r", stdin);
	scanf("%d%d",&K,&n);
	for(int i=1;i<=n;i++){
		int r;scanf("%d%d%d",&s[i],&p[i],&r);
		g[i].push_back(r);g[r].push_back(i);
	}
	printf("%d\n",check(1.293));return 0;
	double l = 0, r = 1e9, ans;
	while(fabs(r-l) > eps){
		double mid = (l+r) / 2;
		if(check(mid))l = ans = mid;
		else r = mid;
	}
	printf("%.3f\n",ans);

	return 0;
}


