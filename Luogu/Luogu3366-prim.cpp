// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=500005;

struct ed{
	int to,w,nxt;
}ed[maxn << 1];
int head[maxn],ecnt=0;
void add(int x,int y,int z){ed[++ecnt].to=y;ed[ecnt].w=z;ed[ecnt].nxt=head[x];head[x]=ecnt;}
int n,m,dis[maxn],vis[maxn];

int prim(){
	int ans = 0;
	for(int i=2;i<=n;i++)dis[i] = inf;
	for(int i=head[1];i;i=ed[i].nxt){
		int u = ed[i].to;
		dis[u] = min(dis[u], ed[i].w);
	}
	int now = 1;
	for(int i=1;i<=n-1;i++){
		int mn = inf;
		vis[now] = 1;
		for(int i=1;i<=n;i++)
			if(!vis[i] && mn > dis[i])mn = dis[i], now = i;
		ans += mn;
		for(int i=head[now];i;i=ed[i].nxt){
			int u = ed[i].to;
			if(dis[u] > ed[i].w && !vis[u])
				dis[u] = ed[i].w;
		}
	}
	for(int i=1;i<=n;++i)if(dis[i] == inf){puts("orz");exit(0);}
	return ans;
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		add(x,y,z),add(y,x,z);
	}
	int r = prim();
	printf("%d\n",r);

	return 0;
}


