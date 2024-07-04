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
int val[maxn];
int dfn[maxn], seq[maxn], dfs_clock;
int dep[maxn], heavy[maxn], top[maxn], sz[maxn], fa[maxn];
int X[maxn], Y[maxn], Z[maxn];
struct seg{
	int mx, lazyadd, lazyall;
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
		se[num].lazyadd = 0;se[num].lazyall = -1;
		se[num].mx = val[seq[x]];
		return ;
	}
	int mid = x + y >> 1;
	build(x,mid,num << 1);build(mid+1, y, num<<1 | 1);
	se[num].mx = max(se[num<<1].mx, se[num << 1|1].mx);
	se[num].lazyadd = 0;se[num].lazyall = -1;
}

void pushdown(int l,int r,int num){
	if(~se[num].lazyall){
		se[num << 1].mx = se[num<<1 | 1].mx = se[num].lazyall;
		se[num << 1].lazyall = se[num << 1 | 1].lazyall = se[num].lazyall;
		se[num << 1].lazyadd = se[num << 1 | 1].lazyadd = 0;
		se[num].lazyall = -1;
	}
	if(se[num].lazyadd){
		se[num << 1].mx += se[num].lazyadd;
		se[num << 1|1].mx += se[num].lazyadd;
		se[num << 1].lazyadd += se[num].lazyadd;
		se[num << 1|1].lazyadd += se[num].lazyadd;
		se[num].lazyadd = 0;
	}
}

void add(int x,int y,int k,int l,int r,int num){
	if(x <= l && r <= y){
		se[num].mx += k;
		se[num].lazyadd += k;
		return ;
	}
	pushdown(l,r,num);
	int mid = l+r >> 1;
	if(y <= mid)add(x,y,k,l,mid,num<<1);
	else if(x > mid)add(x,y,k,mid+1,r,num<<1|1);
	else add(x,y,k,l,mid,num<<1), add(x,y,k,mid+1,r,num<<1|1);
	se[num].mx = max(se[num << 1].mx, se[num << 1| 1].mx);
}

void cover(int x,int y,int k,int l,int r,int num){
	if(x <= l && r <= y){
		se[num].mx = k;
		se[num].lazyadd = 0;
		se[num].lazyall = k;
		return ;
	}
	pushdown(l,r,num);
	int mid = l+r >> 1;
	if(y <= mid)cover(x,y,k,l,mid,num<<1);
	else if(x > mid)cover(x,y,k,mid+1,r,num<<1|1);
	else cover(x,y,k,l,mid,num<<1), cover(x,y,k,mid+1,r,num<<1|1);
	se[num].mx = max(se[num << 1].mx, se[num << 1| 1].mx);
}

int query(int x,int y,int l,int r,int num){
	if(x <= l && r <= y)
		return se[num].mx;
	pushdown(l, r, num);
	int mid = l+r>>1;
	if(y<=mid)return query(x,y,l,mid,num<<1);
	else if(x>mid)return query(x,y,mid+1,r,num<<1|1);
	else return max(query(x,y,l,mid,num<<1),query(x,y,mid+1,r,num<<1|1));
}

void chain_add(int x,int y,int k){
	int tx = top[x], ty = top[y];
	while(tx != ty){
		if(dep[tx] < dep[ty])swap(x, y), swap(tx, ty);
		add(dfn[tx], dfn[x], k, 1, n ,1);
		x = fa[tx], tx = top[x]; 
	}
	if(dep[x] > dep[y])swap(x, y);
	if(x!=y)add(dfn[x]+1, dfn[y], k, 1, n, 1);
}

void chain_cover(int x,int y,int k){
	int tx = top[x], ty = top[y];
	while(tx != ty){
		if(dep[tx] < dep[ty])swap(x, y), swap(tx, ty);
		cover(dfn[tx], dfn[x], k, 1, n ,1);
		x = fa[tx], tx = top[x]; 
	}
	if(dep[x] > dep[y])swap(x, y);
	if(x!=y)cover(dfn[x]+1, dfn[y], k, 1, n, 1);
}

void modify(int tx,int t,int l,int r,int num){
	if(l == r){
		se[num].mx = t;
		return ;
	}
	pushdown(l,r,num);
	int mid = l+r>>1;
	if(tx<=mid)modify(tx,t,l,mid,num<<1);
	else modify(tx,t,mid+1,r,num<<1|1);
	se[num].mx = max(se[num << 1].mx, se[num<<1|1].mx);
}

int chain_max(int x,int y){
	int tx = top[x], ty = top[y];
	int sum = -1e9;
	while(tx != ty){
		if(dep[tx] < dep[ty])swap(x, y), swap(tx, ty);
//		cerr << tx << " " << x << " " << dfn[tx] << " " << dfn[x] << "\n";
//		printf("?? %d %d %d %d\n",x,tx,dfn[tx]+1,dfn[x]);
		sum = max(sum, query(dfn[tx], dfn[x], 1, n, 1));
		x = fa[tx], tx = top[x];
	}
	if(dep[x] > dep[y])swap(x, y);
//	cerr << dfn[x] +1 << " " << dfn[y] << "\n";
	if(x != y)sum = max(sum, query(dfn[x] + 1, dfn[y], 1, n,1));
	return sum;
}

signed main(){
//	freopen("4315.in","r",stdin);
//	freopen("P4315.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&X[i],&Y[i]);scanf("%d",&Z[i]);
		g[X[i]].push_back(Y[i]), g[Y[i]].push_back(X[i]);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=n-1;i++){
		int tx = X[i], ty = Y[i];
		if(fa[tx] != ty)swap(tx, ty);
		val[tx] = Z[i]; 
	}
	build(1,n,1);
//	printf("?? %d %d\n",top[4],top[1]);
	while(1){
		char op[12];scanf("%s",op + 1);
		if(op[1] == 'S')break;
		if(op[1] == 'A'){	// Add
			int x,y,z;scanf("%d%d%d",&x,&y,&z);
			chain_add(x,y,z);
		}
		if(op[1] == 'M'){	// Max
			int x,y;scanf("%d%d",&x,&y);
			printf("%d\n",chain_max(x, y));
		}
		if(op[2] == 'h'){	// Change
			int x,z;scanf("%d%d",&x,&z);
			int tx = X[x], ty = Y[x];
			if(dep[tx] < dep[ty])swap(tx, ty);
			modify(dfn[tx],z,1,n,1);
		}
		if(op[2] == 'o'){	// Cover
			int x,y,z;scanf("%d%d%d",&x,&y,&z);
			chain_cover(x,y,z);
		}
	}

	return 0;
}

