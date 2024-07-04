// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=233;

int n,m,k,n1,n2;
int a[maxn],b[maxn], v[maxn],vis[maxn];
int ans=1e9;

void check(){
	int a1=k,a2=k,r=0;
	for(int i=1;i<=n;i++)
		if(v[i] == 1){
			if(vis[i] == 1)--a1;
			else if(vis[i] == 2)--a2;
			else if(vis[i]==3)--a1,--a2;
			r+=a[i];
		}
	if(a1>0||a2>0)return ;
	if(r==121){
		for(int i=1;i<=n;i++)if(v[i])printf("%d ",i);printf("r=%d %d %d\n",r,a1,a2);
	}
	ans=min(ans,r);
}

void dfs(int x, int ls=0){
	if(x == n+1){
		if(ls !=m)return ;
		check();
		return ;
	}
	if(ls == m){
		check();
		return ;
	}
	v[x] = 0;
	dfs(x+1,ls);
	v[x] = 1;
	dfs(x+1,ls+1);
}

signed main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&n1);
	for(int i=1;i<=n1;i++){
		int t;scanf("%d",&t);
		vis[t]++;
	}
	scanf("%d",&n2);
	for(int i=1;i<=n2;i++){
		int t;scanf("%d",&t);
		vis[t]+=2;
	}
	dfs(1);
	printf("%d\n",ans);

	return 0;
}

