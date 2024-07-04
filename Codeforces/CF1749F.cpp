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

int n;
vector<int>g[maxn];
int a[maxn];
int dfn[maxn], seq[maxn], dfs_clock;
int dep[maxn], heavy[maxn], top[maxn], sz[maxn], fa[maxn];
struct seg{
	int sum,lazy;
}se[maxn << 2][23];

void dfs1(int x,int fat){
	fa[x] = fat;
	sz[x] = 1;
	dep[x] = dep[fat] + 1;
	
	for(int u : g[x]){
		if(u == fat)continue;
		dfs1(u, x);
		sz[x] += sz[u];
		if(!heavy[x] || sz[u] > sz[heavy[x]])
			heavy[x] = u;
	}
}

void dfs2(int x,int now){
	top[x] = now;
	dfn[x] = ++ dfs_clock;
	seq[dfs_clock] = x;
	
	if(!heavy[x])return ;
	dfs2(heavy[x], now);
	for(int u : g[x]){
		if(u == heavy[x] || u == fa[x])continue;
		dfs2(u,u);
	}
}

void build(int x,int y,int num){
	for(int i=0;i<=20;i++)se[num][i].sum = se[num][i].lazy = 0;
	if(x == y){
		return ;
	}
	int mid = x + y >> 1;
	build(x,mid,num << 1);build(mid+1, y, num<<1 | 1);
}

void pushdown(int l,int r,int num,int d){
	if(!se[num][d].lazy)return ;
	int mid = l+r>>1;
	(se[num << 1][d].sum += 1ll*(mid-l+1)*se[num][d].lazy);
	(se[num << 1|1][d].sum += 1ll * (r-mid)*se[num][d].lazy);
	se[num << 1][d].lazy += se[num][d].lazy;
	se[num << 1|1][d].lazy += se[num][d].lazy; 
	se[num][d].lazy = 0;
}

int getlca(int x,int y){
	int tx = top[x], ty = top[y];
	while(tx != ty){
		if(dep[tx] < dep[ty])swap(x, y), swap(tx, ty);
		x = fa[tx], tx = top[x];
	}
	if(dep[x] > dep[y])return y;
	return x;
}

void update(int x,int y,int k,int l,int r,int num,int d){
	if(x <= l && r <= y){
		(se[num][d].sum += 1ll * (r-l+1) * k);
		se[num][d].lazy += k;
		return ;
	}
	pushdown(l,r,num,d);
	int mid = l+r >> 1;
	if(y <= mid)update(x,y,k,l,mid,num<<1,d);
	else if(x > mid)update(x,y,k,mid+1,r,num<<1|1,d);
	else update(x,y,k,l,mid,num<<1,d), update(x,y,k,mid+1,r,num<<1|1,d);
	se[num][d].sum = (se[num<<1][d].sum + se[num<<1|1][d].sum);
}

void upd(int to,int k,int l,int r,int num,int d){
	if(l == r){
		se[num][d].sum += k;
		return ;
	}
	pushdown(l,r,num,d);
	int mid = l+r>>1;
	if(to<=mid)upd(to,k,l,mid,num<<1,d);
	else upd(to,k,mid+1,r,num<<1|1,d);
	se[num][d].sum = se[num << 1][d].sum + se[num<<1|1][d].sum; 
}

void access(int x,int k,int d){
	int curd = d;
	while(1){
		upd(dfn[x],k,1,n,1,curd);
		if(curd == 0)break;
		upd(dfn[x],k,1,n,1,--curd);
		
		if(x == 1)break;
		x = fa[x];
	}
	while(curd >= 1)upd(dfn[1],k,1,n,1,--curd);
}

int query(int to,int l,int r,int num,int d){
	if(l == r)return se[num][d].sum;
	int mid = l+r>>1;
	pushdown(l,r,num,d);
	if(to <= mid)return query(to,l,mid,num<<1,d);
	else return query(to,mid+1,r,num<<1|1,d);
}

void chain_add(int x,int y,int k,int d){
//	printf("(%d,%d)\n",x,y);
	int tx = top[x], ty = top[y];
	while(tx != ty){
		if(dep[tx] < dep[ty])swap(x, y), swap(tx, ty);
		update(dfn[tx], dfn[x], k, 1, n ,1, d);
		x = fa[tx], tx = top[x]; 
	}
	if(dep[x] > dep[y])swap(x, y);
	update(dfn[x], dfn[y], k, 1, n, 1, d);
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y), g[y].push_back(x);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,n,1);
	
	int m;scanf("%d",&m);
	while(m --){
		int op;scanf("%d",&op);
		if(op == 1){
			int x;scanf("%d",&x);
			int curx = x;
			int ans = 0;
			for(int d = 0;d<=20;d++){
				ans += query(dfn[curx],1,n,1,d);
				if(curx == 1)break;
				curx = fa[curx];
			}
			printf("%d\n",ans);
		}
		if(op == 2){
			int u,v,k,d;scanf("%d%d%d%d",&u,&v,&k,&d);
			int lc = getlca(u, v);
//			printf("?? %d\n",lc);
			if(lc == u || lc == v){
				int tx = lc == u ? v : u;
				int ty = lc;
				chain_add(tx,ty,k,d);
				upd(dfn[lc],-k,1,n,1,d);
				access(lc, k, d); 
			}else{
				chain_add(u,lc,k,d);
				upd(dfn[lc],-k,1,n,1,d);
				chain_add(v,lc,k,d);
				upd(dfn[lc],-k,1,n,1,d);
				access(lc, k, d);
			}
		}
	}

	return 0;
}

