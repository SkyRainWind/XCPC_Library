// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn =2e5 + 5;

int n,m;
struct ed{
	int i,j,w;
}e[maxn];
vector<pii>g[maxn];
int cmp(ed a,ed b){return a.w > b.w;}
int vis[maxn],fa[maxn][22],mfa[maxn][22],dep[maxn];
int ffa[maxn];
int find(int x){return ffa[x] == x ? ffa[x] : ffa[x] = find(ffa[x]);}

void dfs(int x,int fat=0){
	vis[x] = 1;
	dep[x] = dep[fat] + 1;
	fa[x][0] = fat;
	for(pii u : g[x])if(u.first != fat){
		mfa[u.first][0] = u.second;
		dfs(u.first, x);
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

int path(int x,int anc){
	if(x == anc)return inf;
	int res = inf;
	for(int i=20;i>=0;i--)
		if(dep[fa[x][i]] >= dep[anc])
			res = min(res, mfa[x][i]),x = fa[x][i];
	return res;
}

signed main(){
//	freopen("Luogu1967.in","r",stdin);
	int cnt = 0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)ffa[i] = i;
	for(int i=1;i<=m;i++){
		++ cnt;
		scanf("%d%d%d",&e[cnt].i,&e[cnt].j,&e[cnt].w);
	}
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int x = e[i].i, y =e[i].j;
		int fx = x, fy = y;
		x = find(x), y = find(y);
		if(x != y){
			ffa[x] = y;
			g[fx].push_back(mpr(fy, e[i].w)), g[fy].push_back(mpr(fx, e[i].w));
		}
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])dfs(i);
	
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n;i++){
			fa[i][j] = fa[fa[i][j-1]][j-1];
			if(fa[i][j] == 0)continue;
			mfa[i][j] = min(mfa[i][j-1], mfa[fa[i][j-1]][j-1]);
		}
	
	int qu;scanf("%d",&qu);
	while(qu --){
		int l,r;scanf("%d%d",&l,&r);
		int fl = find(l), fr = find(r);
		if(fl != fr){
			puts("-1");
			continue;
		}
		int lc = getlca(l, r);
		int r1 = path(l, lc), r2 = path(r, lc);
		printf("%d\n",min(r1, r2));
	}

	return 0;
}

