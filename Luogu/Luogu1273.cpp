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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=3005;

struct node{
	int to, v;
	node(){}
	node(int to,int v) : to(to), v(v){}
};
int n,m;
vector<node>g[maxn];
int cst[maxn];
int dp[maxn][2][maxn], sz[maxn];

// dp[x][p][i] 表示以 x 为根节点，考虑到前p个子结点，选了 i 个用户的最大利润
// dp[x][p][i] = dp[x][p-1][i-c] + dp[u][g[u].size() & 1 ^ 1][c] - (c == 0 ? 0 : w(x,u))
// dp[1][g[1].size() & 1 ^ 1][ppp] > 0 

void dfs(int x,int fat = -1){
	if(~fat && g[x].size() == 1){
		sz[x] = 1;
		dp[x][0][1] = cst[x];
		dp[x][0][0] = 0;
		return ;
	}
	int i = 0;
	for(node nd : g[x]){
		int u = nd.to, w = nd.v;
		if(u == fat)continue;
		dfs(u, x);
		sz[x] += sz[u];

		++ i;
		if(i == 1){
			dp[x][i&1][0] = 0;
			for(int j = 1;j<=sz[x];j++)
				dp[x][i&1][j] = dp[u][g[u].size() & 1 ^ 1][j] - w;
			continue;
		}
		memset(dp[x][i&1], -0x3f, sizeof dp[x][i&1]);
		dp[x][i&1][0] = 0;
		
		for(int j = 1;j<=sz[x];j++)
			for(int c = 0;c<=j;c++){
				dp[x][i&1][j] = max(dp[x][i&1][j], dp[x][i&1^1][j-c] + dp[u][g[u].size() & 1 ^ 1][c] - (c == 0 ? 0 : w));
			}
	}
}

signed main(){
	memset(dp,-0x3f,sizeof dp);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-m;i++){
		int nn;scanf("%d",&nn);
		while(nn --){
			int aa, cc;scanf("%d%d",&aa,&cc);
			g[i].push_back(node(aa, cc)); g[aa].push_back(node(i, cc));
		}
	}
	for(int i = n-m+1; i<=n;i++)scanf("%d",&cst[i]);
	dfs(1);
//	printf("%d\n",dp[2][g[2].size() & 1 ^ 1][2]);
	for(int i = m;i>=1;i--)
		if(dp[1][g[1].size() & 1][i] >= 0)return printf("%d\n",i), 0;
	puts("0");

	return 0;
}


