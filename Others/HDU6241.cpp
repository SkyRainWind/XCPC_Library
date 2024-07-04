// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n;
vector<int>g[maxn];
int sa,sb,gg;
pii alim[maxn], blim[maxn];
vector<int>up,dn;
pii dp[maxn];

void dfs(int x,int fat=0){
	int lw,hi;lw=hi=0;
	for(int u : g[x])if(u!=fat){
		dfs(u, x);
		lw += dp[u].first, hi += dp[u].second;
	}
	dp[x]=mpr(lw,hi+1);
	if(dp[x].first < up[x])
		dp[x].first = up[x];
	if(dp[x].second > dn[x])
		dp[x].second = dn[x];
//		printf("hh %d %d %d\n",x,dp[x].first,dp[x].second);
	if(dp[x].first > dp[x].second)gg = 1;
}

int check(int lim){
	gg = 0;
	up.assign(n+2, -inf);
	dn.assign(n+2, inf);
	for(int i=1;i<=sa;i++){
		up[alim[i].first] = max(up[alim[i].first], alim[i].second);
	}
	for(int i=1;i<=sb;i++){
		dn[blim[i].first] = min(dn[blim[i].first], lim - blim[i].second);
		if(dn[blim[i].first] < 0)return 0;
	}
//	for(int i=1;i<=n;i++)printf("%d == %d %d\n",lim,up[i],dn[i]);
	dfs(1);
	return !gg && dp[1].first <= lim && lim <= dp[1].second;
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
	}
	scanf("%d",&sa);
	for(int i=1;i<=sa;i++)scanf("%d%d",&alim[i].first,&alim[i].second);
	scanf("%d",&sb);
	for(int i=1;i<=sb;i++)scanf("%d%d",&blim[i].first,&blim[i].second);

	int l=1, r=n, ans=-1;
	while(l <= r){
		int mid = l+r>>1;
		if(check(mid))ans = mid, r = mid-1;
		else l = mid+1;
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)g[i].clear();
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}
