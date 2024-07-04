// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int n,k;

signed main(){
	ll ans=0;
	scanf("%d%d",&n,&k);
	ans=1ll*k*n;
	
	for(int l=1,r;l<=min(n,k);){
		r = k/(k/l);
		if(r>min(n,k))r=min(n,k);
		ans-=1ll*(k/l)*(1ll*(l+r)*(r-l+1)/2);
		l=r+1;
	}
	cout<<ans;

	return 0;
}

