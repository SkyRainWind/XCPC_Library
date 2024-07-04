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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=1e5+5;

struct matrix{
	int mat[2][2];
	matrix(){memset(mat,-0x3f,sizeof mat);}
};
int n,m,a[maxn];
vector<int>g[maxn];
int dfn[maxn], seq[maxn], dfs_clock=0, sz[maxn], top[maxn], heavy[maxn],End[maxn] ;
// End[i] 存i作为重链的链头对应的链尾 
int dep[maxn], fa[maxn];
int f[maxn][2];
matrix val[maxn];	// 用来存每个点向父亲转移的转移矩阵
/*
f[i][0/1] 表示 i点不选/选的最大价值
g[i][0/1]表示i点所有轻儿子都可选可不选时的答案/强制i点选，i所有轻儿子的答案
那么有 f[i][0] = g[i][0] + max(f[j][0], f[j][1]); f[i][1] = g[i][1] + f[j][0]
其中 j 是 i 的重儿子 
g[i][0] = sum max(f[son[i]][0], f[son[i]][1])
g[i][1] = sum max(
定义广义矩阵乘法：C=A*B s.t. C[i][j] = max(A[i][k] + B[k][j])
那么 (f[i][0], f[i][1])^T = ((g[i][0], g[i][0]), (g[i][1], -inf)) * (f[j][0],f[j][1])^T  
对于一次更新，显然只需要修改从这个点到根上路径的 dp 值，进一步说，就是根节点的 dp 值
因此我们可以不断跳重链，每条重链用一个线段树维护区间 广义乘法值
相当于每个元素是一个矩阵，运算采用广义乘法
修改的话， 
*/

struct segm{
	int l,r;
	matrix m;
}se[maxn << 2];

matrix operator * (matrix a,matrix b){
	matrix c;
	for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
			for(int k=0;k<=1;k++)
				c.mat[i][j] = max(c.mat[i][j], a.mat[i][k] + b.mat[k][j]);
	return c;
}

void dfs1(int x,int fat){
	sz[x] = 1;
	dep[x] = dep[fat] + 1;
	
	for(int u : g[x]){
		if(u == fat)continue;
		fa[u] = x;
		dfs1(u, x);
		sz[x] += sz[u];
		if(sz[heavy[x]] < sz[u])heavy[x] = u;
	}
}

void dfs2(int x,int tp){
	dfn[x] = ++ dfs_clock;
	seq[dfs_clock] = x;
	
	top[x] = tp;
	End[tp] = max(End[tp], dfs_clock);
	
	f[x][0] = 0, f[x][1] = a[x];
	val[x].mat[0][0] =val[x].mat[0][1] = 0;
	val[x].mat[1][0] = a[x];
	
	if(heavy[x]){
		dfs2(heavy[x], tp);
		f[x][0] += max(f[heavy[x]][0], f[heavy[x]][1]);
		f[x][1] += f[heavy[x]][0];
	}
	
	for(int v : g[x]){
		if(v == fa[x] || v == heavy[x])continue;
		dfs2(v, v);
		f[x][0] += max(f[v][0], f[v][1]);
		f[x][1] += f[v][0];
		val[x].mat[0][0] += max(f[v][0], f[v][1]);	// g[x][0]在矩阵中的位置 
		val[x].mat[0][1] = val[x].mat[0][0];
		val[x].mat[1][0] += f[v][0];	// g[x][1]在矩阵中的位置 
	}
}

void build(int l,int r,int num){
	se[num].l = l, se[num].r = r;
	if(l == r){
		se[num].m = val[seq[l]];
		return ;
	}
	
	int mid = l+r>>1;
	build(l,mid,num<<1);build(mid+1,r,num<<1|1);
	se[num].m = se[num<<1].m * se[num<<1|1].m;
}

void update(int x,int num){
	if(se[num].l == se[num].r){
		se[num].m = val[seq[x]];
		return ;
	}
	
	int mid = se[num].l + se[num].r >> 1;
	if(x <= mid)update(x, num<<1);
	else update(x, num<<1|1);
	se[num].m = se[num << 1].m * se[num << 1|1].m; 
}

matrix query_tree(int l,int r,int num){
//	cerr << l << " " << r << " " << num << endl;
	if(l == se[num].l && r == se[num].r)return se[num].m;
	
	int mid = se[num].l+se[num].r>>1;
//	cerr << mid << endl;
	if(r <= mid)return query_tree(l,r,num<<1);
	else if(l > mid) return query_tree(l,r,num<<1|1);
	else return query_tree(l,mid,num<<1) * query_tree(mid+1,r,num<<1|1);
}

void update_path(int x,int w){
	val[x].mat[1][0] += w - a[x];
	a[x] = w;
	
	while(x){
//		cerr << dfn[top[x]] << " " << End[top[x]] << '\n'; 
		matrix bef = query_tree(dfn[top[x]], End[top[x]], 1);
		update(dfn[x], 1);
		matrix aft = query_tree(dfn[top[x]], End[top[x]], 1);
		x = fa[top[x]];
		
		val[x].mat[0][0] += max(aft.mat[0][0], aft.mat[1][0]) - max(bef.mat[0][0], bef.mat[1][0]);
		val[x].mat[0][1] = val[x].mat[0][0];
		val[x].mat[1][0] += aft.mat[0][0] - bef.mat[0][0];
	}
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n-1;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v), g[v].push_back(u);
	}
	
	dfs1(1, 0);dfs2(1,1);
	build(1,n,1);
//	for(int i=1;i<=n;i++)printf("%d\n",heavy[i]);
	
	while(m --){
		int x,w;scanf("%d%d",&x,&w);
		update_path(x,w);
//		debug();
		matrix ans = query_tree(dfn[1], End[1], 1);
		printf("%d\n",max(ans.mat[0][0], ans.mat[1][0]));
	}

	return 0;
}

