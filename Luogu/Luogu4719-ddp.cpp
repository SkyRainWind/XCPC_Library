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
// End[i] ��i��Ϊ��������ͷ��Ӧ����β 
int dep[maxn], fa[maxn];
int f[maxn][2];
matrix val[maxn];	// ������ÿ��������ת�Ƶ�ת�ƾ���
/*
f[i][0/1] ��ʾ i�㲻ѡ/ѡ������ֵ
g[i][0/1]��ʾi����������Ӷ���ѡ�ɲ�ѡʱ�Ĵ�/ǿ��i��ѡ��i��������ӵĴ�
��ô�� f[i][0] = g[i][0] + max(f[j][0], f[j][1]); f[i][1] = g[i][1] + f[j][0]
���� j �� i ���ض��� 
g[i][0] = sum max(f[son[i]][0], f[son[i]][1])
g[i][1] = sum max(
����������˷���C=A*B s.t. C[i][j] = max(A[i][k] + B[k][j])
��ô (f[i][0], f[i][1])^T = ((g[i][0], g[i][0]), (g[i][1], -inf)) * (f[j][0],f[j][1])^T  
����һ�θ��£���Ȼֻ��Ҫ�޸Ĵ�����㵽����·���� dp ֵ����һ��˵�����Ǹ��ڵ�� dp ֵ
������ǿ��Բ�����������ÿ��������һ���߶���ά������ ����˷�ֵ
�൱��ÿ��Ԫ����һ������������ù���˷�
�޸ĵĻ��� 
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
		val[x].mat[0][0] += max(f[v][0], f[v][1]);	// g[x][0]�ھ����е�λ�� 
		val[x].mat[0][1] = val[x].mat[0][0];
		val[x].mat[1][0] += f[v][0];	// g[x][1]�ھ����е�λ�� 
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

