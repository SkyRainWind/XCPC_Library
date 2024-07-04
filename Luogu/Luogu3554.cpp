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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 3e5 + 5;

int n;
vector<int>g[maxn];
int de[maxn];
LL dp[maxn], K;

void dfs(int x,int fat=0,LL ndp = 0){
//	if(x==10000)cerr<<x<<'\n';
	dp[x] = 0;
	for(int u : g[x])if(u!=fat){
		dfs(u, x);
		dp[x] += (dp[u] + 1);
	}
	dp[x] = max(dp[x] - K,0ll);
}

signed main(){
	freopen("3554.in","r",stdin);
	freopen("3554.out","w",stdout);
	scanf("%d",&n);
	if(n == 1)return puts("0"), 0;
	for(int i=1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y), g[y].push_back(x);
	}
	for(int i=1;i<=n;i++)de[i] = g[i].size() - (i!=1);
	K=1406;dfs(1);
	for(int i=1;i<=n;i++)printf("%d %d\n",i,dp[i]);
	return 0;
	int l=1, r = 300000, ans = n;
	while(l <= r){
		int mid = l+r>>1;
		K = (LL)mid;dfs(1);
		if(dp[1]==0)ans = mid, r = mid-1;
		else l = mid+1;
	}
	printf("%d\n",ans);

	return 0;
}

