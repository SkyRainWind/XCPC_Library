// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e6+5;

int a[1005];
bitset<maxn>dp;
int n;

signed main(){
	scanf("%d",&n);
	dp[0] = 1;
	int sum=0;
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		dp ^= (dp<<x);
	}
	int ans = 0;
	for(int i=1;i<=maxn-5;i++)
		if(dp[i])ans ^= i;
	cout << ans << '\n';

	return 0;
}

