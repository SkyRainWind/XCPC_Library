// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<ll,ll>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int a,b,c,d;ll v,t;

pii solve(ll t){
	ll cur = 0;
	ll x=0,y=0,res=0,tim=-1;
	while(cur <= t){
		if(cur == x){
			res += b-(cur>tim ? 1 : 0);
			tim = cur + v;
			x += a;
		}else{
			res += d-(cur>tim ? 1 : 0);
			tim = cur + v;
			y += c;
		}
		cur = min(x,y);
	}
	return mpr(res,tim>t);
}

void solve(){scanf("%d%d%d%d%lld%lld",&a,&b,&c,&d,&v,&t);
	ll loop = 1ll * a / __gcd(a,c) * c;
	if(t < loop)printf("%lld\n",solve(t).first);
	else{
		pii n1 = solve(loop-1), n2 = solve(t%loop);
		printf("%lld\n",(n1.first + (n1.second ? 1 : 0)) * 1ll * (t/loop) + n2.first);
	}
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

