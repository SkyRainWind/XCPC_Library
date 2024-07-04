// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

vector<pii>g[maxn];
int n,m;
int fa[maxn][22], leaf[maxn], dep[maxn];
pii rans[maxn][2];
int num[maxn], ans = 0, ansid[maxn], cf[maxn];
int res, tot = 0;

void dfs0(int x,int fat=0){
	fa[x][0] = fat;
	dep[x] = dep[fat] + 1;
	for(pii u : g[x]){
		if(u.first == fat)continue;
		dfs0(u.first, x);
	}
	if(fat && g[x].size() == 1)leaf[x] = 1;
}

int getlca(int x,int y){
	if(dep[x] < dep[y])swap(x, y);
	for(int i=20;i>=0;i--){
		if(dep[fa[x][i]] >= dep[y])x = fa[x][i];
	}
	if(x == y)return x;
	for(int i=20;i>=0;i--){
		if(fa[x][i] != fa[y][i])x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}

void dfs1(int x,int fat = 0){
	for(pii u : g[x]){
		if(u.first == fat)continue;
		dfs1(u.first, x);
		num[u.second] += cf[u.first];
		tot += cf[u.first];
		cf[x] += cf[u.first];
	}
	if(leaf[x])return ;
	rans[x][0] = rans[x][1] = mpr(-1e9, 1e9);
	for(pii u : g[x]){
		if(u.first == fat)continue;
		if(num[u.second] > rans[x][0].first)rans[x][1] = rans[x][0], rans[x][0] = mpr(num[u.second], u.second);
		else if(num[u.second] > rans[x][1].first)rans[x][1] = mpr(num[u.second],u.second);
	}
	ans += rans[x][0].first;
	ansid[x] = rans[x][0].second;
}

void getans(int x,int fat = 0,int curans = ans){
	if(x == 1&&g[1].size() == 1){	// corner case 
		int cc = curans;
		pii u = g[1][0];
		int sonu = u.first;
		cc -= rans[x][0].first + rans[sonu][0].first;
		
		if(rans[sonu][0].first < rans[x][0].first){
			ansid[sonu] = rans[x][0].second;
			rans[sonu][1] = rans[sonu][0];rans[sonu][0] = rans[x][0];
		}else if(rans[sonu][1].first < rans[x][0].first)
			rans[sonu][1] = rans[x][0];
		
		cc += rans[sonu][0].first;
		res = max(res, cc);
		
		getans(sonu, x, cc);
		return ;
	}
	
	pii gg =mpr(-1, -1);
	for(pii u : g[x]){
		if(u.first == fat)continue;
		if(leaf[u.first]){	// 叶子结点单独考虑 
			if(ansid[x] != u.second){
				res = max(res, curans + num[u.second]);
			}else{
				if(ansid[x] == rans[x][0].second)
					res = max(res, curans + rans[x][1].first);
				else
					res = max(res, curans + rans[x][0].first);
			}
			continue;
		}
		
		// root : x->u.first
		if(ansid[x] != u.second){	// (x,sonu)没选 
			int sonu = u.first;
			int cc = curans - rans[sonu][0].first;
			if(num[u.second] > rans[sonu][0].first)rans[sonu][1] = rans[sonu][0], rans[sonu][0] = mpr(num[u.second], u.second);
			else if(num[u.second] > rans[sonu][1].first)rans[sonu][1] = mpr(num[u.second], u.second);
			
			ansid[sonu] = rans[sonu][0].second, cc += rans[sonu][0].first;
			
			res = max(res, cc);
			getans(sonu, x, cc);
		}else{	// (x,sonu)选了，最后处理，就不需要再回溯了 
			gg = u;
		}
	}
	
	if(gg.first == -1)return ;
//	printf("!! %d %d\n",x,gg.first);
	pii u = gg;
	int sonu = u.first;
	ansid[x] = rans[x][1].second;
	int cc = curans;
	cc += rans[x][1].first - rans[x][0].first;
	
	if(rans[sonu][0].first < rans[x][0].first){
		ansid[sonu] = rans[x][0].second;
		cc += rans[x][0].first - rans[sonu][0].first;
		rans[sonu][1] = rans[sonu][0];rans[sonu][0] = rans[x][0];
	}else if(rans[sonu][1].first < rans[x][0].first)
		rans[sonu][1] = rans[x][0];
	
	res = max(res, cc);
	getans(u.first, x, cc);
	
	// 除了 sonu 其余的儿子不会更新了，所以不用更新x的 min secmin 
}

signed main(){
//	freopen("zr1120.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(mpr(v,i));
		g[v].push_back(mpr(u,i));
	}
	dfs0(1);
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n;i++)fa[i][j] = fa[fa[i][j-1]][j-1];
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		int lc = getlca(x, y);
		++ cf[x];++ cf[y];cf[lc] -= 2;	// 树上差分 
	}
	dfs1(1);	// 求出 1 为根时的答案 
	
	res = ans;
	getans(1);
	printf("%d\n",tot - res);

	return 0;
}

