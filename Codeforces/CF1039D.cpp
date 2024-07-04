// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=1e5 + 5;

// dp[i] 考虑到 i 点的最大答案 
int n;
struct ed{
	int to, nxt;
}ed[maxn << 1];
int head[maxn], ecnt=0;
int dp[maxn];
int mx[maxn][2], ans[maxn];
int dfn[maxn], dfs_clock, fa[maxn];

void add(int x,int y){
	ed[++ ecnt].to = y;ed[ecnt].nxt=head[x];head[x]=ecnt;
}

int dfs(int lim){
	int res = 0;
	for(int i=1;i<=n;i++)dp[i] = 1;
	for(int i=n;i>=1;i--){
		int x = dfn[i];
		int f = fa[x];
		if(f && dp[f] && dp[x]){	// f!=0 表示不是根节点；dp[f]/dp[x]!=0 表示f和x点都没有一条 横穿的链（因为这样的话必然不可能向上延伸） 
			if(dp[x] + dp[f] >= lim)++ res, dp[f] = 0;
			else dp[f] = max(dp[f], dp[x] + 1);
		}
	}
	return res;
}

void dfs0(int x,int fat=0){
	dfn[++ dfs_clock] = x;
	fa[x] = fat;
	for(int i=head[x];i;i=ed[i].nxt){
		int u=ed[i].to;
		if(u==fat)continue;
		dfs0(u, x);
	}
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);
		add(x, y);add(y, x);
	}
	dfs0(1);
	int blk = (int)sqrt(1.0 * n * log(n) / log(2.0));
	ans[1] = n;
	for(int i=2;i<=blk;i++){
		ans[i] = dfs(i); 
	}
	int rt = 0;
	for(int i=blk+1;i<=n;i=rt+1){
		int l = i+1, r = n;
		rt = i;
		int bs = dfs(i);
		
		while(l <= r){
			int mid = l+r>>1;
			int tt = dfs(mid);
			if(tt == bs)l = mid+1, rt = mid;
			else r = mid-1;
		}
		for(int j=i;j<=rt;j++)ans[j] = bs;
	}
	for(int i=1;i<=n;i++)printf("%d\n",ans[i]);

	return 0;
}


