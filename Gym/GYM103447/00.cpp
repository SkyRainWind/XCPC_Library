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

int n,m,rt,mod;
int a[maxn];
vector<int>g[maxn];
int fa[maxn],dep[maxn],sz[maxn],heavy[maxn];
int dfn[maxn],top[maxn],seq[maxn],dfs_clock;

void dfs(int x,int fat){
	fa[x] = fat;
	sz[x] = 1;
	dep[x] = dep[fat] + 1;
	for(int u:g[x])if(u!=fat){
		dfs(u,x);
		sz[x] += sz[u];
		if(!heavy[x] || sz[u] > sz[heavy[x]])heavy[x] = u;
	}
}

void dfs2(int x,int tp){
	dfn[x] = ++dfs_clock;
	top[x] = tp;
	seq[dfs_clock] = x;
	if(!heavy[x])return ;
	dfs2(heavy[x], tp);
	for(int u : g[x])if(u!=heavy[x] && u!=fa[x])dfs2(u,u);
}

struct segm{
	int sum,lazy;
}se[maxn << 2];

void build(int l,int r,int num){
	se[num].lazy = 0;
	if(l == r){
		se[num].sum = a[seq[l]]%mod;
		return ;
	}
	int mid=l+r>>1;
	build(l,mid,num<<1);build(mid+1,r,num<<1|1);
	se[num].sum = se[num<<1].sum + se[num<<1|1].sum;
	se[num].sum %= mod;
}

void pushdown(int num,int l,int r){
	if(!se[num].lazy)return ;
	int mid=l+r>>1;
	
	(se[num<<1].lazy += se[num].lazy) %= mod;
	(se[num<<1|1].lazy += se[num].lazy) %= mod;
	(se[num<<1].sum += 1ll*(mid-l+1)*se[num].lazy%mod) %= mod;
	(se[num<<1|1].sum += 1ll*(r-mid)*se[num].lazy%mod) %= mod;
	
	se[num].lazy = 0;
}

void update(int x,int y,int to,int l,int r,int num){
	if(x<=l&&r<=y){
		(se[num].sum += 1ll*(r-l+1)*to%mod)%=mod;
		(se[num].lazy += to)%=mod;
		return ;
	}
	pushdown(num,l,r);
	int mid=l+r>>1;
	if(y<=mid)update(x,y,to,l,mid,num<<1);
	else if(x>mid)update(x,y,to,mid+1,r,num<<1|1);
	else update(x,y,to,l,mid,num<<1), update(x,y,to,mid+1,r,num<<1|1);
	(se[num].sum = se[num<<1].sum + se[num<<1|1].sum) %= mod; 
}

ll query(int x,int y,int l,int r,int num){
	if(x<=l&&r<=y)return se[num].sum;
	int mid=l+r>>1;
	pushdown(num,l,r);
	if(y<=mid)return query(x,y,l,mid,num<<1);
	else if(x>mid)return query(x,y,mid+1,r,num<<1|1);
	else return (query(x,y,l,mid,num<<1)+query(x,y,mid+1,r,num<<1|1))%mod;
}

int chain_sum(int x,int y){
	int tx = top[x], ty = top[y];
	ll sum =0 ;
	while(tx != ty){
		if(dep[tx] < dep[ty])swap(tx,ty),swap(x,y);
		(sum += query(dfn[tx], dfn[x], 1,n,1)) %= mod;
		x=fa[tx], tx = top[x];
	}
	if(dep[x] > dep[y])swap(x,y);
	(sum += query(dfn[x], dfn[y],1,n,1)) %= mod;
	return sum;
}

void chain_add(int x,int y,int z){
	int tx = top[x], ty = top[y];
	while(tx != ty){
		if(dep[tx] < dep[ty])swap(tx,ty),swap(x,y);
		update(dfn[tx],dfn[x],z,1,n,1);
		x=fa[tx], tx = top[x];
	}
	if(dep[x] > dep[y])swap(x,y);
	update(dfn[x],dfn[y],z,1,n,1);
}

signed main(){
	scanf("%d%d%d%d",&n,&m,&rt,&mod);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
	}
	dfs(rt,0);
	dfs2(rt,rt);
	build(1,n,1);
	while(m--){
		int op,x,y,z;scanf("%d",&op);
		if(op == 1){
			scanf("%d%d%d",&x,&y,&z);
			chain_add(x,y,z);
		}else if(op == 2){
			scanf("%d%d",&x,&y);
			printf("%d\n",chain_sum(x,y));
		}else if(op == 3){
			scanf("%d%d",&x,&z);
			update(dfn[x], dfn[x]+sz[x]-1,z,1,n,1);
		}else{
			scanf("%d",&x);
			printf("%lld\n",query(dfn[x],dfn[x]+sz[x]-1,1,n,1));
		}
	}

	return 0;
}

