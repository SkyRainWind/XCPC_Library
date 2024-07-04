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

int n,a[maxn];
vector<int>g[maxn];
int sz[maxn], heavy[maxn];

void dfs1(int x,int fat=0){
	sz[x] = 1;
	for(int u : g[x])if(u != fat){
		dfs1(u, x);
		sz[x] += sz[u];
		if(!heavy[x] || sz[u] > sz[heavy[x]])
			heavy[x] = u;
	}
}

ll sum = 0, mx=0;

void add(int x,int fat,int op){
	cnt[a[x]] += op;
	if(cnt[a[x]] > mx)sum = a[x], mx = cnt[a[x]];
	else if(cnt[a[x]] == mx)sum += a[x];
	for(int )
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
	}
	dfs1(1);

	return 0;
}

