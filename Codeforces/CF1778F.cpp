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

int n,k;
int a[maxn];
vector<int>g[maxn], divs[1005];
vector<int>dp[maxn];

void dfs(int x,int fat=0){
	dp[x].clear();
	dp[x].resize(divs[a[x]].size());
	for(int u : g[x])if(u != fat){
		dfs(u, x); 
		for(int j=0;j<divs[a[x]].size();j++){
			int dj = divs[a[x]][j], r = k+1;
			for(int kk=0;kk<divs[a[u]].size();kk++){
				int dk = divs[a[u]][kk];
				if(dk%dj == 0){
					r = min(r, dp[u][kk]);
				}else if(dk*dk%dj == 0){
					r = min(r, dp[u][kk] + 1);
				}
			}
			dp[x][j] = min(dp[x][j] + r, k+1);
		}
	}
	dp[x][0] = 0;
}

void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), g[i].clear();
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
	}
	
	dfs(1);
	for(int i=dp[1].size()-1;i>=0;i--)
		if(dp[1][i] < k){
			printf("%lld\n",1ll*a[1]*divs[a[1]][i]);
			return ;
		}
	printf("%d\n",a[1]);
}

signed main(){
	for(int i=1;i<=1000;i++)
		for(int j=i;j<=1000;j+=i)
			divs[j].pb(i);
		int an=0;
	for(int i=1;i<=1000;i++)an=max(an,(int)divs[i].size());
	cout << an;
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

