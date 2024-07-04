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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = (1 << 20) + 5,mod=1e9+7;

int n, a[maxn], f[maxn], dp[maxn];

int pw(int x,int y){
	if(y == 0)return 1;
	if(y == 1)return x;
	int mid = pw(x, y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), ++ dp[a[i]];
	for(int i=0;i<=19;i++)
		for(int S = (1<<20)-1; S>=0; S--){
			if((S & (1<<i))==0)
				dp[S] += dp[S ^ (1<< i)], dp[S] %= mod;
		}
	for(int S = 0;S <= (1<<20) - 1;S++)
		dp[S] = (pw(2, dp[S]) - 1 + mod) % mod;
	
	for(int i=0;i<=19;i++)
		for(int S = (1<<20) - 1; S >=0;S --)
			if((S & (1<<i))==0)dp[S] = (dp[S] - dp[S ^ (1<<i)] + mod) % mod;
	printf("%d\n",dp[0]);

	return 0;
}

