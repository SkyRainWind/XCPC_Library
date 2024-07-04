// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;
int n,m;
vector<pii>g[maxn];
int out[maxn], in[maxn];
vector<int>seq;
double dp[maxn], coef[maxn];
vector<pair<int,pii>>ed;
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		g[x].push_back(mpr(y, z));
		ed.push_back(mpr(x,mpr(y,z)));
		++ out[x];++ in[y];
	}
	queue<int>Q;
	Q.push(1);seq.push_back(1);
	while(!Q.empty()){
		int now = Q.front(); Q.pop();
		for(pii u : g[now]){
			if(-- in[u.first] == 0){
				Q.push(u.first);
				seq.push_back(u.first);
			}
		}
	}
	
	dp[1] = 1.0;
	for(int u : seq){
		for(pii v : g[u]){
			dp[v.first] += dp[u] / out[u];
//			(dp[v.first] += 1.0 / coef[u] * (dp[u]+v.second));
		}
	}
	double ans = 0.0;
	for(pair<int,pii> u : ed){
		ans += dp[u.first] / out[u.first] * u.second.second;
	}
//	for(int i=1;i<=n;i++)printf("%f\n",dp[i]);
	printf("%.2f\n",ans);

	return 0;
}

