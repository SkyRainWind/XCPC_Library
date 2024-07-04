// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
ll sv(ll c){
	for(int i=(int)sqrt(1.0 * c + 0.5);i>=1;i--){
		if(c%i == 0 && gcd(i, c/i)==1)return i;
	}
}

signed main(){
	ll a,b;
	while(scanf("%lld%lld",&a,&b)!=EOF){
		ll c = b/a;
		ll d = sv(c);
		ll e = c/d;
		printf("%lld %lld\n",a*d,a*e);
	}

	return 0;
}

