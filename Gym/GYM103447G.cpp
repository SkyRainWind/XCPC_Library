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

vector<pii>g[maxn];
int tw,tb,n,m,k;
int pos[maxn];
double p[maxn],ps[maxn];

double dp[(1<<19)+5][24];
int gp[(1<<19)+5][24];
int dis[20][maxn],vis[maxn];
int disi[maxn];

void dijkstra(int idx,int s){
	priority_queue<pii>pq;
	for(int i=0;i<=n;i++)disi[i] = inf, vis[i] = 0;
	disi[s] = 0;
	pq.push(mpr(0,s));
	
	while(!pq.empty()){
		int u=pq.top().second;pq.pop();
		if(vis[u])continue;
		vis[u] = 1;
		for(pii it : g[u]){
			int v = it.first, w=it.second;
			if(disi[v] > disi[u] + w){
				disi[v] = disi[u] + w;
				pq.push(mpr(-disi[v], v));
			}
		}
	}
//	printf("!! %d\n",disi[3]);
	for(int i=1;i<=k;i++)dis[idx][i] = disi[pos[i]];
	dis[idx][21] = disi[1], dis[idx][22] = disi[n];
}

void ck(int &a,int b){a = min(a, b);}
void ck(double &a,double b){a = min(a, b);}

double dfs(int S,int x){
	if(dp[S][x] != -1)return dp[S][x];
	dp[S][x] = dis[x][22] * 1. / tw;
	for(int i=1;i<=k;i++)if(!(S&(1<<(i-1)))){
		dp[S][x] = min(dp[S][x], 1. * dfs(S^(1<<(i-1)), i) * (p[i]) + dis[x][i] * 1. / tw + dis[i][22] * 1. / tb * (1. - p[i]));
//		printf("?? %d %d %d %f\n",i,dis[i][22],dis[x][i],p[i]);
	}
//	printf("hh %d %d %f\n",S,x,dp[S][x]);
	return dp[S][x];
}

signed main(){
	scanf("%d%d",&tw,&tb);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		g[u].pb(mpr(v,w)), g[v].pb(mpr(u,w));
	}
//	printf("? %d\n",dis[0][1]);
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		int pro;
		scanf("%d%d",&pos[i],&pro);
		p[i] = pro / 100.0;
	}
	for(int i=1;i<=k;i++)dijkstra(i,pos[i]);
	dijkstra(0,1);
	if(dis[0][22] == inf){puts("-1");return 0;}
	p[0]=0;
	for(int S=0;S<=(1<<k)-1;S++)
		for(int i=0;i<=k;i++)gp[S][i] = inf, dp[S][i] = -1;
	
	printf("%.9f\n",dfs(0,0));
	/*
	for(int i=1;i<=k;i++)
		gp[1<<(i-1)][i] = dis[i][21],
		dp[(1<<(i-1))][i] = p[i] * dis[i][21];
		printf("%d\n",dis[1][21]);
	for(int S=1;S<=(1<<k)-1;S++){
		for(int j=1;j<=k;j++)if(S&(1<<(j-1)))
			for(int l=1;l<=k;l++)if((S&(1<<(l-1)))==0){
				ck(gp[S ^ (1<<(l-1))][l], gp[S][j] + dis[j][l]);
			}
	}
	for(int S=1;S<=(1<<k)-1;S++){
		for(int j=1;j<=k;j++)if(S&(1<<(j-1)))
			for(int l=1;l<=k;l++)if((S&(1<<(l-1)))==0){
				ck(dp[S ^ (1<<(l-1))][l], dp[S][j] + ps[S] * p[l] * (gp[S^(1<<(l-1))][l]+dis[j][22]));
			}
	}
	double ans = 1e18;
	for(int S=0;S<=(1<<k)-1;S++)
		for(int i=1;i<=k;i++)if(S&(1<<(i-1))){
			ans = min(ans, dp[S][i] / tw + ps[S] * (gp[S][i] + dis[i][22]) / tb);
		}
	printf("%.9f\n",ans);*/

	return 0;
}

