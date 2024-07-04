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

int n,m;
vector<int>g[maxn],res;
int dep[maxn],mx=0,r1;

void dfs(int x,int fat=0){
	dep[x] = dep[fat] + 1;
	if(dep[x] > mx){
		mx = dep[x];
		r1 = x;
	}
	for(int u : g[x])if(u!=fat){
		dfs(u, x);
	}
}

int d2[maxn], f2[maxn], sf2[maxn], rmx;
void dfs2(int x,int fat=0){
	d2[x] = d2[fat] + 1;
	f2[x] = 0;
	rmx = max(rmx, d2[x]);
	for(int u : g[x])if(u!=fat){
		dfs2(u,x); 
		if(f2[x] < f2[u] + 1){
			sf2[x] = f2[x];
			f2[x] = f2[u] + 1;
		}else if(sf2[x] < f2[u] + 1){
			sf2[x] = f2[u] + 1;
		}
	}
}

int g1[maxn], g2[maxn];
void getdp(int x,int fat=0){
	if(fat && g[x].size() == 1){
		g1[x] = g1[fat] + 1;
		g2[x] = 0;
		return ;
	}
	for(int u : g[x])if(u!=fat){
		g1[u] = f2[u], g2[u] = sf2[u];
		if(g1[x] != g1[u] + 1){
			g2[u] = g1[u];
			g1[u] = g1[x] + 1;
		}else{
			if(g1[u] < g2[x] + 1){
				g2[u] = g1[u];
				g1[u] = g2[x] + 1;
			}else if(g2[u] < g2[x] + 1){
				g2[u] = g2[x] + 1;
			}
		}
		getdp(u, x);
	}
}

signed main(){
//	freopen("LOJ10195.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		++ x, ++ y;
		g[x].pb(y),g[y].pb(x);
	}
	dfs(1);
	dfs2(r1);
	
	g1[r1] = f2[r1], g2[r1] = sf2[r1];
	-- rmx;
//	printf("! %d %d %d\n",f2[1],sf2[1],rmx);
	getdp(r1);
//	printf("! %d %d\n",g1[4],g2[4]);
	for(int i=1;i<=n;i++)
		if(rmx == g1[i] + g2[i])res.pb(i);
	for(auto it : res)printf("%d\n",it-1);

	return 0;
}

