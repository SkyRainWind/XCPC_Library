// by Balloons
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=155;

int n,p;
vector<int>g[maxn];
int dp[maxn][2][maxn], ans = INF, sz[maxn];

void dfs(int x,int fat = -1){
	sz[x] = 1;
	if(~fat && g[x].size() == 1){
		dp[x][0][1] = 0;
		return ;
	}
	
	int i = 0;
	for(int u : g[x]){
		if(u == fat)continue;
		dfs(u, x);
		sz[x] += sz[u];

		++ i;
		memset(dp[x][i&1], 0x3f, sizeof dp[x][i&1]);
		
		if(i == 1){
			dp[x][i&1][1] = 1;
			for(int j = 1;j<=sz[u];j++)
				dp[x][i&1][j + 1] = dp[u][g[u].size() & 1 ^ 1][j];
			continue;
		}
		
		dp[x][i&1][sz[x]] = 0;
		for(int j = p; j>=1;j--){
			for(int k = 0;k<=j-1;k++){
				dp[x][i&1][j] = min(dp[x][i&1][j], dp[x][i&1^1][j-k] + (k == 0 ? 1 : dp[u][g[u].size() & 1 ^ 1][k]));
			}
		}
	}
}

signed main(){
	memset(dp, 0x3f, sizeof dp);
	scanf("%d%d",&n,&p);
	if(n == 1)return puts("0"), 0;
	for(int i = 1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y), g[y].push_back(x);
	}
	dfs(1);
	ans = min(ans, dp[1][g[1].size() & 1][p]);
	for(int i=2;i<=n;i++)ans = min(ans, 1 + dp[i][g[i].size() & 1 ^ 1][p]);
	printf("%d\n",ans);

	return 0;
}

