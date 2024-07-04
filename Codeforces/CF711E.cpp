// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 1e6+3;

int pw(ll x,ll y){
	if(!y)return 1;
	if(y == 1)return x;
	int mid=pw(x,y/2);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

signed main(){
	ll n,k;scanf("%lld%lld",&n,&k);
//	if(k >= mod)
//		return puts("1 1"), 0;
	if(n <= 62 && (1ll << n) < k)
		return puts("1 1"), 0;
	
	ll r = 0;
	for(ll p=2;p<=k-1;p*=2){
		r += (k-1) / p;
	}
	
	int fz = 1;
	for(ll i=pw(2,n)-1,c=1;c<=k-1;c++,i--){
		ll j = i;
//		while(j%2 == 0)j /= 2;
		fz = 1ll*fz*j%mod;
		if(fz == 0)break;
	}
//	debug();
	ll fm = pw(2, n);
	fm = pw(fm, k-1);
	fm = 1ll * fm * pw(pw(2, r), mod-2) % mod;
	fz = 1ll * fz * pw(pw(2, r), mod-2) % mod;
	
	fz = (fm - fz + mod)%mod;
	printf("%d %d\n",fz,fm);

	return 0;
}

