// by SkyRainWind
#include <cstdio>
#include <queue>
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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2e5+5;
const double eps = 1e-6;

int n,m;
int a[maxn],vis[maxn],cnt[maxn];
double dis[maxn];
struct node{int to;double t,f;};
vector<node>g[maxn];

int check(double r){
	for(int i=0;i<=n;i++)dis[i] = 1e9, vis[i] = cnt[i] = 0;
	
	queue<int>Q;
	Q.push(0);dis[0] = 0;vis[0] = 1;
	while(!Q.empty()){
		int x = Q.front();Q.pop();
		vis[x] = 0;	////////!!!
		for(node now : g[x]){
			int u = now.to;
			double v = r * now.t - now.f;
			if(dis[u] > dis[x] + v){
				dis[u] = dis[x] + v;
				cnt[u] = cnt[x] + 1;
				if(cnt[u] >= n+1)return 1;
				if(!vis[u]){
					vis[u] = 1;
					Q.push(u);
				}
			}
		}
	}
	return 0; 
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y,v,p;scanf("%d%d%d%d",&x,&y,&v,&p);
		g[x].push_back((node){y,1.0 * p,1.0 * v});
	}
	for(int i=1;i<=n;i++)g[0].emplace_back((node){i,0,0});
	double l = 0.0, r = 200, ans = 1e9;
	while(fabs(r - l) > eps){
		double mid = (l+r)/2.0;
		if(check(mid))l = mid, ans = mid;
		else r = mid;
	}
	if(fabs(ans - 1e9) < eps)puts("-1");
	else printf("%.1f\n",ans);

	return 0;
}


