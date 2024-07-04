// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 3e5 + 5;

map<vector<int>,ll> dp[maxn];
int n,a[maxn];

pair<vector<int>, ll>go(int x,vector<int>c){
	if(x == 0)
		return mpr(c, 1);
	int fg = 0;
	for(int i=0;i<c.size();i++){
		int u = c[i];
		if(u&x){
			fg = 1;
			c[i] = x;
			break;
		}
	}
	if(!fg){
		c.push_back(x);
		return mpr(c, 1);
	}
	return mpr(c, 0);
}

ll solve(int x,vector<int>c){
	if(x == n+1)return 0;
	if(dp[x].count(c))return dp[x][c];
	auto p = go(a[x], c);
	return dp[x][c] = 1ll * (n-x+1) * p.second + solve(x+1, p.first);
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
	ll ans = 0;
	for(int i=1;i<=n;i++)
		ans += solve(i, vector<int>(0));
	printf("%lld\n",ans);

	return 0;
}

