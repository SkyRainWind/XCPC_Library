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

ll c(int x){return 1ll*x*(x-1)/2;}

signed main(){
	int n,m;scanf("%d%d",&n,&m);
	++n, ++m;
	
	ll ans = 0; 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
//			int fx = min(i-1, j-1), fy = min(n-i, m-j);
			int dx = min(i-1, n-i), dy = min(j-1, m-j);
//			ans += 1ll * fx * fy;
			ans += 2ll * dx * dy;
			ans += min(j-1, m-j);
			ans += min(i-1, n-i);
		}
	cout << ans << '\n';

	return 0;
}

