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

void solve(){
	int n,po=0,ne=0,ze=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		--x;
		if(x<0)++ne;else if(x>0)++po;else ++ze;
	}
	ll ans = 0;
	ans = 1ll * ze * (n - ze) + 1ll * ze * (ze-1) / 2;
	ans += 1ll * po * ne;
	printf("%lld\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

