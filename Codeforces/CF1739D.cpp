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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5 + 5;

int n,k;
vector<int>g[maxn];
int dep[maxn];
int tot = 0;

int dfs2(int x,int fat,int lim){
	int curd = 0;
	for(int u : g[x]){
		curd = max(curd, dfs2(u, x,lim ));
	}
	++ curd;
	if(fat != 1 && x != 1 && curd >= lim){++tot;return 0;}
	return curd;
}

int check(int x){
	tot = 0;
	dfs2(1,-1,x);
//	printf("?? %d\n",tot);
	if(tot > k)return 0;
	return 1;
}

void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=2;i<=n;i++){
		int p;scanf("%d",&p);
		g[p].push_back(i);
	}
	int l=1,r=n, ans;
//	for(int i=1;i<=n;i++)printf("%d ",dep[i]);puts("");
//	printf("%d\n",check(1));
//	return ;
	while(l <= r){
		int mid = l +r >>1;
		if(check(mid))r = mid-1, ans =mid;
		else l = mid+1;
	}
	printf("%d\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}


