// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;

int n,x,a[maxn];
ll pre[maxn];
signed main(){
	scanf("%d%d",&n,&x);
	ll ans = 1e18;
	for(int i=1;i<n;i++)scanf("%d",&a[i]),pre[i] = pre[i-1] + a[i];
	for(int i=1;i+x-1<n;i++){
		ll tmp = pre[i+x-1]-pre[i-1]; 
		ans = min(ans, tmp);
	}
	cout << ans << '\n';

	return 0;
}

