// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2005;

int n;
char s[maxn];
int fa[maxn][23];
int dp[maxn][maxn],dep[maxn];
vector<int>g[maxn];

int getson(int x,int to){
	for(int i=20;i>=0;i--)
		if(dep[fa[x][i]] > dep[to])x =fa[x][i];
	return x;
}

int solve(int x,int y,int lc){
//	printf("%d %d %d\n",x,y,lc);
	if(~dp[x][y])return dp[x][y];
	
	if(x == y)return dp[x][y] = 1;
	if(x == lc){
		int u = getson(y, lc);
		if(y == u)return dp[x][y] = dp[y][x] = (s[x] == s[y] ? 2 : 1);
		int t = max(solve(u, y, u), max(solve(x, fa[y][0], lc), solve(u, fa[y][0], u) + 2 * (s[x] == s[y])));;
		return dp[x][y] = dp[y][x] = t;
	}
	if(y == lc){
		int u = getson(x, lc);
		if(x == u)return dp[x][y] = dp[y][x] = (s[x] == s[y] ? 2 : 1);
		int t = max(solve(x, u, u), max(solve(fa[x][0], u, lc), solve(fa[x][0], u, u) + 2 * (s[x] == s[y])));
		return dp[x][y] = dp[y][x] = t;
	}
	int t = max(solve(x, fa[y][0], lc), max(solve(fa[x][0], y, lc), solve(fa[x][0], fa[y][0], lc) + 2 * (s[x] == s[y])));
	return dp[x][y] = dp[y][x] = t;
}

void dfs(int x,int fat = 0){
	fa[x][0] = fat;
	dep[x] = dep[fat] + 1;
	for(int u : g[x])if(u != fat){
		dfs(u, x);
	}
}

int getlca(int x,int y){
	if(dep[x] < dep[y])swap(x, y);
	for(int i=20;i>=0;i--)
		if(dep[fa[x][i]] >= dep[y])x = fa[x][i];
	if(x == y)return x;
	
	for(int i=20;i>=0;i--)
		if(fa[x][i] != fa[y][i])x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

void solve(){
	scanf("%d",&n);scanf("%s",s + 1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)dp[i][j] = -1;
		
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y), g[y].push_back(x);
	}
	dep[0] = 1;
	dfs(1);
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n;i++)
			fa[i][j] = fa[fa[i][j-1]][j-1];
	
	int ans = 0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			ans = max(ans, solve(i,j,getlca(i,j)));
	printf("%d\n",ans);
}

signed main(){
//	freopen("CF1771D.in","r",stdin);
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

