// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,mod=998244353;

ll f(ll x){
	ll res=0;
	for(ll l=1,r;l<=x;l=r+1){
		r=x/(x/l);
		res += x/l*1ll*(r-l+1)%mod, res%=mod;
	}
	return res;
}

signed main(){
	ll l,r;scanf("%lld%lld",&l,&r);
	printf("%lld\n",(f(r) - f(l-1)+mod)%mod);

	return 0;
}

