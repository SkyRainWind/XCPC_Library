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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1005;

int n,a[maxn], f[maxn];
LL res[maxn];
int g[maxn][maxn], v[maxn];

void dijk(){
	for(int i=1;i<=n;i++){
		int cur=0;
		for(int j=1;j<=n;j++){
			if(!v[j] && (cur == 0 || f[cur] > f[j]))cur = j;
		}
		
		v[cur] = 1;
		for(int j=1;j<=n;j++)if(v[j]){
			if(g[cur][j] && f[cur] + f[j] < f[g[cur][j]]){
				f[g[cur][j]] = f[cur] + f[j];
				res[g[cur][j]] = res[cur] * res[j];
			}else if(g[cur][j] && f[cur] + f[j] == f[g[cur][j]])
				res[g[cur][j]] += res[cur] * res[j];
		}
	}
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), f[i] = a[i], res[i] =1 ;
	int x,y,t;
	while(scanf("%d%d%d",&x,&y,&t) != EOF){
		++x, ++y, ++t;
		g[x][y] = g[y][x] = t;
	}
	dijk();
	printf("%d %lld\n",f[1], res[1]);

	return 0;
}

