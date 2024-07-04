// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1005;

int n,m;
vector<int>g[85];
int dp[2][81*81+5][2][82],x[85],dis[85][85];

void ck(int &a,int b){a = min(a, b);}

signed main(){
	memset(dp,0x3f,sizeof dp);
	memset(dis,0x3f,sizeof dis);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y);
		dis[x][y] = 1;
	}
	int q;scanf("%d",&q);
	for(int i=1;i<=q;i++)scanf("%d",&x[i]);
	for(int i=1;i<=n;i++)dis[i][i] = 0;
	
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	
	dp[0][0][0][1] = dp[0][0][1][1] = 0;
	x[0] = 1;
	for(int i=0;i<q;i++){
		for(int j=0;j<=q*n;j++){
			for(int other=1;other<=n;other++){
				ck(dp[i+1&1][j+dis[x[i]][x[i+1]]][0][other], dp[i&1][j][0][other]);
				ck(dp[i+1&1][j][1][x[i]], dp[i&1][j][0][other] + dis[other][x[i+1]]);
				ck(dp[i+1&1][j+dis[other][x[i+1]]][0][x[i]], dp[i&1][j][1][other]);
				ck(dp[i+1&1][j][1][other], dp[i&1][j][1][other] + dis[x[i]][x[i+1]]);
			}
		}
		memset(dp[i&1], 0x3f, sizeof dp[i&1]);
	}
	
	int ans = INF;
	for(int j=0;j<=q*n;j++){
		int now = INF;
		for(int other=1;other<=n;other++)
			ck(now, dp[q&1][j][0][other]), ck(now, dp[q&1][j][1][other]);
//		printf("%d %d\n",j,now);
		ans = min(ans, max(j, now));
	}
	printf("%d\n",ans);

	return 0;
}

