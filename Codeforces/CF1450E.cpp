// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 205;

int n,m;
vector<pii>g[maxn];
int dis[maxn][maxn];

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y,b;scanf("%d%d%d",&x,&y,&b);
		// a_y=a_x+1 -> a_y-a_x <= 1 && a_x-a_y <= -1
		if(b == 0)g[x].pb(mpr(y, 1)), g[y].pb(mpr(x, 1));
		else g[x].pb(mpr(y, 1)), g[y].pb(mpr(x, -1));
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)
		dis[i][i] = 0;
	for(int i=1;i<=n;i++)
		for(auto j : g[i])dis[i][j.first] = j.second;
	
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for(int i=1;i<=n;i++)
		if(dis[i][i] < 0)	// 判负环 
			return puts("NO"), 0;
	
	int res = -INF, r;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			for(auto k : g[j])
				if(dis[i][k.first] == dis[i][j])	// 判二分图 
					return puts("NO"), 0;
			if(dis[i][j] > res)
				res = dis[i][j],
				r = i;
		}
	puts("YES");
	int mx = -INF, mn = INF;
	for(int i=1;i<=n;i++)mx = max(mx, dis[r][i]), mn = min(mn, dis[r][i]);
	printf("%d\n",mx-mn);
	int ans = 0;
	for(int i=1;i<=n;i++)
		printf("%d ",dis[r][i]);
	
	return 0;
}

