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
	int n;scanf("%d",&n);
	vector<ll>a(n+1);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]); 
	if(n%2 == 1)return (void)puts("YES");
	for(int i=n-1;i>=3;i-=2){
		ll tmp = a[i] - a[i+1];
		if(i>1)a[i-1] -= tmp;
	}
	if(a[1] <= a[2])puts("YES");
	else puts("NO");
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

