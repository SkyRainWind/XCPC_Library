// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 998244353;

signed main(){
	int ans=1,n;
	cin>>n;
	for(int i=1;i<n;i++)
		ans = 2ll*ans%mod;
	cout << ans << '\n';

	return 0;
}
