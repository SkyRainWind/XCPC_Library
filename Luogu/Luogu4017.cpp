// by SkyRainWind
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5005, mod = 80112002;

int n,m;
vector<int>g[maxn];
int de[maxn], ans[maxn];

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y);
		++ de[y];
	}
	queue<int>Q;
	for(int i=1;i<=n;i++)if(de[i] == 0)Q.push(i), ans[i] = 1;
	int res = 0;
	while(!Q.empty()){
		int fr = Q.front();Q.pop();
		if(g[fr].size() == 0)(res += ans[fr]) %= mod;
		for(int u : g[fr]){
			(ans[u] += ans[fr]) %= mod;
			if(-- de[u] == 0)Q.push(u);
		}
	}
	printf("%d\n",res);

	return 0;
}

