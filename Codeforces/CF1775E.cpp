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

void solve(){
	int n;
	scanf("%d",&n);
	ll s1=0, s2=0, ans = 0;
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		if(x == 0)continue;
		if(x > 0){
			if(x >= s2){
				ans += x-s2, s2 = 0;
			}else s2 -= x;
			s1 += x;
		}else{
			int tx = -x;
			if(tx >= s1){
				ans += tx-s1, s1 = 0;
			}else s1 -= tx;
			s2 += tx;
		}
	}
	printf("%lld\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

