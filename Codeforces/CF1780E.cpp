// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

void solve(){
	ll L,R; 
	scanf("%lld%lld",&L,&R);
	
	ll ans=(R/2 - L+1);
	if(ans<0)ans=0;
	
	for(ll l=1,r;l<=L-1;){
		r = (L-1) / ((L-1) / l);
		ll now = (L-1) / l;
		
		ll le = l, ri = r, res=-1;
		while(le <= ri){
			ll mid = le+ri>>1;
			if(R/mid >= now+2)res = mid, le=mid+1;
			else ri=mid-1;
		}
		if(~res)ans += res-l+1;
		l = r+1;
	}
	cout<<ans<<'\n';
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

