// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1005;

int n,qu,a[maxn],k;
ll b[maxn];

int check(ll s){
	ll r = 0;
	for(int i=1;i<=n;i++){
		if(b[i] < s)return 0;
		r += abs(b[i] - s);
	}
	if(r >= k)return 1;
	return 0;
}

signed main(){
	scanf("%d%d",&n,&qu);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	while(qu --){
		scanf("%d",&k);
		for(int i=1;i<=n;i++)b[i] = a[i];
		if(k <= n){
			ll ans = 2e14;
			for(int i=1;i<=k;i++)b[i] += k-i+1;
			for(int i=1;i<=n;i++) ans = min(ans, b[i]);
			printf("%lld ",ans);
			continue;
		}
		
		for(int i=1;i<=n;i++)b[i] = a[i];
		if((k-n)%2 == 0){
			for(int i=1;i<=n;i++)
				b[i] += k-i+1;
			k -= n;
		}else{
			for(int i=1;i<=n-1;i++)
				b[i] += k-i+1;
			k -= n-1;
		}
		k /= 2;
		
		ll l=-2e9, r=2e14, ans;
		while(l <= r){
			ll mid = l+r>>1;
			if(check(mid))ans = mid, l =mid+1;
			else r = mid-1;
		}
		printf("%lld ",ans);
	}

	return 0;
}

