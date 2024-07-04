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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=1e5+5, mod = 1e9+7;

int n,K;
vector<int>g[maxn];
int sz[maxn], ans[maxn];
int dp[maxn][205], f[maxn];

// \sum f(x)^K = \sum_{i=1}^K S(K,i) * i! * ( \sum_X C(f(x), i) )
// 考虑对于一个给定的 i 如何计算这个组合数 

void dfs(int x,int fat = -1){
	sz[x] = 1;
	dp[x][0] = 2;	// 选和没选自己都合法 
	for(int u : g[x]){
		if(u == fat)continue;
		dfs(u, x);
		memset(f, 0, sizeof f); 
		for(int j = 0;j <= min(K, sz[x]);j++)
			for(int k = 0;k <= min(K-j, sz[u]);k++)
				(f[j+k] += 1ll * dp[x][j] * dp[u][k] % mod) %= mod;
		for(int i=0;i<=K;i++)
			dp[x][i] = f[i];
		for(int i=0;i<=K;i++)(ans[i] = ans[i] - dp[u][i] + mod) %= mod;
		sz[x] += sz[u];
	}
	for(int i=0;i<=K;i++)(ans[i] = ans[i] + dp[x][i]) %= mod;
	for(int i=K;i>=1;i--)(dp[x][i] += dp[x][i-1]) %= mod;
	(dp[x][1] = dp[x][1] - 1 + mod) %= mod;
}

int S[205][205];

signed main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y), g[y].push_back(x);
	}
	dfs(1);
	S[1][1] = 1;
	for(int i=2;i<=K;i++){
		for(int j=1;j<=K;j++)
			(S[i][j] = S[i-1][j-1] + 1ll * S[i-1][j] * j %mod) %= mod;
	}
	int fac = 1, res=0;
	for(int i=1;i<=K;i++){
		fac = 1ll*fac*i%mod;
		(res += 1ll*S[K][i]*fac%mod*ans[i]%mod) %= mod;
	}
	printf("%d\n",res);

	return 0;
}


