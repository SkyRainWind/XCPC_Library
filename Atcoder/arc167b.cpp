// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e6+5, mod=998244353;

signed main(){
	ll a=1ll<<40,b=1e18;
//	ll a,b;cin>>a>>b;
	ll ans=1,f=0;
	for(ll i=2;i<=sqrt(a);i++){
		if(a%i==0){
			int c=0;
			while(a%i==0)++c,a/=i;
			ll qw = 1ll*c*(b%mod)%mod;++qw;qw%=mod;
			if(qw%2 == 0)f=1;
			ans=1ll*ans*qw%mod;
		}
	}
	if(a!=1){
		ans=1ll*ans*((b+1)%mod)%mod;
		if((b+1)%2==0)f=1;
	}
	int inv=(mod+1)/2;
	ans=1ll*ans*(b%mod)%mod;
	if(b%2==0)f=1;
	if(f==0)ans = (ans+mod-1)%mod;
	ans=ans*inv%mod;
	printf("%lld\n",ans);

	return 0;
}

