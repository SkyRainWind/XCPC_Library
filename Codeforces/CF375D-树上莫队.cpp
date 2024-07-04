// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn = 2e5+5;

int n,q;
vector<int>g[maxn];
struct node{int v,id,dfn,r;}a[maxn];
struct query{int x,k,l,r,id;}qu[maxn];
int dfs_clock, blk;
int val[maxn], sum[maxn], ans[maxn];
	// val[i] i 颜色出现次数 sum[i] 有多少个节点数 >=i 的颜色 

void dfs(int x,int fat = 0){
	a[x].dfn = ++ dfs_clock;
	for(int u : g[x])if(u != fat){
		dfs(u, x);
	}
	a[x].r = dfs_clock;
}

int cmp1(node a,node b){return a.dfn < b.dfn;}
int cmp2(query a,query b){
	if(a.l / blk == b.l / blk)return a.r < b.r;
	return a.l < b.l;
}

void add(int x){
	++ val[a[x].v];
	++ sum[val[a[x].v]];
}

void del(int x){
	-- sum[val[a[x].v]];
	-- val[a[x].v];
}

signed main(){
	scanf("%d%d",&n,&q);
	blk = (int)sqrt(1.0 * n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].v), a[i].id = i;
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
	}

	dfs(1);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&qu[i].x,&qu[i].k);
		qu[i].l = a[qu[i].x].dfn;		
		qu[i].r = a[qu[i].x].r;	
		qu[i].id = i;	
	}
	sort(a+1,a+n+1,cmp1);
	sort(qu+1,qu+q+1,cmp2);
	
	int l=0, r=0;
	for(int i=1;i<=q;i++){
		int le = qu[i].l, ri = qu[i].r;
		while(l > le)add(--l);
		while(r < ri)add(++r);
		while(l < le)del(l++);
		while(r > ri)del(r--);
		ans[qu[i].id] = sum[qu[i].k];
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);

	return 0;
}

