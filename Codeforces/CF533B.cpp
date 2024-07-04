// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;

int n,a[maxn];
vector<int>g[maxn];
LL dp[maxn][2];

void dfs(int x){
	dp[x][1] = -1e18;
	for(int u : g[x]){
		dfs(u);
		vector<LL>predp(2);
		predp[0] = dp[x][0], predp[1] = dp[x][1];
		dp[x][0] = max(predp[0]+dp[u][0], predp[1]+dp[u][1]);
		dp[x][1] = max(predp[1]+dp[u][0], predp[0]+dp[u][1]);
	}
	dp[x][1] = max(dp[x][1], dp[x][0] + a[x]);
}

signed main(){
	scanf("%d",&n);
	for(int i=1,p;i<=n;i++){scanf("%d%d",&p,&a[i]);if(~p)g[p].push_back(i);}
	dfs(1);
	printf("%lld\n",max(dp[1][1], dp[1][0]));

	return 0;
}

