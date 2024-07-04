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

int n, k, a[maxn], oc[maxn], ned[maxn], dep[maxn];
vector<int>g[maxn]; 

void dfs(int x,int fat=0){
	for(int u : g[x])if(u!=fat){
		dfs(u, x);
		if(!oc[u]){
			dep[x] = max(dep[x], dep[u]+1);
		}
	}
	if(!oc[x])return ;
	if(dep[x] >= ned[x]){
		ned[x] = 0;
		return ;
	}
	if(fat && !oc[fat]){
		ned[fat] = ned[x] - 1;
		ned[x] = 0;
		oc[fat] = 1;
		return ;
	}
}

int check(int lim){
	for(int i=1;i<=n;i++)oc[i] = ned[i] = dep[i] = 0;
	
	for(int i=1;i<=k;i++)oc[a[i]] = 1;
	for(int i=1;i<=k;i++)ned[a[i]] = lim/k+(i<=lim%k);
	
	dfs(1);
	for(int i=1;i<=n;i++)
		if(ned[i])return 0;
	return 1;
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++)scanf("%d",&a[i]);
	
	int l=0, r=n, ans;
	while(l <= r){
		int mid = l+r>>1;
		if(check(mid))l = mid+1, ans = mid;
		else r = mid-1;
	}
	printf("%d\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

