// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int n;
ll a[65];
ll d[65];

void insert(ll x){
	for(int i=62;i>=0;i--)if(x & (1ll<<i)){
		if(!d[i]){d[i] = x;break;}
		x ^= d[i];
	}
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),insert(a[i]);
	ll ans=0;
	for(int i=62;i>=0;i--)
		if((ans^d[i]) >= ans)ans ^= d[i];
	cout << ans;

	return 0;
}

