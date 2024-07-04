// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e6+5, mod = 998244353;

int n,k,a[maxn],dp[maxn];
int fac[maxn], inv[maxn], to[maxn];

int pw(int x,int y){
	if(!y)return 1;
	if(y==1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

int que(int l,int r){
	return 1ll*fac[r]*inv[l-1]%mod;
}

signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	reverse(a+1,a+n+1);
	
	for(int i=1, j=1;i<=n;i++){
		while(j <= n && a[i] - a[j] <= k)++ j;
		to[i] = j;
	}
	
	fac[0] = inv[0] = 1;
	for(int i=1;i<=n;i++)fac[i] = 1ll*fac[i-1]*i%mod;
	inv[n] = pw(fac[n], mod-2);
	for(int i=n-1;i>=1;i--)inv[i] = 1ll*inv[i+1]*(i+1)%mod;
	
	if(a[1] - a[2] > k)dp[1] = 1;
	for(int i=1;i<n;i++){
		// (i+2) .. (to[i]-1)
		(dp[to[i+1]-1] += 1ll*dp[i]*que(i, to[i+1]-3)%mod) %= mod;
		(dp[i+1] += 1ll*dp[i]*i%mod) %= mod;
	}
	printf("%d\n",dp[n]);

	return 0;
}

