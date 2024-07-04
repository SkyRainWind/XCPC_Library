// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5, mod = 1e9+7;

int n,a[maxn],b[maxn];

void solve(){

	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	sort(b+1,b+n+1,[&](int a,int b){return a>b;});
	sort(a+1,a+n+1,[&](int a,int b){return a>b;});

	int now = 1,ans = 1;
	for(int i=1;i<=n;i++){
		while(now <= n && a[now] > b[i])
			++ now;
		-- now;
		if(now-i+1 < 0)
			return puts("0"), void();
		ans = 1ll*ans*(now-i+1)%mod;
	}
	printf("%d\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}
