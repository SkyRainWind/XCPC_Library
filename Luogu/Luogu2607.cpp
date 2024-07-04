// by SkyRainWind
#include <cstdio>
#include <queue>
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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=1e6+1;

int n;
vector<int>g[maxn],ed[maxn];
int a[maxn];
LL dp[maxn][2];
int vdfs[maxn], fa[maxn];
int root, hh;

void topo(int x){
	vdfs[x] = 1;
	for(int u : ed[x]){
		if(vdfs[u]){hh = u;continue;}
		topo(u);
	}
}

void upd(int x,int fat = -1){
	vdfs[x] = 1;
	dp[x][0] =0, dp[x][1] = a[x];
	for(int u : g[x]){
		if(u == root){dp[x][1] = -inf;continue;}
		upd(u, x);
		dp[x][0] += max(dp[u][0], dp[u][1]);
		dp[x][1] += dp[u][0];
	}
}

signed main(){
//	freopen("2607.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int to;
		scanf("%d%d",&a[i],&to);
		g[to].push_back(i);
		ed[i].push_back(to);
		fa[i] = to; 
	}
	LL ans = 0;
	for(int i=1;i<=n;i++){
		if(vdfs[i])continue;
		int cr[2],cc=0;
		int pre = i;
		while(!vdfs[pre]){
			vdfs[pre] = 1;
//			cr.push_back(pre);
			pre = fa[pre];
		}
		hh = pre;
		do{
			cr[1] = cr[0];
			cr[0] = hh;
			hh = fa[hh];
		}while(hh != pre);
		root = cr[0];
		upd(root);
		LL t1 = max(dp[root][0], dp[root][1]);
		root = cr[1];
		
		upd(root);
		ans += max(t1, max(dp[root][0], dp[root][1]));
	}
	printf("%lld\n",ans);

	return 0;
}


