// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2e5+5;

int n,a[maxn],dept[maxn],fa[maxn][23],buc[maxn];
LL dep[maxn];
vector<pair<int,int> >g[maxn];

void dfs(int x,int fat=0){
	fa[x][0] = fat;
	for(pair<int,int> now : g[x]){
		int u = now.first, w = now.second;
		if(u == fat)continue;
		dep[u] = dep[x] + w;
		dept[u] = dept[x] + 1;
		dfs(u, x);
	}
}

int getanc(int x,int k){	// kmax = dept[x] - 1
	int tp = x;
	for(int i=0;i<=20;i++)
		if(k&(1<<i))tp = fa[tp][i];
	return tp;
}

int check(int x,int k){
	int anc = getanc(x, k);
	int dis = dep[x] - dep[anc];
	return dis <= a[x];
}

void dfs2(int x,int fat=0){
	for(pair<int,int> now : g[x]){
		int u = now.first, w = now.second;
		if(u == fat)continue;
		dfs2(u, x);
	}
	if(x != 1){
		int l = 1, r = dept[x] - 1, ans = -1;
		while(l <= r){
			int mid = l+r>>1;
			if(check(x,mid))l = mid+1, ans = mid;
			else r = mid-1;
		}
		if(~ans){
			int rans = getanc(x, ans);
			++ buc[fa[x][0]]; -- buc[fa[rans][0]];
		}
	}
}

void dfs3(int x,int fat = 0){
	for(pair<int,int> now : g[x]){
		int u = now.first;
		if(u == fat)continue;
		dfs3(u, x);
		buc[x] += buc[u];
	}
}

signed main(){
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	for(int i=2;i<=n;i++){
		int x,w;scanf("%I64d%I64d",&x,&w);
		g[i].push_back(mpr(x,w));g[x].push_back(mpr(i,w));
	}
	dept[1] = 1;
	dfs(1);
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n;i++)fa[i][j] = fa[fa[i][j-1]][j-1];
	dfs2(1);
	dfs3(1);
	for(int i=1;i<=n;i++)printf("%I64d ",buc[i]);puts("");

	return 0;
}


