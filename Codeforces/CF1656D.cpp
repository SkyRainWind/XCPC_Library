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

signed main(){
	int te;scanf("%d",&te);
	while(te --){
		ll n;scanf("%lld",&n);
		ll x=n;
		while(x%2==0)x/=2;
		if(x==1)puts("-1");
		else if(x<=2e9 && 1ll*x*(x+1)/2 <= n)printf("%lld\n",x);
		else printf("%lld\n",2*(n/x));
	}

	return 0;
}

