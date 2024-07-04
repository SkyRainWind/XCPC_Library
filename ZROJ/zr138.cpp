// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5e5+5;

int n,m;
int de[maxn];
vector<pii>g[maxn];
map<pii,int>mp;
int hd[maxn];
int ans[maxn], acnt = 0, vis[maxn];
//int qw[maxn],qwq;

// 无向图欧拉回路 
void dfs(int x){	// 当前搜到 x 号点 
	vis[x] = 1;
	while(1){
		for(;hd[x] < g[x].size() && !mp[mpr(x, g[x][hd[x]].first)];)++ hd[x];
		if(hd[x] >= g[x].size())break;
		int cur = hd[x], u = g[x][cur].first, v = g[x][cur].second;	// (x,u) in E
		if(mp[mpr(x, u)]){
			-- mp[mpr(x, u)]; -- mp[mpr(u, x)];
			++ hd[x];
			dfs(u);
			if(v < 0)ans[-v] = 1;
		}
	}
//	qw[++qwq] = x;
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		++ de[x], ++ de[y];
		++ mp[mpr(x, y)];++ mp[mpr(y, x)];
		g[x].push_back(mpr(y, i)), g[y].push_back(mpr(x, -i)); 
	}
	vector<int>odd;
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(de[i]%2 == 0)++ cnt;
		else odd.push_back(i);
	}
	for(int i=0;i<odd.size();i+=2){
		int u = odd[i], v = odd[i+1];
//		printf("%d %d\n",u,v);
		++ mp[mpr(u, v)]; ++ mp[mpr(v, u)];
		g[u].push_back(mpr(v, m+1));g[v].push_back(mpr(u, m+1));
	}
	
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++){
		if(!vis[i])dfs(i);
	}
//	while(qwq)printf("%d ",qw[qwq--]);
	for(int i=1;i<=m;i++)printf("%d",ans[i]);

	return 0;
}

