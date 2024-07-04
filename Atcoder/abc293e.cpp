// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;
#define int ll

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e5+5;

ll a,m,mod;
ll x;

int pw(int x,ll y){
	if(!y)return 1;
	if(y==1)return x%m;
	int mid=pw(x,y/2);
	if(y%2==1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

ll solve(ll x){
//	if(mp.count(x))return mp[x];
	if(x == 1)return (1+a)%m;
	if(x == 0)return 1;
	 
	ll mid = x/2;
	ll r=0;
	if(x%2==0){
		ll tmp = solve(mid-1);
		ll tmp2 = (tmp + pw(a,mid))% mod;
		r = (tmp + 1ll*pw(a,mid)*tmp2%mod) % mod;
	}else{
		r = 1ll*(1+pw(a, mid+1))%mod*solve(mid)%mod;
	}
	return r;
}

signed main(){
	cin>>a>>x>>m;
	mod = m;
	if(a==1){
		cout << x%m << '\n';
		return 0;
	}
	cout << solve(x-1) % m << '\n';

	return 0;
}

