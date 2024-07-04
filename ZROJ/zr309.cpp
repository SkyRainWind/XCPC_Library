// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=4005;

int n,m;
vector<int>g[maxn];
int w[maxn],c[maxn],s[maxn],f[maxn][maxn];

void dfs(int x){
	for(int i=m;i>=c[x];i--)
		if(f[x][i-c[x]] >= 0)f[x][i] = f[x][i-c[x]] + w[x];
	for(int i=0;i<=c[x]-1;i++)
		f[x][i] = -inf;
		
	for(int u:g[x]){
		dfs(u);
		int curj=1,
		for(int j=m;j>=c[x];j--){
			
		}
	}
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++){
		int x;scanf("%d",&x);
		g[x].pb(i);
	}
	for(int i=1;i<=n;i++)scanf("%d%d%d",&w[i],&c[i],&s[i]);
	dfs(1);

	return 0;
}

