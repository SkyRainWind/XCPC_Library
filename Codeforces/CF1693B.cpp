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
int l[maxn], r[maxn], cnt=0;
ll sum[maxn];

void dfs(int x,int fat=0){
	if(g[x].size() == 0){
		sum[fat] += r[x];
		++ cnt;
		return ;
	}
	
	for(int u : g[x]){
		dfs(u,x);
	}
	if(sum[x] > r[x]){
		sum[x] = r[x];
	}else if(sum[x] < l[x]){
		sum[x] = r[x];
		++ cnt;
	}
	sum[fat] += sum[x];
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)g[i].clear(), sum[i] = 0;
	cnt = 0;
	
	for(int i=2;i<=n;i++){
		int x;scanf("%d",&x);
		g[x].pb(i);
	}
	for(int i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]);
	dfs(1);
	printf("%d\n",cnt);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

