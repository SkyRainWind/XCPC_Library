// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=305;

// dp[u][i][j] 表示 u 结点，考虑了前 i 个子节点，选了 j 门课的最大学分
// dp[u][0][1] = k[u]
// dp[u][i][j] = max{dp[u][i-1][j-k] + dp[v][sz_son[v]][k]} v = son[u][i]

int dp[maxn][2][maxn];
int n,m;
int sc[maxn];
vector<int>g[maxn];

void dfs(int x){
	if(g[x].size() == 0){
		dp[x][0][1] = sc[x];
		dp[x][0][0] = 0;
		return ;
	}
	dp[x][0][1] = sc[x]; 
	dp[x][0][0] = 0;
	for(int i=0;i<g[x].size();i++){	// 注意由于 i 是从 0 开始的，所以其奇偶性和上式是反的 
		int u = g[x][i];
		dfs(u);
		memset(dp[x][i&1^1], 0, sizeof dp[x][i&1^1]);
		dp[x][i&1^1][1] = sc[x];
		for(int j=2;j<=m;j++){
			dp[x][i&1^1][j] = dp[x][i&1][j];
			for(int k=0;k<j;k++){
				dp[x][i&1^1][j] = max(dp[x][i&1^1][j], dp[x][i&1][j-k]+dp[u][g[u].size()&1][k]);
			}
		}
	}
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int s;scanf("%d%d",&s,&sc[i]);
		g[s].push_back(i);
	}
	++ m;
	dfs(0);

	printf("%d\n",dp[0][g[0].size()&1][m]);
	return 0;
}


