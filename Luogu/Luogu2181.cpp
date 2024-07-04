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

signed main(){
	int n;scanf("%d",&n);
	unsigned long long ans = 0;
	for(int i=3;i<=n-1;i++){
		int t1 = i-2, t2 = n-i;
		ans += 1ll*t1*t2;
	}
	ans *= n;
	cout << ans/4; 

	return 0;
}

