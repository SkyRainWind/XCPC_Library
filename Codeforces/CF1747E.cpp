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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5e6 + 5, mod=1e9+7;

int p2[maxn * 2];
int fac[maxn], inv[maxn];

int pw(int x,int y){
	if(y == 0)return 1;
	if(y == 1)return x;
	int mid = pw(x, y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

int C(int x,int y){
	return 1ll*fac[x] * inv[y] % mod * inv[x-y] % mod;
}

void solve(){
	int n,m;scanf("%d%d",&n,&m);
	if(n > m)swap(n,m);
	int ans = 0;
	for(int i=0;i<=n;i++){
		int cur = 1ll * C(n,i) * C(m,i) % mod;
		int s = n+m-i-1;
		cur = 1ll * cur * ((1ll * p2[s] * (i+2) % mod + 1ll * s * p2[s-1] % mod) % mod) % mod;
		(ans += cur) %= mod;
	}
	printf("%d\n",ans);
}

signed main(){
	p2[0] = 1;
	fac[0] = inv[0] = 1;
	for(int i=1;i<=maxn - 5;i++)fac[i] = 1ll*fac[i-1]*i%mod;
	for(int i=1;i<=10000000;i++) p2[i] = 2ll*p2[i-1]%mod;
	inv[maxn - 5] = pw(fac[maxn-5] ,mod-2);
	for(int i=maxn-6;i>=1;i--)inv[i] = 1ll*inv[i+1]*(i+1)%mod;
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

