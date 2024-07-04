// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, maxn=1e6+5;

int n,m;
struct edges{
	int to,nxt;
}ed[maxn<<1];
int head[maxn],ecnt=0;
int sz[maxn], heavy[maxn], top[maxn], deep[maxn], fa[maxn];
int dfn[maxn], seq[maxn];
int dfs_clock=0;
struct segment{
	int sum,lazy;
}se[maxn << 2];

void add(int x,int y){
	ed[++ ecnt].to=y;ed[ecnt].nxt=head[x];head[x]=ecnt;
}

void dfs1(int x,int fat=0){
	
	deep[x] = deep[fat] + 1;
	fa[x] = fat;
	sz[x] = 1;
	
	for(int i=head[x];i!=-1;i=ed[i].nxt){
		int u=ed[i].to;
		if(u == fat)continue;
		dfs1(u,x); 
		sz[x] += sz[u];
		if(heavy[x] == 0 || sz[u] > sz[heavy[x]]){
			heavy[x] = u;
		}
	}
}

void dfs2(int u,int now){
	top[u] = now;
	dfn[u] = ++dfs_clock;
	seq[dfs_clock] = u;
	if(!heavy[u])return ;
	dfs2(heavy[u], now);
	for(int i=head[u];i!=-1;i=ed[i].nxt){
		int v=ed[i].to;
		if(v == heavy[u] || v == fa[u])continue;
		dfs2(v,v);
	}
}

int getlca(int x,int y){
	while(top[x] != top[y]){
		if(deep[top[x]] < deep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(deep[x] > deep[y])swap(x,y);
	return x; 
}

void build(int x,int y,int num){
	if(x == y){se[num].sum = 0;se[num].lazy = 0;return ;}
	int mid=x+y>>1;
	build(x,mid,num<<1);build(mid+1,y,num<<1|1);
	se[num].sum = se[num<<1].sum + se[num<<1|1].sum;
}

struct que{
	int a,b;
	que(){}
	que(int a,int b):a(a),b(b){}
}qu[maxn];

void pushdown(int num,int l,int r){
	if(!se[num].lazy)return ;
	(se[num<<1].lazy+=se[num].lazy);
	(se[num<<1|1].lazy+=se[num].lazy);
	
	int mid=l+r>>1;
	se[num<<1].sum=(se[num<<1].sum+(mid-l+1)*se[num].lazy);
	se[num<<1|1].sum=(se[num<<1|1].sum+(r-(mid+1)+1)*se[num].lazy);
	se[num].lazy=0;
}

int query(int x,int y,int l,int r,int num){
	if(x<=l&&r<=y){
		return se[num].sum;
	}
	pushdown(num,l,r);
	int mid=l+r>>1;
	if(y<=mid)return query(x,y,l,mid,num<<1);
	else if(x>mid)return query(x,y,mid+1,r,num<<1|1);
	else return (query(x,y,l,mid,num<<1)+query(x,y,mid+1,r,num<<1|1));
}

void update(int x,int y,int pl,int l,int r,int num){
	if(x<=l&&r<=y){
		se[num].sum=(se[num].sum+(r-l+1)*pl);
		(se[num].lazy+=pl);
		return ;
	}
	pushdown(num,l,r);
	int mid=l+r>>1;
	if(y<=mid)update(x,y,pl,l,mid,num<<1);
	else if(x>mid)update(x,y,pl,mid+1,r,num<<1|1);
	else{
		update(x,y,pl,l,mid,num<<1);
		update(x,y,pl,mid+1,r,num<<1|1);
	}
	se[num].sum=(se[num<<1].sum+se[num<<1|1].sum);
}

int chain_sum(int u,int v){
	int tu=top[u],tv=top[v];
	int ans=0;
	while(tu!=tv){
		if(deep[tu]<deep[tv]){
			swap(u,v);
			swap(tu,tv);
		}
		
		(ans+=query(dfn[tu],dfn[u],1,n,1));
		u=fa[tu];
		tu=top[u];
	}
	if(deep[u]>deep[v])swap(u,v);
	(ans+=query(dfn[u],dfn[v],1,n,1));
	return ans;
}

int g[maxn];

inline int read()
{
    int res = 0;
    char ch;
    do ch = getchar(); while (ch < 48 || ch > 57);
    do res = res * 10 + ch - 48, ch = getchar(); while (ch >= 48 && ch <= 57) ;
    return res;
}

int main()
{
	memset(head,-1,sizeof head);
	n = read(), m = read();
    for (int i = 1; i < n; ++i)
    {
        int u = read(), v = read();
        add(u, v);
        add(v, u);
    }
    dfs1(1);
    dfs2(1,1);
    build(1, n,1);
    for (int i = 1; i <= m; ++i)
    {
    	qu[i].a = read(), qu[i].b = read();
		int lc = getlca	(qu[i].a, qu[i].b);
    	++g[lc];
    	update(dfn[lc],dfn[lc],1,1,n,1);
    }
    LL ans = 0;
    for(int i=1;i<=m;i++)ans += chain_sum(qu[i].a, qu[i].b) - 1;
    for(int i=1;i<=n;i++)ans -= (g[i] -1) * g[i] / 2;
    printf("%lld", ans);
    return 0;
}
