// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n;
ll a[maxn], b[maxn];

int d(ll p){
	int r=0;
	while(p){r+=p%10;p/=10;}
	return r;
}
signed main(){
	ll ans = 0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]), ans += 2ll*n*d(a[i]);
	ll bs = 1;
	for(int i=0;i<=15;i++){
		bs *= 10;
		for(int j=1;j<=n;j++)
			b[j] = a[j] % bs;
		sort(b+1, b+n+1);
		
		int pos = n;
		for(int j=1;j<=n;j++){
			while(pos >= 1 && b[j] + b[pos] >= bs)-- pos;
			ans -= 9ll*(n-pos);
		}
	}
	cout << ans << '\n';

	return 0;
}

