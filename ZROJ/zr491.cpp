// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;
#define int LL

typedef long long LL;

const int inf = 1e18, INF = 0x3f3f3f3f, maxn=2e5+5;

vector<pair<int,int> >g[maxn];
int n,ty[maxn];
int dp[maxn][3];

void dfs(int x,int fat = -1){
	int r = 0, rr = 0, rrr=0;
	if(~fat && g[x].size() == 1){
		for(int i=0;i<=2;i++)
			if(i == ty[x])dp[x][i] = 0;
			else dp[x][i] = inf;
		return ;
	}
	for(int i=0;i<g[x].size();i++){
		pair<int,int> u = g[x][i];
		int v = u.first, w = u.second;
		if(v == fat)continue;
		dfs(v,x);
		if(ty[x] == 1){
			dp[x][0] = dp[x][2] = inf;
			dp[x][1] += min(min(dp[v][0], dp[v][1]), dp[v][2]+w); 
//			dp[x][0] += min(min(dp[v][0], dp[v][1]+w), dp[v][2]+w);
		}
		if(ty[x] == 2){
			dp[x][0] = dp[x][1] = inf;
			dp[x][2] += min(min(dp[v][0], dp[v][1]+w), dp[v][2]); 
		}
		r += min(min(dp[v][0], dp[v][1]), dp[v][2]+w);
		rr += min(min(dp[v][0], dp[v][1]+w), dp[v][2]);
		rrr += min(min(dp[v][0], dp[v][1]+w), dp[v][2]+w);
	}
	if(ty[x] == 0){
		dp[x][0] = rrr;
		dp[x][1] = inf;
		for(int i=0;i<g[x].size();i++){
			pair<int,int>u = g[x][i];
			int v = u.first,w = u.second;
			if(v == fat)continue;
			dp[x][1] = min(dp[x][1], r - min(min(dp[v][0], dp[v][1]), dp[v][2]+w) + dp[v][1]);
		}
		dp[x][2] = inf;
		for(int i=0;i<g[x].size();i++){
			pair<int,int>u = g[x][i];
			int v = u.first,w = u.second;
			if(v == fat)continue;
			dp[x][2] = min(dp[x][2], rr - min(min(dp[v][0], dp[v][1]+w), dp[v][2]) + dp[v][2]);
		}
	}
}

signed main(){
	scanf("%lld",&n);
	int n1,n2;scanf("%lld",&n1);
	while(n1--){int x;scanf("%lld",&x);ty[x] = 1;}
	scanf("%lld",&n2);
	while(n2--){int x;scanf("%lld",&x);ty[x] = 2;}
	
	for(int i=1;i<=n-1;i++){
		int u,v,w;scanf("%lld%lld%lld",&u,&v,&w);
		g[u].push_back(mpr(v,w));
		g[v].push_back(mpr(u,w));
	}
	
	dfs(1);
//	printf("%d %d %d\n",dp[2][0], dp[2][1], dp[2][2]);
//	printf("%d %d %d\n",dp[3][0], dp[3][1], dp[3][2]);
	printf("%lld\n",min(min(dp[1][0], dp[1][1]), dp[1][2]));

	return 0;
}


