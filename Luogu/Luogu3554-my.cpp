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

int dfs(int x,int fat=0,LL ndp = 0){
//	if(x==10000)cerr<<x<<'\n';
	dp[x] = ndp;
	if(dp[x] < 0)return 0;
	for(int u : g[x])if(u!=fat){
		int r = dfs(u, x, dp[x] + K - de[x]);
		if(!r)return 0;
	}
	return 1;
}

signed main(){
	freopen("3554.in","r",stdin);
	freopen("3554-my.out","w",stdout);
	scanf("%d",&n);
	if(n == 1)return puts("0"), 0;
	for(int i=1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y), g[y].push_back(x);
	}
	for(int i=1;i<=n;i++)de[i] = g[i].size() - (i!=1);
	K=1406;
	dfs(1);
	for(int i=1;i<=n;i++)if(de[i]==0)printf("%d %d\n",i,dp[i]);
	return 0;
	int l=1, r = 300000, ans = n;
	while(l <= r){
		int mid = l+r>>1;
		K = mid;
		if(dfs(1))ans = mid, r = mid-1;
		else l = mid+1;
	}
	printf("%d\n",ans);

	return 0;
}

