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

int n,mod;
vector<int>g[maxn];
ll dp[maxn],ans[maxn];
int id[maxn];
vector<int>prem[maxn], sufm[maxn];
int leaf[maxn];

void dfs(int x,int fat=0){
	dp[x] = 1;
	prem[x].resize(g[x].size()+2);
	sufm[x].resize(g[x].size()+2);
	prem[x][0] = 1;
	sufm[x][g[x].size()+1] = 1;
	
	if(fat && g[x].size() == 1){
		leaf[x] = 1;
		return ;
	}
	
	for(int i=0;i<g[x].size();i++){
		int u=g[x][i];
		if(u!=fat){
			id[u] = i+1;
			dfs(u, x);
			
			prem[x][i+1] = 1ll * prem[x][i] * (1+dp[u]) % mod;
		}else prem[x][i+1] = prem[x][i]; 
	}
	for(int i=g[x].size()-1;i>=0;i--){
		int u=g[x][i];
		if(u!=fat){
			dfs(u, x);
			
			sufm[x][i+1] = 1ll * sufm[x][i+2] * (1+dp[u]) % mod;
		}else sufm[x][i+1] = sufm[x][i+2];
	}
	dp[x] = prem[x][g[x].size()];
}

signed main(){
	scanf("%d%d",&n,&mod);
	for(int i=1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
	}
	
	for(int i=1;i<=n;i++){
		dfs(i);	
		ans[i] = dp[i];
		printf("%d\n",dp[i]);
	}

	return 0;
}

