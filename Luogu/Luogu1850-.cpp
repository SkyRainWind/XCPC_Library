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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2005,maxv=305;

// dp[i][j][0/1] 表示第 i 个时间，已经用了 j 次机会，第i时间申请/没有 的最小期望值 
double dp[maxn][maxn][2];
int dis[maxv][maxv];
int n,m,v,e;
int c[maxn], d[maxn];
double k[maxn];

void ckmn(double &x,double y){x = min(x, y);}

signed main(){
	scanf("%d%d%d%d",&n,&m,&v,&e);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	for(int i=1;i<=n;i++)scanf("%lf",&k[i]);
	memset(dis, 0x3f, sizeof dis);
	for(int i=1;i<=v;i++)dis[i][i] = 0;
	for(int i=1;i<=e;i++){
		int x,y,w;scanf("%d%d%d",&x,&y,&w);
		if(x == y)continue;
		dis[x][y] = dis[y][x] = min(dis[x][y], w);
	}
	for(int k=1;k<=v;k++)
		for(int i=1;i<=v;i++)
			for(int j=1;j<=v;j++)dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
			dp[i][j][0] = dp[i][j][1] = 1e9;
			
	dp[1][0][0] = 0;
	dp[1][1][1] = 0;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=m;j++){
			ckmn(dp[i][j][0] , dp[i-1][j][0] + 1.0 * dis[c[i-1]][c[i]]);
			if(j >= 1)ckmn(dp[i][j][0], dp[i-1][j][1] + 1.0 * (1 - k[i-1]) * dis[c[i-1]][c[i]] + 1.0 * k[i-1] * dis[d[i-1]][c[i]]);
		}
		for(int j=1;j<=m;j++){
			ckmn(dp[i][j][1], dp[i-1][j-1][0] + 1.0 * (1 - k[i]) * dis[c[i-1]][c[i]] + 1.0 * k[i] * dis[c[i-1]][d[i]]);
			if(j >= 2)ckmn(dp[i][j][1], dp[i-1][j-1][1] + 1.0 * (1 - k[i-1]) * (1 - k[i]) * dis[c[i-1]][c[i]] + 1.0 * (1 - k[i-1]) * k[i] * dis[c[i-1]][d[i]] + 1.0 * k[i-1] * (1 - k[i]) * dis[d[i-1]][c[i]] + 1.0 * k[i-1] * k[i] * dis[d[i-1]][d[i]]);
		}
	}
	double ans = 1e9;
	for(int i=0;i<=m;i++){
		ckmn(ans, dp[n][i][0]);
		if(i >= 1)ckmn(ans, dp[n][i][1]);
	}
	printf("%.2f\n",ans);

	return 0;
}


