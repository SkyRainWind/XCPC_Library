// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 998244353, maxn = 2e5 + 5;

int n,a[maxn];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%1d",&a[i]);
	if(n == 1){
		puts("1");
		return ;
	}
	int cursz = 1;
	int ans = 1;
	for(int i=1;i<=n-1;i++){
		if(a[i] == a[i+1]){
			cursz = 2ll * cursz % mod;
			(ans += cursz) %= mod;
		}else{
			cursz = 1;
			ans ++;
			ans %= mod;
		}
	}
	printf("%d\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

