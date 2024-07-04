// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 998244353;

map<ll,ll>f,g;
void solve(ll n){
	if(n == 0){
		f[n] = 0, g[n] = 1;
		return ;
	}
	if(f.count(n))return ;
	if(n%2 == 1){
		solve(n/2);
		(f[n] = 2ll*f[n/2]%mod + g[n/2])%=mod;
		g[n] = g[n/2];
	}else{
		solve(n/2);solve(n/2-1);
		f[n] = 2ll * (f[n/2] + f[n/2-1]) % mod;
		g[n] = (g[n/2] + g[n/2-1]) % mod;
	}
}

signed main(){
	int te;scanf("%d",&te);
	while(te --){
		f.clear(), g.clear();
		ll n,m;cin >> n >> m;
		if(m == 1){
			cout << n%mod << '\n';
		}else if(m >= 3){
			if(n%2 == 1)cout << (n+1)/2%mod*((n+1)/2%mod)%mod << '\n';
			else cout << (1+n/2%mod)*(n/2%mod) % mod << '\n';
		}else{
			solve(n);
			cout << f[n] << '\n';
		}
	}

	return 0;
}

