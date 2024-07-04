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

int n,a[maxn],b[maxn],cf[maxn];
ll df[maxn];
ll pre[maxn];
void solve(){
	scanf("%d",&n);
	for(int i=0;i<=n+1;i++)cf[i]=pre[i]=df[i]=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	
	for(int i=1;i<=n;i++)pre[i] = pre[i-1] + b[i];
	ll bs = 0;
	for(int i=1;i<=n;i++){
		int t = upper_bound(pre+i, pre+n+1, bs+a[i]) - pre - 1;
		// [i..t]
		++ cf[i], -- cf[t+1];
		ll qs = pre[t] - pre[i-1];
		if(t+1 <= n)df[t+1] += a[i] - qs;
		bs += b[i];
	}
	
	int cur = 0;
	for(int i=1;i<=n;i++){
		cur += cf[i];
		df[i] += 1ll*cur*b[i];
		printf("%lld ",df[i]);
	}
	puts("");
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

