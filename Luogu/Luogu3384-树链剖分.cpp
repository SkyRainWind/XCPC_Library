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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e5+5;

int n,m,rt,p;
vector<int>g[maxn];
int a[maxn];
int dfn[maxn], seq[maxn], dfs_clock;
int dep[maxn], heavy[maxn], top[maxn], sz[maxn], fa[maxn];
struct seg{
	int x,y;
	int sum, lazy;
}se[maxn << 2];

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
	if(x == y){
		se[num].x = x, se[num].y = y;
		se[num].lazy = 0;
		se[num].sum = a[seq[x]] % p;
		return ;
	}
	int mid = x + y >> 1;
	build(x,mid,num << 1);build(mid+1, y, num<<1 | 1);
	se[num].sum = ((LL)se[num << 1].sum + (LL)se[num << 1 | 1].sum) % p;
	se[num].lazy = 0;
	se[num].x = se[num << 1].x, se[num].y = se[num << 1| 1].y;
}

void pushdown(int l,int r,int num){
	if(!se[num].lazy)return ;
	int mid = l+r>>1;
	(se[num << 1].sum += 1ll*(mid-l+1)*se[num].lazy%p) %= p;
	(se[num << 1|1].sum += 1ll * (r-mid)*se[num].lazy%p) %= p;
	se[num << 1].lazy += se[num].lazy;
	se[num << 1|1].lazy += se[num].lazy; 
	se[num].lazy = 0;
}

void update(int x,int y,int k,int l,int r,int num){
	if(x <= l && r <= y){
		(se[num].sum += 1ll * (r-l+1) * k%p ) %= p;
		se[num].lazy += k;
		return ;
	}
	pushdown(l,r,num);
	int mid = l+r >> 1;
	if(y <= mid)update(x,y,k,l,mid,num<<1);
	else if(x > mid)update(x,y,k,mid+1,r,num<<1|1);
	else update(x,y,k,l,mid,num<<1), update(x,y,k,mid+1,r,num<<1|1);
	se[num].sum = ((LL)se[num<<1].sum + (LL)se[num<<1|1].sum) % p;
}

int query(int x,int y,int l,int r,int num){
	if(x <= l && r <= y)
		return se[num].sum;
	pushdown(l, r, num);
	int mid = l+r>>1;
	if(y<=mid)return query(x,y,l,mid,num<<1);
	else if(x>mid)return query(x,y,mid+1,r,num<<1|1);
	else return ((LL)query(x,y,l,mid,num<<1) + (LL)query(x,y,mid+1,r,num<<1|1))%p;
}

void chain_update(int x,int y,int k){
	int tx = top[x], ty = top[y];
	while(tx != ty){
		if(dep[tx] < dep[ty])swap(x, y), swap(tx, ty);
		update(dfn[tx], dfn[x], k, 1, n ,1);
		x = fa[tx], tx = top[x]; 
	}
	if(dep[x] > dep[y])swap(x, y);
	update(dfn[x], dfn[y], k, 1, n, 1);
}

int chain_sum(int x,int y){
	int tx = top[x], ty = top[y];
	LL sum = 0;
	while(tx != ty){
		if(dep[tx] < dep[ty])swap(x, y), swap(tx, ty);
		(sum += query(dfn[tx], dfn[x], 1, n, 1)) %= p;
		x = fa[tx], tx = top[x];
	}
	if(dep[x] > dep[y])swap(x, y);
	(sum += query(dfn[x], dfn[y], 1, n,1)) %= p;
	return sum;
}

signed main(){
	scanf("%d%d%d%d",&n,&m,&rt,&p);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y), g[y].push_back(x);
	}
	dfs1(rt,0);
	dfs2(rt,rt);
	build(1,n,1);
	
//	printf("%d\n",query(1,n,1,n,1));
//	printf("?? %d %d %d\n",se[1].sum,seq[1],seq[2]);
//	printf("!! %d %d\n",dfn[1],sz[1]);
	while(m --){
		int op;scanf("%d",&op);
		if(op == 1){
			int x,y,z;scanf("%d%d%d",&x,&y,&z);
			chain_update(x,y,z);
		}
		if(op == 2){
			int x,y;scanf("%d%d",&x,&y);
			printf("%d\n",chain_sum(x, y));
		}
		if(op == 3){
			int x,z;scanf("%d%d",&x,&z);
			update(dfn[x], dfn[x] + sz[x] - 1,z, 1, n, 1);
		}
		if(op == 4){
			int x;scanf("%d",&x);
			printf("%d\n",query(dfn[x], dfn[x] + sz[x] - 1, 1, n, 1));
		}
	}

	return 0;
}

