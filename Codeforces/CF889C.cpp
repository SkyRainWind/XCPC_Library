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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e6 + 5;
const int mod = 1e9 +7;

int dp[maxn],fac[maxn],inv[maxn],sum[maxn];

int pw(int x,int y) {
	if(!y)return 1;
	if(y == 1)return x;
	int mid = pw(x, y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

int C(int x,int y) {
	return 1ll * fac[x] * inv[x-y] % mod * inv[y] % mod;
}

signed main() {
	int n,k;
	scanf("%d%d",&n,&k);
	fac[0] = inv[0] = 1;
	for(int i=1; i<=(int)1e6; i++)fac[i] = 1ll * fac[i-1] * i % mod;
	inv[(int)1e6] = pw(fac[(int)1e6], mod - 2);
	for(int i = 999999; i>=1; i--)inv[i] = 1ll * inv[i+1] * (i+1)%mod;
	dp[1] = sum[1] = 1;
	for(int i=2; i<=n; i++) {
		int sm;
		if(i-k >= 1)sm = sum[i-1] - sum[i-k-1], dp[i] = 1ll * sm * fac[i-1] % mod;
		else dp[i] = fac[i];
		sum[i] = (sum[i-1] + 1ll * dp[i] * inv[i] % mod)%mod;
	}
	int res = 0;
	for(int i=1; i<=n; i++) {
		if(i == 1)dp[0] = 1;
		(res += (mod - 1ll * dp[i-1] * C(n-1, n-i) % mod * fac[n-i] % mod) % mod) %= mod;
	}
	(res += fac[n]) %= mod;
//	printf("%d %d %d\n",dp[1],dp[2],dp[3]);
	printf("%d\n",res);

	return 0;
}

